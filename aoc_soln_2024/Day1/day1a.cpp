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

    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
            sum = sum + std::abs(a[i] - b[i]);
    }

    std::cout << "Sum: " << sum << std::endl;
    // // Optional: Print the vectors to verify the contents
    // for (size_t i = 0; i < a.size(); ++i) {
    //     std::cout << "a[" << i << "] = " << a[i] << ", b[" << i << "] = " << b[i] << std::endl;
    // }

    return 0;
    
}