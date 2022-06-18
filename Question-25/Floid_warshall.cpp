#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define INF INT_MAX

int V;
void printSolution(vector<vector<int> > dist)
{
	cout<<"The following matrix shows the shortest distances between every pair of vertices"<<endl;
	for(int i=0;i<V;i++) 
    {
		for(int j=0;j<V;j++) 
        {
			if(dist[i][j]==INF)
				cout<<"INF"<<" ";
			else if(i!=j)
				cout<<dist[i][j]<<" ";
            else
                cout<<0<<" ";
		}
		cout<<endl;
	}
}
void floydWarshall(vector<vector<int> > graph)
{
	vector<vector<int> > dist(V,vector<int>(V,INF));
    int i,j,k;
	for (i = 0;i<V;i++)
		for (j=0;j<V;j++)
			dist[i][j]=graph[i][j];
	for (k=0;k<V;k++) 
    {
		for(i=0;i<V;i++) 
        {
			for(j=0;j<V;j++) 
            {
				if(dist[i][j]>(dist[i][k]+dist[k][j]) && (dist[k][j]!=INF && dist[i][k] != INF))
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	printSolution(dist);
}
int main()
{
	int E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    vector<vector<int> > g(V,vector<int> (V,INF));
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
	floydWarshall(g);
	return 0;
}