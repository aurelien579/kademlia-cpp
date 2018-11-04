#include <boost/test/unit_test.hpp>

#include <iostream>

#include "../src/message.hpp"

BOOST_AUTO_TEST_SUITE(test_message)

BOOST_AUTO_TEST_CASE(test_message_message)
{
    std::stringstream stream;

    Message message(Message::RESPONSE, "test_method");
    {
        boost::archive::text_oarchive oar(stream);
        oar << message;
    }

    Message newMessage;
    {
        boost::archive::text_iarchive iar(stream);
        iar >> newMessage;
    }

    BOOST_TEST(message.type() == newMessage.type());
    BOOST_TEST(message.method() == newMessage.method());
}

BOOST_AUTO_TEST_CASE(test_message_request)
{
    std::stringstream stream;

    Request message("test_method");
    {
        boost::archive::text_oarchive oar(stream);
        oar << message;
    }

    Request newMessage;
    {
        boost::archive::text_iarchive iar(stream);
        iar >> newMessage;
    }

    BOOST_TEST(message.type() == newMessage.type());
    BOOST_TEST(message.method() == newMessage.method());
}

BOOST_AUTO_TEST_CASE(test_message_response)
{
    std::stringstream stream;

    Response message("test_method");
    {
        boost::archive::text_oarchive oar(stream);
        oar << message;
    }

    Response newMessage;
    {
        boost::archive::text_iarchive iar(stream);
        iar >> newMessage;
    }

    BOOST_TEST(message.type() == newMessage.type());
    BOOST_TEST(message.method() == newMessage.method());
}

BOOST_AUTO_TEST_CASE(test_message_find_nodes_response)
{
    std::stringstream stream;

    FindNodeResponse message;
    {
        boost::archive::text_oarchive oar(stream);
        oar << message;
    }

    FindNodeResponse newMessage;
    {
        boost::archive::text_iarchive iar(stream);
        iar >> newMessage;
    }

    BOOST_TEST(message.type() == newMessage.type());
    BOOST_TEST(message.method() == newMessage.method());
}

BOOST_AUTO_TEST_SUITE_END()
