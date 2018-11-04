#include "args.hpp"

#include <vector>

#include <iostream>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;
using namespace boost::asio;

Args::Args(int argc, char **argv) :
    m_has_contact(false)
{
    parse(argc, argv);
}

void Args::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-c")) {
            i++;

            if (i >= argc) {
                throw invalid_argument("Invalid argument");
            } else {
                parse_contact(argv[i]);
            }
        }
    }
}

void Args::parse_contact(const char *arg)
{
    vector<string> splitted;
    string s(arg);
    boost::split(splitted, s, boost::is_any_of(":"), boost::token_compress_on);

    m_has_contact = true;

    int port = -1;

    if (splitted.size() > 1) {
        try {
            port = stoi(splitted[1]);
        } catch(invalid_argument &) {
            port = -1;
        }
    }

    if (port < 0) {
        throw invalid_argument("Invalid contact ip: " + s + " (port missing)");
    }

    m_contact = ip::udp::endpoint(ip::make_address(splitted[0]), stoi(splitted[1]));
}

bool Args::has_contact() const
{
    return m_has_contact;
}

ip::udp::endpoint Args::get_contact() const
{
    if (!has_contact()) {
        throw out_of_range("No contact in argument");
    }

    return m_contact;
}
