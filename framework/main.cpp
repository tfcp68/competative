#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct SparseTable {
    typedef std::function<T(T, T)> Func;

    size_t k;
    std::vector<std::vector<T>> table;
    Func func;

    template<typename It, typename F>
    SparseTable(It first, It last, F f) {
        auto n = std::distance(first, last);
        k = log2(n) + 1;
        func = f;


        table.resize(k);
        for (auto &r: table)
            r.resize(n);

        for (auto &item: table[0])
            item = *first++;

        build();
    }

    size_t log2(size_t n) {
        size_t result = 0;
        while (n > 1) {
            n >>= 1;
            ++result;
        }
        return result;
    }

    void build() {
        for (size_t j = 1; j < k; ++j) {
            size_t s = 1 << (j - 1);
            for (size_t i = 0; i + s < table[0].size(); ++i)
                table[j][i] = func(table[j - 1][i], table[j - 1][i + s]);
        }
    }

    T query(size_t l, size_t r) {
        size_t m = log2(r - l);
        return func(table[m][l], table[m][r - (1 << m)]);
    }

};

int main() {

    return 0;
}
