#ifndef ARGS_HPP
#define ARGS_HPP

#include <boost/asio.hpp>

class Args
{
public:
    Args(int argc, char **argv);

    bool has_contact() const;
    boost::asio::ip::udp::endpoint get_contact() const;

private:
    void parse(int argc, char **argv);
    void parse_contact(const char *arg);

private:
    bool m_has_contact;
    boost::asio::ip::udp::endpoint m_contact;
};

#endif
