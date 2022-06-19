#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define INF INT_MAX
using namespace std;

class Graph
{
    public:
        int V;
        vector<vector<int> > edges;
        vector<int> parent;
        Graph(int V)
        {
            this->V=V;
            parent.assign(V,-1);
        }
        void addEdge(int u,int v,int w)
        {
            edges.push_back({u,v,w});
        }
        void print_path(int j)
        {
            if(parent[j]==-1)
            {
                return;
            }
            print_path(parent[j]);
            cout<<j<<" ";
        }
        void bellmanFord(int src)
        {
            vector<int> dist(this->V,INF);
            dist[src]=0;
            for(int i=0;i<this->V-1;i++)
            {
                for(auto e:edges)
                {
                    int u=e[0];
                    int v=e[1];
                    int w=e[2];
                    int c=dist[v];
                    dist[v]=min(dist[v],dist[u]+w);
                    parent[v]=(c==dist[v])?parent[v]:u;
                }
            }
            for(int i=0;i<this->V;i++)
            {
                cout<<src<<" ";
                print_path(i);
                cout<<" : "<<dist[i]<<endl;
            }
        } 
};
int main()
{
    int V,E,s;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    Graph g(V);
    cout<<"Enter the number of edges in the graph : ";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cout<<"Enter the "<<i+1<<" edge and weight of the edge : ";
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    cout<<"Enter the source vertex : ";
    cin>>s;
    g.bellmanFord(s);
    return 0;
}