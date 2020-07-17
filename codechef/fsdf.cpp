#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v={3,4,5,5,5,8,9};
	//auto a=lower_bound(v.begin(),v.end(),2);
	//auto b=upper_bound(v.begin(),v.end(),2);
	auto pos=binary_search(v.begin(), v.end(), 5);
	cout<<pos;
//	cout<<*(v.begin()+2)<<endl;
}
