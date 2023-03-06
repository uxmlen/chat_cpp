add_executable(chat
  main.cpp
  chatroom.cpp
  user.cpp
  message.cpp
)
set_target_properties(
    chat PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
