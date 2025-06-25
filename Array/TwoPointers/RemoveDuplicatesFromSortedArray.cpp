#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 1;
        int j = 0;
        while (i < n) {
            if (nums[i] == nums[j]) {
                i++;
            } else {
                j++;
                nums[j] = nums[i];
                i++;
            }
        }
        return j + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    int newLength = sol.removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << "\nNew length: " << newLength << endl;

    return 0;
}
