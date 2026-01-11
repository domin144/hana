/*!
@file
Defines `boost::hana::enum_description`.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_ENUM_DESCRIPTION_HPP
#define BOOST_HANA_ENUM_DESCRIPTION_HPP

#include <boost/hana/fwd/enum_description.hpp>

#include <boost/hana/concept/enum.hpp>
#include <boost/hana/config.hpp>
#include <boost/hana/core/dispatch.hpp>

namespace boost { namespace hana {
    template <typename E>
    struct enum_description_t {
    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        static_assert(hana::Enum<E>::value,
        "hana::enum_description<S> requires 'E' to be an Enum");
    #endif

        constexpr decltype(auto) operator()() const {
            using Description = BOOST_HANA_DISPATCH_IF(enum_description_impl<E>,
                hana::Enum<E>::value
            );

            return Description::apply();
        }
    };

    template <typename E, bool condition>
    struct enum_description_impl<E, when<condition>> : default_ {
        template <typename ...Args>
        static constexpr auto apply(Args&& ...) = delete;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_ENUM_DESCRIPTION_HPP
