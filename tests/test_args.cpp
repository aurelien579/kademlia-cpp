#define BOOST_TEST_MODULE args
#include <boost/test/included/unit_test.hpp>

#include "../src/args.hpp"

BOOST_AUTO_TEST_CASE(test_args_contact)
{
    /* Test 1: no arguments */
    Args args(1, std::initializer_list<const char *>({"prog"}).begin());

    BOOST_TEST(args.has_contact() == false);

    /* Checks if exception is raised */
    try {
        args.get_contact();
        BOOST_ERROR("should have raised exception");
    } catch (std::out_of_range &) {
    }

    /* Test 2: invalid arguments */
    try {
        args = Args(2, std::initializer_list<const char *>({"prog", "-c"}).begin());
        BOOST_ERROR("should have raised exception");
    } catch (std::invalid_argument &) {
    }

    /* Test 3: contact without -c */
    args = Args(2, std::initializer_list<const char *>({"prog", "127.0.0.1:4000"}).begin());
    BOOST_TEST(args.has_contact() == false);

    /* Test 4: valid contact */
    args = Args(3, std::initializer_list<const char *>({"prog", "-c", "127.0.0.1:4000"}).begin());
    BOOST_TEST(args.has_contact() == true);
    auto endpoint = args.get_contact();
    BOOST_TEST(endpoint.port() == 4000);
    BOOST_TEST(endpoint.address().to_string() == "127.0.0.1");

    /* Test 5: malformed ip */
    try {
        args = Args(3, std::initializer_list<const char *>({"prog", "-c", "127.00.1:4000"}).begin());
        BOOST_ERROR("should have raised exception");
    } catch (std::exception &) {
    }

    /* Test 6: malformed port */
    try {
        args = Args(3, std::initializer_list<const char *>({"prog", "-c", "127.0.0.1:azer"}).begin());
        BOOST_ERROR("should have raised exception");
    } catch (std::invalid_argument &) {
    }

    /* Test 7: no port */
    try {
        args = Args(3, std::initializer_list<const char *>({"prog", "-c", "127.0.0.1:"}).begin());
        BOOST_ERROR("should have raised exception");
    } catch (std::invalid_argument &) {
    }
}
