#pragma once

#include <string>

namespace Chat {

    class User final
    {
        const std::string username_;
        std::string password_;
        std::string name_;
    public:
        User(const std::string& username, const std::string& password, const std::string& name)
            : username_(username), password_(password), name_(name) {}
        // getters
        std::string getUsername() const noexcept;
        std::string getPassword() const noexcept;
        std::string getName() const noexcept;
        // setters
        void setName(const std::string& name);
        void setPassword(const std::string& pass);
    };

} // namespace Chat
