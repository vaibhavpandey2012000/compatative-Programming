#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long a,b,c;
		cin>>a>>b>>c;
		long a1,b1,c1;
		cin>>a1>>b1>>c1;
		set<long>s;
		if(a!=a1) s.insert(a-a1);
		if(b!=b1) s.insert(b-b1);
		if(c!=c1) s.insert(c-c1);
		cout<<s.size()<<endl;
	}
}
