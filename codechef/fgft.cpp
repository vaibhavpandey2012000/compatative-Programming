#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<ll> v(n);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	sort(v.begin(),v.end());
	ll mid=sum/n;
//	cout<<mid<<endl;
	int ind1=lower_bound(v.begin(),v.end(),mid)-v.begin();
	int ind2=upper_bound(v.begin(),v.end(),mid)-v.begin();
//	for(int i=0;i<n;i++)
//	cout<<v[i]<<" ";
//	cout<<endl;
//	cout<<ind1<<" "<<ind2<<endl;
	if(ind1==ind2)
	ind2++;
	ll ele1=v[ind1],ele2=v[ind2],s1=0,s2=0;
	for(int i=0;i<n;i++)
	{
		s1+=abs(v[i]-ele1);
		s2+=abs(v[i]-ele2);
	}
	//cout<<s1<<" "<<s2<<endl;
	cout<<min(s1,s2)<<endl;
}
