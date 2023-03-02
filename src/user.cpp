#include "user.h"

std::string Chat::User::getUsername() const noexcept
{
    return name_;
}

std::string Chat::User::getPassword() const noexcept
{
    return password_;
}

std::string Chat::User::getName() const noexcept
{
    return name_;
}

void Chat::User::setPassword(const std::string& password)
{
    password_ = password;
}

void Chat::User::setName(const std::string& name)
{
    name_ = name;
}

