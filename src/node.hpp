#ifndef NODE_HPP
#define NODE_HPP

#include <boost/asio.hpp>
#include <string>

#include "socket.hpp"

class Node
{
public:
    Node(std::string ip, int port);

    void listen();

private:
    boost::asio::io_context m_context;
    Socket m_socket;
};

#endif
