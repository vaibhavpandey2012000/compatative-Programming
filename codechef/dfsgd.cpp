#include<bits/stdc++.h>
using namespace std;
bool p1(int a,int b,int c,int p,int q,int r)
{
	if(a==p && b==q && r==c)
	return 1;
	return 0;
}
bool p2(int a,int b,int c,int p,int q,int r)
{
	int aa=a-p;
	int bb=b-q;
	int cc=c-r;
	if(aa==0&&bb==0&&cc!=0 || cc==0&&bb==0&&aa!=0 || aa==0&&cc==0&&bb!=0)
	return 1;
	if(p%a==0 && q%b==0 && r%c==0 &&a!=0&&b!=0&&c!=0)
	{
		if(p/a==q/b && p/a==r/c && a!=0 &&b!=0 &&c!=0)
		return 1;
		if(p/a==q/b && cc==0 && a!=0 && b!=0)
		return 1;
		if(q/b==r/c && aa==0 && b!=0 && c!=0)
		return 1;
		if(p/a==r/c && bb==0 && a!=0 && c!=0)
		return 1;
	}
	if((aa==0 && bb==cc) ||(bb==0 && aa==cc)||(cc==0 && bb==aa))
	return 1;
	return 0;
}
bool p3(int a,int b,int c,int p,int q,int r)
{
	int aa=a-p;
	int bb=b-q;
	int cc=c-r;
	if(aa==0 && (b%q!=0 || c%r!=0) && q!=0 && r!=0)
	return 1;
	if(bb==0 && (a%p!=0 || c%r!=0) &&p!=0 && r!=0)
	return 1;
	if(cc==0 && (a%p!=0 || b%q!=0) && p!=0 && q!=0)
	return 1;
	
	if(aa==0 && (b%q==0 && c%r==0) && b/q!=c/r && q!=0 && r!=0)
	return 1;
	if(bb==0 && (a%p==0 || c%r==0) && a/p!=c/r && p!=0 && r!=0)
	return 1;
	if(cc==0 && (a%p==0 || b%q==0) && a/p!=b/q && p!=0 && q!=0)
	return 1;
	
	if( (b%q==0 && c%r==0 && a%p!=0) && (b/q==c/r) && (p!=0 && q!=0 &&r!=0))
	return 1;
	if( (a%p==0 && c%r==0 && b%q!=0) && (a/p==c/r) && (p!=0 && q!=0 &&r!=0))
	return 1;
	if( (a%p==0 && b%q==0 && c%r!=0) && (a/p==b/q) && (p!=0 && q!=0 &&r!=0))
	return 1;
	
	
	if( (b%q==0 && c%r==0 && a%p==0) && (b/q==c/r && a/p!=b/q) && p!=0 && q!=0 &&r!=0)
	return 1;
	if( (a%p==0 || c%r==0 && b%q==0) && (a/p==c/r && a/p!=b/q) && p!=0 && q!=0 &&r!=0)
	return 1;
	if( (a%p==0 || b%q==0 && c%r==0) && (a/p==b/q && a/p!=c/r) && p!=0 && q!=0 &&r!=0)
	return 1;
	if(((aa==bb) && cc)||((cc==bb) && aa)||((aa==cc) && bb))
	return 1;
	return 0;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int p,q,r;
		cin>>p>>q>>r;
		if(p1(a,b,c,p,q,r))
		{
			cout<<"0"<<endl;
			continue;
		}
		else{
			cout<<"p1"<<endl;
		}
		if(p2(a,b,c,p,q,r))
		{
			cout<<"1"<<endl;
			continue; 
		}
		else{
			cout<<"p2"<<endl;
		}
		if(p3(a,b,c,p,q,r))
		{
			cout<<"2"<<endl;
			continue;
		}
		else{
			cout<<"p3"<<endl;
		}
		cout<<"3"<<endl;
	}
}
