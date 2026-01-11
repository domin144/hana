/*!
@file
Forward declares `boost::hana::enum_description`.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_ENUM_DESCRIPTION_HPP
#define BOOST_HANA_FWD_ENUM_DESCRIPTION_HPP

#include <boost/hana/config.hpp>
#include <boost/hana/core/when.hpp>


namespace boost { namespace hana {
    //! Returns a `Sequence` of pairs representing the description of the
    //! enum type.
    //! @ingroup group-Enum
    //!
    //! Given an `Enum` `E`, `enum_description<S>()` is a `Sequence` of
    //! `Product`s where the first element of each pair is the "name" of a value
    //! of the `Enum`, and the second element of each pair is an integral 
    //! constant for the value.
    //!
    //! Example
    //! -------
    //! @include example/enum/description.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    template <typename S>
    constexpr auto enum_description = []() {
        return tag-dispatched;
    };
#else
    template <typename E, typename = void>
    struct enum_description_impl : enum_description_impl<E, when<true>> { };

    template <typename E>
    struct enum_description_t;

    template <typename E>
    BOOST_HANA_INLINE_VARIABLE constexpr enum_description_t<E> enum_description
    {};
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_ENUM_DESCRIPTION_HPP
