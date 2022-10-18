#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int maxChar = 0;
    string str;
    cout << "Enter the string" << endl;
    cin >> str;

    //Create vector with ASCII codes
    std::vector<int> chars = {};
    std::vector<int> count = {};
    std::vector<char> sorted = {};



    for (int i = 0; i < str.length(); i++) {
        chars.push_back(int(str[i]));
    }


    //Find max ASCII element
    for (int j = 0; j < chars.size(); j++) {
        if (chars[j] > maxChar) {
            maxChar = chars[j];
        }
    }

    //Create an array with max length of maxChar
    for (int i = 0; i <= maxChar - 65; i++) {
        count.push_back(0);
    }

    //Go through initial string and count elements
    for (int i = 0; i < chars.size(); i++) {
        count[int(chars[i]) - 65]++;
    }

    //Create sorted vector
    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count[i]; j++) {

            sorted.push_back('0' + i + 17);

        }

    }
    for (int k = 0; k < sorted.size(); k++) {
        cout << sorted[k];
    }
}



