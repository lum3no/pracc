#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return canGet24(nums);
    }

    bool canGet24(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6; // Check if the single number is 24 (floating point comparison)
        }

        int n = nums.size();

        // Try all permutations of nums
        sort(nums.begin(), nums.end());
        do {
            // Try all operator combinations
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    vector<double> next_nums;
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            next_nums.push_back(nums[k]);
                        }
                    }

                    for (double operand : getOperators(nums[i], nums[j])) {
                        next_nums.push_back(operand);
                        if (canGet24(next_nums)) {
                            return true;
                        }
                        next_nums.pop_back();
                    }
                }
            }
        } while (next_permutation(nums.begin(), nums.end()));

        return false;
    }

    vector<double> getOperators(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (b != 0) results.push_back(a / b);
        if (a != 0) results.push_back(b / a);
        return results;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<vector<int>> testCases = {
        {4, 1, 8, 7},
        {1, 2, 1, 2},
        {3, 3, 8, 8}
    };

    for (auto& cards : testCases) {
        bool result = solution.judgePoint24(cards);
        cout << "Input: [";
        for (int i = 0; i < 4; ++i) {
            cout << cards[i];
            if (i < 3) cout << ", ";
        }
        cout << "] -> Output: " << (result ? "true" : "false") << endl;
    }

    return 0;
}
