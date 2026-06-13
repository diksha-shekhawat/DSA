/*
 * PROBLEM: Climbing Stairs (Classic DP)
 * ------------------------------------
 * You are climbing a staircase. It takes 'n' steps to reach the top.
 * Each time you can either take 1 step or 2 steps.
 * In how many distinct ways can you climb to the top?
 *
 * THE CONCEPT: Dynamic Programming (Tabulation)
 * ---------------------------------------------
 * 1. Optimal Substructure: To reach step [i], you must have come 
 * from step [i-1] OR step [i-2].
 * 2. Overlapping Subproblems: Computing ways for step 5 involves 
 * computing step 4 and 3. Computing step 4 also involves step 3.
 * Instead of re-calculating step 3, we store it in a 'dp' table.
 *
* To reach step 'n', you must have made your last move from (n-1) or (n-2).
 * * n = 1: [1]                                     => 1 way
 * n = 2: [1+1], [2]                              => 2 ways
 * n = 3: ([1,1]+1), ([2]+1), ([1]+2)             => 3 ways
 * n = 4: ([1,1,1]+1), ([2,1]+1), ([1,2]+1),([1,1]+2), ([2]+2)    => 5 ways
 * 
 * * FORMULA:
 * Ways(n) = Ways(n-1) + Ways(n-2)
 */
/*
 * TIME COMPLEXITY: O(n) - We loop from 2 to n once.
 * SPACE COMPLEXITY: O(n) - We store results in a vector of size n+1.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Function to calculate total ways using DP Tabulation
 * parameter n: total number of steps
 * return: total distinct ways to reach the top
 */
long long solveClimbingStairs(int n) {
    // Edge Case: If steps are 0 or 1, there's only 1 way (do nothing or 1-step)
    if (n <= 1) return 1;

    // STEP 1: Define the DP Table
    // We use long long to prevent integer overflow for large 'n'
    vector<long long> dp(n + 1);

    // STEP 2: Initialize Base Cases
    // dp[i] represents "Number of ways to reach step i"
    dp[0] = 1; // Base ground
    dp[1] = 1; // Only one way to reach step 1

    // STEP 3: Fill the table using the Recurrence Relation
    // Total ways to step 'i' = (ways to step i-1) + (ways to step i-2)
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // STEP 4: Return the final state
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    if (!(cin >> n) || n < 0) {
        cout << "Please enter a valid non-negative integer." << endl;
        return 1;
    }

    long long result = solveClimbingStairs(n);
    
    cout << "------------------------------------" << endl;
    cout << "Total distinct ways to reach step " << n << ": " << result << endl;
    cout << "------------------------------------" << endl;

    return 0;
}