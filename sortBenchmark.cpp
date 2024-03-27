#include <iostream>
#include <fstream>
#include "sorts.hpp"
using namespace std;

ofstream g("benchmarks.txt");
void testInt(string file)
{

    ifstream f(file);
    double rez;
    coolVector<int> v;
    int x;
    while (f >> x)
    {
        v.add(x);
    }
    f.close();
    g << "\nResults for " << file << ", of size N=" << v.size() << ":\n\n";

    rez = v.functieSortare();
    g << "Native sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    rez = v.heapSort();
    g << "Heap sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    rez = v.bucketSort();
    g << "Bucket sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    rez = v.radixSort(10);
    g << "Radix 10 sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    rez = v.radixSort(1 << 16);
    g << "Radix 1<<16 sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    rez = v.mergeSort();
    g << "Merge sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    rez = v.countingSort();
    g << "Counting sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    rez = v.shellSort();
    g << "Shell sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';
}

void testFloat(string file)
{

    ifstream f(file);
    double rez;
    coolVector<double> v;
    double x;
    while (f >> x)
    {
        v.add(x);
    }
    f.close();

    g << "\nResults for " << file << ", of size N=" << v.size() << ":\n\n";

    rez = v.functieSortare();
    // cout << "sortare nativa pe " << file << '\n';
    g << "Native sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    // cout<<"heap sort pe "<<file<<'\n';
    rez = v.heapSort();
    g << "Heap sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    // cout<<"bucket sort pe "<<file<<'\n';
    rez = v.bucketSort();
    g << "Bucket sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    // cout<<"radix sort10 pe "<<file<<'\n';
    rez = v.radixSort(10);
    g << "Radix10 sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    // cout<<"radix sort1<<16 pe "<<file<<'\n';
    rez = v.radixSort(65536);
    g << "Radix1<<16 sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    // cout<<"merge sort pe "<<file<<'\n';
    rez = v.mergeSort();
    g << "Merge sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    // cout<<"counting sort pe "<<file<<'\n';
    rez = v.countingSort();
    g << "Counting sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';

    // cout<<"shell sort pe "<<file<<'\n';
    rez = v.shellSort();
    g << "Shell sort on " << file << ": ";
    rez == -1 ? (g << "Sort messed up") : g << rez << " seconds";
    g << '\n';
}

int main()
{

    string file;
    for (int i = 1; i <= 5; ++i)
    {

        file = "test_int_" + to_string(i);
        testInt(file);

        file = "test_float_" + to_string(i);
        testFloat(file);
    }
}