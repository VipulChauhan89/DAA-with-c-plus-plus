#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int> A[],int u,int v)
{
    A[u].push_back(v);
    A[v].push_back(u);
}
void dfs(vector<int> A[],int u,bool visited[])
{
    visited[u]=true;
    for(auto it=A[u].begin();it!=A[u].end();it++)
    {
        if(!visited[*it])
        {
            dfs(A,*it,visited);
        }
    }
}
int main()
{
    int V,E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    vector<int> A[V];
    bool visited[V];
    cout<<"Enter the number of edges in the graph : ";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter the "<<i+1<<" edge : ";
        cin>>u>>v;
        addEdge(A,u,v);
    }
    cout<<"Enter the Source : ";
    int source,destination;
    cin>>source;
    cout<<"Enter the Destination : ";
    cin>>destination;
    dfs(A,source,visited);
    if(visited[destination]==true)
    {
        cout<<"Yes Path Exist"<<endl;
    }
    else
    {
        cout<<"No Such Path Exist"<<endl;
    }
    return 0;
}