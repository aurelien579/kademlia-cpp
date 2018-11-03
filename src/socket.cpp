#include "socket.hpp"

using namespace std;
using namespace boost::asio;

Socket::Socket(io_context &ctx, string address, int port) :
    ip::udp::socket(ctx, ip::udp::endpoint(ip::make_address(address), port))
{

}

size_t Socket::receive_from(Message *msg, endpoint_type &endpoint)
{
    //TODO: Deserialization
    return 0;
}

size_t Socket::send_to(Message msg, const endpoint_type &endpoint)
{
    //TODO: Derialization
    return 0;
}
