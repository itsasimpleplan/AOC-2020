#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<algorithm>


using namespace std;

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

void part1(string line, vector<string> v) {

    ifstream myfile("Day 2/Input/input.txt");
    int valid = 0;

    while (getline(myfile, line))
    {
        line.erase(remove(line.begin(), line.end(), ':'), line.end());
        auto words = split(line, ' ');
        int count = 0;
        for (int i = 0; i < words[2].size(); i++) {
            if ( words[2][i] == words[1][0] ) {
                count = count+1;
            }
        }
        auto min_max = split(words[0], '-');

        if (count >= stoi(min_max[0]) && count <= stoi(min_max[1])){
            valid = valid + 1;
        }

    }
    cout << valid << endl;

}


void part2(string line, vector<string> v) {

    ifstream myfile("Day 2/Input/input.txt");
    int valid = 0;

    while (getline(myfile, line))
    {
        line.erase(remove(line.begin(), line.end(), ':'), line.end());
        auto words = split(line, ' ');
        auto min_max = split(words[0], '-');
        bool first = words[2][stoi(min_max[0])-1] == words[1][0];
        bool second = words[2][stoi(min_max[1])-1] == words[1][0];

        if (first != second) {
            valid = valid+1;
        }



    }
    cout << valid << endl;

}



int main() {


    string line;
    vector<string> v;


    part1(line, v);
    part2(line, v);

}
