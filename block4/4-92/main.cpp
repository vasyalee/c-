#include <iostream>
#include <bitset>
using namespace std;
int main(){
    int i,a,k,j,u;
    char b;
    cout << "Enter the number: ";
    cin >> dec >> i;
    a = i;
    for (int w = 3; w < 8; w++) {
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

    cout << "8: " << oct << a << endl;
    cout << "16: " << hex << a << endl;

    b = a;
    bitset<8> x(b);
    cout << "2: " << x << endl;
}