#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int comp,swp;
int partion(int *arr,int l,int r)
{
    srand(time(NULL));
    int random=(l+rand())%(r+l);
    swap(arr[random],arr[r]);
    int i,j,pivot;
    pivot=arr[r];
    i=l-1;
    for(j=l;j<r;j++)
    {
        comp++;
        if(arr[j]<pivot)
        {
            i++;
            swp++;
            swap(arr[i],arr[j]);
        }
    }
    swp++;
    swap(arr[i+1],arr[r]);
    return i+1;
}
void randomize_quick_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pivot=partion(arr,l,r);
        randomize_quick_sort(arr,l,pivot-1);
        randomize_quick_sort(arr,pivot+1,r);
    }
    return;
}
int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        comp=0;
        swp=0;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        randomize_quick_sort(arr,0,N-1);
        for(int i=0;i<N;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl<<"comparision = "<<comp<<endl<<"swaps = "<<swp<<endl;
    }
    return 0;
}
