#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = -1, Count = 0;

        // Step 1: Find a potential candidate
        for(int i = 0; i < n; i++) {
            if(Count == 0) {
                Count = 1;
                element = nums[i];
            } else if(nums[i] == element) {
                Count++;
            } else {
                Count--;
            }
        }

        // Step 2: Verify if the candidate is truly a majority
        int count1 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == element) {
                count1++;
            }
        }

        if(count1 > n / 2) {
            return element;
        }

        return -1; // No majority element
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.majorityElement(nums);

    if(result != -1)
        cout << "Majority element is: " << result << endl;
    else
        cout << "No majority element found." << endl;

    return 0;
}
