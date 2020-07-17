#include<bits/stdc++.h>
using namespace std;
int sign(int n)
{
	return (n<0)? -1:1;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int &e:v)
		cin>>e;
		long long sum=0;
		for(int i=0,j=0;i<n;)
		{
			while(j<n && sign(v[i])==sign(v[j]))
			j++;	
			sum+=*max_element(v.begin()+i,v.begin()+j);
			i=j;
		}
		cout<<sum<<endl;
	}
}