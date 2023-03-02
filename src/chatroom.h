#pragma once

#include <vector>
#include <string>

#include "message.h"

namespace Chat {

    class ChatRoom
    {
        std::vector<Message> msg_;
    public:
        void displayAllMessages() const;
        void sendMessage(const std::string message);

    };

}
