#include <iostream>
#include <vector>
using namespace std;

class DSU 
{
public:
	int* parent;
	int* rank;
	DSU(int n)
	{
		parent=new int[n];
		rank=new int[n];

		for(int i=0;i<n;i++) 
        {
			parent[i]=-1;
			rank[i]=1;
		}
	}
	int find(int i)
	{
		if(parent[i]==-1)
			return i;
		return parent[i]=find(parent[i]);
	}
	void unite(int x,int y)
	{
		int s1=find(x);
		int s2=find(y);

		if(s1!=s2) 
        {
			if(rank[s1]<rank[s2]) 
            {
				parent[s1]=s2;
				rank[s2]+=rank[s1];
			}
			else 
            {
				parent[s2]=s1;
				rank[s1]+=rank[s2];
			}
		}
	}
};

class Graph 
{
public:
	vector<vector<int> > edgelist;
	int V;
	Graph(int V) 
    { 
        this->V=V; 
    }
	void addEdge(int x,int y,int w)
	{
		edgelist.push_back({w,x,y});
	}
	void kruskals_mst()
	{
		sort(edgelist.begin(),edgelist.end());
		DSU s(V);
		int ans = 0;
		cout<<"Following are the edges in the constructed MST"<< endl;
		for(auto edge : edgelist) 
        {
			int w=edge[0];
			int x=edge[1];
			int y=edge[2];
			if(s.find(x)!= s.find(y)) 
            {
				s.unite(x,y);
				ans+=w;
				cout<<x<<" -- "<<y<<" == "<<w<< endl;
			}
		}
		cout<<"Minimum Cost Spanning Tree: "<<ans<<endl;
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
    g.kruskals_mst();
	return 0;
}

