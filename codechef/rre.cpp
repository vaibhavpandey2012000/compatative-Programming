#include<bits/stdc++.h>
using namespace std;
const int maxN=1000000;
bool arr[maxN];
void seave()
{
	arr[0]=arr[1]=true;
	for(int i=2;i*i<=maxN;i++)
	{
		if(arr[i]==false)
		for(int j=i*i;j<=maxN;j+=i)
		arr[j]=true;
	}
	for(int i=1;i<=1000;i++)
	if(!arr[i])
	cout<<i<<",";
}
int main()
{
	seave();
}
