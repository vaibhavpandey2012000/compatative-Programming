#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,x;
	cin>>n>>x;
	vector<long>v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	sort(v.begin(),v.end());
	int flag=0;
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			cout<<v[i]<<" "<<v[j]<<endl;
			long pp=x-v[i]-v[j];
			int p=lower_bound(v.begin()+j+1,v.end(),pp)-v.begin();
			cout<<pp<<" "<<v[p]<<endl;
			if(v[p]==pp)
			{
				cout<<i+1<<" "<<j+1<<" "<<p+1<<endl;
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	if(flag==0)
	cout<<"IMPOSSIBLE"<<endl;
}
