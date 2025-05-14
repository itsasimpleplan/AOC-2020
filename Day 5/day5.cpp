#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string_view>

using namespace std;

int findRow(vector<int> rows, string seating) {
    if (rows.size() == 1) {
        return rows[0];
    }
    if (seating[0] == 'F' || seating[0] == 'L') {
        vector<int> newRows(rows.begin(), rows.begin()+rows.size()/2);

        seating.erase(0, 1);
        return findRow(newRows, seating);

    }
    if (seating[0] == 'B' || seating[0] == 'R') {

        vector<int> newRows(rows.begin()+rows.size()/2, rows.begin()+rows.size());
        seating.erase(0, 1);
        return findRow(newRows, seating);
    }
}

vector<int> findMissingNumber(vector<int> seats) {
    vector<int> missingList;
    for (int i=0; i<seats.size()-1; i++) {
        if (seats[i]+1 != seats[i+1]) {
            missingList.push_back(seats[i]+1);
        }
    }
    return missingList;
}

int main() {
    ifstream myfile("Day 5/Input/input.txt");

    string line;

    int maxSeatID = 0;
    vector<int> listSeatID;

    vector<int> rows(128) ; // vector with 100 ints.
    iota (begin(rows), end(rows), 0);
    vector<int> seats(8) ; // vector with 100 ints.
    iota (begin(seats), end(seats), 0);

    while (getline(myfile, line))
    {

        int rowNum = findRow(rows, line.substr(0,7));
        int seatNum = findRow(seats, line.substr(7,3));
        int seatID = 8*rowNum + seatNum;

        listSeatID.push_back(seatID);

        if (maxSeatID < seatID) {
            maxSeatID = seatID;
        }



    }

    cout << maxSeatID << endl;
    stable_sort(listSeatID.begin(), listSeatID.end());
    auto missing = findMissingNumber(listSeatID);
    cout << missing[0] <<endl;
    myfile.close();



}






