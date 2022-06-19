#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1]<b[1];
}

int main()
{
    int N; 
    cin>>N;
    vector<int> start(N);
    vector<int> finish(N);
    vector<int> selected;
    for(int i=0;i<N;i++)
    {
        cin>>start[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>finish[i];
    }
    vector<vector<int> > vp;
    for (int i=0;i<N;i++)
        vp.push_back({start[i],finish[i]});

    sort(vp.begin(),vp.end(),compare);
    int take=1;
    int end=vp[0][1];
    selected.push_back(1);
    for(int i=1;i<N;i++)
    {
        if(vp[i][0]>=end)
        {
            take++;
            end=vp[i][1];
            selected.push_back(i+1);
        }
    }
    cout<<"No. of non-conflicting activities : "<<take<<endl;
    cout<<"List of selected activities : ";
    for(auto i:selected)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}