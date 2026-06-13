#include<iostream>
#include<string>
using namespace std;
void printS(int ind,int arr[],int n,vector<int> vec){//print all contiguous subsequences of an array using recursion
    int s=vec.size();
    if(ind==n){
        for(int i=0;i<s;i++){
            cout<<vec[i];
        }
        if (s==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    vec.push_back(arr[ind]);//take the element
    printS(ind+1,arr,n,vec);//move forward
    vec.pop_back();//remove the element 
    printS(ind+1,arr,n,vec);//not take the element and move forward
}
int main(){
    int arr[]={3,1,2};
    vector<int> vec;//empty vector to store the subsequences
    printS(0,arr,3,vec);
    return 0;
}