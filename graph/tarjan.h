//
// Created by slyao on 5/18/2018.
//

#ifndef ALGORITHMS_TARJAN_H
#define ALGORITHMS_TARJAN_H


#include <iostream>
#include <vector>
#include <stack>

template<size_t size>
class Tarjan {
        int _dfn[size], _low[size], _block[size], _inStack[size];
        int _index = 0, _blockSize = 0;
        std::stack<int> _stack;
        std::vector<int> (&_graph)[size];
public:
        explicit Tarjan(const std::vector<int> (&_graph)[size]);

        void stronglyconnected(int u);

        void tarjan(int n);
};

#endif //ALGORITHMS_TARJAN_H
