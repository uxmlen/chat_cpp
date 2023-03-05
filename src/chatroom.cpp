#include <iostream>

#include "chatroom.h"

void Chat::ChatRoom::showMenu()
{
    int action = -1;
    while(true) {
        std::cout << "choose the action" << std::endl
                  << "0 - change the account" << std::endl
                  << "1 - display all messages" << std::endl
                  << "2 - send message to user or all users" << std::endl;
        std::cin >> action;
        selectAction(action);
    }
}


void Chat::ChatRoom::selectAction(unsigned int action)
{
    switch(action) {
    case LOGOUT:
        // TODO logout in proxy chat
        break;
    case DISPLAY_MSG_ALL:
        displayAllMessages();
        break;
    case SEND_MESSAGE:
        sendMessage();
        break;
    }

}

void Chat::ChatRoom::displayAllMessages() const
{
    // TODO display all messages from std::vector<Message> msg
    std::cout << "messages =>";
    for (auto m : msgs_) {
        std::cout << "from: " << m.getSender() << " to: " << m.getReceiver() << std::endl;
        std::cout << m.getContent() << std::endl;
    }
}

void Chat::ChatRoom::sendMessage()
{
    std::string reciever;
    std::cout << "who will be the reciever?" << std::endl;
    std::cin >> reciever;
    // ... 
}

