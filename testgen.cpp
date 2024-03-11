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
#include <time.h> 
using namespace std;
#define MOD 1572869
void genFiles(string file, const int nb, auto seed) {

    srand(time(0));
    for(int i=0; i<nb; ++i) {
        string aux = file;
        aux += to_string(i);
        ofstream g(aux);

        int limit = rand()%MOD;
        for(int it=0; it<limit; ++it) {
            g<<(seed*(rand()%MOD))/(seed*(rand()%24593)+1)<<' ';
        }
        g.close();
    }
}
int main()
{
    string file = "test_int_";
    genFiles(file, 15, 15);
    file = "test_float_";
    genFiles(file, 15, 15.13);
}