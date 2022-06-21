#include <iostream>
#include <vector> 
#include <set>
using namespace std;
 
bool check(vector<int> a,int n,int k)
{
    set<int> ans;
    for(int i=0;i<n;i++)
    {
        if(ans.find(a[i])!=ans.end())
        {
            return true;
        }
        ans.insert(a[i]);
        if(i>=k) 
            ans.erase(a[i-k]);
    }
    return false;
} 

 
void solve(){
    

}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cin>>k;
        if(check(arr,n,k))
            cout<<"Duplicate present in window "<<k<<endl;
        else 
            cout<<"Duplicate not present in window "<<k<<endl;
    }
    return 0;
}