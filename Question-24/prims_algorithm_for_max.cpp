#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int V;
int findMaxVertex(bool visited[], int weights[])
{
	int index=-1;
	int maxW=INT_MIN;
	for (int i=0;i<V;i++) 
    {
		if(visited[i]==false && weights[i]>maxW) 
        {
			maxW=weights[i];
			index = i;
		}
	}
	return index;
}
void printMaximumSpanningTree(vector<vector<int> > graph,int parent[])
{
	int MST = 0;
	for(int i=1;i<V;i++) 
    {
		MST+=graph[i][parent[i]];
	}
	cout<<"Weight of the maximum Spanning-tree "<<MST<<endl;
	cout << "Edges \tWeight\n";
	for(int i=1;i<V;i++) 
    {
		cout<<parent[i]<<" - "<<i<<" \t"<< graph[i][parent[i]]<<endl;
	}
}
void maximumSpanningTree(vector<vector<int> > graph)
{
	bool visited[V];
	int weights[V];
	int parent[V];
	for (int i=0;i<V;i++) 
    {
		visited[i]=false;
		weights[i]=INT_MIN;
	}
	weights[0]=INT_MAX;
	parent[0]=-1;
	for (int i=0;i<V-1;i++) 
    {
		int maxVertexIndex=findMaxVertex(visited,weights);
		visited[maxVertexIndex]=true;
		for (int j=0;j<V;j++) 
        {
			if (graph[j][maxVertexIndex]!=0 && visited[j]==false) 
            {
				if (graph[j][maxVertexIndex]>weights[j]) 
                {
					weights[j]=graph[j][maxVertexIndex];
					parent[j]=maxVertexIndex;
				}
			}
		}
	}
	printMaximumSpanningTree(graph,parent);
}
int main()
{
	int E;
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
    maximumSpanningTree(g);
	return 0;
}