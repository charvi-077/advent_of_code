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

A  X = 3
A  Z = 0
A  Y = 6

B  X = 0
B  Z = 6
B  Y = 3

C  X = 6
C  Y = 0
C  Z = 3

 */

int main() {
    std::fstream newfile;
    int sum = 0;

    newfile.open("../input/day2a.txt", std::ios::in);
    if (newfile.is_open()) {
        std::string output_txt;
        while (getline(newfile, output_txt)) {
        if (output_txt == "A X") {
            sum += 3 + 1;

        } else if (output_txt == "A Y") {
            sum += 6 + 2;

        } else if (output_txt == "A Z") {
            sum += 0 + 3;

        } else if (output_txt == "B X") {
            sum += 0 + 1;

        } else if (output_txt == "B Y") {
            sum += 3 + 2;

        } else if (output_txt == "B Z") {
            sum += 6 + 3;

        } else if (output_txt == "C X") {
            sum += 6 + 1;

        } else if (output_txt == "C Y") {
            sum += 0 + 2;

        } else if (output_txt == "C Z") {
            sum += 3 + 3;
        }
        }
    }
    newfile.close();
    std::cout << "Net sum of scores : " << sum << std::endl;
}
