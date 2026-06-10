cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
PROJECT(zephyr_reach)

target_sources(app PRIVATE 
src/main.cpp
src/Reach/reachDevice.cpp
src/Reach/lib/transport/transport.cpp
src/Reach/lib/transport/uartConnection.cpp
src/Reach/lib/digitalOut/digitalOut.cpp
src/Reach/lib/digitalOut/reachDigitalOut.cpp

)
