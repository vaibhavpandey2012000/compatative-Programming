	
		// 2 7 15 26 40 57 77 100 126 155 187 222 260 301 345 392 442 495 551 610

#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v;
void seave(){
	for(int i=1;i<100000;i++)
	{
		ll temp=(3*i*i+i)/2;
		if(temp>1000000000)
		break;
		v.push_back(temp);
	}
	for(int i=0;i<20;i++)
	cout<<v[i]<<" ";
}
int main(){
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
//		auto p=lower_bound(v.begin(),v.end(),n)-v.begin();
//		cout<<p<<endl;	
		int cnt=0;
		while(n>1)
		{
			auto p=lower_bound(v.begin(),v.end(),n)-v.begin();
			if(v[p]==n)
			{
				cnt++;
				break;
			}
			n=n-v[p-1];
			cnt++;
		}
		cout<<cnt<<endl;
	}
}



