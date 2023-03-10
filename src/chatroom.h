#pragma once

#include <memory>
#include <string>
#include <vector>

#include "message.h"
#include "user.h"

namespace chat {

class ChatRoom {
    std::shared_ptr<User> current_user_;
    bool isAuthorized_ = false;
    std::vector<Message> msgs_;
    std::vector<User> users_;

public:
    void showMenu();

private:
    void showAuthMenu();
    void showProfileMenu();

    void displayAllMessages() const;
    void sendMessage();
    void selectAction(unsigned int action);
    // login in an account previously created by signUp()
    void signIn();
    // creating a new account in std::vector<User> users_
    void signUp();

    void viewAccount() const;

    bool isUserExisted(const std::string& username) const;
    std::shared_ptr<User> lookUpUserByUsername(const std::string& username) const;
};

} // namespace chat
