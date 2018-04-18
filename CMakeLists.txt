cmake_minimum_required (VERSION 2.6)
project (can-dbcparser)
set (CMAKE_CXX_STANDARD 11)

add_executable(candbcparser
  dbciterator.cpp
  header/dbciterator.hpp
  header/message.hpp
  header/signal.hpp
  main.cpp
  message.cpp
  signal.cpp
)
