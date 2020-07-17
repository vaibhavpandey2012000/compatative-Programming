#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v1(n),v2(n),v3(2*n);
	for(int i=0;i<n;i++)
	{
		cin>>v1[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>v2[i];
	}

	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	// for(int i=0;i<2*n;i++)
	// {
	// 	cout<<v3[i]<<" ";
	// }
	int ans=(v3[n-1]+v3[n])/2;
	cout<<ans<<endl;
}