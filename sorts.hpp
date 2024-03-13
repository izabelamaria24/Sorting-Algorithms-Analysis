#ifndef SORTS_HPP
#define SORTS_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
template <typename T>
class coolVector {
private:
    std::vector<T> data;

public:
    coolVector() = default;

    void add(T element) {
        data.push_back(element);
    }

    double functieSortare() {
        // copiem vectorul
        std::vector<T> aux = data;
        clock_t start = clock();

        // Sortam sortam
        std::sort(aux.begin(), aux.end());

        clock_t end = clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }

    double heapSort() {
        // copiem vectorul
        std::vector<T> aux;
        std::priority_queue<T, std::vector<T>, std::greater<T>> pq;

        clock_t start = clock();
        // Sortam sortam
        for (const auto &elem : data) {
            pq.push(elem);
        }

        while (!pq.empty()) {
            aux.push_back(pq.top());
            pq.pop();
        }
        clock_t end = clock();
        data = aux; // debugging
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }

    double bucketSort() {
        // copiem vectorul
        std::vector<T> aux = data;
        clock_t start = clock();

        T Min = std::numeric_limits<T>::max();
        T Max = std::numeric_limits<T>::min();
        for (const auto &val : data) {
            if (val < Min)
                Min = val;
            if (val > Max)
                Max = val;
        }

        //alegem bucket urile
        int nrBuckets = aux.size() / 4;
        double range = (Max - Min + 1) / static_cast<double>(nrBuckets);
        std::vector<std::vector<T>> buckets(nrBuckets);

        for (const auto &val : aux) {
            int bucket_index = static_cast<int>((val - Min) / range);
            buckets[bucket_index].push_back(val);
        }

        //sortam bucket urile individuale
        for (auto &bucket : buckets) {
            std::stable_sort(bucket.begin(), bucket.end());
        }

        //inseram elementele din bucket uri in ordine inapoi in aux
        int index = 0;
        for (const auto &bucket : buckets) {
            for (const auto &val : bucket) {
                aux[index++] = val;
            }
        }

        clock_t end = clock();
        data = aux;
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }

    void print() const { // debugging
        for (const auto &elem : data) {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
};
#endif