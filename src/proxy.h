#pragma once

#include <vector>

#include "user.h"
#include "chatroom.h"

namespace Chat {

    class ChatRoomProxy
    {
    
        bool isAuthorized = false;
        std::vector<User> users_;
    public: 
        void showMenu();
    private:
        // login in an account previously created by signUp()
        void signIn();
        // creating a new account in std::vector users_
        void signUp();
        void showAuthMenu();

    };

} // namespace Chat
