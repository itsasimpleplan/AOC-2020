#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

int main() {
    ifstream myfile("Day 6/Input/input.txt");
    string line;
    int counter = 0;

    set<char> answers;
    while (getline(myfile, line))
    {

        if (line != "") {
            if (line.length()>1) {
                for (int i = 0; i < line.length(); i++) {
                    answers.insert(line[i]);
                }
            }else {
                answers.insert(line[0]);
            }
        }else {
            counter = counter + answers.size();
            answers.clear();
        }

    }
    counter = counter + answers.size();
    cout << counter << endl;
}