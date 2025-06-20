#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return 1;
        int start = 0, end = n;
        int ans = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;  // safer way to avoid overflow

            // At each step, calculate how many coins are needed to form mid complete rows.
            // Formula: 1 + 2 + 3 + ... + mid = mid × (mid + 1) / 2
            // Cast to long long to prevent integer overflow.
            
            long long coinsNeeded = (long long)mid * (mid + 1) / 2;
            if(coinsNeeded <= n) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    int result = sol.arrangeCoins(n);
    cout << "Maximum number of complete staircase rows: " << result << endl;
    return 0;
}
