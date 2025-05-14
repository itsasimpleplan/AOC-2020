#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

int check_doc(int counter, vector<bool> typeFound) {
    auto count = std::count(typeFound.begin(), typeFound.end(), true);

    if (count == 8) {
        counter++;
    }else if (count == 7 && !typeFound[7]) {
        counter++;
    }
    return counter;
}




int main() {
    ifstream myfile("Day 4/Input/input.txt");
    string line;
    int counter = 0;
    int countvalids = 0;


    vector<string> validTypes = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
    vector<bool> typeValid = {false, false, false, false, false, false, false, false};

    while (getline(myfile, line))
    {

        if (line != "") {
            for (int i = 0; i < validTypes.size();  i ++) {
                if (line.find(validTypes[i]) != std::string::npos) {
                    if (check_criteria(line, i)) {
                        typeValid[i] = true;
                    }
                }
            }
        }else {
            counter = check_doc(counter, typeValid);
            typeValid = {false, false, false, false, false, false, false, false};
        }

    }
    counter = counter = check_doc(counter, typeValid);
    cout << counter << endl;
}
