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
		long mul=1;
		vector<int> v;
		while(n)
		{
			int rem=n%10;
			if(rem==0)
			{
				n/=10;
				mul*=10;
				continue;
			}
			int nm=rem*mul;
			n/=10;
			v.push_back(nm);
			mul*=10;
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		cout<<endl;
	}
}
