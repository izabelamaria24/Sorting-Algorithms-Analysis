#ifndef SORTS_HPP
#define SORTS_HPP
#include <iostream>
template<typename T>
class Sorts {
private:
    std::vector<T> data;

public:
    Sorts() = default;

    void add(T element) {
        data.push_back(element);
    }

    double functieSortare() {
        clock_t start = clock();
        
        // Sortam sortam

        clock_t end = clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }
};
#endif