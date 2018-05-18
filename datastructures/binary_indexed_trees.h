//
// Created by slyao on 5/18/2018.
//

#ifndef ALGORITHMS_BINARY_INDEXED_TREES_H
#define ALGORITHMS_BINARY_INDEXED_TREES_H


#include <iostream>

template <typename T, size_t size>
class BIT {
        T _array[size];

public:
        void modify(int index, T delta);
        T ask(int index);
};

template <typename T, size_t rows, size_t cols>
class BIT2 {
        T _array[rows][cols];

public:
        void modify(int x, int y, T delta);
        T ask(int x, int y);
        T ask(int x1, int y1, int x2, int y2);
};

template <typename T, size_t size>
class BIT_RangeQuery {
        BIT<T, size>  _interval;
        BIT<T, size>  _boundary;

public:
        void modify(int l, int r, T delta);
        T ask(int index);
};

#endif //ALGORITHMS_BINARY_INDEXED_TREES_H
