#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,p;
	cin>>n;
	int x,y;
	cin>>x>>y;
	vector<int> A(n),B(n);
	for(int i=0;i<n;i++)
	cin>>A[i];
	for(int i=0;i<n;i++)
	cin>>B[i];
	//xivis
	if(x%10==0)
	{
		p=n/4;
		for(int i=0;i<p;i++)
		A[i]*=2;
	}
	if(x%8==0)
	{
		p=n/4;
		for(int i=0;i<p;i++)
		A[i]/=2;
	}
	//magnito
	if(y%4==0){
		p=n/3;
		for(int i=0;i<p;i++)
		B[i]*=3;
	}
	if(y%10==0)
	{
		for(int i=0;i<n;i++)
		B[i]=(B[i]*4)/5;
	}
	long s1=0,s2=0;
	for(int i=0;i<n;i++)
	{
		s1+=A[i];
		s2+=B[i];
	}
	if(s1>s2)
	cout<<"Xavier"<<endl;
	else
	cout<<"Magneto"<<endl;
}
