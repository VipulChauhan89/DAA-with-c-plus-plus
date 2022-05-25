#include<iostream>
using namespace std;
int pairs(int *a,int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n && j!=i;j++)
        {
            if(abs(a[i]-a[j])==key)
            {
                count++;    
            }
        }
    }
    return count;
}
int main()
{
    int T,N,key;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        cin>>key;
        int B=pairs(A,N,key);
        if(B==0)
        {
            cout<<"No Sequence found"<<endl;
        }
        else
        {
            cout<<B<<endl;
        }
    }
    return 0;
}
