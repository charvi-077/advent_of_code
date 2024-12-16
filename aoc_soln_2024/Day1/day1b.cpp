#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::vector<int> a, b;
    int num1, num2;

    while (inputFile >> num1 >> num2) {
        a.push_back(num1);
        b.push_back(num2);
    }

    inputFile.close();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::cout << "First 10 elements of a: ";
    for (int i = 0; i < 30 && i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "First 10 elements of b: ";
    for (int i = 0; i < 30 && i < b.size(); ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    int sum = 0;

    int i = 0;
    for (int j = 0; j < a.size(); j++) {
        int count = 0;
        if (a[j] < b[i]) {
            continue;
        }
        else {
            while (a[j] >= b[i] && i < b.size()) {
                if (a[j] == b[i]) 
                    count++;

                i++;
            }
            sum += a[j]*count;
        }
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}