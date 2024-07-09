#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;
        return max(maxSum(slices, 0, slices.size() - 2, n), maxSum(slices, 1, slices.size() - 1, n));
    }

private:
    int maxSum(vector<int>& slices, int start, int end, int n) {
        int len = end - start + 1;
        vector<vector<int>> dp(len + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1) {
                    dp[i][j] = slices[start];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], (i >= 2 ? dp[i - 2][j - 1] : 0) + slices[start + i - 1]);
                }
            }
        }

        return dp[len][n];
    }
};

int main() {
    Solution solution;

    vector<int> slices1 = { 1, 2, 3, 4, 5, 6 };
    cout << "Maximum sum of slices (Example 1): " << solution.maxSizeSlices(slices1) << endl;

    vector<int> slices2 = { 8, 9, 8, 6, 1, 1 };
    cout << "Maximum sum of slices (Example 2): " << solution.maxSizeSlices(slices2) << endl;

    return 0;
}
