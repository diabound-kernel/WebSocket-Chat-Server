#include "listener.hpp"

#include <boost/asio.hpp>

int main(int argc, const char *argv[])
{
    const auto address = boost::asio::ip::make_address(argv[1]);

    const auto port = static_cast<unsigned int>(std::atoi(argv[2]));

    boost::asio::io_context ioContext;

    std::make_shared<Listener>(
        ioContext,
        boost::asio::ip::tcp::endpoint(address, port),
        std::make_shared<SharedState>())
        ->run();

    ioContext.run();
}