#include <iostream>
#include <fstream>


int main() {
    std::fstream newfile;
    int len;
    int mid;

    newfile.open("../input/day3a.txt", std::ios::in);
    if (newfile.is_open()) {
        std::string num_txt;
        std::string string1;
        std::string string2;
        std::string string3;


        int sum = 0, match_count = 0;
        bool get_common_str = false;
        int count = 0;
        char letter = '\n';

        while (getline(newfile, num_txt)) {
            if (count != 3) {
                switch (count) {
                    case 0:
                        string1 = num_txt;
                        count++;
                        break;
                    case 1:
                        string2 = num_txt;
                        count++;
                        break;
                    case 2:
                        string3 = num_txt;
                        count++;
                        get_common_str = true;
                        break;
                }
            }
            if (get_common_str == true) {
                std::cout << string1 << " " << string2
                            << " " << string3 << " " << std::endl;

                for (int i = 0; i < string1.size(); i++) {

                    for (int j = 0; j < string2.size(); j++) {
                        if (string1[i] == string2[j]) {
                            match_count++;
                            break;
                        }
                    }

                    for (int k = 0; k < string3.size(); k++) {
                        if (string1[i] == string3[k]) {
                            match_count++;
                            break;
                        }

                    }

                    if (match_count == 2) {
                        letter = string1[i];
                        match_count = 0;
                        break;
                    } else {
                        match_count = 0;
                    }
                }
                count = 0;
                get_common_str = false;
            } else {
                continue;
            }

        std::cout << letter << "  " << int(letter) << std::endl;
        if (static_cast<int>(letter) > 92)
            sum = sum + static_cast<int>(letter) - 96;
        else
            sum = sum + static_cast<int>(letter) - 38;
        std::cout << "Result is : " << sum << std::endl;
    }
    newfile.close();
}
}
