#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        
        // Find the first zero in the array
        //Maine Yahan pe yeh logic lagaya h ki maine sbse pehle 0 ki position find krke j ko i place krdiya maine
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If there is no zero, nothing to do
        if(j == -1) return;

        // Swap non-zero elements with the zero at position j
        //FIR MAINE I KO J KE AAGE PLACE KRDIAY FIR I NOT EQUAL TO ZERO H TOH MAIN SWAP KRDOONGA I KO AUR J KO 
        for(int i = j + 1; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    } 
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
