#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> wt,vector<int> val,int w,int n,vector<pair<int,int> > &vp)
{
    vector<vector<int> > t(n+1,vector<int>(w+1,-1));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i== 0 || j==0)
                t[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
}

int main()
{
    int n,w;
    cin>>n;
    vector<pair<int,int> > vp;
    vector<int> wt(n);
    vector<int> val(n);
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    cin>>w;
    cout<<"Maximum Profit :"<<knapsack(wt,val,w,n,vp)<<endl;
    return 0;
}