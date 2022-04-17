#include<iostream>
using namespace std;
int main()
{
	int N,T,search,count,low,high,mid,flag;
	cin>>T;
	while(T--)
	{
		count=0;
		flag=0;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		cin>>search;
		low=0;
		high=N-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(search==arr[mid])
			{
				cout<<"Present "<<count<<endl;
				flag=1;
				break;
			}
			else if(search<arr[mid] )
			{
				high=mid-1;
				count++;
			}
			else
			{
				low=mid+1;
				count++;
			}
		}
		if(flag==0)
		{
			cout<<"Not Present "<<count<<endl;
		}
	}
	
	return 0;
}