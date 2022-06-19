#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int,double> a,const pair<int,double> b)
{
    return a.second>b.second;
}
int main()
{
    int N,W; 
    cin>>N;
    vector<int> val(N);
    vector<int> wt(N);
    for(int i=0;i<N;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>wt[i];
    }
    cin>>W;
    double ans=0;
    vector<pair<int,double> > vp;
    for (int i=0;i<N;i++)
    {
        vp.push_back(make_pair(i,(double)val[i]/wt[i]));
    }
    sort(vp.begin(), vp.end(), compare);

    for (int i=0;i<N;i++)
    {
        if(W>=wt[vp[i].first])
        {
            ans+=val[vp[i].first];
            W-=wt[vp[i].first];
            continue;
        }
        ans+=W*vp[i].second;
        break;
    }
    cout<<"Maximum Value "<<ans << endl;
    return 0;
}