#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    int solve(int n){ //brute force using recursion
        if(n<0) return 0;
        if(n==0) return 1;
        int oneStep=solve(n-1);
        int twoStep=solve(n-2);
        return oneStep+twoStep;
    }
    int solve2(int n,vector<int> &dp){ //Top-Down Dynamic Programming (Memoization).
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int oneStep=solve2(n-1,dp);
        int twoStep=solve2(n-2,dp);
        return dp[n]= oneStep+twoStep;
    }
    int solve3(int n){ //Bottom-Up Dynamic Programming (Tabulation). 
        vector<int> dp(n+1,0);
        dp[0]=1; // Base case: There is one way to climb 0 steps (do nothing)
        if(n>=1) dp[1]=1; // Base case: There is one way to climb 1 step (take one step)
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]; // The number of ways to climb i steps is the sum of the ways to climb (i-1) and (i-2) steps
        }
        return dp[n];
    }
    int solve4(int n){ //Space Optimized Dynamic Programming
        if(n==0) return 1;
        if(n==1) return 1;
        int prev2=1; // Represents the number of ways to climb (i-2) steps
        int prev1=1; // Represents the number of ways to climb (i-1) steps
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2; // The number of ways to climb i steps is the sum of the ways to climb (i-1) and (i-2) steps
            prev2=prev1; // Update prev2 to be the previous prev1
            prev1=curr; // Update prev1 to be the current number of ways
        }
        return prev1; // Return the number of ways to climb n steps
    }
    int climbStairs(int n) {
        
        //return solve(n);
        vector<int> dp(n+1,-1);
        return solve2(n,dp);
        //return solve3(n);
        //return solve4(n);

    }
};