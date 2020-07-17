#include<bits/stdc++.h>
using namespace std;
int count_set(int ans)
{
	int as=0;
	while((ans&1)!=1)
	{
		as++;
		ans=ans>>1;
	}
		return as;
}
void count_num(vector<int> &v,int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=ans^v[i];
	}
	int ss=count_set(ans);
	int mask=(1<<ss),ff=0;
//	cout<<mask<<endl;
	for(int i=0;i<n;i++)
	{
		if((v[i] & mask)==0)
		{
			ff ^=v[i];
		}
	}
	int se=ans^ff;
	if(ff>se)
		cout<<se<<" "<<ff<<endl;
	else
		cout<<ff<<" "<<se<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	count_num(v,n);
}