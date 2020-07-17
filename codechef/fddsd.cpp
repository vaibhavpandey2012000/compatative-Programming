#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v={4,8,11,15};
	int pos=lower_bound(v.begin(),v.end(),3)-v.begin();
	cout<<pos<<endl;
}
