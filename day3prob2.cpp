#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream file("test.txt");

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

    uint64_t code = 0;

    for(std::string s : banks) {

        std::string result;

        int iter = 88;

        for(char c : s) {
            while(!result.empty() && result.back() < c && iter > 0) {
                result.pop_back();
                iter--;
            }

            result.push_back(c);
        }

        while(iter > 0) {
            result.pop_back();
            iter--;
        }

        std::cout << result << std::endl;

        code += std::stoull(result);
    }

    std::cout << code << std::endl;

    return 0;
}
