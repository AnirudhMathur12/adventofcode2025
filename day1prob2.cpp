#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
        return 0;
    }

    std::stringstream buffer;

    buffer << file.rdbuf();

    std::string token;
    std::vector<std::string> directions;

    while (std::getline(buffer, token, '\n')) {
        directions.push_back(token);
    }

    int dial_pos = 50;
    unsigned int password = 0;
    unsigned int remainder;

    for (std::string s : directions) {
        unsigned int rotation = std::stoi(s.substr(1));
        password += rotation / 100;
        remainder = rotation % 100;

        if (s.starts_with("L")) {

            if (dial_pos != 0 && remainder >= dial_pos) {
                password++;
            }

            dial_pos -= remainder;
            if (dial_pos < 0)
                dial_pos += 100;

        } else {
            dial_pos += remainder;
            if (dial_pos > 99) {
                password++;
                dial_pos -= 100;
            }
        }
    }

    std::cout << password << "\n";
}
