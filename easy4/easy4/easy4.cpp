#include <iostream>
#include <vector>
#include <algorithm> // for std::min and std::max

using namespace std;

int lastRemainingElement(vector<int>& nums) {
    while (nums.size() > 1) {
        int n = nums.size();
        vector<int> newNums(n / 2);

        for (int i = 0; i < n / 2; ++i) {
            newNums[i] = min(nums[2 * i], nums[2 * i + 1]); // Even indices
        }

        for (int i = 0; i < n / 2; ++i) {
            newNums[i] = max(newNums[i], max(nums[2 * i], nums[2 * i + 1])); // Odd indices
        }

        nums = newNums;
    }

    return nums[0];
}

int main() {
    vector<int> nums = { 6, 2, 3, 4 };
    int result = lastRemainingElement(nums);
    cout << "Last remaining element: " << result << endl;

    return 0;
}
