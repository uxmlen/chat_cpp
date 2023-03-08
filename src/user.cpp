#include "user.h"

const std::string& chat::User::getUsername() const noexcept
{
    return username_;
}

const std::string& chat::User::getPassword() const noexcept
{
    return password_;
}

const std::string& chat::User::getName() const noexcept
{
    return name_;
}

void chat::User::setPassword(const std::string& password) noexcept
{
    password_ = password;
}

void chat::User::setName(const std::string& name) noexcept
{
    name_ = name;
}

