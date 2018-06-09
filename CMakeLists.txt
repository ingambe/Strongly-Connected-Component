cmake_minimum_required(VERSION 3.10)
project(graphes)

set(CMAKE_CXX_STANDARD 11)

add_executable(graphes main.cpp Graphes/Graphe_Liste.cpp Graphes/Graphe_Liste.h CFC/Kosaraju.cpp CFC/Kosaraju.h Graphes/Graphe.cpp Graphes/Graphe.h CFC/Tarjan.cpp CFC/Tarjan.h CFC/Gabow.cpp CFC/Gabow.h GraphGenerator.cpp GraphGenerator.h Graphes/Graphe_Adjacence.cpp Graphes/Graphe_Adjacence.h CFC/CFC_Implementation.cpp CFC/CFC_Implementation.h)