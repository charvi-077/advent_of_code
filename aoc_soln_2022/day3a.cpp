#include <iostream>
#include <fstream>


int main() {
    std::fstream newfile;
    int len;
    int mid;

    newfile.open("../input/day3a.txt", std::ios::in);
    if (newfile.is_open()) {
        std::string num_txt;
        int sum = 0;
        while (getline(newfile, num_txt)) {
            len = num_txt.size();
            mid = ((len/2));
            char letter = '\n';

            for (int i = 0 ; i < mid ; i++) {
                for (int j = mid; j < len; j++) {
                    if (num_txt[i] == num_txt[j]) {
                        letter = num_txt[i];
                        break;
                    }
                }

                if (letter != '\n')
                    break;
            }
        std::cout << letter << "  " << int(letter) << std::endl;
        if (static_cast<int>(letter) > 92)
            sum = sum + static_cast<int>(letter) - 96;
        else
            sum = sum + static_cast<int>(letter) - 38;
    }
    std::cout << "Result is : " << sum << std::endl;
    newfile.close();
}
}
