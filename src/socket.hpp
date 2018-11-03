#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <boost/asio.hpp>

#include <string>

#include "message.hpp"

class Socket : public boost::asio::ip::udp::socket
{

public:
    Socket(boost::asio::io_context &ctx, std::string address, int port);

    std::size_t send_to(Message msg, const endpoint_type &endpoint);
    std::size_t receive_from(Message *msg, endpoint_type &endpoint);
};

#endif
