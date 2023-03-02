#pragma once

#include <vector>
#include <string>

#include "user.h"
#include "message.h"

namespace Chat {

    class ChatRoom
    {
        //const bool typeChat_;
        std::vector<User> users_;
        std::vector<Message> msg_;
    public:
        void displayAllMessages() const;
        void sendMessage(const std::string message);

    };

}
