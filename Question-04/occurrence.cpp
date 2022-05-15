#include<iostream>
using namespace std;
int occurrence(int *arr,int n,int x)
{
    int *low=lower_bound(arr,arr+n,x);
    if(low==(arr+n)||*low!=x)
    {
        return 0;
    }
    int *high=upper_bound(arr,arr+n,x);
    return high-low;
}
int main()
{
    int T,N,search;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        cin>>search;
        cout<<search<<"-"<<occurrence(arr,N,search)<<endl;
    }
}
