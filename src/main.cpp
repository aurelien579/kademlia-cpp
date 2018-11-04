#include <iostream>

#include "args.hpp"
#include "node.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Args args(argc, argv);

    if (args.has_contact()) {
        cout << args.get_contact() << endl;
    }

    Node node("127.0.0.1", 5000);

    return 0;
}
