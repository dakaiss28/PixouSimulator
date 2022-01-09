cmake_minimum_required(VERSION 3.0.0)
project(PixouSimulator VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(PixouSimulator 
                header/Pixou.hpp header/Position.hpp header/Coin.hpp header/Star.hpp header/Reward.hpp
                main.cpp src/Pixou.cpp src/Position.cpp src/Coin.cpp src/Star.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
