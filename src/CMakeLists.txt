add_executable(console_chat
  main.cpp
  proxy.cpp
  chatroom.cpp
  user.cpp
  message.cpp
)
set_target_properties(
    console_chat PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
