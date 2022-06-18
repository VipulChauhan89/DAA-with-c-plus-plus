#include <iostream>
#include <vector>
using namespace std;

int minnode(int n,int keyval[],bool mstset[]) 
{
    int mini=numeric_limits<int>::max();
    int mini_index;
    for (int i=0;i<n;i++) 
    {
	    if(mstset[i]==false && keyval[i]<mini) 
        {
	        mini=keyval[i],mini_index=i;
	    }
    }
    return mini_index;
}
void findcost(int n,vector<vector<int> > city) 
{
    int parent[n];
    int keyval[n];
    bool mstset[n];
    for (int i=0;i<n;i++) 
    {
	    keyval[i]=numeric_limits<int>::max();
	    mstset[i]=false;
    }
    parent[0]=-1;
    keyval[0]=0;
    for(int i=0;i<n-1;i++) 
    {
	    int u=minnode(n,keyval,mstset);
	    mstset[u]=true;
	    for(int v=0;v<n;v++) 
        {
	        if(city[u][v] && mstset[v]==false && city[u][v]<keyval[v]) 
            {
		        keyval[v]=city[u][v];
		        parent[v]=u;
	        }
	    }
    }
    int cost=0;
    for(int i=1;i<n;i++)
	    cost+=city[parent[i]][i];
    cout<<"Minimum Spanning Weight : "<<cost<<endl;
}
int main() 
{
    int V,E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    vector<vector<int> > g(V,vector<int> (V,0));
    cout<<"Enter the number of edges in the graph : ";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cout<<"Enter the "<<i+1<<" edge and weight of the edge : ";
        cin>>u>>v>>w;
        g[u][v]=w;
        g[v][u]=w;
    }
    findcost(V,g);
return 0;
}
