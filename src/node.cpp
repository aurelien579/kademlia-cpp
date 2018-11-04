#include "node.hpp"

#include <iostream>

using namespace std;
using namespace boost::asio;

Node::Node(string address, int port) :
    m_socket(m_context, address, port)
{
    cout << "Creating node at " << m_socket.local_endpoint() << endl;

    listen();
}

void Node::listen()
{
    while (1) {
        ip::udp::endpoint endpoint;

        Message msg;
        m_socket.receive_from(&msg, endpoint);
    }
}
