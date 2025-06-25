#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (sum == target) {
                return {start + 1, end + 1}; // 1-based indexing
            }
            else if (sum < target) {
                start++;
            }
            else {
                end--;
            }
        }
        return {}; // Return empty if no solution
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(numbers, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers sum to the target." << endl;
    }

    return 0;
}
