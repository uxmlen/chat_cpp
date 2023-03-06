#include <iostream>

#include "chatroom.h"

void chat::ChatRoom::showMenu()
{
    showAuthMenu();
    int action = -1;
    while(true) {
        std::cout << "Choose the action" << std::endl
                  << "0 - change the account" << std::endl
                  << "1 - display all messages" << std::endl
                  << "2 - send message to user or all users" << std::endl
                  << "3 - view profile" << std::endl;
        std::cin >> action;
        selectAction(action);
    }
}

void chat::ChatRoom::showAuthMenu()
{
    int action = -1;
    while(!isAuthorized_) {
        std::cout << "Choose the action" << std::endl
                  << "0 - sign up" << std::endl
                  << "1 - sign in" << std::endl
                  << "2 - exit" << std::endl;
        std::cin >> action;
        switch(action) {
            case 0:
                signUp();
                break;
            case 1:
                signIn();
                break;
            case 2:
                exit(0);
        }
    }
}

void chat::ChatRoom::selectAction(unsigned int action)
{
    switch(action) {
    case CHANGE_ACCOUNT:
        showAuthMenu();
        break;
    case DISPLAY_MSG_ALL:
        displayAllMessages();
        break;
    case SEND_MESSAGE:
        sendMessage();
        break;
    case VIEW_ACCOUNT:
        view_account();
        break;
    }

}

void chat::ChatRoom::displayAllMessages() const
{
    // TODO display all messages from std::vector<Message> msg
    if (msgs_.empty()) {
        std::cerr << "  there are no messages yet." << std::endl;
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
    std::cout << "who will be the receiver?" << std::endl;
    std::cin >> reciever;
    // ... 
}

void chat::ChatRoom::signUp()
{
    std::string name, username, password;
    std::cout << "Enter the name: ";
    std::cin >> name;
    std::cout << "Enter the username: ";
    std::cin >> username;
    if (isUserExisted(username)) {
        // TODO exceptions
        std::cerr << "this username is already taken " << std::endl;
        return;
    }
    std::cout << "Enter the password: ";
    std::cin >> password;
    User client(name, username, password);
    users_.push_back(client);
    std::cout << "Account was created" << std::endl; 
}

void chat::ChatRoom::signIn()
{
    std::string username, password;
    std::cout << "Enter the username: ";
    std::cin >> username;
    if (!isUserExisted(username)) {
        std::cerr << "This user does not exist" << std::endl;
        return;
    }
    std::cout << "Enter the password: ";
    std::cin >> password;
    User user = lookUpUserByUsername(username);
    if (!isPassCorrect(password, user)) {
        std::cerr << "this password is not correct" << std::endl;
        return;
    }
    current_user_ = user.getUsername();
    isAuthorized_ = true;
}

void chat::ChatRoom::view_account() const
{
    
    std::cout << "which profile do you want to view?" << std::endl;
    // ...
    // TODO finish this
}

bool chat::ChatRoom::isUserExisted(std::string& username)
{
    // TODO check by func. lookUpUserByUsername();
    for (const auto& user : users_) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}

bool chat::ChatRoom::isPassCorrect(std::string& password, User& user)
{
    return user.getPassword() == password;
}

chat::User chat::ChatRoom::lookUpUserByUsername(std::string& username)
{
    for (const auto& user : users_) {
        if (user.getUsername() == username) {
            return user;
        }
    }
}
