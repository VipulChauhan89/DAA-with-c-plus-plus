#include <iostream>
using namespace std;
int merge(int *arr,int l,int mid,int h,int *comp) 
{
    int inver=0;
    int i=l,j=mid+1,k=l;
    int temp[h+1];
    while(i<=mid && j<=h) 
    {
        (*comp)++; 
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++]; 
        }
        else 
        {
            inver+=(mid+1-i);
            temp[k++]=arr[j++]; 
        }
    }
    while(i<=mid) 
    {
        temp[k++]=arr[i++]; 
    }
    while(j<=h) 
    {
        temp[k++]=arr[j++]; 
    }
    for(int p=l;p<=h;p++) 
    {
        arr[p]=temp[p]; 
    } 
    return inver; 
}
int mergesort(int *arr,int l,int h,int *comp)
{
    int mid;
    int inver=0;
    if(l<h) 
    {
        mid=(l+h)/2;
        inver+=mergesort(arr,l,mid,comp); 
        inver+=mergesort(arr,mid+1,h,comp);
        inver+=merge(arr,l,mid,h,comp); 
    }
    return inver; 
}
int main() 
{
    int N,T;
    cin>>T;
    while(T--)
    {
        int comp=0,inver=0;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
        {
            cin>>arr[i]; 
        }
        inver=mergesort(arr,0,N-1,&comp);
        for(int i=0;i<N;i++)
        {
            cout<<arr[i]<<" "; 
        }
        cout<<endl;
        cout<<"Comparison :- "<<comp<<endl<<"Inversion :- "<<inver<<endl;
    }
    return 0;
}
