#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , ans=0;

	cin>>n;

	vector<int> black(n),white(n);
	for(int i=0;i<n;i++) white[i];
	for(int i=0;i<n;i++) black[i];

	sort(white.begin(),white.end());
	sort(black.begin(), black.end());

	for(int i=0;i<n;i++)
	{
		ans+=abs(black[i]-white[i]);
	}

	cout<<ans<<endl;

}