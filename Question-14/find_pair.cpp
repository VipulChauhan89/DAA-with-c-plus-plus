#include <iostream>
#include <vector> 
using namespace std;
vector<int> twoSum(int arr[],int n,int k) 
{
    int st=0,end=n-1; 
    vector<int> ans;
    while(st<end)
    {
        if(arr[st]+arr[end]==k) 
        {
            ans.push_back(arr[st]); 
            ans.push_back(arr[end]); 
            return ans;
        }
        else if(arr[st]+arr[end]>k)
            end--; 
        else
            st++; 
    }
    return ans; 
}
void merge(int *arr,int l,int mid,int h) 
{
    int i=l,j=mid+1,k=l;
    int temp[h+1];
    while(i<=mid && j<=h) 
    {
        if(arr[i]<arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid) 
    {
        temp[k++] = arr[i++]; 
    }
    while(j<=h)
    {
        temp[k++] = arr[j++]; 
    }
    for(int p=l;p<=h;p++) 
    {
        arr[p]=temp[p];
    }
}
void merge_sort(int *arr,int l,int h) 
{
    if(l<h)
    {   
        int mid=(l+h)/2; 
        merge_sort(arr,l,mid); 
        merge_sort(arr,mid+1,h); 
        merge(arr,l,mid,h);
    } 
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
        merge_sort(A,0,N-1);
        cin>>key;
        vector<int> ans=twoSum(A,N,key); 
        if(ans.empty()==1)
        {
            cout<<"No Such Element Exist"<<endl; 
        }
        else
        {
            for(auto it:ans)
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0; 
}