#include<iostream>
#include<vector>
using namespace std;
vector<int> pairs(int *a,int n)
{
    vector<int> A;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(a[i]+a[j]==a[k])
                {
                    A.push_back(i);
                    A.push_back(j);
                    A.push_back(k);
                }
            }
        }
    }
    return A;
}
int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        vector<int> B=pairs(A,N);
        if(B.size()==0)
        {
            cout<<"No Sequence found"<<endl;
        }
        else
        {
            for(int i=0;i<B.size();i++)
            {
                if(i%3!=0 ||i==0)
                {
                    cout<<B[i]<<" ";
                }
                else
                {
                    cout<<" and ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
