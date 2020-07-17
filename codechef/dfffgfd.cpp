#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>p(n);
	for(int i=0;i<n;i++)
	cin>>p[i];
	sort(p.begin(),p.end());
	for(int i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		auto ff=lower_bound(p.begin(),p.end(),temp)-p.begin();
		auto ee=upper_bound(p.begin(),p.end(),temp)-p.begin();
		cout<<ff<<" "<<ee<<endl;
	}
}
