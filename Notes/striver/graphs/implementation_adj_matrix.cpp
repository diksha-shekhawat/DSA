#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    vector<vector<int>> adjMatrix(n+1,vector<int>(n+1,0));
    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Enter the edges (u v): "<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v]=1; // For directed graph
        adjMatrix[v][u]=1; // For undirected graph, comment this line for directed graph
    }
    cout<<"Adjacency Matrix: "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}