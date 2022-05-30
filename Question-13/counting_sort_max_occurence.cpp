#include<iostream>
#include<climits>
#include<vector> 
using namespace std;
int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        vector<char> v;
        char temp;
        cin>>N;
        for(int i=0;i<N;i++) 
        {
            cin>>temp; 
            v.push_back(temp);
        }
        vector<int> freq(26,0);
        for(auto it:v)
            freq[it-'a']++;
        int mx=INT_MIN,ind; 
        for(int i=0;i<26;i++) 
        {
            if(mx<freq[i])
            { 
                ind=i;
                mx=freq[i]; 
            }
        }
        if(mx!=1)
            cout<<char(ind+'a')<<"-"<<mx<<endl; 
        else
            cout<<"No Duplicate Present"<<endl; 
    }
    return 0;
}