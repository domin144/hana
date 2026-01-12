/*!
@file
Defines utility functions for types realizing the `boost::hana::Enum` concept.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_ENUM_UTILS_HPP
#define BOOST_HANA_ENUM_UTILS_HPP

#include <boost/hana/enum_description.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/find_if.hpp>
#include <boost/hana/functional/compose.hpp>
#include <boost/hana/fwd/enum_utils.hpp>
#include <boost/hana/second.hpp>

#include <array>
#include <boost/hana/find.hpp>
#include <boost/hana/functional/on.hpp>
#include <boost/hana/length.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/maximum.hpp>
#include <boost/hana/range.hpp>
#include <boost/hana/reverse.hpp>
#include <boost/hana/transform.hpp>
#include <boost/hana/zip_with.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/plus.hpp>

namespace boost { namespace hana {
    //! @cond
    template <typename E, E value>
    constexpr auto enum_description_by_value_t::operator()(
        const integral_constant<E, value> c) const
    {
        using Enum_description_by_value_ =
            BOOST_HANA_DISPATCH_IF(
                enum_description_by_value_impl<E>,
                hana::Enum<E>::value
            );

#ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
            static_assert(hana::Enum<E>::value,
            "hana::enum_description_by_value(value) requires 'value' to be an "
            "Enum");
#endif

        return Enum_description_by_value_::apply(c);
    }
    //! @endcond

    template <typename E, bool condition>
    struct enum_description_by_value_impl<E, when<condition>> : default_ {
        template <E value>
        static constexpr auto apply(const integral_constant<E, value> c) {
            const auto result = hana::find_if(
                enum_description<E>(),
                compose(equal.to(c), second));
            static_assert(
                is_just(result),
                "enum value not found in the description");
            return result.value();
        }
    };


    namespace enum_detail {
        struct reverse_pair_t {
            template<typename T, typename U>
            constexpr pair<U, T> operator()(pair<T, U> &&x) const {
                return {
                    second(static_cast<pair<T, U>&&>(x)),
                    first(static_cast<pair<T, U>&&>(x))};
            }
        };

        BOOST_HANA_INLINE_VARIABLE constexpr reverse_pair_t reverse_pair{};

        struct const_to_underlying_type_t {
            template <typename T, T v>
            constexpr auto operator()(const integral_constant<T, v>) const
            {
                using U = std::underlying_type_t<T>;
                return integral_c<U, static_cast<U>(v)>;
            }
        };

        BOOST_HANA_INLINE_VARIABLE constexpr const_to_underlying_type_t const_to_underlying_type{};

        struct value_to_index_array_t {
            template <typename Map, typename ...Value>
            constexpr auto operator()(Map map, Value ...value) const {
                return std::array<std::size_t, sizeof...(Value)>{
                    find(map, value).value_or(static_cast<std::size_t>(-1))...
                };
            }
        };

        template <typename E>
        using U = std::underlying_type_t<E>;

        template <typename E>
        static constexpr auto index_range() {
            return range<std::size_t, 0, length(enum_description<E>())>{};
        };

        template <typename E>
        static constexpr auto index_and_value() {
            return zip_with(
                make_pair,
                to_tuple(make_range(size_c<0>, length(enum_description<E>()))),
                transform(
                    enum_description<E>(),
                    on(const_to_underlying_type, second)));
        }

        template <typename E>
        static constexpr auto value_and_index() {
            return transform(index_and_value<E>(), reverse_pair);
        }

        template <typename E>
        static constexpr auto index_to_value() {
            return to_map(index_and_value<E>());
        }

        template <typename E>
        static constexpr auto value_to_index() {
            return to_map(value_and_index<E>());
        }

        template <typename E>
        static constexpr auto max_value() {
            return maximum(transform(index_and_value<E>(), second));
        }

        template <typename E>
        static constexpr auto value_range() {
            return make_range(
                integral_c<U<E>, 0>,
                max_value<E>() + integral_c<U<E>, 1>);
        }

        template <typename E>
        static constexpr auto enum_to_description_index() {
            return unpack(
                to_tuple(value_range<E>()),
                partial(value_to_index_array_t{}, value_to_index<E>()));
        }
        
        template <typename E, typename F, typename Index>
        constexpr decltype(auto) specialization(F f) {
            return static_cast<F>(f)(at(enum_description<E>(), Index{}));
        }

        template <typename E, typename F>
        struct specializations {
            template<typename ...Index>
            constexpr auto operator()(Index ...)
            {
                using return_type =
                    decltype(std::declval<F>()(front(enum_description<E>())));
                using function_type = return_type(F);
                return std::array<function_type *, sizeof...(Index)>{
                    &specialization<E, F, Index>...};
            }
        };
    }

    template <typename E, typename F>
    constexpr auto enum_select_t::operator()(const E value, F &&f) const {
        const auto enum_to_description_index =
            enum_detail::enum_to_description_index<E>();
        const std::size_t index =
            enum_to_description_index[static_cast<std::size_t>(value)];
        constexpr auto specializations = unpack(
            enum_detail::index_range<E>(),
            enum_detail::specializations<E, F&&>{});
        return specializations[index](static_cast<F&&>(f));
    }
}} // end namespace boost::hana

#endif // !BOOST_HANA_ENUM_UTILS_HPP
