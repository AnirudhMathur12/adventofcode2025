#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct Range {
    long long start;
    long long end;
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

    while (std::getline(buffer, token, ',')) {
        size_t pos = token.find('-');
        ranges.push_back({std::stoi(token.substr(0, pos)),
                          std::stoi(token.substr(pos + 1))});
    }

    for (Range r : ranges) {
        std::cout << "Start: " << r.start << ", End: " << r.end << "\n";
    }

    return 0;
}
