#pragma once

#include <boost/asio.hpp>

#include <iostream>
#include <string_view>

void fail(boost::system::error_code error, std::string_view where)
{
    if (error == boost::asio::error::operation_aborted) {
        return;
    }

    std::cout << where << ": " << error.message() << std::endl;
}