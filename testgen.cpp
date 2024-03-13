/*
    *-*
    |             run in terminal             |
    g++ -O2 -std=c++20 testgen.cpp -o generator
    ./generator
    *-*
*/


#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>
#include "sorts.hpp"

using namespace std;

//void genFiles(string file, const int nb, auto seed) {
//    for(int i=0; i<nb; ++i) {
//        string aux = file;
//        aux += to_string(i);
//        ofstream g(aux);
//
//        for(int it=0; it<201326611; ++it) {
//            g<<(seed*(rand()%1572869))/(seed*(rand()%24593)+1)<<' ';
//        }
//        g.close();
//    }
//}
int main()
{
    coolVector<int> vec;
    int n = 7;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.add(x);
    }

    vec.countingSort();
    vec.shellSort();

//    srand(time(0));
//    string file = "test_int_";
//    genFiles(file, 1, 15);
//    file = "test_float_";
//    genFiles(file, 1, 15.13);
}