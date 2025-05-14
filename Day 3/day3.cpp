//
// Created by sarah on 11/05/2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <tuple>
using namespace std;
#include "day3.h"

int main() {
    ifstream myfile("Day 3/Input/input.txt");

    string line;
    vector<vector<char>> grid;

    while (getline(myfile, line))
    {
        vector<char> temp;
        for (int i = 0; i < line.length(); i++) {
            temp.push_back(line[i]);
        }
        grid.push_back(temp);
    }

    myfile.close();

    float outcomes = 1;
    vector<tuple<int,int>> slopes;
    slopes.push_back(make_tuple(1,1));
    slopes.push_back(make_tuple(3,1));
    slopes.push_back(make_tuple(5,1));
    slopes.push_back(make_tuple(7,1));
    slopes.push_back(make_tuple(1,2));



    for (int i = 0; i < slopes.size(); i++) {
        int trees = 0;
        int coordX = 0;
        int coordY = 0;

        while (coordY < grid.size()-1) {
            coordX = coordX + get<0>(slopes[i]);
            coordY = coordY + get<1>(slopes[i]);

            if (coordX%grid[0].size() < grid[0].size() && coordY < grid.size()) {
                //cout << coordX%grid[0].size() <<endl;
                if (grid[coordY][coordX%grid[0].size()] == '#') {

                    trees = trees + 1;
                }
            }

        }
        cout << trees << endl;
        outcomes = outcomes * trees;
    }
    cout << setprecision(13);
    cout << outcomes << endl;
}
