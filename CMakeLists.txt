cmake_minimum_required(VERSION 3.16)
project(scrubb)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(scrubb
    src/main.cpp
    src/TextureAtlas.cpp
)

target_link_libraries(scrubb PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
