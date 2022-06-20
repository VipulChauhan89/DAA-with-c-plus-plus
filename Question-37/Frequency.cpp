#include <iostream>
#include <vector> 
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<char,int> m;
    vector<char> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        m[s[i]]++;
    }
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}