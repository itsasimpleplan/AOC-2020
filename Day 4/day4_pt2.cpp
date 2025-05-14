#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <regex>
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


// bool check_criteria(const string & line, int i) {
//     switch (i) {
//         case 0:
//             break;
//         case 1:
//             break;
//         case 2:
//             break;
//         case 3:
//             break;
//         case 4:
//             break;
//         case 5:
//             break;
//         case 6:
//             break;
//         case 7:
//             break;
//         default:
//             return false;
//     }
//
//
// }

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
bool is_digits(string& str)
{
    for (char ch : str) {
        int v = ch; // ASCII Val converted
        if (!(ch >= 48 && ch <= 57)) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream myfile("Day 4/Input/input.txt");
    string line;
    int counter = 0;

    vector<string> validTypes = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
    vector<bool> typeValid = {false, false, false, false, false, false, false, false};

    while (getline(myfile, line))
    {

        if (line != "") {
            auto vecline = split(line, ' ');
            for (int i = 0; i < vecline.size(); i++) {
                auto criteria = split(vecline[i], ':');
                if (criteria[0] == "byr") {
                    if (criteria[1].length() == 4 && stoi(criteria[1]) >= 1920 && stoi(criteria[1]) <= 2002) {
                        typeValid[0] = true;
                    }
                }else if (criteria[0] == "iyr") {
                    if (criteria[1].length() == 4 && stoi(criteria[1]) >= 2010 && stoi(criteria[1]) <= 2020) {
                        typeValid[1] = true;
                    }
                }else if (criteria[0] == "eyr") {
                        if (criteria[1].length() == 4 && stoi(criteria[1]) >= 2020 && stoi(criteria[1]) <= 2030) {
                            typeValid[2] = true;
                        }
                }else if (criteria[0] == "hgt") {
                        if (criteria[1].find("in") != std::string::npos) {
                            criteria[1].pop_back();
                            criteria[1].pop_back();
                            if (stoi(criteria[1]) >= 59 and stoi(criteria[1]) <= 76) {
                                typeValid[3] = true;
                            }
                        }else if (criteria[1].find("cm") != std::string::npos) {
                            criteria[1].pop_back();
                            criteria[1].pop_back();
                            if (stoi(criteria[1]) >= 150 and stoi(criteria[1]) <= 193) {
                                typeValid[3] = true;
                            }
                        }
                }else if (criteria[0] == "hcl") {
                        regex hcl("#([0-9]|[a-f]){6}");
                        if (regex_match(criteria[1], hcl)){
                            typeValid[4] = true;
                        }

                }else if (criteria[0] == "ecl") {
                    if (criteria[1] == "amb" || criteria[1] == "blu" || criteria[1] == "brn" || criteria[1] == "gry" ||
                        criteria[1] == "grn" || criteria[1] == "hzl" || criteria[1] == "oth") {
                        typeValid[5] = true;
                    }

                }else if (criteria[0] == "pid") {
                    if (is_digits(criteria[1]) && criteria[1].length()==9) {
                        typeValid[6] = true;
                    }

                }
                // for (int i = 0; i < validTypes.size();  i ++) {
                //     if (line.find(validTypes[i]) != std::string::npos) {
                //         if (check_criteria(line, i)) {
                //             typeValid[i] = true;
                //         }
                //     }
                // }
            }


        } else {
            counter = check_doc(counter, typeValid);
            typeValid = {false, false, false, false, false, false, false, false};
        }

    }
    counter = counter = check_doc(counter, typeValid);
    cout << counter << endl;
}
