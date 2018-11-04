#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Message
{
public:
    enum Type {
        REQUEST,
        RESPONSE
    };

    Message(Type type, std::string method);
    Message();

    Type type() const;
    const std::string &method() const;

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & m_type;
        ar & m_method;
    }

private:
    Type m_type;
    std::string m_method;
};



class Request : public Message
{
public:
    Request(std::string method);
    Request();
};



class Response : public Message
{
public:
    Response(std::string method);
    Response();
};



class FindNodeResponse : public Response
{
public:
    FindNodeResponse();
};

#endif
