#include<iostream>
#include<string>
using namespace std;
void rec1(int n){
    if (n==0) return;
    cout<<"i"<<endl;
    n--;
    rec1(n);
}
void f1(int i,int n){//print 1 to n using forward recursion
    if (i>n) return;
    cout<<i<<endl;
    f1(i+1,n);

}
void f2(int i,int n){//print n to 1 using forward recursion
    if (i<1) return;
    cout<<i<<endl;
    f2(i-1,n);
}
//recursion are of two types: forward and backtracking 
//backtracking means go forward with recursion and do work while coming back 
void f3(int i,int n){//print n to 1 using backtracking
    if(i<1) return;
    f3(i-1,n);
    cout<<i;
}
void f4(int i,int n){//print 1 to n using backtracking
    if(i>n) return ;
    f4(i+1,n);
    cout<<i;
}
void f5(int i,int sum){ //sumof first i numbers : paramteerized sum
    if (i<1){
        cout<<sum;
        return;
    }
    f5(i-1,sum+i);
}
int f6(int n){ //sum of first n numbers : using functional recursion
    if(n==0) return 0;
    return n+f6(n-1);
}
int fact(int n){//factorial using recursion 
    if(n==0) return 1;
    return n*fact(n-1);
}
void rev(int arr[],int l,int r){ //reverse an array using recursion
    if(l>=r) return;
    int temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
    rev(arr,l+1,r-1);
}
bool palindrome(int i,string &str){ //check if a string is palindrome using recursion
    int n=str.size();
    if(i>=n/2) return true;
    if(str[i]!=str[n-i-1]){
        return false;
    }
    return palindrome(i+1,str);

}
int main(){
    int n=5;
   rec1(n);
   f1(1,n);
   f2(n,n);
   f3(n,n);//backtracking
   cout<<endl;
   f4(1,n);//backtracking
   cout<<endl;
   f5(n,0);//parameteried sum of first n numbers
   cout<<endl;
   int sum=f6(n);//functional recursion  for sum of n numbers
   cout<<sum;
   cout<<endl;
   cout<<fact(n)<<endl;//factorial
   int arr[]={1,2,3,4,5};
   rev(arr,0,4);
   for(int i=0;i<n;i++){
    cout<<arr[i];
   }
   cout<<endl;
   string str="madam";
   cout<<palindrome(0,str)<<endl;

    return 0;
}