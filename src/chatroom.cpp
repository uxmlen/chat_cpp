#include <iostream>

#include "chatroom.h"
#include "exceptions.h"

namespace chat {

enum ActionsMenu {
    ChangeAccount,
    DisplayMsgAll,
    SendMessage,
    ViewAccount
};

void ChatRoom::showMenu()
{
    showAuthMenu();
    int action = -1;
    while (true) {
        std::cout << "Choose the action" << std::endl
                  << "0 - change the account" << std::endl
                  << "1 - display all messages" << std::endl
                  << "2 - send message to user or all users" << std::endl
                  << "3 - view profile" << std::endl;
        std::cin >> action;
        selectAction(action);
    }
}

void ChatRoom::showAuthMenu()
{
    int action = -1;
    while (!isAuthorized_) {
        std::cout << "Choose the action" << std::endl
                  << "0 - sign up" << std::endl
                  << "1 - sign in" << std::endl
                  << "2 - exit" << std::endl;
        std::cin >> action;
        try {
            switch (action) {
            case 0:
                signUp();
                break;
            case 1:
                signIn();
                break;
            case 2:
                exit(0);
            }
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void ChatRoom::selectAction(unsigned int action)
try {
    switch (action) {
    case ChangeAccount:
        isAuthorized_ = false;
        showAuthMenu();
        break;
    case DisplayMsgAll:
        displayAllMessages();
        break;
    case SendMessage:
        sendMessage();
        break;
    case ViewAccount:
        viewAccount();
        break;
    }
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}

void ChatRoom::displayAllMessages() const
{
    if (msgs_.empty()) {
        std::cerr << "  there are no messages yet." << std::endl;
        return;
    }

    std::cout << "messages =>" << std::endl;
    for (const auto& m : msgs_) {
        std::cout << "from: " << m.getSender()
                  << " to: " << m.getReceiver() << std::endl
                  << m.getContent() << std::endl;
    }
}

void ChatRoom::sendMessage()
{
    std::string receiver, text;
    std::cout << "use \"all\" to send a message to all users" << std::endl;
    std::cout << "who will be the receiver?" << std::endl;
    std::cin >> receiver;
    // receiver check is needed here
    std::cout << "enter text: ";
    std::cin >> text;
    Message m(text, chat::ChatRoom::current_user_->getUsername(), receiver);
    msgs_.push_back(m);
    if (receiver.compare("all") == 0) {
        for (const auto& r : users_) {
            // don't send to yourself
            if (m.getSender().compare(r.getUsername()) == 0)
                continue;
            std::cout << "from: " << m.getSender()
                      << " to: " << r.getUsername() << std::endl
                      << text << std::endl;
        }
    } else {
        std::cout << "from: " << m.getSender()
                  << " to: " << m.getReceiver() << std::endl
                  << text << std::endl;
    }
}

void ChatRoom::signUp()
{
    std::string name, username, password;
    std::cout << "Enter the name: ";
    std::cin >> name;
    std::cout << "Enter the username: ";
    std::cin >> username;
    if (isUserExisted(username))
        throw busy_login_error();
    std::cout << "Enter the password: ";
    std::cin >> password;
    User client(username, password, username);
    users_.push_back(client);
    // u001b[32m  green
    // u001b[0    reset color
    std::cout << "\u001b[32mAccount was created\u001b[0m" << std::endl;
}

void ChatRoom::signIn()
{
    std::string username, password;
    std::cout << "Enter the username: ";
    std::cin >> username;
    if (!isUserExisted(username))
        throw user_not_existed_error();
    std::cout << "Enter the password: ";
    std::cin >> password;
    current_user_ = lookUpUserByUsername(username);
    if (!current_user_ || (password != current_user_->getPassword())) {
        // TODO: exception
        std::cerr << "the password or username is not correct" << std::endl;
        current_user_ = nullptr;
        return;
    }
    isAuthorized_ = true;
}

void ChatRoom::viewAccount() const
{
    std::string username;
    std::shared_ptr<User> profile;
    std::cout << "which profile do you want to view?" << std::endl;
    std::cin >> username;
    profile = lookUpUserByUsername(username);
    if (!profile)
        throw user_not_existed_error();

    std::cout << "info about: " << profile->getUsername() << std::endl
              << "name: " << profile->getName() << std::endl
              << "description: " << (profile->getDescription().empty() ? "not set" : profile->getDescription()) << std::endl;
}

bool ChatRoom::isUserExisted(const std::string& username) const
{
    return lookUpUserByUsername(username) ? true : false;
}

std::shared_ptr<chat::User> ChatRoom::lookUpUserByUsername(const std::string& username) const
{
    for (const auto& user : users_) {
        if (user.getUsername() == username) {
            return std::make_shared<User>(user);
        }
    }
    return nullptr;
}

} // namespace chat
