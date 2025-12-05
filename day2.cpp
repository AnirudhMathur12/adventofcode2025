#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct Range {
    std::string start;
    std::string end;
};

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
        return 0;
    }

    std::stringstream buffer;

    buffer << file.rdbuf();

    std::string token;
    std::vector<Range> ranges;

    std::string start;
    std::string end;

    uint64_t password = 0;

    while (std::getline(buffer, token, ',')) {
        size_t pos = token.find('-');
        if (pos != std::string::npos) {
            ranges.push_back({token.substr(0, pos), token.substr(pos + 1)});
        }
    }

    for (Range r : ranges) {
        for (uint64_t i = std::stoull(r.start); i <= std::stoull(r.end); i++) {
            std::string num = std::to_string(i);
            std::string doubled = num + num;

            size_t repeated_len = doubled.find(num, 1);

            if (repeated_len < num.length()) {
                password += i;
            }
        }

        std::cout << password << std::endl;
    }

    return 0;
}
