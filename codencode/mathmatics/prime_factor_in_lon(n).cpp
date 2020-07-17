#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
int arr[maxN]={0};
void seave(){
	for(int i=2;i*i<=maxN;i++)
	{
		if(arr[i]==0)
		{
			for(int j=i*i;j<=maxN;j+=i)
			if(arr[j]==0)
			arr[j]=i;
		}
	}
//	for(int i=0;i<=100;i++)
//	cout<<arr[i]<<",";
}
map<int,int> factor(int n)
{
	map<int,int>mp;
	while(1)
	{
		if(n==1) break;
		if(arr[n]==0) {
			mp[n]++;
			break;
		}
		mp[arr[n]]++;
		n=n/arr[n];
	//	cout<<n<<",";
	}
	return mp;
}
int main()
{
	seave();
	int n;
	cin>>n;
	map<int,int>mp= factor(n);
	for(auto e:mp)
	cout<<e.first<<" "<<e.second<<endl;
}