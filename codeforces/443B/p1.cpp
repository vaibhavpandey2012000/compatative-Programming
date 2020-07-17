#include<bits/stdc++.h>
using namespace std;
int s,d;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>s>>d;
		int p=s;
		while(p<=ans){
			p+=d;
		}
		ans=p;
	}
	cout<<ans<<endl;
}