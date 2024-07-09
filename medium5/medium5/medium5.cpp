#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    vector<string> romanSymbols = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    vector<int> romanValues = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    string result = "";
    int index = 0;

    while (num > 0) {
        while (num >= romanValues[index]) {
            result += romanSymbols[index];
            num -= romanValues[index];
        }
        index++;
    }

    return result;
}

int main() {
    cout << intToRoman(3749) << endl; // Output: "MMMDCCXLIX"
    cout << intToRoman(58) << endl;   // Output: "LVIII"
    cout << intToRoman(1994) << endl; // Output: "MCMXCIV"

    return 0;
}
