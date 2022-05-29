#include <iostream>
using namespace std;
int paritition(int arr[],int l,int r) 
{
    int i,j,pivot;
    pivot=arr[r];
    i=l-1;
    for(j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int kthSmallest(int arr[],int l,int r,int k) 
{
    int parIndex=paritition(arr,l,r); 
    if(parIndex==k-1)
        return arr[parIndex]; 
    if(parIndex>k-1)
        return kthSmallest(arr,l,parIndex-1,k);
    else
        return kthSmallest(arr,parIndex+1,r,k); 
}
int main() 
{
    int T,N,K;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        cin>>K;
        if(K>N)
            cout<<"not present";
        else
        {
            cout<<kthSmallest(A,0,N-1,K)<<endl;
        }
    }
    return 0;
}
