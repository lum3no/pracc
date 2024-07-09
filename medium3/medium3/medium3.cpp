#include <iostream>
#include <vector>
#include <algorithm>

int robLinear(std::vector<int>& nums) {
    int rob1 = 0;
    int rob2 = 0;

    // [rob1, rob2, n, n+1, ...]
    for (int n : nums) {
        int temp = std::max(rob1 + n, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}

int robCircular(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    std::vector<int> nums1(nums.begin(), nums.end() - 1);
    std::vector<int> nums2(nums.begin() + 1, nums.end());
    return std::max(robLinear(nums1), robLinear(nums2));
}

int main() {
    std::vector<int> nums = { 2, 3, 2 }; // Пример массива с деньгами в домах
    std::cout << "Максимальная сумма денег, которую можно украсть: " << robCircular(nums) << std::endl;
    return 0;
}
