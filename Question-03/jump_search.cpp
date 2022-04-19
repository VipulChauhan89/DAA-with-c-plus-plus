#include<iostream>
using namespace std;
void linear_search(int *A,int i,int n,int search)
{
    for(;i<n;i++)
    {
        if(A[i]==search)
        {
            cout<<search<<" is found at index "<<i+1<<endl;
            return;
        }
    }
    cout<<search<<" is not found "<<endl;
}
void jump(int *A,int n,int search)
{
    int i;
    for(i=1;i<n;i=i*2)
    {
        if(A[i]>search)
        {
            break;
        }
    }
    linear_search(A,i/2,n,search);
}

int main()
{
    int N,T,search;
	cout<<"Enter the number of elements you want to enter in an array : ";
	cin>>N;
	int arr[N];
	cout<<"Enter "<<N<<" sorted elements : ";
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the element you want to search : ";
	cin>>search;
    jump(arr,N,search);
    return 0;
}