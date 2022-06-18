#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define INF INT_MAX

int shortestPath(vector<vector<int> > graph, int s, int d, int k,int V)
{
    if(k==0 && s==d)			 
        return 0;
    if(k==1 && graph[s][d]!=INF) 
        return graph[s][d];
    if(k<=0)					 
        return INF;
        
    int res=INF;
    for(int i=0;i<V;i++)
    {
	    if (graph[s][i]!=INF && s!=i && d!=i)
	    {
		    int rec_res=shortestPath(graph,i,d,k-1,V);
		    if(rec_res!=INF)
			    res=min(res,graph[s][i]+rec_res);
	    }
    }
    return res;
}
int main()
{
    int V,E,s,d,k;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    vector<vector<int> > graph(V,vector<int>(V,0));
    cout<<"Enter the number of edges in the graph : ";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cout<<"Enter the "<<i+1<<" edge and weight of the edge : ";
        cin>>u>>v>>w;
        graph[u][v]=w;
    }
	cout<<"Enter the source vertex : ";
    cin>>s;
    cout<<"Enter the destination vertex : ";
    cin>>d;
    cout<<"Enter the number of edges in the path : ";
    cin>>k;
	int ans=shortestPath(graph,s,d,k,V);
    if(ans==0 || ans==INF)
    {
        cout<<"no path of length k is available"<<endl;
    }
    else
    {
        cout<<"Weight of shortest path from ("<<s<<","<<d<<") with "<<k<<" edges : "<<ans<<endl;
    }
}