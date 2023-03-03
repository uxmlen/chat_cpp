#pragma once

#include <memory>

#include "user.h"
#include "chatroom.h"

namespace Chat {

    class ChatRoomProxy
    {
        std::vector<User> users_;
        // login in an account previously created by (singUp())
        void signIn();
        // creating a new account in std::vector users_
        void SignUp();
    public: 
        void showMenu();
    };

}
