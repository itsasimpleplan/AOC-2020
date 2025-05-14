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
    int counter_pt1 = 0;
    int counter_pt2 = 0;


    vector<char> answers;
    set<char> answersSet;
    int groupSize = 0;
    while (getline(myfile, line))
    {

        if (line != "") {
            groupSize++;
            if (line.length()>1) {
                for (int i = 0; i < line.length(); i++) {
                    answers.push_back(line[i]);
                    answersSet.insert(line[i]);
                }
            }else {
                answers.push_back(line[0]);
                answersSet.insert(line[0]);
            }
        }else {
            for (char answerOption : answersSet){
                int count_ans = count(answers.begin(), answers.end(), answerOption);
                if (count_ans == groupSize) {
                    counter_pt2 = counter_pt2 + 1;
                }
            }
            counter_pt1 = counter_pt1 + answersSet.size();
            answers.clear();
            answersSet.clear();
            groupSize = 0;
        }

    }
    for (char answerOption : answersSet) {
        int count_ans = count(answers.begin(), answers.end(), answerOption);
        if (count_ans == groupSize) {
            counter_pt2 = counter_pt2 + 1;
        }
    }
    counter_pt1 = counter_pt1 + answersSet.size();
    cout << counter_pt1 << endl;
    cout << counter_pt2 << endl;
}