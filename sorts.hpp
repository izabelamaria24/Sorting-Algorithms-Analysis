#ifndef SORTS_HPP
#define SORTS_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>
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

    double radixSort_10()
    {
        std::vector<T> aux=data;
        clock_t start=clock();

        long long maxx=aux[0];
        for(auto it: aux)
            if(aux[it] > maxx)
                maxx=aux[it];
        for(long long exp=1; maxx/exp > 0; exp*=10)
        {
            long long size_aux=aux.size();
            std::vector<long long> res(size_aux);
            long long i, fr[10]={};
            for(auto it: aux)
                fr[(it/exp)%10]++;
            for(i=1; i < 10; i++)
                fr[i]+=fr[i-1];
            for(i=size_aux-1; i >= 0; i--)
            {
                res[fr[(aux[i]/exp)%10]-1]=aux[i];
                fr[(aux[i]/exp)%10]--;
            }
            aux.clear();
            for(auto el: res)
                aux.push_back(el);
        }

        clock_t end=clock();
        return static_cast<double>(end-start)/CLOCKS_PER_SEC;
    }

    double radixSort_2la16()
    {
        std::vector<T> aux=data;
        clock_t start=clock();

        long long maxx=aux[0];
        for(auto it: aux)
            if(aux[it] > maxx)
                maxx=aux[it];
        for(long long exp=1; maxx/exp > 0; exp=exp << 16)
        {
            long long size_aux=aux.size();
            std::vector<long long> res(size_aux);
            long long i, fr[65536]={};
            for(auto it: aux)
                fr[(it/exp)%65536]++;
            for(i=1; i < 65536; i++)
                fr[i]+=fr[i-1];
            for(i=size_aux-1; i >= 0; i--)
            {
                res[fr[(aux[i]/exp)%65536]-1]=aux[i];
                fr[(aux[i]/exp)%65536]--;
            }
            aux.clear();
            for(auto el: res)
                aux.push_back(el);
        }

        clock_t end=clock();
        return static_cast<double>(end-start)/CLOCKS_PER_SEC;
    }

    double mergeSort()
    {
        std::vector<T> res=data;
        clock_t start=clock();

        std::vector<T> aux(data.size());

        long long size_aux=aux.size();
        mergeSorter(aux, res, 0, size_aux-1);

        data=aux;
        print();

        clock_t end=clock();
        return static_cast<double>(end-start)/CLOCKS_PER_SEC;
    }

    double mergeSorter(std::vector<T> &aux, std::vector<T> &res, int left, int right)
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
      
    double shellSort() {
        // copying array data in an auxiliary one
        std::vector<T>sorted = data;

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

        clock_t end = clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }
};
#endif