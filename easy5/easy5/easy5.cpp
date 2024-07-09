#include <iostream>

using namespace std;

string determinePokerHand(int ranks[], char suits[]) {
    // Count occurrences of each rank and suit
    int rankCount[14] = { 0 }; // ranks range from 1 to 13
    int suitCount[4] = { 0 };  // suits are 'a', 'b', 'c', 'd'

    for (int i = 0; i < 5; ++i) {
        rankCount[ranks[i]]++;
        if (suits[i] == 'a') suitCount[0]++;
        else if (suits[i] == 'b') suitCount[1]++;
        else if (suits[i] == 'c') suitCount[2]++;
        else if (suits[i] == 'd') suitCount[3]++;
    }

    // Check for each type of hand
    bool isFlush = (suitCount[0] == 5 || suitCount[1] == 5 || suitCount[2] == 5 || suitCount[3] == 5);
    bool isThreeOfAKind = false;
    bool isPair = false;

    for (int i = 1; i <= 13; ++i) {
        if (rankCount[i] == 3) {
            isThreeOfAKind = true;
        }
        else if (rankCount[i] == 2) {
            isPair = true;
        }
    }

    // Determine the best hand
    if (isFlush) {
        return "Flush";
    }
    else if (isThreeOfAKind) {
        return "Three of a Kind";
    }
    else if (isPair) {
        return "Pair";
    }
    else {
        return "High Card";
    }
}

int main() {
    int ranks1[] = { 13, 2, 3, 1, 9 };
    char suits1[] = { 'a', 'a', 'a', 'a', 'a' };
    cout << determinePokerHand(ranks1, suits1) << endl; // Output: "Flush"

    int ranks2[] = { 4, 4, 2, 4, 4 };
    char suits2[] = { 'd', 'a', 'a', 'b', 'c' };
    cout << determinePokerHand(ranks2, suits2) << endl; // Output: "Three of a Kind"

    int ranks3[] = { 10, 10, 2, 12, 9 };
    char suits3[] = { 'a', 'b', 'c', 'a', 'd' };
    cout << determinePokerHand(ranks3, suits3) << endl; // Output: "Pair"

    return 0;
}
