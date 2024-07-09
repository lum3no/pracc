#include <iostream>
using namespace std;

int countOnes(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j > 0) {
            if (j % 10 == 1) {
                count++;
            }
            j /= 10;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Введите число n: ";
    cin >> n;
    cout << "Общее количество цифр 1 во всех неотрицательных целых числах, меньших или равных " << n << ", равно: " << countOnes(n) << endl;
    return 0;
}
