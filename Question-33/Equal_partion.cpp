#include <iostream>
using namespace std;

bool subsetsum(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

bool Equal_Sum_Partition(int arr[],int n)
{
    int sum=0;

    for(int i=0;i<n;i++)
        sum+=arr[i];

    if(sum%2== 1)
        return false;

    return subsetsum(arr,sum/2,n);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(Equal_Sum_Partition(arr,n)==true)
        cout<<"Can be divided into two subsets of equal sum"<<endl;
    else
        cout<<"Can not be divided into two subsets of equal sum"<<endl;
    return 0;
}