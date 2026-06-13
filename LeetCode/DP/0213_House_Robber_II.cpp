#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
=========================================================
LeetCode 213. House Robber II
Difficulty: Medium

Prerequisite:
LeetCode 198. House Robber

This problem is an extension of House Robber I.

Key Difference:
In House Robber I, houses are arranged linearly.

In House Robber II, houses are arranged in a circle.

Therefore:
- First house and last house are adjacent.
- We cannot rob both together.

Observation:

Any valid solution must satisfy one of the following:

1. Exclude the last house
   -> Solve House Robber I on houses [0...n-2]

2. Exclude the first house
   -> Solve House Robber I on houses [1...n-1]

Final Answer:

max(
    rob houses [0...n-2],
    rob houses [1...n-1]
)

Thus, House Robber II is reduced to two
House Robber I problems.

Time Complexity: O(n)
Space Complexity: O(1)
=========================================================
*/
int solve(vector<int>& nums, int start, int end) {
    int prev2 = 0;
    int prev1 = 0;
    for(int i = start; i <= end; i++) {
        int take = nums[i] + prev2;
        int skip = prev1;
        int curr = max(take, skip);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}