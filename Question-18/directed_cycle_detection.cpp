#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int>A[],int u,int v)
{
    A[u].push_back(v);
}
bool isCycleUtil(vector<int> A[],int v,bool visited[],bool recStack[])
{
    if(visited[v]==false)
    {
        visited[v]=true;
        recStack[v]=true;
        for(auto i=A[v].begin();i!=A[v].end();i++)
        {
            if(!visited[*i] && isCycleUtil(A,*i,visited,recStack))
            {
                return true;
            }
            else if(recStack[*i])
            {
                return true;
            }
        }

    }
    recStack[v]=false;
    return false;
}
bool cycle(vector<int>A[],int V)
{
    bool visited[V];
    bool recStack[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        recStack[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && isCycleUtil(A,i,visited,recStack))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int V,E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    vector<int> A[V];
    cout<<"Enter the number of edges in the graph : ";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter the "<<i+1<<" edge : ";
        cin>>u>>v;
        addEdge(A,u,v);
    }
    if(cycle(A,V))
    {
        cout<<"Yes Cycle Exist"<<endl;
    }
    else
    {
        cout<<"No Cycle Exists"<<endl;
    }
    return 0;
}