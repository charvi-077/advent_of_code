#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <sstream>
#include <vector>

// Input stack : 
// [C]         [S] [H]                
// [F] [B]     [C] [S]     [W]        
// [B] [W]     [W] [M] [S] [B]        
// [L] [H] [G] [L] [P] [F] [Q]        
// [D] [P] [J] [F] [T] [G] [M] [T]    
// [P] [G] [B] [N] [L] [W] [P] [W] [R]
// [Z] [V] [W] [J] [J] [C] [T] [S] [C]
// [S] [N] [F] [G] [W] [B] [H] [F] [N]
//  1   2   3   4   5   6   7   8   9 

const int row = 9;
const int col = 8;

char input_arr[row][col] = {{'S', 'Z', 'P', 'D', 'L', 'B', 'F', 'C'},
                            {'N', 'V', 'G', 'P', 'H', 'W', 'B', ' '},
                            {'F', 'W', 'B' , 'J', 'G', ' ', ' ', ' '},
                            {'G', 'J', 'N' , 'F', 'L', 'W', 'C', 'S'},
                            {'W', 'J', 'L' , 'T', 'P', 'M', 'S', 'H'},
                            {'B', 'C', 'W' , 'G', 'F', 'S', ' ', ' '},
                            {'H', 'T', 'P' , 'M', 'Q', 'B', 'W', ' '},
                            {'F', 'S', 'W' , 'T', ' ', ' ', ' ', ' '},
                            {'N', 'C', 'R' , ' ', ' ', ' ', ' ', ' '}};

std::vector<std::vector<char>> input_list;

int main() {
    std::fstream newfile;
    newfile.open("../input/day5a.txt", std::ios::in);


    if (newfile.is_open()) {
        std::string num_txt;

        // Insert the data input in list of stacks
        for (int i = 0; i < row; i++) {
            std::vector<char> s;
            for (int j = 0; j < col; j++) {
                if (input_arr[i][j] != ' ') {
                    s.push_back(input_arr[i][j]);
                }
            }
            input_list.push_back(s);
        }

        // Traverse and get the top of stacks in the list of stacks
        std::cout << "For input list last elements are  : " << std::endl;
        for (int i = 0; i < 9; i++) {
            std::cout << input_list[i].back() << " ";
        }
        std::cout << std::endl;

        while (getline(newfile, num_txt)) {
            std::stringstream ss;
            std::string temp_string;
            int number;
            std::vector<int> num_vec;
            ss << num_txt;
            while (!ss.eof()) {
                ss >> temp_string;

                if (std::stringstream(temp_string) >> number) {
                    // std::cout << temp_string << " ";
                    num_vec.push_back(number);
                }

                temp_string = "";
            }

            while (num_vec[0]--) {
                char temp = input_list[num_vec[1]-1].back();
                input_list[num_vec[1]-1].pop_back();
                input_list[num_vec[2]-1].push_back(temp);
                int countc = 0;
            }
        }

        std::cout << "Result is : " << std::endl;
        for (int i = 0; i < row; i++) {
            std::cout << input_list[i].back() << " ";
        }
    newfile.close();
    }
}
