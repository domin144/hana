// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/assert.hpp>
#include <boost/hana/concept/struct.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/fuse.hpp>
#include <boost/hana/integral_constant.hpp>

#include "minimal_struct.hpp"
#include <laws/base.hpp>
#include <support/minimal_product.hpp>
namespace hana = boost::hana;

int main() {
    auto modifiable_object = obj(0, 1, 2);
    hana::for_each(
        modifiable_object,
        hana::fuse([](auto, auto &value) { ++value; }));
    BOOST_HANA_RUNTIME_ASSERT(hana::equal(modifiable_object, obj(1, 2, 3)));

    return 0;
}
