#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <boost/asio.hpp>
#include "key.hpp"

class Contact
{
public:
    Contact(const std::string &key);

    const Key &key() const;

    const boost::asio::ip::udp::endpoint &endpoint() const;
    void endpoint(const boost::asio::ip::udp::endpoint &endpoint);

    bool operator<(const Contact& rhs) const;
    bool operator>(const Contact& rhs) const;
    bool operator<=(const Contact& rhs) const;
    bool operator>=(const Contact& rhs) const;

    bool operator==(const Contact &rhs) const;
    bool operator!=(const Contact &rhs) const;

private:
    Key m_key;
    boost::asio::ip::udp::endpoint m_endpoint;
};

std::ostream& operator<<(std::ostream& os, const Contact &contact);

#endif
