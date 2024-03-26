#ifndef SORTS_HPP
#define SORTS_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <map>
#include <ctime>
template <typename T>
class coolVector
{
private:
    std::vector<T> data;

    bool checker(std::vector<T>&v)
    {
        auto prev = v[0];
        for (const auto &elem : v)
        {
            if (elem < prev)
                return 0;
        }
        return 1;
    }

    // methods for radix sort
    long long double_to_uint(double d) {
        return *reinterpret_cast<long long*>(&d);
    }

    double uint_to_double(long long i) {
        return *reinterpret_cast<double*>(&i);
    }

    void radixSort_x(const int x, std::vector<T>&aux)
    {
        if (aux.empty()) return;
        T maxx = aux[0];
        for (auto it : aux)
            if (it > maxx)
                maxx = it;
        for (long long exp = 1; maxx / exp > 0; exp *= x)
        {
            long long size_aux = aux.size();
            std::vector<long long> res(size_aux);
            long long i;
            std::vector<long long> fr(x, 0);
            for (auto it : aux)
                fr[int(it / exp) % x]++;
            for (i = 1; i < x; i++)
                fr[i] += fr[i - 1];
            for (i = size_aux - 1; i >= 0; i--)
            {
                res[fr[int(aux[i] / exp) % x] - 1] = aux[i];
                fr[int(aux[i] / exp) % x]--;
            }

            aux.clear();
            for (auto el : res)
                aux.push_back(el);
        }
    }

    // method for merge sort
    void mergeSorter(std::vector<T> &aux, std::vector<T> &res, int left, int right)
    {
        if (left < right)
        {
            long long mid = left + (right - left) / 2 ;
            mergeSorter(aux, res, left, mid);
            mergeSorter(aux, res, mid + 1, right);
            long long i = left, j = mid + 1, k = 0;
            while (i <= mid && j <= right)
                if (res[i] < res[j])
                    aux[k++] = res[i++];
                else
                    aux[k++] = res[j++];
            while (i <= mid)
                aux[k++] = res[i++];
            while (j <= right)
                aux[k++] = res[j++];
            for (i = left, j = 0; i <= right; i++, j++)
                res[i] = aux[j];
        }
    }

public:
    coolVector() = default;

    void add(T element)
    {
        data.push_back(element);
    }

    double radixSort(const int x) {
        std::vector<T> aux = data;
        std::vector<T> positives, negatives;

        clock_t start=clock();

        for (auto elem : aux) {
            if (elem < 0) {
                negatives.push_back(-elem); // Make negative numbers positive for sorting
            } else {
                positives.push_back(elem);
            }
        }

        // convert floating point numbers to int
        for (int i = 0; i < negatives.size(); i++) {
            double p = double_to_uint(negatives[i]);
            negatives[i] = p;
        }

        for (int i = 0; i < positives.size(); i++) {
            double p = double_to_uint(positives[i]);
            positives[i] = p;
        }

        // apply radix sort on each vector
        radixSort_x(x, negatives);
        radixSort_x(x, positives);

        // convert sorted integers back to floating-point numbers
        for (int i = 0; i < negatives.size(); i++) {
            negatives[i] = uint_to_double(negatives[i]);
        }

        for (int i = 0; i < positives.size(); i++) {
            positives[i] = uint_to_double(positives[i]);
        }

        // Merge sorted negative and positive numbers
        aux.clear();
        for (int i = negatives.size() - 1; i >= 0; i--) {
            aux.push_back(-negatives[i]);
        }
        for (int i = 0; i < positives.size(); i++) {
            aux.push_back(positives[i]);
        }

        clock_t end = clock();
        if (checker(aux))
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        return -1;
    }
    
//    double radixSort_2la16()
//    {
//        std::vector<T> aux = data;
//        clock_t start = clock();
//
//        long long maxx = aux[0];
//        for (auto it : aux)
//            if (aux[it] > maxx)
//                maxx = aux[it];
//        for (long long exp = 1; maxx / exp > 0; exp = exp << 16)
//        {
//            long long size_aux = aux.size();
//            std::vector<long long> res(size_aux);
//            long long i, fr[65536] = {};
//            for (auto it : aux)
//                fr[int(it / exp) % 65536]++;
//            for (i = 1; i < 65536; i++)
//                fr[i] += fr[i - 1];
//            for (i = size_aux - 1; i >= 0; i--)
//            {
//                res[fr[int(aux[i] / exp) % 65536] - 1] = aux[i];
//                fr[int(aux[i] / exp) % 65536]--;
//            }
//            aux.clear();
//            for (auto el : res)
//                aux.push_back(el);
//        }
//
//        clock_t end = clock();
//        if (checker(aux))
//            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
//        return -1;
//    }

    double mergeSort()
    {
        std::vector<T> res = data;

        std::vector<T> aux(data.size());

        long long size_aux = aux.size();
        clock_t start = clock();
        mergeSorter(aux, res, 0, size_aux - 1);
        clock_t end = clock();
        if (checker(res))
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        return -1;
    }

    double shellSort()
    {
        // copying array data in an auxiliary one
        std::vector<T> aux = data;

        clock_t start = clock();

        int gap = aux.size() / 2;
        while (gap > 0)
        {
            for (int i = gap; i < aux.size(); i++)
            {
                int j = i;
                while (j >= gap && aux[j] < aux[j - gap])
                {
                    std::swap(aux[j], aux[j - gap]);
                    j -= gap;
                }
            }
            gap /= 2;
        }

        clock_t end = clock();
        if (checker(aux))
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        return -1;
    }

    double countingSort()
    {
        std::vector<T> aux;
        clock_t start = clock();

        std::map<T, int> count;
        for (const auto &elem : data)
            count[elem]++;

        for (const auto &elem : count)
        {
            T value = elem.first;
            int cnt = elem.second;
            for (int i = 0; i < cnt; ++i)
                aux.emplace_back(value);
        }

        clock_t end = clock();
        if (checker(aux))
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        return -1;
    }

    double functieSortare()
    {
        // copiem vectorul
        std::vector<T> aux = data;
        clock_t start = clock();

        // Sortam sortam
        std::sort(aux.begin(), aux.end());

        clock_t end = clock();
        if (checker(aux))
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        return -1;
    }

    double heapSort()
    {
        // copiem vectorul
        std::vector<T> aux;
        std::priority_queue<T, std::vector<T>, std::greater<T> > pq;

        clock_t start = clock();
        // Sortam sortam
        for (const auto &elem : data)
        {
            pq.push(elem);
        }

        while (!pq.empty())
        {
            aux.push_back(pq.top());
            pq.pop();
        }
        clock_t end = clock();
        if (checker(aux))
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        return -1;
    }

    double bucketSort()
    {
        // copiem vectorul
        std::vector<T> aux = data;
        clock_t start = clock();

        T Min = std::numeric_limits<T>::max();
        T Max = std::numeric_limits<T>::min();
        for (const auto &val : data)
        {
            if (val < Min)
                Min = val;
            if (val > Max)
                Max = val;
        }

        // alegem bucket urile
        int nrBuckets = aux.size() / 4;
        double range = (Max - Min + 1) / static_cast<double>(nrBuckets);
        std::vector<std::vector<T>> buckets(nrBuckets);

        for (const auto &val : aux)
        {
            int bucket_index = static_cast<int>((val - Min) / range);
            buckets[bucket_index].push_back(val);
        }

        // sortam bucket urile individuale
        for (auto &bucket : buckets)
        {
            std::stable_sort(bucket.begin(), bucket.end());
        }

        // inseram elementele din bucket uri in ordine inapoi in aux
        int index = 0;
        for (const auto &bucket : buckets)
        {
            for (const auto &val : bucket)
            {
                aux[index++] = val;
            }
        }

        clock_t end = clock();
        if (checker(aux))
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        return -1;
    }

    void print() const
    { // debugging
        for (const auto &elem : data)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
    int size() const
    {
        return data.size();
    }
};

#endif