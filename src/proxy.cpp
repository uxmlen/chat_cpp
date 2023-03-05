#include "proxy.h"

#include <iostream>


void Chat::ChatRoomProxy::signUp()
{
    std::string name, username, password;
    std::cout << "Enter the name: ";
    std::cin >> name;
    std::cout << "Enter the username: ";
    std::cin >> username;
    if (isUserExisted(username)) {
        std::cerr << "this username is already taken " << std::endl;
        return;
    }
    std::cout << "Enter the password: ";
    std::cin >> password;
    User client(name, username, password);
    users_.push_back(client);
}

bool Chat::ChatRoomProxy::isUserExisted(std::string& username)
{
    for (auto user : users_) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}

bool Chat::ChatRoomProxy::isPassCorrect(std::string& password, User& user)
{
    return user.getPassword() == password;
}

User Chat::ChatRoomProxy::lookUpUserByUsername(std::string& username)
{
    for (auto user : users_) {
        if (user.getUsername() == username) {
            return user;
        }
    }
}


void Chat::ChatRoomProxy::signIn()
{
    std::string username, password;
    std::cout << "Enter the username: ";
    std::cin >> username;
    if (!isUserExisted(username)) {
        std::cerr << "This user does not exist";
        return;
    }
    std::cout << "Enter the password: ";
    std::cin >> password;
    User user = lookUpUserByUsername(username);
    if (!isPassCorrect(password, user)) {
        std::cerr << "this password is not correct";
        return;
    }
    isAuthorized = true;
}


void Chat::ChatRoomProxy::showAuthMenu()
{
    int action = -1;
    while(!isAuthorized) {
        std::cout << "choose the action" << std::endl
                  << "0 - sign up" << std::endl
                  << "1 - sign in" << std::endl;
        std::cin >> action;
        switch(action) {
            case 0:
                signUp();
                break;
            case 1:
                signIn();
                break;
        }
    }
}

void Chat::ChatRoomProxy::showMenu()
{
    // TODO: тут проверка (регистрация и авторизация)
    // и передача пользователя
    showAuthMenu();
    std::string user1 = "user";
    ChatRoom chat(user1);
    chat.showMenu();
}

