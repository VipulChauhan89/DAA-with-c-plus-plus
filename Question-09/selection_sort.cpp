#include<iostream>
using namespace std;
void selectionSort(int *A,int N)
{
    int comp=0,swaps=0;
    for(int i=0;i<N-1;i++)
    {
        int min=i;
        for(int j=i+1;j<N;j++)
        {
            comp++;
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        swaps++;
        swap(A[min],A[i]);
    }
    for(int i=0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl<<"comparision = "<<comp<<endl<<"swaps = "<<swaps<<endl;
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
        selectionSort(A,N);
    }
    return 0;
}
