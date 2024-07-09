#include <iostream>
#include <string>
#include <algorithm>

std::string shortestPalindrome(std::string s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s.substr(0, n - i) == reversed_s.substr(i)) {
            return reversed_s.substr(0, i) + s;
        }
    }
    return "";
}

int main() {
    std::string s;
    std::cout << "Введите строку s: ";
    std::cin >> s;
    std::cout << "Самый короткий палиндром: " << shortestPalindrome(s) << std::endl;
    return 0;
}
