#include <iostream>
#include <vector>
using namespace std;
int fib(int n,vector<int> &dp){
    //time complexity is O(n)
    //space complexity O(n)
    if (n<=1){
        return n;
    }
    if (dp[n]!=-1) return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);

}
int fib2(int n){ //optimised
    //time complexity is O(n)
    //space complexity O(1)
      if (n<=1) return n;
      int prev1 =0, prev2=1;
      int curr;
      for(int i=2;i<=n;i++){
          curr=prev1+prev2;
          prev1=prev2;
          prev2=curr;
      }
      return curr;

}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp);
    cout<<endl;
    cout<<fib2(n);
    return 0;
}
