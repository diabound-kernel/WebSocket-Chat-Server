#pragma once

#include <boost/asio.hpp>

#include <iostream>
#include <string_view>

void fail(std::string_view where, boost::system::error_code error)
{
    if (error == boost::asio::error::operation_aborted) {
        return;
    }

    std::cerr << where << " " << error.message() << std::endl;
}

template<typename... Args>
void info(Args &&...args)
{
    ((std::cout << args << ' '), ...) << std::endl;
}