#include<bits/stdc++.h>
using namespace std;
const int maxN=10000;
int arr[maxN+1];
void seave(){
	arr[1]=1;
	for(int i=2;i<=maxN;i++)
	{
		
		if(arr[i]==0)
		{	
			arr[i]=i;
			for(int j=i*i;j<=maxN;j+=i)	
			arr[j]=i;
		}
	}
}
int main()
{
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		while(n!=1)
		{
			cout<<arr[n]<<" ";
			n=n/arr[n];
		}
	}
}