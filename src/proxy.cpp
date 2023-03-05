#include "proxy.h"

#include <iostream>

void chat::ChatRoomProxy::signUp()
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
}

bool chat::ChatRoomProxy::isUserExisted(std::string& username)
{
    // TODO check by func. lookUpUserByUsername();
    for (const auto& user : users_) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}

bool chat::ChatRoomProxy::isPassCorrect(std::string& password, User& user)
{
    return user.getPassword() == password;
}

chat::User chat::ChatRoomProxy::lookUpUserByUsername(std::string& username)
{
    for (const auto& user : users_) {
        if (user.getUsername() == username) {
            return user;
        }
    }
    // TODO throw exception
}

void chat::ChatRoomProxy::signIn()
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
    active_user_ = user.getUsername();
    isAuthorized_ = true;
}


void chat::ChatRoomProxy::showAuthMenu()
{
    int action = -1;
    while(!isAuthorized_) {
        std::cout << "choose the action" << std::endl
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

void chat::ChatRoomProxy::showMenu()
{
    showAuthMenu();

    ChatRoom chat(active_user_);
    chat.showMenu();
}
