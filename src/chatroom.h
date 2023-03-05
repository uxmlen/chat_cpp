#pragma once

#include <vector>
#include <string>

#include "message.h"

namespace chat {

    class ChatRoom
    {
        enum {
            CHANGE_ACCOUNT,
            DISPLAY_MSG_ALL,
            SEND_MESSAGE
        };

        std::string current_user_;
        std::vector<Message> msgs_;
    public:
        ChatRoom(std::string& current_user)
            : current_user_(current_user) {}
        void displayAllMessages() const;
        void sendMessage();
        void showMenu();
    private:
        void selectAction(unsigned int action);
    };

} // namespace chat
