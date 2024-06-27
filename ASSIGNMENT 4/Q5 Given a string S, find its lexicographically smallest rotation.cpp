#include <iostream>
#include <string>
#include <algorithm>

std::string lexicographicallySmallestRotation(const std::string &s) {
    std::string ss = s + s;
    std::string smallest = s;
    for (int i = 1; i < s.size(); i++) {
        std::string rotation = ss.substr(i, s.size());
        if (rotation < smallest) {
            smallest = rotation;
        }
    }
    return smallest;
}

int main() {
    std::string s = "cbabde";
    std::cout << "Lexicographically smallest rotation: " << lexicographicallySmallestRotation(s) << std::endl;
    return 0;
}
