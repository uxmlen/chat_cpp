#include <stdexcept>

struct busy_login_error : public std::runtime_error
{
    busy_login_error() : std::runtime_error("error: this username is already taken") {}
};

struct user_not_existed_error : public std::runtime_error
{
    user_not_existed_error() : std::runtime_error("error: this user does not exist") {}
};

