#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

class HttpServer {
public:
    HttpServer(io_service& ioService, short port)
        : acceptor_(ioService, tcp::endpoint(tcp::v4(), port)),
          socket_(ioService) {
        startAccept();
    }

private:
    void startAccept() {
        acceptor_.async_accept(socket_,
            [this](const boost::system::error_code& ec) {
                if (!ec) {
                    handleRequest();
                }
                startAccept();
            });
    }

    void handleRequest() {
        async_read_until(socket_, request_, "\r\n\r\n",
            [this](const boost::system::error_code& ec, size_t bytes_transferred) {
                if (!ec) {
                    istream request_stream(&request_);
                    string request_line;
                    getline(request_stream, request_line);

                    // Respond with "Hello, World!" message
                    string response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
                    async_write(socket_, buffer(response),
                        [this](const boost::system::error_code& ec, size_t bytes_transferred) {
                            socket_.close();
                        });
                }
            });
    }

    tcp::acceptor acceptor_;
    tcp::socket socket_;
    streambuf request_;
};

int main() {
    try {
        io_service ioService;
        HttpServer server(ioService, 8080);
        ioService.run();
    } catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
