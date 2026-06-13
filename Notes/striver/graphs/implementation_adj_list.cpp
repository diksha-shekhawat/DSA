#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    vector<vector<int>> adjList(n+1);
    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Enter the edges (u v): "<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v); // For directed graph
        adjList[v].push_back(u); // For undirected graph, comment this line for directed graph
    }
    cout<<"Adjacency List: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(int j=0;j<adjList[i].size();j++){
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
}   