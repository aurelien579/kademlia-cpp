#include <boost/test/unit_test.hpp>

#include "../src/bucket.hpp"

#include <iostream>

BOOST_AUTO_TEST_SUITE(test_bucket)

bool is_valid(Bucket &bucket, std::initializer_list<Key> keys)
{
    auto it2 = keys.begin();
    for (auto it = bucket.begin();
         it != bucket.end() && it2 != keys.end();
         it++, it2++)
    {
        if (it->key() != *it2) {
            return false;
        }
    }

    return true;
}

BOOST_AUTO_TEST_CASE(test_bucket_add)
{
    Bucket bucket;
    bucket.addContact(Contact("11"));
    bucket.addContact(Contact("12"));
    bucket.addContact(Contact("13"));
    bucket.addContact(Contact("14"));

    BOOST_TEST(is_valid(bucket, { Key("14"), Key("13"), Key("12"), Key("11") }));

    bucket.addContact(Contact("12"));

    BOOST_TEST(is_valid(bucket, { Key("12"), Key("14"), Key("13"), Key("11") }));
}

BOOST_AUTO_TEST_SUITE_END()
