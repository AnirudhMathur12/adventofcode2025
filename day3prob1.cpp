#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
        return 0;
    }

    std::stringstream buffer;

    buffer << file.rdbuf();

    std::vector<std::string> banks;
    std::string token;

    while(std::getline(buffer, token, '\n')) {
        banks.push_back(token);
    }

    int code = 0;

    for(std::string s : banks) {
        char max_char = *std::max_element(s.begin(), s.end() - 1);
        int first_pos = s.find(max_char);

        char next_max_char = *std::max_element(s.begin() + first_pos + 1, s.end());

        code += (max_char - '0') * 10 + (next_max_char - '0');
    }

    std::cout << code << std::endl;

    return 0;
}
