#include <iostream>
#include <bitset>
using namespace std;
int main(){
    int i,a,k,j,u;
    k = 1;
    j = 0;
    char b;
    cout << "Enter number: " << endl;
    cin >> hex >> i;
    std::string x = std::bitset<16>(i).to_string();

    cout << "2: " << x << endl;
    a = i;
    for (int w = 3; w < 9; w++) {
        u = i;
        k = 1;
        j = 0;
        while (u>0) {
            j+=(u%w)*k;
            u = u/w;
            k*=10;

        }
        cout << w << ": " << j << endl;
    }
    while (i>0) {
        j+=(i%4)*k;
        i = i/4;
        k*=10;

    }
    cout << "16: "<< hex << a << endl;



}