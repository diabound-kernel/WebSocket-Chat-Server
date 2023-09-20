#pragma once

#include "web_socket_session.hpp"

#include <algorithm>
#include <memory>
#include <unordered_set>

class SharedState
{
public:
    SharedState() {}

    void join(WebSocketSession<SharedState> &session)
    {
        sessions_.insert(&session);
    }

    void leave(WebSocketSession<SharedState> &session)
    {
        sessions_.erase(&session);
    }

    void send(std::string message)
    {
        auto message_ = std::make_shared<std::string>(std::move(message));

        std::ranges::for_each(
            sessions_, [&](auto session) { session->send(message_); });
    }

private:
    std::unordered_set<WebSocketSession<SharedState> *> sessions_;
};