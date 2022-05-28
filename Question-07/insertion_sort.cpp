#include<iostream>
using namespace std;
void insertionSort(int *A,int N)
{
    int comp=0,shift=0;
    for(int i=0;i<N;i++)
    {
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j]>key)
        {
            shift++;
            comp++;
            A[j+1]=A[j];
            j--;
        }
        shift++;
        A[j+1]=key;
    }
    shift--;
    for(int i=0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl<<"comparision = "<<comp<<endl<<"shifts = "<<shift<<endl;
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
        insertionSort(A,N);
    }
    return 0;
}
