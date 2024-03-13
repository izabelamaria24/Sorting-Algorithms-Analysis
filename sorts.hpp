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
        radixSort_10(aux.begin(), aux.end());

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
        radixSort_2la16(aux.begin(), aux.end());

        clock_t end=clock();
        return static_cast<double>(end-start)/CLOCKS_PER_SEC;
    }

    double mergeSort()
    {
        std::vector<T> aux=data;
        clock_t start=clock();

        long long size_aux=aux.size();
        mergeSorter(aux, 0, size_aux);

        clock_t end=clock();
        return static_cast<double>(end-start)/CLOCKS_PER_SEC;
    }

    double mergeSorter(std::vector<T> &aux, int left, int right)
    {
        if (left < right)
        {
            long long mid = left + (right - left) / 2 ;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            long long i = left, j = mid + 1, k = 0;
            while (i <= mid and j <= right)
                if (data[i] < data[j])
                    aux[++k] = data[i++];
                else
                    aux[++k] = data[j++];
            while (i <= mid)
                aux[++k] = data[i++];
            while (j <= right)
                aux[++k] = data[j++];
            for (i = left, j = 1; i <= right; i++, j++)
                data[i] = aux[j];
        }
    }
    
    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
    
};
#endif