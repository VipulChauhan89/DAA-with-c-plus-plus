#include <iostream>
#include <list>
#include <queue>
#include <climits>
#define INF INT_MAX
using namespace std;

typedef pair<int,int> myPair;
class Graph
{
    public:
        int V;
        list<myPair> *adj;
        vector<int> parent;
        Graph(int V)
        {
            this->V=V;
            adj=new list<myPair>[this->V];
            parent.assign(V,-1);
        }
        void addEdge(int u,int v,int w)
        {
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        void print_path(int j)
        {
            if(parent[j]==-1)
            {
                return;
            }
            print_path(parent[j]);
            cout<<j<<"->";
        }
        void dijkstra_shortest_path(int src)
        {
            priority_queue<myPair,vector<myPair>,greater<myPair> > pq;
            vector<int> dist(this->V,INF);
            dist[src]=0;
            list<myPair>::iterator it;

            pq.push(make_pair(0,src));
            while(!pq.empty())
            {
                int u=pq.top().second;
                pq.pop();

                for(it=adj[u].begin();it!=adj[u].end();++it)
                {
                    int v=it->first;
                    int w=it->second;
                    if(dist[v]>dist[u] + w)
                    {
                        dist[v]=dist[u] + w;
                        pq.push(make_pair(dist[v],v));
                        parent[v]=u;
                    }
                }
            }
            for(int i=0;i<this->V;i++)
            {
                cout<<src<<"->";
                print_path(i);
                cout<<" distance = "<<dist[i]<<endl;
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
    g.dijkstra_shortest_path(s);
    return 0;
}