//
// Created by slyao on 5/18/2018.
//

#include <cstring>
#include "matrix.h"

template<typename T, size_t size>
MATRIX<T, size>::MATRIX(T _mod) : _mod(_mod) {}

template<typename T, size_t size>
const T &MATRIX<T, size>::operator()(size_t idx, size_t idy) const { return _array[idx][idy]; }

template<typename T, size_t size>
T &MATRIX<T, size>::operator()(size_t idx, size_t idy) { return _array[idx][idy]; }

template<typename T, size_t size>
MATRIX<T, size> MATRIX<T, size>::operator*(const MATRIX &o) const {
        MATRIX<T, size> ret(_mod);
        memset(ret._array, 0, sizeof(ret._array));
        for (auto i = 0; i < size; i++)
                for (auto j = 0; j < size; j++)
                        for (auto k = 0; k < size; k++)
                                ret(i, j) = (ret(i, j) + _array[i][k] * o(k, j)) % _mod;
        return ret;
}

template<typename T, size_t size>
T MATRIX<T, size>::determinant() {
        T ans = 1;
        for (auto i = 0; i < size; i++) {
                for (auto j = i + 1; j < size; j++)
                        while (_array[j][i]) {
                                T t = _array[i][i] / _array[j][i];
                                for (auto k = i; k < size; k++) _array[i][k] = (_array[i][k] - _array[j][k] * t) % _mod;
                                for (auto k = i; k < size; k++) std::swap(_array[i][k], _array[j][k]);
                                ans = -ans;
                        }
                if (_array[i][i] == 0) return 0;
                ans = ans * _array[i][i] % _mod;
        }
        return (ans % _mod + _mod) % _mod;
}
