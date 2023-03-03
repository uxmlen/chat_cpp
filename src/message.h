#pragma once

#include <string>

namespace Chat {

    class Message final
    {
        const std::string content_;
        const std::string sender_;
        const std::string receiver_;
    public:
        Message(const std::string& content, const std::string& sender, const std::string& receiver)
            : content_(content), sender_(sender), receiver_(receiver) {}

        std::string getSender() const noexcept;
        std::string getContent() const noexcept;
        std::string getReceiver() const noexcept;
    };

}
