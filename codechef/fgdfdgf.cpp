#include<bits/stdc++.h>
using namespace std;
const int maxN=100000;
int arr[maxN+1];
void seave(){
	for(int i=1;i<=maxN;i++)
	arr[i]=i;
	for(int i=2;i<=maxN;i++)
	{
		if(arr[i]==i)
		for(int j=i;j<=maxN;j+=i)
		{
			arr[j]/=i;
			arr[j]*=(i-1);
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
		cout<<arr[n]<<endl;
	}
	
}
