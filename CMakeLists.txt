cmake_minimum_required(VERSION 3.10)
project(graphes)

set(CMAKE_CXX_STANDARD 11)

add_executable(graphes main.cpp Graphes/Graphe_Liste.cpp Graphes/Graphe_Liste.h Kosaraju.cpp Kosaraju.h Graphes/Graphe.cpp Graphes/Graphe.h Tarjan.cpp Tarjan.h Gabow.cpp Gabow.h GraphGenerator.cpp GraphGenerator.h)