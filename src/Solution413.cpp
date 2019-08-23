#include "utils.hpp"
/*
 * Intution:
 *  dp
 */
class Solution413 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ret = 0;
        int dp = 0;
        for (size_t i = 2; i < A.size(); i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp += 1; 
            } else {
                dp = 0;
            }
            ret += dp;
        }
        return ret;
    }
};
