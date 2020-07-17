#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,d;
	cin>>n>>d;
	vector<int> ch(n);
	for(int i=0;i<n;i++)
	cin>>ch[i];
	sort(ch.begin(),ch.end());
	int ans=0;
	for(int i=0;i<n-1;i++)
	{
		cout<<i<<endl;
		if(ch[i+1]-ch[i]<=d)
		{
			ans++;
			i++;
		}
		
	}
	cout<<ans<<endl;
}