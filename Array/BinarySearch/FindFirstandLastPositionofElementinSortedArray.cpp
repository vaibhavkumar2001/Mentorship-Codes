#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindFirstOccurence(vector<int>&nums,int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                ans = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
    int FindLastOccurence(vector<int>&nums,int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        } 
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIndex = FindFirstOccurence(nums,target);
        int lastIndex = FindLastOccurence(nums,target);
        return {firstIndex,lastIndex};
    }
};

int main() {
        Solution sol;
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;
        vector<int> result = sol.searchRange(nums,target);
        cout << "First Occurrence: " << result[0] << endl;
        cout << "Last Occurrence: " << result[1] << endl;
        return 0;
    }