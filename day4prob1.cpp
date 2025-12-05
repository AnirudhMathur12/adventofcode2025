#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main() {

    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
        return 0;
    }

    std::stringstream buffer;

    buffer << file.rdbuf();
    std::string token;

    std::vector<std::string> lines;
    int count = 0;

    bool modified = true;

    while(std::getline(buffer, token, '\n')) {
       lines.push_back(token);
       std::cout << token << std::endl;
    }

    while(modified) {
        modified = false;
        for(int i = 0; i < lines.size(); i++) {
            for(int j = 0; j < lines[i].size(); j++) {
                if(lines[i][j] != '@') continue;
                int another_count = 0;
                if(i != 0 && lines[i-1][j] == '@') another_count++;
                if(i != 0 && j != 0 && lines[i-1][j-1] == '@') another_count++;
                if(i != 0 && j != lines[i].size() - 1 && lines[i-1][j+1] == '@') another_count++;

                if(j != 0 && lines[i][j-1] == '@') another_count++;
                if(j != lines[i].size() - 1 && lines[i][j+1] == '@') another_count++;

                if(i != lines.size() - 1 && lines[i+1][j] == '@') another_count++;
                if(i != lines.size() - 1 && j != 0 && lines[i+1][j-1] == '@') another_count++;
                if(i != lines.size() - 1 && j != lines[i].size() - 1 && lines[i+1][j+1] == '@') another_count++;

                if(another_count < 4) {
                    lines[i][j] = '.';
                    count++;
                    modified = true;
                }
            }

        }
    }



    std::cout << count << std::endl;

    return 0;
}
