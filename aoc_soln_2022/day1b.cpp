#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

std::vector<int> calories_sum;
int sum;

int main() {
    std::fstream newfile;

    newfile.open("../input/day1a.txt", std::ios::in);
    if (newfile.is_open()) {
        std::string num_txt;
        while (getline(newfile, num_txt)) {
            if (num_txt.empty()) {
                std::cout << std::endl << "Sum of calories of one Elf : "
                            << " " << sum << std::endl;
                calories_sum.push_back(sum);
                sum = 0;
                continue;
            }
            int num = std::stoi(num_txt);
            sum += num;
            std::cout << num << " ";
        }
        std::cout << std::endl << "Sum of calories of one Elf : "
                            << " " << sum << std::endl;
        calories_sum.push_back(sum);
    }
    newfile.close();

    sort(calories_sum.begin(), calories_sum.end());
    std::cout << "Sum of top 3 Max element is : " <<
                accumulate(calories_sum.end() - 3, calories_sum.end(), 0)
                        << std::endl;
}
