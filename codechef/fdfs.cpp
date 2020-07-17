#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,i;
	cin>>n>>x;
	int cnt=0;
	vector<int>v(n);
	for(i=0;i<n;i++)
	cin>>v[i];
//	v[i]=INT_MAX;
	sort(v.begin(),v.end());
	for(int i=0;i<n;)
	{
		if(v[i]+v[i+1]<=x)
		{
			i+=2;
		}
		else
		i++;
		cnt++;
	}
	cout<<cnt<<endl;
}
