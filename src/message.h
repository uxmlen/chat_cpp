#pragma once

#include <string>

namespace Chat {

    class Message
    {    
        const std::string sender_;
        const std::string receiver_;
        const std::string content_;
    public:
        Message(const std::string& content, const std::string& sender, const std::string& receiver)
            : content_(content), sender_(sender), receiver_(receiver) {}

        std::string getSender() const noexcept;
        std::string getContent() const noexcept;
    };

}
