#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, g, countOne;
    bool allDead;
    ifstream dat;
    ofstream out;
    double now[21][21];
    double then[21][21];
    char test;
    cout << "Enter the number of generations: ";
    cin >> n;
    dat.open("DATA.txt");
    g = 0;
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            dat.get(test);
            if (test == 'M')
            {
                now[i][j] = 1;
            }
            else
            {
                now[i][j] = 0;
            }
        }

    }
    cout << "---------------------------------------------------" << endl;
    out.open("OUT.txt");
    countOne=0;
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            out << now[i][j];
            if (now[i][j] == 1) {
                countOne++;
            }
        }
    }
    dat.close();
    if (countOne > 0) {
        for (int q = 0; q < n; q++) {
            countOne = 0;
            allDead = true;
            for (int i = 0; i < 21; i++) {
                for (int j = 0; j < 21; j++) {

                    if (now[i][j] == 12) {
                        then[i][j] = 0;
                    } else {
                        if (i == 0) {
                            if (j == 0) {
                                if ((now[i][j + 1] != 0) and (now[i + 1][j] != 0)) {
                                    then[i][j] = now[i][j] + 1;
                                } else {
                                    then[i][j] = 0;
                                }
                            } else if (j == 20) {
                                if ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) {
                                    then[i][j] = now[i][j] + 1;
                                } else {
                                    then[i][j] = 0;
                                }
                            } else {
                                if (((now[i][j - 1] != 0) and (now[i][j + 1] != 0)) or
                                    ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) or ((now[i][j + 1] != 0)) and
                                    ((now[i + 1][j] != 0))) {
                                    then[i][j] = now[i][j] + 1;
                                } else {
                                    then[i][j] = 0;
                                }
                            }
                        } else if (i == 20) {
                            if (j == 0) {
                                if ((now[i][j] != 0) and (now[i - 1][j] != 0)) {
                                    then[i][j] = now[i][j] + 1;
                                } else {
                                    then[i][j] = 0;
                                }
                            } else if (j == 20) {
                                if ((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) {
                                    then[i][j] = now[i][j] + 1;
                                } else {
                                    then[i][j] = 0;
                                }
                            } else {
                                if (((now[i][j - 1] != 0) and (now[i][j + 1] != 0)) or
                                    ((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) or
                                    ((now[i][j + 1] != 0) and (now[i - 1][j] != 0))) {
                                    then[i][j] = now[i][j] + 1;
                                } else {
                                    then[i][j] = 0;
                                }
                            }
                        } else if (j == 0) {
                            if (((now[i][j + 1] != 0) and (now[i - 1][j] != 0)) or
                                ((now[i][j + 1] != 0) and (now[i + 1][j] != 0)) or
                                ((now[i - 1][j] != 0) and (now[i + 1][j] != 0))) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        } else if (j == 20) {
                            if (((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) or
                                ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) or
                                ((now[i - 1][j] != 0) and (now[i + 1][j] != 0))) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        } else {
                            if (((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) or
                                ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) or
                                ((now[i][j - 1] != 0) and (now[i][j + 1] != 0)) or
                                ((now[i + 1][j] != 0) and (now[i - 1][j] != 0)) or
                                ((now[i][j + 1] != 0) and (now[i - 1][j] != 0)) or
                                ((now[i][j + 1] != 0) and (now[i + 1][j] != 0))) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < 21; i++) {
                for (int j = 0; j < 21; j++) {
                    now[i][j] = then[i][j];
                }
            }

            for (int i = 0; i < 21; i++)
            {
                for (int j = 0; j < 21; j++) {
                    cout << then[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < 21; i++)
            {
                for (int j = 0; j < 21; j++) {
                    if (now[i][j] == 1) {
                        countOne++;
                    }
                    if (now[i][j] != 0) {
                        allDead = false;
                    }
                }


            }
            cout << "There are " << countOne << " newborns!" << endl;
            if (allDead == false) {
                cout << "This generation lives!" << endl;
            } else {
                cout << "Oops, everybody is dead..." << endl;
            }

            cout << "----------------------------------------------------------------" << endl;
        }
    } else {
        cout << "Oops, there is no bacteria here..." << endl;
    }

}