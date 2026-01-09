/*!
@file
Defines `boost::hana::accessors`.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_ACCESSORS_HPP
#define BOOST_HANA_ACCESSORS_HPP

#include <boost/hana/fwd/accessors.hpp>

#include <boost/hana/concept/struct.hpp>
#include <boost/hana/config.hpp>
#include <boost/hana/core/dispatch.hpp>
#include <boost/hana/first.hpp>
#include <boost/hana/functional/id.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/transform.hpp>
#include <utility>

namespace boost { namespace hana {
    template <typename S>
    struct accessors_t {
    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        static_assert(hana::Struct<S>::value,
        "hana::accessors<S> requires 'S' to be a Struct");
    #endif

        constexpr decltype(auto) operator()() const {
            using Accessors = BOOST_HANA_DISPATCH_IF(accessors_impl<S>,
                hana::Struct<S>::value
            );

            return Accessors::apply();
        }
    };

    template <typename S, bool condition>
    struct accessors_impl<S, when<condition>> : default_ {
        template <typename ...Args>
        static constexpr auto apply(Args&& ...) = delete;
    };

    namespace struct_detail {
        template <typename ...>
        struct is_valid { static constexpr bool value = true; };
    }

    template <typename S>
    struct accessors_impl<S, when<
        struct_detail::is_valid<typename S::hana_accessors_impl>::value
    >>
        : S::hana_accessors_impl
    { };


    // Required field:
    // constexpr auto apply() {
    //      return hana::make_tuple(
    //          hana::make_pair(
    //              boost::hana::string_c<'l', 'a', 'b', 'e', 'l'>,
    //              struct_type::*member),
    //          hana::make_pair(
    //              boost::hana::string_c<'l', 'a', 'b', 'e', 'l', '2'>,
    //              struct_type::*member_2));
    // }
    template <typename struct_type>
    struct simple_accessors_impl;

    namespace struct_detail {
    struct simple_accessor_to_accessor
    {
        template <typename member_annotation>
        constexpr auto operator()(const member_annotation& annotation) const
        {
            return make_pair(
                hana::first(annotation), [annotation](auto&& p) -> decltype(auto) {
                    return id(
                        std::forward<decltype(p)>(p).*hana::second(annotation));
                });
        }
    };

    template <typename simple_accessors>
    struct simple_accessors_to_accessors
    {
        static constexpr auto apply()
        {
            return transform(simple_accessors::apply(), simple_accessor_to_accessor {});
        }
    };
    }

    template <typename S>
    struct accessors_impl<
        S,
        when<struct_detail::is_valid<
            decltype(simple_accessors_impl<S>::apply)>::value>>
        : struct_detail::simple_accessors_to_accessors<
            simple_accessors_impl<S>>
    {
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_ACCESSORS_HPP
