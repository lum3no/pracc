#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

int uniqueMorseRepresentations(std::vector<std::string>& words) {
    std::vector<std::string> morseCodes = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };

    std::unordered_set<std::string> transformations;

    for (const std::string& word : words) {
        std::string transformation;
        for (char c : word) {
            transformation += morseCodes[c - 'a'];
        }
        transformations.insert(transformation);
    }

    return transformations.size();
}

int main() {
    std::vector<std::string> words = { "gin", "zen", "gig", "msg" };
    std::cout << uniqueMorseRepresentations(words) << std::endl;

    return 0;
}
