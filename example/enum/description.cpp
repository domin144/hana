// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/enum_description.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/string.hpp>
#include <boost/hana/tuple.hpp>

//! [main]
enum class length {
    short_,
    medium,
    long_,
    // Enum may contain special value, which we do not to model in the 
    // enum_description. These might become redundant with the description
    // present, but this is not always feasible to remove them, especially in
    // legacy code.
    Num
};


namespace boost { namespace hana {
    template <>
    struct enum_description_impl<::length> {
        static constexpr auto apply() {
            using T = ::length;
            return make_tuple(
                make_pair(
                    string_c<'s', 'h', 'o', 'r', 't'>,
                    integral_c<T, T::short_>),
                make_pair(
                    string_c<'m', 'e', 'd', 'i', 'u', 'm'>,
                    integral_c<T, T::medium>),
                make_pair(
                    string_c<'l', 'o', 'n', 'g'>,
                    integral_c<T, T::long_>)
            );
        }
    };
}}
//! [main]

int main() {
    static_assert(boost::hana::Enum<length>::value, "length is not an Enum");

    return 0;
}
