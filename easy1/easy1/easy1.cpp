#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        }
        else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    std::vector<int> nums1 = { 1, 3, 5, 7, 0, 0, 0 };
    std::vector<int> nums2 = { 2, 4, 6 };
    int m = 4;
    int n = 3;

    merge(nums1, m, nums2, n);

    std::cout << "Merged array: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }

    return 0;
}
