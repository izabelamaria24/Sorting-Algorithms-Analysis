#ifndef SORTS_HPP
#define SORTS_HPP
#include <iostream>
#include <vector>
#include <algorithm>
template<typename T>
class coolVector {
private:
    std::vector<T> data;

public:
    coolVector() = default;

    void add(T element) {
        data.push_back(element);
    }

    double functieSortare() {
        clock_t start = clock();
        
        // Sortam sortam
        std::sort(data.begin(), data.end());

        clock_t end = clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }
    
    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
};
#endif