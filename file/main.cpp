#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


bool check(int _first, int _last, vector<int> _nums) {

    if (_nums[_first] == _nums[_last] and _first <= _last and _first+1 > _last-1) {
        return true;
    } else if (_first <= _last and _nums[_first] == _nums[_last] and _first+1 <= _last-1) {
        return check(_first+1, _last-1, _nums);
    } else if (_nums[_first] != _nums[_last]) {
        return false;
    }
}

int main() {
    // Write to file
    int n, first, last, checker, mxlen, subcount;
    bool flag;

    string nums;
    vector<int> part = {};

    cout << "Enter number of digits: " << endl;
    cin >> n;


    //Working with file
    ofstream fout("digits.txt");
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter number: " << endl;
        cin >> x;
        fout << x;

    }
    fout.close();

    // Read from file
    ifstream fin("digits.txt"); //

    if (!fin.is_open()) { // если файл не открыт
        cout << "File cannot be opened!\n";
    }// сообщить об этом
    else {
        getline(fin, nums); // считали строку из файла
        fin.close(); // закрываем файл
//        cout << nums << endl; // напечатали эту строку
    }


    for (int i = 0; i < nums.length(); i++) {
        part.push_back(nums[i] - 48);
    }


    mxlen = 0;
    flag = false;


    for (int first = 0; first < part.size(); first++){
        for (int last = part.size(); last > first; last--)
        if (part[first] == part[last]) {
            checker = check(first, last, part);
            if (checker == true) {
                flag = true;
                subcount = 1;
                for (int i = first; i < last; i++) {
                    subcount++;
                }
                if (subcount > mxlen) {
                    mxlen = subcount;
                    for (int a = first; a < last+1; a++) {
                        cout << part[a];
                    }
                    cout << "\n";
                    cout << mxlen << endl;
                }


            }

        }
    }
    if (flag == false) {
        cout << "Nothing found!" << endl;
    }


}










