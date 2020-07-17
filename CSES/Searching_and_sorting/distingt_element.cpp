#include<bits/stdc++.h>
using namespace std;
// int main()
// {
// 	set<int> s;
// 	int n;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 		int temp;
// 		cin>>temp;
// 		s.insert(temp);
// 	}
// 	cout<<s.size()<<endl;
// }
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	sort(v.begin(),v.end());
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(v[i-1]!=v[i])
		cnt++;
	}
	cout<<cnt+1<<endl;
}