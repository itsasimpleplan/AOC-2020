#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1(vector<string> v){

    for (int index = 0; index < v.size(); index++)
    {
        if (2020 - stoi(v[index]) > 0){
            for (int indexB = 0; indexB < v.size(); indexB++) {
                if ( index != indexB ) {
                    if ( stoi(v[index]) + stoi(v[indexB]) == 2020) {
                        cout << stoi(v[index])*stoi(v[indexB]) << endl;
                    }
                }
            }
        }
    }
}

void part2(vector<string> v){

    for (int index = 0; index < v.size(); index++){
        if (2020 - stoi(v[index]) > 0){
            for (int indexB = 0; indexB < v.size(); indexB++) {
                if ( index != indexB ){
                    if ( 2020 - stoi(v[index]) - stoi(v[indexB]) > 0 ) {
                        for (int indexC = 0; indexC < v.size(); indexC++) {
                            if ( index != indexC and indexB != indexC ) {
                                if (stoi(v[index]) + stoi(v[indexB]) + stoi (v[indexC]) == 2020) {
                                    cout << stoi(v[index])*stoi(v[indexB])*stoi(v[indexC]) << endl;
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}


int main() {
    ifstream myfile("Day 1/Input/input.txt");

    string line;
    vector<string> v;

    while (getline(myfile, line))
    {
        v.push_back(line);
    }

    myfile.close();

    part1(v);
    part2(v);
}
