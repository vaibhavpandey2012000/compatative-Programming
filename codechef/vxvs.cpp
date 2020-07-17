#include<bits/stdc++.h>
using namespace std;
int nxt(int x)
{
	if(x%10==9) return x-9;
	return x+1;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		map<int,int>mp;
		int n;
		cin>>n;
		int arr[11];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			mp[arr[i]]++;
		}
		cout<<int(n-mp.size())<<endl;
		for(int i=0;i<n;i++)
		{
			--mp[arr[i]];
			while(mp[arr[i]]!=0)
			{
				arr[i]=nxt(arr[i]);
			}
			mp[arr[i]]++;
		}
		for(int i=0;i<n;i++)
		cout<<setfill('0')<<setw(4)<<arr[i]<<endl;
		
	}
}
