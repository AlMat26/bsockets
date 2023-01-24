#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main () {

    cout << "Hi" << endl;

    io_service service;
    ip::tcp::endpoint ep;
    ep.port(9999);
    ep.address(ip::address::from_string("127.0.0.1"));

    ip::tcp::socket sock (service);
    sock.connect(ep);

    char buf[256];
    cin >> buf;
    sock.write_some(buffer(buf, 256));
}
