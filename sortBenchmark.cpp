#include <iostream>
#include <fstream>
#include "sorts.hpp"
using namespace std;
int main() {
    ifstream f("test.txt");
    
    coolVector<double> v;
    double x;
    while(f>>x) {
        v.add(x);
    }
    cout<<v.bucketSort()<<'\n';
    v.print();
    
}