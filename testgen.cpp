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
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void genFiles(string file, auto seed, const int N, const int i)
{
    string aux = file;
    aux += to_string(i);
    ofstream g(aux);
    for (int it = 0; it < N; ++it)
        g << (seed * (rand() % 1572869)) / (seed * (rand() % 24593) + 1) << ' ';

    g.close();
}

int main()
{
    const int T = 5;
    srand(time(0));
    string file = "test_int_";
    for (int i = 1; i <= T; ++i)
    {
        genFiles(file, 5, pow(10, i+3), i);
    }

    file = "test_float_";

    for (int i = 1; i <= T; ++i)
    {
        genFiles(file, 5.3, pow(10, i+3), i);
    }
}