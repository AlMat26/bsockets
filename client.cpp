#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main () {

    cout << "Hi" << endl;

    io_service service;
    ip::tcp::endpoint ep;
    ep.port(9999);

    cout << "Введите ip адрес:\t";
    string addr;
    cin >> addr;
    ep.address(ip::address::from_string(addr));

    ip::tcp::socket sock (service);
    sock.connect(ep);

    for(;;) {
    	char buf[256];
    	cin >> ws;
    	cin.getline ( buf, 256 );
    	sock.write_some(buffer(buf, 256));

	memset(buf, 0, 256);

	sock.read_some(buffer(buf,256));
	cout << buf << endl;

	memset(buf, 0, 256);
    }
    sock.close();
}
