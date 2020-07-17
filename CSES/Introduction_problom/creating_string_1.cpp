#include<bits/stdc++.h>
using namespace std;
int fact[10];
void f(){
	fact[0]=1;
	for(int i=1;i<10;i++)
	fact[i]=fact[i-1]*i;
}
int main()
{
	f();
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	map<char,int>mp;
	for(auto e:s)
	mp[e]++;
	int num=fact[s.length()];
	for(auto e:mp)
	{
		num/=fact[e.second];
	}
	cout<<num<<endl;
	do{
		cout<<s<<endl;
	}
	while(next_permutation(s.begin(),s.end()));
}