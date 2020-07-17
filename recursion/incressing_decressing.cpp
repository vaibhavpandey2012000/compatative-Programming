#include<bits/stdc++.h>
using namespace std;
#define ll long long
void incressing(int n)
{
	if(n==0)
		return;
	incressing(n-1);
	printf("%d",n);
}
void decressing(int n)
{
	if(n==0)
		return;
	printf("%d",n);
	decressing(n-1);
}
int main()
{
	int n;
	cin>>n;
	incressing(n);
	cout<<endl;
	decressing(n);
}