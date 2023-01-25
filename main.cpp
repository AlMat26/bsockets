#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main(int argc, char **argv) {

    cout << "Hello, world!" << endl;

    io_service service;
    ip::tcp::endpoint ep (ip::tcp::v4(), 9999);
    ip::tcp::acceptor acc ( service, ep );
    ip::tcp::socket sock ( service );

    acc.accept (sock);

    for(;;){
    	char buf[256];
    	sock.read_some(buffer(buf, 256));
    	cout << buf << endl;

	memset ( buf, 0, 256 );
	cin >> ws;
	cin.getline(buf, 256);
	sock.write_some(buffer(buf,256));
	memset(buf,0,256);
    }
    sock.close();

    return 0;
}
