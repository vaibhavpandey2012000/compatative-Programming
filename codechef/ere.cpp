#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			long long temp;
			cin>>temp;
			if(temp%2!=0)
			ans^=temp;
			
			
		}
		if(ans==0)
		cout<<"Second"<<endl;
		else
		cout<<"First"<<endl;
	}
}
