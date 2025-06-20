#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1 + n2;
        int half = (total + 1) / 2;

        int start = 0, end = n1;

        while(start <= end) {
            int mid1 = (start + end) / 2;
            int mid2 = half - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if(l1 <= r2 && l2 <= r1) {
                if(total % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if(l1 > r2) {
                end = mid1 - 1;
            } else {
                start = mid1 + 1;
            }
        }

        return 0.0; // should not reach here
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;

    return 0;
}
