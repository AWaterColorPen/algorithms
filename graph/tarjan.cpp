//
// Created by slyao on 5/18/2018.
//

#include "tarjan.h"

template<size_t size>
Tarjan<size>::Tarjan(const std::vector<int> (&_graph)[size]) : _graph(_graph) {}

template<size_t size>
void Tarjan<size>::stronglyconnected(int u) {
        _low[u] = _dfn[u] = ++_index;
        _stack.push(u);
        _inStack[u] = 1;

        for (const auto &v : _graph[u])
                if (_dfn[v] == 0)
                        stronglyconnected(v), _low[u] = std::min(_low[u], _low[v]);
                else if (_inStack[v]) _low[u] = std::min(_low[u], _low[v]);

        if (_dfn[u] == _low[u] && ++_blockSize)
                for (auto v = 0; v != u;)
                        v = _stack.top(), _stack.pop(), _block[v] = _blockSize, _inStack[v] = 0;
}


template<size_t size>
void Tarjan<size>::tarjan(int n) {
        for (auto i = 0; i < n; i++) if (_dfn[i] == 0) stronglyconnected(i);
}