#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAX 20;
int compare(const void *a,const void *b)
{ 
    return (*(char *)a-*(char *)b);
}
void swap(char* a,char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
int findCeil(char str[],char first,int l,int h)
{
    int ceilIndex=l;
    for(int i=l+1;i<=h;i++)
        if(str[i]>first && str[i]<str[ceilIndex])
            ceilIndex=i;

    return ceilIndex;
}
void reverse(char str[],int l,int h)
{
	while(l<h)
	{
		swap(&str[l],&str[h]);
		l++;
		h--;
	}
}
void sortedPermutations(char str[])
{
	int size=strlen(str);
	qsort(str,size,sizeof(str[0]),compare);
	bool isFinished=false;
	while(!isFinished)
	{
		cout<<str<<endl;
		int i;
		for(i=size-2;i>=0;i--)
		    if(str[i]<str[i+1])
			    break;

		if(i==-1)
			isFinished=true;
		else
		{
			int ceilIndex=findCeil(str,str[i],i+1,size-1);
			swap(&str[i],&str[ceilIndex]);
			reverse(str,i+1,size-1);
		}
	}
}
int main()
{
    char str[20];
    cin>>str;
    cout<<"all possible permutations in lexicographic order are :"<<endl;
    sortedPermutations(str);
    return 0;
}