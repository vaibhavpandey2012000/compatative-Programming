#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v={1,2,3,4,5,5,5,8,9};
	auto a=lower_bound(v.begin(),v.end(),5);
	auto b=upper_bound(v.begin(),v.end(),5);
	cout<<a-v.begin()<<"  "<<b-v.begin()<<endl;
}