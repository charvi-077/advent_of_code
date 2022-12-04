#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

int count = 0;

int main() {
    std::fstream newfile;


    newfile.open("../input/day4a.txt", std::ios::in);
    if (newfile.is_open()) {
        std::string num_txt;
        while (getline(newfile, num_txt)) {
            std::stringstream ss;
            std::string temp_string;
            int number;
            std::vector<int> num_vec;

            std::cout << "num txt : " << num_txt << std::endl;
            int i = 0;
            while (num_txt[i]) {
                if (num_txt[i] == ',' || num_txt[i] == '-')
                    num_txt[i] = ' ';
                i++;
            }
            std::cout << "num txt : " << num_txt << std::endl;
            ss << num_txt;

            // std::cout << num_txt[0] << num_txt[2] << std::endl;

            while (!ss.eof()) {
                ss >> temp_string;

                if (std::stringstream(temp_string) >> number) {
                    std::cout << number << " " << std::endl;
                    num_vec.push_back(number);
                }

                temp_string = "";
            }

            if (num_vec[0] >= num_vec[2] && num_vec[1] <= num_vec[3]) {
                count++;
                std::cout << "yes1" << std::endl;
            } else if (num_vec[2] >= num_vec[0] && num_vec[3] <= num_vec[1]) {
                count++;
                std::cout << "yes" << std::endl;
            }
        }
    }
    newfile.close();

    std::cout << "Result is : " << count << std::endl;
}
