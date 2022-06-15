#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void addEdge(vector<int> A[],int u,int v)
{
    A[u].push_back(v);
    A[v].push_back(u);
}
bool isBipartite(int V,vector<int>A[])
{
    vector<int> color(V,-1);
    queue<pair<int,int> > q;
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            q.push({i,0});
            color[i]=0;
            while(!q.empty())
            {
                pair<int,int> p=q.front();
                q.pop();
                int a=p.first;
                int b=p.second;
                for(int j:A[a])
                {
                    if(color[j]==b)
                    {
                        return 0;
                    }
                    if(color[j]==-1)
                    {
                        color[j]=(b)?0:1;
                        q.push({j,color[j]});
                    }
                }
            }
        }
    }
    return 1;
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
    if(isBipartite(V,A))
    {
        cout<<"Yes Bipertite"<<endl;
    }
    else
    {
        cout<<"Not Bipertite"<<endl;
    }
    return 0;
}