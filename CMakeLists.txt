cmake_minimum_required(VERSION 3.16)
project(Scrubb)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(Scrubb
    src/main.cpp
    src/TextureAtlas.cpp
    # src/TileMap.cpp
)

target_link_libraries(Scrubb PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
