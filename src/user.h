#pragma once

#include <string>

namespace Chat {

    class User 
    {
        std::string password_;
        std::string name_;
        const std::string username_;
    public:
        User(const std::string& username, const std::string& password, const std::string& name)
            : username_(username), password_(password), name_(name) {}
        // getters
        std::string getUserName() const noexcept;
        std::string getPassword() const noexcept;
        std::string getName() const noexcept;
        // setters
        std::string setUserName(const std::string& name);
        std::string setPassword(const std::string& pass);
        std::string setName(const std::string& name);
    };

}
