cmake_minimum_required(VERSION 3.0.0)
project(PixouSimulator VERSION 0.1.0)

include(CTest)
enable_testing()


find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(PixouSimulator 
                header/Pixou.hpp header/Position.hpp header/Reward.hpp header/Game.hpp
                main.cpp src/Pixou.cpp src/Position.cpp src/Reward.cpp  src/Game.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
target_link_libraries(PixouSimulator sfml-system sfml-window sfml-graphics sfml-audio)