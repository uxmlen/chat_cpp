#include "user.h"

std::string chat::User::getUsername() const noexcept
{
    return username_;
}

std::string chat::User::getPassword() const noexcept
{
    return password_;
}

std::string chat::User::getName() const noexcept
{
    return name_;
}

void chat::User::setPassword(const std::string& password)
{
    password_ = password;
}

void chat::User::setName(const std::string& name)
{
    name_ = name;
}

