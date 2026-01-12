/*!
@file
Forward declares utility functions for types realizing the `boost::hana::Enum`
concept.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_ENUM_UTILS_HPP
#define BOOST_HANA_FWD_ENUM_UTILS_HPP

#include <boost/hana/concept/enum.hpp>

namespace boost { namespace hana {
    //! Returns the `enum_description` entry corresponding to a given enum
    //! value. This is primarily useful to map an enum value to its compile-
    //! time description (name + integral constant) in a type-safe way.
    //! @ingroup group-Enum
    //!
    //! Example
    //! -------
    //! @include example/enum/description.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto enum_description_by_value = [](auto&& value) {
        return tag-dispatched;
    };
#else
    template <typename E, typename = void>
    struct enum_description_by_value_impl
        : enum_description_by_value_impl<E, when<true>>
    { };

    struct enum_description_by_value_t {
        template <typename E, E value>
        constexpr auto operator()(const integral_constant<E, value>) const;
    };

    BOOST_HANA_INLINE_VARIABLE constexpr enum_description_by_value_t
    enum_description_by_value{};


    struct enum_select_t {
        template <typename E, typename F>
        constexpr auto operator()(const E value, F&&) const;
    };

    BOOST_HANA_INLINE_VARIABLE constexpr enum_select_t
    enum_select{};

#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_ENUM_UTILS_HPP
