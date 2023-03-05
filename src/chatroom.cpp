#include <iostream>

#include "chatroom.h"

void chat::ChatRoom::showMenu()
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


void chat::ChatRoom::selectAction(unsigned int action)
{
    switch(action) {
    case CHANGE_ACCOUNT:
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

void chat::ChatRoom::displayAllMessages() const
{
    // TODO display all messages from std::vector<Message> msg
    if (msgs_.empty()) {
        std::cout << "  there are no messages yet." << std::endl;
        return;
    }
    std::cout << "messages =>";
    for (const auto& m : msgs_) {
        std::cout << "from: " << m.getSender()
                  << " to: " << m.getReceiver() << std::endl
                  << m.getContent() << std::endl;
    }
}

void chat::ChatRoom::sendMessage()
{
    std::string reciever;
    std::cout << "who will be the reciever?" << std::endl;
    std::cin >> reciever;
    // ... 
}

