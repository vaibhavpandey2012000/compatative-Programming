#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int ll,bb,n;
		cin>>ll>>bb>>n;
		vector<int> l,b;
		l.push_back(0) ,l.push_back(ll+1);
		b.push_back(0) ,b.push_back(bb+1);
		for(int i=0;i<n;i++)
		{
			int aa,bb;
			cin>>aa>>bb;
			l.push_back(aa) ;
			b.push_back(bb);
		}
		sort(l.begin(),l.end());
		sort(b.begin(),b.end());
		int ldiff=0,bdiff=0;
		for(int i=0;i<n+1;i++)
		{
			int aa=l[i+1]-l[i]-1;
			ldiff=max(ldiff,aa);
		}
		for(int i=0;i<n+1;i++)
		{
			int aa=b[i+1]-b[i]-1;
			bdiff=max(bdiff,aa);
		}
		cout<<ldiff*bdiff<<endl;
		
	}
}