#include "proxy.h"

#include <iostream>

void Chat::ChatRoomProxy::signUp()
{
    std::string name, username, password;
    std::cout << "Enter the name: ";
    std::cin >> name;
    std::cout << "Enter the username: ";
    std::cin >> username;
    std::cout << "Enter the password: ";
    std::cin >> password;
    User client(name, username, password);
    users_push_back(client);
}

void Chat::ChatRoomProxy::signIn()
{
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

