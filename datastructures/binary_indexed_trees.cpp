//
// Created by slyao on 5/18/2018.
//

#include "binary_indexed_trees.h"

template<typename T, size_t size>
void BIT<T, size>::modify(int index, T delta) {
        for (auto i = index; i < size; i += i & (-i)) _array[i] += delta;
}

template<typename T, size_t size>
T BIT<T, size>::ask(int index) {
        T sum = 0;
        for (auto i = index; i; i -= i & (-i)) sum += _array[i];
        return sum;
}

template<typename T, size_t rows, size_t cols>
void BIT2<T, rows, cols>::modify(int x, int y, T delta) {
        for (auto i = x; i < rows; i += i & (-i))
                for (auto j = y; j < cols; j += j & (-j))
                        _array[i][j] += delta;
}

template<typename T, size_t rows, size_t cols>
T BIT2<T, rows, cols>::ask(int x, int y) {
        T sum = 0;
        for (auto i = x; i; i -= i & (-i))
                for (auto j = y; j; j -= j & (-j))
                        sum += _array[i][j];
        return sum;
}

template<typename T, size_t rows, size_t cols>
T BIT2<T, rows, cols>::ask(int x1, int y1, int x2, int y2) {
        return ask(x2, y2) - ask(x1 - 1, y2) - ask(x2, y1 - 1) + ask(x1 - 1, y1 - 1);
}

template<typename T, size_t size>
void BIT_RangeQuery<T, size>::modify(int l, int r, T delta) {
        _boundary.modify(l, delta);
        _boundary.modify(r + 1, -delta);
        _interval.modify(l, delta * l);
        _interval.modify(r + 1, -delta * (r + 1));
}

template<typename T, size_t size>
T BIT_RangeQuery<T, size>::ask(int index) {
        return _boundary.ask(index) * (index + 1) - _interval.ask(index);
}