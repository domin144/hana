// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/assert.hpp>
#include <boost/hana/at_key.hpp>
#include <boost/hana/concept/struct.hpp>
#include <boost/hana/contains.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/string.hpp>

#include <laws/base.hpp>
namespace hana = boost::hana;
using hana::test::ct_eq;


namespace ns {
    struct Data0 { };
    struct Data1 {
        ct_eq<1> member1;
    };
    struct Data2 {
        ct_eq<1> member1;
        ct_eq<2> member2;
    };
    struct Data3 {
        ct_eq<1> member1;
        ct_eq<2> member2;
        ct_eq<3> member3;
    };
    struct MemberArray {
        int array[10];
    };
    struct Data100 {
        ct_eq<0> m00;
        ct_eq<1> m01;
        ct_eq<2> m02;
        ct_eq<3> m03;
        ct_eq<4> m04;
        ct_eq<5> m05;
        ct_eq<6> m06;
        ct_eq<7> m07;
        ct_eq<8> m08;
        ct_eq<9> m09;
        ct_eq<10> m10;
        ct_eq<11> m11;
        ct_eq<12> m12;
        ct_eq<13> m13;
        ct_eq<14> m14;
        ct_eq<15> m15;
        ct_eq<16> m16;
        ct_eq<17> m17;
        ct_eq<18> m18;
        ct_eq<19> m19;
        ct_eq<20> m20;
        ct_eq<21> m21;
        ct_eq<22> m22;
        ct_eq<23> m23;
        ct_eq<24> m24;
        ct_eq<25> m25;
        ct_eq<26> m26;
        ct_eq<27> m27;
        ct_eq<28> m28;
        ct_eq<29> m29;
        ct_eq<30> m30;
        ct_eq<31> m31;
        ct_eq<32> m32;
        ct_eq<33> m33;
        ct_eq<34> m34;
        ct_eq<35> m35;
        ct_eq<36> m36;
        ct_eq<37> m37;
        ct_eq<38> m38;
        ct_eq<39> m39;
        ct_eq<40> m40;
        ct_eq<41> m41;
        ct_eq<42> m42;
        ct_eq<43> m43;
        ct_eq<44> m44;
        ct_eq<45> m45;
        ct_eq<46> m46;
        ct_eq<47> m47;
        ct_eq<48> m48;
        ct_eq<49> m49;
        ct_eq<50> m50;
        ct_eq<51> m51;
        ct_eq<52> m52;
        ct_eq<53> m53;
        ct_eq<54> m54;
        ct_eq<55> m55;
        ct_eq<56> m56;
        ct_eq<57> m57;
        ct_eq<58> m58;
        ct_eq<59> m59;
        ct_eq<60> m60;
        ct_eq<61> m61;
        ct_eq<62> m62;
        ct_eq<63> m63;
        ct_eq<64> m64;
        ct_eq<65> m65;
        ct_eq<66> m66;
        ct_eq<67> m67;
        ct_eq<68> m68;
        ct_eq<69> m69;
        ct_eq<70> m70;
        ct_eq<71> m71;
        ct_eq<72> m72;
        ct_eq<73> m73;
        ct_eq<74> m74;
        ct_eq<75> m75;
        ct_eq<76> m76;
        ct_eq<77> m77;
        ct_eq<78> m78;
        ct_eq<79> m79;
        ct_eq<80> m80;
        ct_eq<81> m81;
        ct_eq<82> m82;
        ct_eq<83> m83;
        ct_eq<84> m84;
        ct_eq<85> m85;
        ct_eq<86> m86;
        ct_eq<87> m87;
        ct_eq<88> m88;
        ct_eq<89> m89;
        ct_eq<90> m90;
        ct_eq<91> m91;
        ct_eq<92> m92;
        ct_eq<93> m93;
        ct_eq<94> m94;
        ct_eq<95> m95;
        ct_eq<96> m96;
        ct_eq<97> m97;
        ct_eq<98> m98;
        ct_eq<99> m99;
    };
}

namespace boost {
namespace hana {
    template<>
    struct simple_accessors_impl<ns::Data0> {
        static constexpr auto apply() {
            return make_tuple();
        }
    };

    template<>
    struct simple_accessors_impl<ns::Data1> {
        static constexpr auto apply() {
            using T = ns::Data1;
            return make_tuple(
                make_pair(
                    hana::string_c<'m', 'e', 'm', 'b', 'e', 'r', '1'>,
                    &T::member1)
            );
        }
    };

    template<>
    struct simple_accessors_impl<ns::Data2> {
        static constexpr auto apply() {
            using T = ns::Data2;
            return make_tuple(
                make_pair(
                    hana::string_c<'m', 'e', 'm', 'b', 'e', 'r', '1'>,
                    &T::member1),
                make_pair(
                    hana::string_c<'m', 'e', 'm', 'b', 'e', 'r', '2'>,
                    &T::member2)
            );
        }
    };

    template<>
    struct simple_accessors_impl<ns::Data3> {
        static constexpr auto apply() {
            using T = ns::Data3;
            return make_tuple(
                make_pair(
                    hana::string_c<'m', 'e', 'm', 'b', 'e', 'r', '1'>,
                    &T::member1),
                make_pair(
                    hana::string_c<'m', 'e', 'm', 'b', 'e', 'r', '2'>,
                    &T::member2),
                make_pair(
                    hana::string_c<'m', 'e', 'm', 'b', 'e', 'r', '3'>,
                    &T::member3)
            );
        }
    };

    template<>
    struct simple_accessors_impl<ns::MemberArray> {
        static constexpr auto apply() {
            using T = ns::MemberArray;
            return make_tuple(
                make_pair(
                    hana::string_c<'a', 'r', 'r', 'a', 'y'>,
                    &T::array)
            );
        }
    };

    template<>
    struct simple_accessors_impl<ns::Data100> {
        static constexpr auto apply() {
            using T = ns::Data100;
            return make_tuple(
                make_pair(hana::string_c<'m', '0', '0'>, &T::m00),
                make_pair(hana::string_c<'m', '0', '1'>, &T::m01),
                make_pair(hana::string_c<'m', '0', '2'>, &T::m02),
                make_pair(hana::string_c<'m', '0', '3'>, &T::m03),
                make_pair(hana::string_c<'m', '0', '4'>, &T::m04),
                make_pair(hana::string_c<'m', '0', '5'>, &T::m05),
                make_pair(hana::string_c<'m', '0', '6'>, &T::m06),
                make_pair(hana::string_c<'m', '0', '7'>, &T::m07),
                make_pair(hana::string_c<'m', '0', '8'>, &T::m08),
                make_pair(hana::string_c<'m', '0', '9'>, &T::m09),
                make_pair(hana::string_c<'m', '1', '0'>, &T::m10),
                make_pair(hana::string_c<'m', '1', '1'>, &T::m11),
                make_pair(hana::string_c<'m', '1', '2'>, &T::m12),
                make_pair(hana::string_c<'m', '1', '3'>, &T::m13),
                make_pair(hana::string_c<'m', '1', '4'>, &T::m14),
                make_pair(hana::string_c<'m', '1', '5'>, &T::m15),
                make_pair(hana::string_c<'m', '1', '6'>, &T::m16),
                make_pair(hana::string_c<'m', '1', '7'>, &T::m17),
                make_pair(hana::string_c<'m', '1', '8'>, &T::m18),
                make_pair(hana::string_c<'m', '1', '9'>, &T::m19),
                make_pair(hana::string_c<'m', '2', '0'>, &T::m20),
                make_pair(hana::string_c<'m', '2', '1'>, &T::m21),
                make_pair(hana::string_c<'m', '2', '2'>, &T::m22),
                make_pair(hana::string_c<'m', '2', '3'>, &T::m23),
                make_pair(hana::string_c<'m', '2', '4'>, &T::m24),
                make_pair(hana::string_c<'m', '2', '5'>, &T::m25),
                make_pair(hana::string_c<'m', '2', '6'>, &T::m26),
                make_pair(hana::string_c<'m', '2', '7'>, &T::m27),
                make_pair(hana::string_c<'m', '2', '8'>, &T::m28),
                make_pair(hana::string_c<'m', '2', '9'>, &T::m29),
                make_pair(hana::string_c<'m', '3', '0'>, &T::m30),
                make_pair(hana::string_c<'m', '3', '1'>, &T::m31),
                make_pair(hana::string_c<'m', '3', '2'>, &T::m32),
                make_pair(hana::string_c<'m', '3', '3'>, &T::m33),
                make_pair(hana::string_c<'m', '3', '4'>, &T::m34),
                make_pair(hana::string_c<'m', '3', '5'>, &T::m35),
                make_pair(hana::string_c<'m', '3', '6'>, &T::m36),
                make_pair(hana::string_c<'m', '3', '7'>, &T::m37),
                make_pair(hana::string_c<'m', '3', '8'>, &T::m38),
                make_pair(hana::string_c<'m', '3', '9'>, &T::m39),
                make_pair(hana::string_c<'m', '4', '0'>, &T::m40),
                make_pair(hana::string_c<'m', '4', '1'>, &T::m41),
                make_pair(hana::string_c<'m', '4', '2'>, &T::m42),
                make_pair(hana::string_c<'m', '4', '3'>, &T::m43),
                make_pair(hana::string_c<'m', '4', '4'>, &T::m44),
                make_pair(hana::string_c<'m', '4', '5'>, &T::m45),
                make_pair(hana::string_c<'m', '4', '6'>, &T::m46),
                make_pair(hana::string_c<'m', '4', '7'>, &T::m47),
                make_pair(hana::string_c<'m', '4', '8'>, &T::m48),
                make_pair(hana::string_c<'m', '4', '9'>, &T::m49),
                make_pair(hana::string_c<'m', '5', '0'>, &T::m50),
                make_pair(hana::string_c<'m', '5', '1'>, &T::m51),
                make_pair(hana::string_c<'m', '5', '2'>, &T::m52),
                make_pair(hana::string_c<'m', '5', '3'>, &T::m53),
                make_pair(hana::string_c<'m', '5', '4'>, &T::m54),
                make_pair(hana::string_c<'m', '5', '5'>, &T::m55),
                make_pair(hana::string_c<'m', '5', '6'>, &T::m56),
                make_pair(hana::string_c<'m', '5', '7'>, &T::m57),
                make_pair(hana::string_c<'m', '5', '8'>, &T::m58),
                make_pair(hana::string_c<'m', '5', '9'>, &T::m59),
                make_pair(hana::string_c<'m', '6', '0'>, &T::m60),
                make_pair(hana::string_c<'m', '6', '1'>, &T::m61),
                make_pair(hana::string_c<'m', '6', '2'>, &T::m62),
                make_pair(hana::string_c<'m', '6', '3'>, &T::m63),
                make_pair(hana::string_c<'m', '6', '4'>, &T::m64),
                make_pair(hana::string_c<'m', '6', '5'>, &T::m65),
                make_pair(hana::string_c<'m', '6', '6'>, &T::m66),
                make_pair(hana::string_c<'m', '6', '7'>, &T::m67),
                make_pair(hana::string_c<'m', '6', '8'>, &T::m68),
                make_pair(hana::string_c<'m', '6', '9'>, &T::m69),
                make_pair(hana::string_c<'m', '7', '0'>, &T::m70),
                make_pair(hana::string_c<'m', '7', '1'>, &T::m71),
                make_pair(hana::string_c<'m', '7', '2'>, &T::m72),
                make_pair(hana::string_c<'m', '7', '3'>, &T::m73),
                make_pair(hana::string_c<'m', '7', '4'>, &T::m74),
                make_pair(hana::string_c<'m', '7', '5'>, &T::m75),
                make_pair(hana::string_c<'m', '7', '6'>, &T::m76),
                make_pair(hana::string_c<'m', '7', '7'>, &T::m77),
                make_pair(hana::string_c<'m', '7', '8'>, &T::m78),
                make_pair(hana::string_c<'m', '7', '9'>, &T::m79),
                make_pair(hana::string_c<'m', '8', '0'>, &T::m80),
                make_pair(hana::string_c<'m', '8', '1'>, &T::m81),
                make_pair(hana::string_c<'m', '8', '2'>, &T::m82),
                make_pair(hana::string_c<'m', '8', '3'>, &T::m83),
                make_pair(hana::string_c<'m', '8', '4'>, &T::m84),
                make_pair(hana::string_c<'m', '8', '5'>, &T::m85),
                make_pair(hana::string_c<'m', '8', '6'>, &T::m86),
                make_pair(hana::string_c<'m', '8', '7'>, &T::m87),
                make_pair(hana::string_c<'m', '8', '8'>, &T::m88),
                make_pair(hana::string_c<'m', '8', '9'>, &T::m89),
                make_pair(hana::string_c<'m', '9', '0'>, &T::m90),
                make_pair(hana::string_c<'m', '9', '1'>, &T::m91),
                make_pair(hana::string_c<'m', '9', '2'>, &T::m92),
                make_pair(hana::string_c<'m', '9', '3'>, &T::m93),
                make_pair(hana::string_c<'m', '9', '4'>, &T::m94),
                make_pair(hana::string_c<'m', '9', '5'>, &T::m95),
                make_pair(hana::string_c<'m', '9', '6'>, &T::m96),
                make_pair(hana::string_c<'m', '9', '7'>, &T::m97),
                make_pair(hana::string_c<'m', '9', '8'>, &T::m98),
                make_pair(hana::string_c<'m', '9', '9'>, &T::m99)
            );
        }
    };
}
}



static_assert(hana::Struct<ns::Data0>::value, "");
static_assert(hana::Struct<ns::Data1>::value, "");
static_assert(hana::Struct<ns::Data2>::value, "");
static_assert(hana::Struct<ns::Data3>::value, "");
static_assert(hana::Struct<ns::MemberArray>::value, "");

int main() {
    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::Data1{}, BOOST_HANA_STRING("member1")));

    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::Data2{}, BOOST_HANA_STRING("member1")));
    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::Data2{}, BOOST_HANA_STRING("member2")));

    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::Data3{}, BOOST_HANA_STRING("member1")));
    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::Data3{}, BOOST_HANA_STRING("member2")));
    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::Data3{}, BOOST_HANA_STRING("member3")));

    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::MemberArray{}, BOOST_HANA_STRING("array")));

    BOOST_HANA_CONSTANT_CHECK(hana::contains(ns::Data100{}, BOOST_HANA_STRING("m99")));

    BOOST_HANA_CONSTANT_CHECK(
        hana::equal(hana::at_key(ns::Data1{}, BOOST_HANA_STRING("member1")), ct_eq<1>()));

    BOOST_HANA_CONSTANT_CHECK(
        hana::equal(hana::at_key(ns::Data100{}, BOOST_HANA_STRING("m99")), ct_eq<99>()));
}
