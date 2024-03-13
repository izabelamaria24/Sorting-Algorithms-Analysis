#ifndef SORTS_HPP
#define SORTS_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>

template<typename T>
class coolVector {
private:
    std::vector<T> data;

public:
    coolVector() = default;

    void add(T element) {
        data.push_back(element);
    }

    double shellSort() {
        // copying array data in an auxiliary one
        std::vector<T>sorted;
        std::copy(data.begin(), data.end(), sorted.begin());

        clock_t start = clock();
        
        int gap = sorted.size() / 2;
        while (gap > 0) {
            for (int i = gap; i < sorted.size(); i++) {
                int j = i;
                while (j >= gap && sorted[j] < sorted[j - gap]) {
                    std::swap(sorted[j], sorted[j -gap]);
                    j -= gap;
                }
            }
            gap /= 2;
        }

        clock_t end = clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }

    double countingSort() {
        std::vector<T>sorted;
        clock_t start = clock();

        std::map<T, int>count;
        for (const auto& elem : data) count[elem]++;

        for (const auto& elem : count) {
            T value = elem.first;
            int cnt = elem.second;
            for (int i = 0; i < cnt; ++i)
                sorted.emplace_back(value);
        }

        clock_t end = clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }
    
//    void printSorted() const {
//        for (const auto& elem : sorted) {
//            std::cout << elem << " ";
//        }
//        std::cout << '\n';
//    }
};
#endif