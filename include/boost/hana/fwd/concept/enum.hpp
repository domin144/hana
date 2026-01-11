/*!
@file
Forward declares `boost::hana::Enum`.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_CONCEPT_ENUM_HPP
#define BOOST_HANA_FWD_CONCEPT_ENUM_HPP

#include <boost/hana/config.hpp>


namespace boost { namespace hana {
    //! @ingroup group-concepts
    //! @defgroup group-Enum Enum
    //! The `Enum` concept represents `enums` with additional annotion.
    //!
    //! The `Enum` concept allows restricted compile-time reflection over
    //! enums. In particular, it allows accessing the names of the values.
    //! 
    //! Additionally, `Enum` can be used to instantiate templates over its
    //! values and select those instances at runtime.
    //!
    //! Minimal complete definition
    //! ---------------------------
    //! `enum_description`
    //!
    //! A model of `Enum` is created by specifying a sequence of key/value
    //! pairs. The first element of a pair in this sequence represents
    //! the "name" of a value, while the second element is a value itself.
    //! The "names" do not have to be in any special form; they just have to be
    //! compile-time `Comparable`. For example, it is common to provide "names"
    //! that are `hana::string`s representing the actual names of the values,
    //! but one could provide `hana::integral_constant`s just as well.
    //!
    //! @snippet example/struct.custom_accessor.cpp main
    //!
    //!
    //! Laws
    //! ----
    //! TODO or skip.
    template <typename E>
    struct Enum;
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_CONCEPT_ENUM_HPP
