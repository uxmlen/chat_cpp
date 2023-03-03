#pragma once

#include <vector>
#include <string>

#include "message.h"

namespace Chat 
{
    class ChatRoom
    {
        enum { 
            LOGOUT, 
            DISPLAY_MSG_ALL,
            SEND_MESSAGE
        };

        std::string current_user_;
        std::vector<Message> msgs_;
    public:
        ChatRoom(std::string& current_user)
            : current_user_(current_user) {}
        //TODO: make this
        void displayAllMessages() const;
        void sendMessage();
        //void showMessages();
        void showMenu();
    private:
        void selectAction(unsigned int action);
    };

}
