#include "message.h"

std::string Chat::Message::getContent() const noexcept
{
    return content_;
}

std::string Chat::Message::getSender() const noexcept
{
    return sender_;
}

std::string Chat::Message::getReceiver() const noexcept
{
    return receiver_;
}
