#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int arr[26]={0};
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			int pp=int(s[i]-'a');
			arr[pp]++;
		}
		while(q--)
		{
			int sum=0;
			int qq;
			cin>>qq;
			for(int i=0;i<26;i++)
			{
				if(arr[i]>0)
				{
					(arr[i]-qq)>0?sum+=arr[i]-qq:sum+=0;
				}
			}
			cout<<sum<<endl;
		}
	}
}
