#pragma once

#include <vector>

#include "user.h"
#include "chatroom.h"

namespace chat {

    class ChatRoomProxy
    {
        std::string active_user_;
        bool isAuthorized_ = false;
        std::vector<User> users_;
    public: 
        void showMenu();
    private:
        // login in an account previously created by signUp()
        void signIn();
        // creating a new account in std::vector users_
        void signUp();
        // shows a menu with the choice of sing up or sing in
        void showAuthMenu();
        bool isUserExisted(std::string& username);
        // comparing entered password with the user password
        bool isPassCorrect(std::string& password, User& user);
        User lookUpUserByUsername(std::string& username);

    };

} // namespace chat
