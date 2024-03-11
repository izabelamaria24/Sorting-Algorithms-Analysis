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
            g<<(seed*seed*(rand()%MOD))/(seed*(rand()%MOD)+1)<<' ';
        }
        g.close();
    }
}
int main()
{
    string file = "test_intregi_";
    genFiles(file, 15, 15);
    file = "teste_floating_";
    genFiles(file, 15, 15.13);
}