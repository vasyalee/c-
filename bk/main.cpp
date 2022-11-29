#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> getOtherNumbers(vector<int> PC, int step) {

    random_device hd;
    mt19937 gen(hd());


    int n = gen() % 10;

    int count = 0;
    if (step == 4){
        return PC;
    }
    else {
        for (int i = 0; i < PC.size(); i++) {
            if (n != PC[i]) {
                count++;

            }
        }
        if (count == step) {
            PC.push_back(n);
            return getOtherNumbers(PC, step+1);
        }
        else {
            return getOtherNumbers(PC, step);
        }
    }


}

int main()
{
    vector <int> PC;
    vector <int> player;
    int a, b, c, d;
    random_device hd;
    mt19937 gen(hd());

    cout << "Enter the number (4 digits separated by space):";

    cin >> a >> b >> c >> d;
    player.push_back(a);
    player.push_back(b);
    player.push_back(c);
    player.push_back(d);

    int n = gen() % 10;
    PC.push_back(n);
    PC = getOtherNumbers(PC, 1);




    cout << "PC: " << PC[0] << PC[1] << PC[2] << PC[3] << endl << "Result: ";
    for (int i = 0; i < 4; i++)
    {
        if (PC[i] == player[i])
        {
            cout << "+";
        }
        else
        {
            cout << "-";
        }
    }
}