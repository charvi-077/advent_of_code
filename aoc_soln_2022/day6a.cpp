#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
int count = 0;

int main() {
    std::fstream newfile;

    newfile.open("../input/day6a.txt", std::ios::in);
    if (newfile.is_open()) {
        std::string num_txt;
        int i, j;
        while (getline(newfile, num_txt)) {
        //    std::cout << num_txt << std::endl;

           for (i = 0; i < num_txt.length(); i++) {
               std::vector<char> sub_string;
               for (j = i; j < i+4; j++) {
                   sub_string.push_back(num_txt[j]);
                }
                sort(sub_string.begin(), sub_string.end());
                sub_string.erase(unique(sub_string.begin(), sub_string.end()),
                                                         sub_string.end());
                if (sub_string.size() != 4) {
                    continue;
                } else {
                    std::cout << "Result is : " << j << " " << num_txt[j]
                                                             << std::endl;
                    break;
                }

                // to cross-check substring data
                // for(int k = 0; k<sub_string.size(); k++){
                //     std::cout << sub_string[k];
                // }
               }
           }
    }
    newfile.close();
}
