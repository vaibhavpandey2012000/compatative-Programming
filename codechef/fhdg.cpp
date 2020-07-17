#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
	int n;
	cin>>n;
	vi a(n),b(n),ans;
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	int i=0,j=0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	while(i<n && j<n)
	{
		if(a[i]<b[j]) i++;
		else if(a[i]>b[j]) j++;
		else ans.push_back(a[i]) ,i++,j++;
	}
	cout<<"[";
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i<ans.size()-1)
		cout<<",";
	}
	cout<<"]"<<endl;
}
