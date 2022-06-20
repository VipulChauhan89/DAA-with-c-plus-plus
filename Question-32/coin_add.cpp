#include <iostream>
using namespace std;

int count(int S[], int m, int n)
{
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(m<=0 && n>=1)
		return 0;
	return count(S,m-1,n)+count(S,m,n-S[m-1]);
}
int main()
{
	int N,num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    cin>>N;
	cout<<count(arr,num,N)<<endl;
	return 0;
}