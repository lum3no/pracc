#include <iostream>
#include <vector>
#include <string>

int numDistinct(std::string s, std::string t) {
    int m = t.length(), n = s.length();
    std::vector<std::vector<unsigned long>> dp(m + 1, std::vector<unsigned long>(n + 1, 0));

    // Каждая строка содержит пустую подпоследовательность
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string s = "rabbbit";
    std::string t = "rabbit";
    std::cout << "Количество уникальных подпоследовательностей: " << numDistinct(s, t) << std::endl;
    return 0;
}
