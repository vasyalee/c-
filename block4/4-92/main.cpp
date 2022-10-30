#include <iostream>
#include <bitset>
using namespace std;
int main(){
    int i,a,k,u;
    long long int j = 0;
    k = 1;
    char b;
    cout << "Enter num: ";
    cin >> hex >> i;
    a = i;
    for (int w = 2; w < 9; w++) {
        u = i;
        k = 1;
        j = 0;
        while (u>0) {
            j+=(u%w)*k;
            u = u/w;
            k*=10;

        }
        cout << w << ": "<< j << endl;
    }
    while (i>0) {
        j+=(i%4)*k;
        i = i/4;
        k*=10;

    }
    cout << "16: " << hex << a << endl;




}