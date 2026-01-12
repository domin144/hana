// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/assert.hpp>
#include <boost/hana/enum_description.hpp>
#include <boost/hana/enum_utils.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/string.hpp>
#include <boost/hana/tuple.hpp>
#include <string>

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

struct to_int {
    template<typename Pair>
    constexpr int operator()(Pair &&x) const {
        using T = std::decay_t<decltype(boost::hana::second(x))>;
        return static_cast<int>(T::value);
    }
};

struct to_string {
    template<typename Pair>
    constexpr char const* operator()(Pair &&x) const {
        return boost::hana::first(x).c_str();
    }
};

template <typename E>
E from_string(const std::string &s) {
    bool found = false;
    E result{};
    boost::hana::for_each(
        boost::hana::enum_description<E>(),
        [&found, &result, &s](auto &&pair) {
            if (found || s != boost::hana::first(pair).c_str())
                return;
            found = true;
            result = boost::hana::second(pair).value;
        });
    return result;
}

int main() {
    static_assert(boost::hana::Enum<length>::value, "length is not an Enum");

    // description_by_value
    static_assert(
        boost::hana::enum_description_by_value(
            boost::hana::integral_c<length, length::short_>)
        == boost::hana::make_pair(
            boost::hana::string_c<'s', 'h', 'o', 'r', 't'>,
            boost::hana::integral_c<length, length::short_>),
        "value description not found");
    static_assert(
        boost::hana::enum_detail::index_range<length>()
        == boost::hana::range_c<std::size_t, 0, 3>,
        "unexpected index range for length");

    static_assert(
        boost::hana::enum_select(length::medium, to_int{}) == 1,
        "enum_select failed");
    static_assert(
        boost::hana::enum_select(length::long_, to_int{}) == 2,
        "enum_select failed");
    BOOST_HANA_RUNTIME_CHECK(
        boost::hana::enum_select(length::long_, to_string{})
        == std::string{"long"});
    BOOST_HANA_RUNTIME_CHECK(from_string<length>("long") == length::long_);

    return 0;
}
