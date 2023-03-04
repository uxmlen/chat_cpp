#include "proxy.h"

#include <string>

void Chat::ChatRoomProxy::signIn()
{

}

void Chat::ChatRoomProxy::showMenu()
{
    // TODO: тут проверка (регистрация и авторизация)
    // и передача пользователя
    std::string user1 = "user";
    ChatRoom chat(user1);
    chat.showMenu();
}

