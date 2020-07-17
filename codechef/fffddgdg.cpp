#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define maxN 1000001
bool prime[1000005];
int pp[1000005];
vector<long>v;
void seave(){
	for(int i=2;i<maxN;i+=2)
	{
		prime[i]=true;
	}
	prime[2]=false;
	for(long i=3;i*i<=maxN;i+=2)
	{
		if(!prime[i]){
			for(long j=i*i;j<=maxN;j+=i)
			prime[j]=true;
		}
	}
	int cnt=0;
	for(int i=2;i<=maxN;i++)
	{
		if(!prime[i])
		cnt++;
		
		if(!prime[cnt])
		pp[i]=1;
	}
	for(int i=1;i<=maxN;i++)
	pp[i]+=pp[i-1];
	
}
int main()
{
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		long l,r;
		cin>>l>>r;
		cout<<pp[r]-pp[l-1]<<endl;
	}
}
