#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    vector<int> ans;
    int m,n;
    cin>>m;
    int arr1[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }
    cin>>n;
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
     map<int,bool> h;
    for(int i=0;i<m;i++)
    {
        h[arr1[i]]=true;
    }
    for(int i=0;i<n;i++)
    {
        if(h[arr2[i]]==true)
        {
            ans.push_back(arr2[i]);
        }
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}