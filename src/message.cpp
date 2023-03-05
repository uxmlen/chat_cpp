#include "message.h"

std::string chat::Message::getContent() const noexcept
{
    return content_;
}

std::string chat::Message::getSender() const noexcept
{
    return sender_;
}

std::string chat::Message::getReceiver() const noexcept
{
    return receiver_;
}
