#include "cli.hpp"
#include "listener.hpp"

#include <boost/asio.hpp>

struct ServerConfig
{
    std::string address;
    unsigned int port;

    GEN_METADATA(address, port);
};

int main(int argc, const char *argv[])
{
    const auto config = parseCLI<ServerConfig>(argc, argv);

    boost::asio::io_context ioContext{};

    std::make_shared<Listener>(
        ioContext,
        boost::asio::ip::tcp::endpoint(
            boost::asio::ip::make_address(config.address), config.port),
        std::make_shared<SharedState>())
        ->run();

    ioContext.run();
}