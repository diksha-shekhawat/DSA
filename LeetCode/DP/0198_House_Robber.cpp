/*
=========================================================
LeetCode 198. House Robber
Difficulty: Medium

Problem:
You are a robber planning to rob houses along a street.
Each house has a certain amount of money.

Constraint:
You cannot rob two adjacent houses.

Goal:
Find the maximum amount of money you can rob.

Example:
nums = [2,7,9,3,1]

Rob house 1 (2), house 3 (9), house 5 (1)

Answer = 12
=========================================================
*/

class Solution {
public:

    /*
    =========================================================
    APPROACH 1 : BRUTE FORCE (Recursion)

    At every house we have 2 choices:

    1. Rob current house
       -> Add current money
       -> Move to i + 2

    2. Skip current house
       -> Move to i + 1

    Take maximum of both choices.

    Recurrence:

    f(i) = max(
                nums[i] + f(i+2),
                f(i+1)
              )

    Time Complexity:
    O(2^n)

    Reason:
    Every index branches into two recursive calls.

    Space Complexity:
    O(n)
    (Recursion stack)

    This solution gives TLE for large inputs.
    =========================================================

    int solve(vector<int>& nums, int i){

        if(i >= nums.size())
            return 0;

        int take = nums[i] + solve(nums, i+2);

        int skip = solve(nums, i+1);

        return max(take, skip);
    }

    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
    */


    /*
    =========================================================
    APPROACH 2 : BETTER (Memoization / Top-Down DP)

    Problem in brute force:
    Same states are solved multiple times.

    Example:
    f(2) may be computed from many paths.

    Idea:
    Store already computed answers in dp[].

    dp[i] = maximum money that can be robbed
            starting from index i

    Before solving a state:
    Check if it already exists.

    Time Complexity:
    O(n)

    Space Complexity:
    O(n) -> DP array
    O(n) -> Recursion stack

    Much faster than brute force.
    =========================================================

    int solve(vector<int>& nums, int i, vector<int>& dp){

        if(i >= nums.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(nums, i+2, dp);

        int skip = solve(nums, i+1, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return solve(nums, 0, dp);
    }
    */


    /*
    =========================================================
    APPROACH 3 : OPTIMAL (Space Optimized DP)

    Observation:

    DP Relation:

    dp[i] = max(
                nums[i] + dp[i-2],
                dp[i-1]
              )

    To calculate current state,
    we only need:

    dp[i-1]
    dp[i-2]

    Therefore we don't need the entire dp array.

    Variables:

    prev1 = dp[i-1]
    prev2 = dp[i-2]

    Example:

    nums = [2,7,9,3,1]

    Index 0:
    prev1 = 2

    Index 1:
    max(7,2) = 7

    Index 2:
    max(9+2,7) = 11

    Index 3:
    max(3+7,11) = 11

    Index 4:
    max(1+11,11) = 12

    Answer = 12

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)

    Best Solution
    =========================================================
    */

    int rob(vector<int>& nums) {

        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for(int num : nums){

            // If we rob current house
            int take = num + prev2;

            // If we skip current house
            int skip = prev1;

            // Best choice till current house
            int curr = max(take, skip);

            // Move DP window forward
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};