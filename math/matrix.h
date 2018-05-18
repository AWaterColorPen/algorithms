//
// Created by slyao on 5/18/2018.
//

#ifndef ALGORITHMS_MATRIX_H
#define ALGORITHMS_MATRIX_H


#include <iostream>

template <typename T, size_t size>
class MATRIX {
        T _array[size][size];
        T _mod;
public:
        explicit MATRIX(T _mod);

        const T& operator()(size_t idx, size_t idy) const;
        T& operator()(size_t idx, size_t idy);
        MATRIX operator * (const MATRIX &o) const;

        T determinant();
};

#endif //ALGORITHMS_MATRIX_H
