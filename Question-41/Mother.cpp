#include <iostream>
#include <vector>
#include <list>
using namespace std;
 
class Graph
{
    public:
        int V;    
        list<int> *adj;   
        Graph(int V)
        {
            this->V=V;
            adj=new list<int>[V];
        }   
        void DFSUtil(int v, vector<bool> &visited)
        {
            visited[v]=true;
            list<int>::iterator i;
            for(i=adj[v].begin();i!=adj[v].end();i++)
                if(!visited[*i])
                    DFSUtil(*i,visited);
        }
        void addEdge(int v, int w)
        {
            adj[v].push_back(w); 
        }
        int findMother()
        {
            vector <bool> visited(V,false);
            int v=0;
            for(int i=0;i<V;i++)
            {
                if(visited[i]==false)
                {
                    DFSUtil(i,visited);
                    v=i;
                }
            } 
            fill(visited.begin(),visited.end(),false);
            DFSUtil(v,visited);
            for(int i=0;i<V;i++)
            if(visited[i]==false)
                return -1;
 
            return v;
        }
};
int main()
{
    int V,E,u,v;
    cout<<"Enter the number of vertices in the graph : ";
    cin>>V;
    Graph g(V);
    cout<<"Enter the number of edges in the graph : ";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter the edge "<<i+1<<" : ";
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<"A mother vertex is "<<g.findMother()<<endl;
    return 0;
}