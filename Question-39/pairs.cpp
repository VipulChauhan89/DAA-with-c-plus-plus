#include <iostream>
#include <vector> 
#include <map>
using namespace std;
bool algo(int n,vector<int> arr)
{
    map<int,pair<int,int> > Hash;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int mul=arr[i]*arr[j];
            if(Hash.find(mul)==Hash.end())
                Hash[mul]=make_pair(i,j);
            else 
            {
                pair<int,int> pp=Hash[mul]; 
                cout<<arr[pp.first]<<" "<<arr[pp.second]<<endl<<arr[i]<<" "<<arr[j]<<endl;
                return true;
            }
        }
    }
    cout<<"No pairs found";
    return false;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Output : "<<endl;
    algo(n,arr);
    return 0;
}