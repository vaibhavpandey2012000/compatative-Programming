#include<bits/stdc++.h>
using namespace std;
vector<long>v;
void seave(){
	long sum=0;
	for(int i=1;i<=10000000;i++)
	{
		sum=(3*i*i+i)/2;
		if(sum>1000000000) break;
		v.push_back(sum);
	}
//	for(int i=0;i<=10;i++)
//	cout<<v[i]<<" ";
}
int main()
{
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		long n;
		cin>>n;
		int tot=0;
		while(n>1)
		{
			int i=0;
			for(;i<=v.size();i++)
			{
				if(n<v[i])
				break;
			}
			n=n-v[i-1];
			tot++;
		}
		cout<<tot<<endl;
	}
}
