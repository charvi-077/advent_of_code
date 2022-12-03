#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

/* 

Rock Paper Sciccor 
A - ROCK - X
B - Paper - Y
C - Sciccor - z

Rock - 1
Paper - 2
Sciccor - 3

X - loose - 0
Y - Draw -3
Z - Win - 6

 */

int main() {
    std::fstream newfile;
    int sum = 0;

    newfile.open("../input/day2a.txt", std::ios::in);
    if (newfile.is_open()) {
        std::string output_txt;
        while (getline(newfile, output_txt)) {
        if (output_txt == "A X") {
            //  X is loose , A is ROCK so X should be Sciccor
            sum += 0 + 3;

        } else if (output_txt == "A Y") {
            // Y is draw, a is ROCK so Y should be ROCK
            sum += 3 + 1;

        } else if (output_txt == "A Z") {
            // Z is win, A is ROCK so Z should be Paper
            sum += 6 + 2;

        } else if (output_txt == "B X") {
            // X is loose , B is Paper , so X is ROCK
            sum += 0 + 1;

        } else if (output_txt == "B Y") {
            // Y is draw , B is Paper, so Y is Paper
            sum += 3 + 2;

        } else if (output_txt == "B Z") {
            // Z is win, B is Paper, so Z is Sciccor
            sum += 6 + 3;

        } else if (output_txt == "C X") {
            // X is loose, C is sciccor, so X is Paper
            sum += 0 + 2;

        } else if (output_txt == "C Y") {
            // Y is draw, C is sciccor, so Y is Sciccor
            sum += 3 + 3;

        } else if (output_txt == "C Z") {
            // Z is win, C is sciccor, so Z is Rock
            sum += 6 + 1;
        }
        }
    }
    newfile.close();
    std::cout << "Net sum of scores : " << sum << std::endl;
}
