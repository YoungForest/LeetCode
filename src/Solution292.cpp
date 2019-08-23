#include "utils.hpp"
/*
 * 1: t
 * 2: t
 * 3: t
 * 4: f
 * 5: t -> 4
 * 6: t -> 4
 * 7: t -> 4
 * 8: f
 * all 4 * k: f
 * all other: t
 */
class Solution292 {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
