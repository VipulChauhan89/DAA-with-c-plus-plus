#include<iostream>
using namespace std;

void merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=0;
    int temp[h-l+1];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=h)
        temp[k++]=a[j++];
    int x,y=0;
    for(x=l;x<=h;x++)
    {
        a[x]=temp[y];
        y++;
    }
}
void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid= (l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
    int T,N;
    string ans;
    cin>>T;
    while(T--)
    {
        ans="NO";
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        mergesort(A,0,N-1);
        for(int i=0;i<N-1;i++)
        {
            if(A[i]==A[i+1])
            {
                ans="YES";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
