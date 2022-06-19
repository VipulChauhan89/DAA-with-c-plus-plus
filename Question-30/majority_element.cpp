#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,count=0,ans=0;
	cout<<"Enter the number of elements in an array : ";
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A,A+n);
	for(int i=1;i<n;i++)
	{
		if(A[i-1]==A[i])
		{
			count++;
			if(count>=n/2)
			{
				ans=A[i];
				break;
			}
		}
		else
		{
			count=0;
		}
	}
	(ans==0)?cout<<"No majority element found"<<endl:cout<<"Yes"<<endl<<ans<<endl;
	return 0;
}
