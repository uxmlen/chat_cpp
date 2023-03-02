#pragma once

#include <vector>
#include <string>

#include "message.h"

namespace Chat {

    class ChatRoom
    {
        std::string current_user;
        std::vector<Message> msgs_;
    public:
        ChatRoom(std::string& current_user);
        void displayAllMessages() const;
        void sendMessages();
        void showMessages();

    };

}
