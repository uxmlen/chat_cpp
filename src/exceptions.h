#include <stdexcept>

namespace chat {

// 001b[31m  red color
// 001b[0m   reset color
struct busy_login_error : public std::runtime_error {
    busy_login_error()
        : std::runtime_error("\u001b[31merror: this username is already taken\u001b[0m")
    {
    }
};

struct user_not_existed_error : public std::runtime_error {
    user_not_existed_error()
        : std::runtime_error("\u001b[31merror: this user does not exist\u001b[0m")
    {
    }
};

} // namespace chat
