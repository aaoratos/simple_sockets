cmake_minimum_required(VERSION 3.28)
project(lab)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Wextra -Wconversion -Wpedantic -Werror)

include_directories(src/lib)

add_executable(simple_server src/Server.cpp src/main_server.cpp
        src/Socket.cpp
        src/Logger.cpp
        src/ThreadPool.cpp
        src/Utility.cpp
)
target_link_libraries(simple_server -lpthread)

add_executable(simple_client src/Client.cpp src/main_client.cpp
        src/Socket.cpp
        src/Utility.cpp
)
