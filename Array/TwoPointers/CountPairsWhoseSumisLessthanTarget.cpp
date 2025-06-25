#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        //Brute Force sol 
        // int n = nums.size();
        // int count = 0;
        // for(int i = 0;i < n;i++) {
        //     for(int j = i + 1;j < n;j++) {
        //         if(nums[i] + nums[j] < target) {
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //Most Optimal SOl
        //pehle main sort kardoonga jisse ki main two pointer laga paoon 
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int count = 0;
        int right = n - 1;
        for(int i = 0;i < n;i++) {
            int j = i + 1;
            while(j < n && nums[i] + nums[j] < target) {

                j++;
            }
            count += (j - i - 1);
        }
        return count;
    }
};