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
    int password = 0;

    for (std::string s : directions) {
        if (s.starts_with("L")) {
            dial_pos -= std::stoi(s.substr(1));
        }
        if (s.starts_with("R")) {
            dial_pos += std::stoi(s.substr(1));
        }

        if (dial_pos < 0) {
            dial_pos = (dial_pos + 100) % 100;
        }

        if (dial_pos > 99) {
            dial_pos %= 100;
        }

        if (dial_pos == 0) {
            password++;
        }
    }

    std::cout << password << "\n";
}
