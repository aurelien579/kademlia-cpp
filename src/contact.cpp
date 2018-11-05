#include "contact.hpp"

using namespace boost::asio;

Contact::Contact(const std::string &key) :
    m_key(key)
{
}

const Key &Contact::key() const
{
    return m_key;
}

const ip::udp::endpoint &Contact::endpoint() const
{
    return m_endpoint;
}

void Contact::endpoint(const ip::udp::endpoint &endpoint)
{
    m_endpoint = endpoint;
}

bool Contact::operator<(const Contact& rhs) const
{
    return m_key < rhs.key();
}

bool Contact::operator>(const Contact& rhs) const
{
    return m_key > rhs.key();
}

bool Contact::operator<=(const Contact& rhs) const
{
    return m_key <= rhs.key();
}

bool Contact::operator>=(const Contact& rhs) const
{
    return m_key >= rhs.key();
}

bool Contact::operator==(const Contact &rhs) const
{
    return m_key == rhs.key();
}

bool Contact::operator!=(const Contact &rhs) const
{
    return m_key != rhs.key();
}

std::ostream& operator<<(std::ostream& os, const Contact &contact)
{
    os << "{ " << contact.key() << ", " << contact.endpoint() << " }";
    return os;
}
