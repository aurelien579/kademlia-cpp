#include "message.hpp"

Message::Message(Type type, std::string method) :
    m_type(type),
    m_method(method)
{
}

Message::Message() : Message(REQUEST, "")
{
}

Message::Type Message::type() const
{
    return m_type;
}

const std::string &Message::method() const
{
    return m_method;
}

Request::Request(std::string method) :
    Message(REQUEST, method)
{
}

Request::Request() :
    Request("")
{
}

Response::Response(std::string method) :
    Message(RESPONSE, method)
{
}

Response::Response() :
    Response("")
{
}

FindNodeResponse::FindNodeResponse() :
    Response("find_nodes")
{
}
