#include <iostream>
#include <fstream>
#include "sorts.hpp"
using namespace std;
int main() {
    ofstream g("benchmarks.txt");

    const int testNr = 5;

    // ifstream f("test.txt");
    // double x;
    // coolVector<double> v;
    // while(f>>x) {
    //     v.add(x);
    // }
    // cout<<v.radixSort_10()<<" "<<v.radixSort_2la16()<<" <<v.bucketSort()<<" "<<v.functieSortare()<<" "<<v.heapSort()<<" "<<v.mergeSort()<<" "<<v.shellSort()<<" "<<v.countingSort();
    



    for (int i=0; i < 1; ++i) {
        double rez;
        string file = "test_int_" + to_string(i);
        ifstream f(file);
        coolVector<int> v;
        int x;
        while(f>>x) {
            v.add(x);
        }
        f.close();

        rez = v.functieSortare(); 
        g<<"Native sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';

        rez = v.heapSort(); 
        g<<"Heap sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';

        rez = v.bucketSort(); 
        g<<"Bucket sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';

        rez = v.radixSort_10(); 
        g<<"Radix 10 sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';

        rez = v.radixSort_2la16(); 
        g<<"Radix 1<<16 sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';

        rez = v.mergeSort(); 
        g<<"Merge sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';

        rez = v.countingSort(); 
        g<<"Counting sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';

        rez = v.shellSort(); 
        g<<"Shell sort on "<<file<<": ";
        rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
        g<<'\n';
    }

    // for (int i=0; i < testNr; ++i) {
    //     string file = "test_float_" + to_string(i);
    //     double rez; 
    //     ifstream f(file);
    //     coolVector<double> v;
    //     double x;
    //     while(f>>x) {
    //         v.add(x);
    //     }
    //     f.close();

    //     rez = v.bucketSort(); 
    //     g<<"Bucket sort on "<<file<<": ";
    //     rez == -1 ? (g<<"Sort messed up") : g<<rez<<" seconds";
    //     g<<'\n';

    // }
    
}