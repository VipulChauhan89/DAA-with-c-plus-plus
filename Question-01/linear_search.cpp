#include<iostream>
using namespace std;
int main()
{
	int N,T,search,count;
	cin>>T;
	while(T--)
	{
		count=0;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		cin>>search;
		for(int i=0;i<N;i++)
		{
			if(search==arr[i])
			{
				cout<<"Present "<<count+1<<endl;
				break;
			}
			count++;
		}
		if(count==N)
		{
			cout<<"Not Present "<<N<<endl;
		}

	}
	return 0;
}
