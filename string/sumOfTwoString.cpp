#include<bits/stdc++.h>
using namespace std;
int j,k;
void print(string a,int arr[])
{
	int j=0;
	int rem=0;
	for(int i=a.length()-1;i>=0;i--)
	{
		int num=arr[j]+(a[i]-48)+rem;
		arr[j]=num%10;
		rem=num/10;
		j++;
	}
	while(rem)
	{
		arr[j]+=rem%10;
		rem=rem/10;
		j++;
	}
	k=j;	
}
int main()
{
	int tc;
	cin>>tc;
	int arr[200]={0,};
	while(tc--)
	{
		string a;
		cin>>a;
		print(a,arr);
	}
	for(int i=k-1;i>=0;--i)
	{
		cout<<arr[i];
	}
	cout<<endl;
//	cout<<k<<endl;
}