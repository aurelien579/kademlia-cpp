#include <boost/test/unit_test.hpp>

#include "../src/key.hpp"

#include <iostream>

BOOST_AUTO_TEST_SUITE(test_key)

BOOST_AUTO_TEST_CASE(test_key_parsing)
{
    const int N = 4;

    Key keys[N] = {
        Key("FF"),
        Key("FF00000000000000000000000000000000000000"),
        Key("00000000000000000000000000000000000100f0"),
        Key("FF00000000000000000000000000000000001000")
    };

    Key::data_type expected[N] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xff },
        { 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0xf0 },
        { 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x10, 0 },
    };

    for (int i = 0; i < N; i++) {
        if (keys[i].bytes() != expected[i]) {
            BOOST_ERROR(std::to_string(i) + " failed");
        }
    }
}

BOOST_AUTO_TEST_CASE(test_key_compare)
{
    BOOST_TEST((Key("ff") > Key("fe")) == true);
    BOOST_TEST((Key("FF00") < Key("00FF")) == false);
    BOOST_TEST((Key("FFFF") > Key("FFFF")) == false);
    BOOST_TEST((Key("01") > Key("02")) == false);
    BOOST_TEST((Key("0010") < Key("01FF")) == true);
}

BOOST_AUTO_TEST_SUITE_END()
