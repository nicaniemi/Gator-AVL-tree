##AVL Tree

A C++ implementation of a self-balancing AVL binary search tree. The project supports insertion, deletion, and search operations while maintaining AVL balance through tree rotations.

##Features

- Binary search tree insertion

- Binary search tree deletion

- Key search

- Automatic height and balance-factor maintenance

- LL, RR, LR, and RL rotations

- Catch2 unit testing

##Complexity

AVL trees maintain a height of O(log n), resulting in O(log n) time complexity for search, insertion, and deletion operations.

##Testing

The project uses Catch2 for unit testing. Tests cover core tree operations, balancing, rotations, and edge cases involving insertion and deletion.

##Building

This project uses CMake. From the project directory:

mkdir build
cd build
cmake ..
cmake --build .

The project can also be opened and built directly using CLion.

##Acknowledgments

The initial project structure and Catch2 testing setup were based on the Catch2 template provided for the course by Professor [Professor Name].

The AVL tree implementation and project-specific tests were developed by me.

Catch2 is an open-source C++ testing framework. The Catch2 source files included in this repository are distributed under the license provided by the Catch2 project.
