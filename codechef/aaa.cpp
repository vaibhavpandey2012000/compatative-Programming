#include<bits/stdc++.h>
using namespace std;
long GCD(long a,long b)
{
	if(b==0) return a;
	return GCD(b,a%b);
}
bool p1(long a,long b,long c,long p,long q,long r)
{
	if(a==p && b==q && r==c)
	return 1;
	return 0;
}
bool p2(long a,long b,long c,long p,long q,long r)
{
	long aa=a-p;
	long bb=b-q;
	long cc=c-r;
	set<long> s;
	if((aa==0 && bb==0 && cc!=0)||(aa==0 && bb==0 && cc!=0)||(aa==0 && bb==0 && cc!=0))
	return 1;
	if(aa==0)
	{
		if((b!=0 && c!=0) && (q%b==0 && r%c==0) && (q/b==r/c))
		return 1;
		if((q!=0 && r!=0) && (b%q==0 && c%r==0) && (b/q==c/r))
		return 1;
		if(b-q==c-r)
		return 1;
	}
	if(bb==0)
	{
		if((a!=0 && c!=0) && (p%a==0 && r%c==0) && (p/a==r/c))
		return 1;
		if((p!=0 && r!=0) && (a%p==0 && c%r==0) && (a/p==c/r))
		return 1;
		if( a-p==c-r)
		return 1;
	}
	if(cc==0)
	{
		if((b!=0 && a!=0) && (q%b==0 && p%a==0) && (q/b==p/a))
		return 1;
		if((q!=0 && p!=0) && (b%q==0 && a%p==0) && (b/q==a/p))
		return 1;
		if(a-p==b-q)
		return 1;
	}
	if(aa!=0 && bb!=0 && cc!=0)
	{
		if((a!=0 && b!=0 && c!=0) && (p%a==0 && q%b==0 && r%c==0) && (p/a==q/b && p/a==r/c))
		return 1;
		if((p!=0 && q!=0 && r!=0) && (a%p==0 && b%q==0 && c%r==0) && (a/p==b/q && a/p==c/r))
		return 1;
		if(b-q==c-r && a-p==b-q && a-p==c-r)
		return 1;
	}
	return 0;
}
bool p3(long a,long b,long c,long p,long q,long r)
{
	long aa=a-p;
	long bb=b-q;
	long cc=c-r;
	set<long> s;
	if(aa!=0)
	s.insert(aa);
	if(bb!=0)
	s.insert(bb);
	if(cc!=0)
	s.insert(cc);
	if(s.size()!=3)
	return 0;
	if(aa==bb||bb==cc||cc==aa)
	return 0;
	if( ((p!=0 && q!=0)&&(a%p==0 && b%q==0)&&(a/p==b/q)) || ((p!=0 && r!=0)&&(a%p==0 && c%r==0)&&(a/p==c/r))||((r!=0 && q!=0)&&(b%q==0 && c%r==0)&&(c/r==b/q)))
	return 0;
	if( ((a!=0 && b!=0)&&(p%a==0 && q%b==0)&&(p/a==q/b)) || ((a!=0 && c!=0)&&(p%a==0 && r%c==0)&&(p/a==r/c))||((b!=0 && c!=0)&&(q%b==0 && r%c==0)&&(r/c==q/b)))
	return 0;
	return 1;	
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long a,b,c;
		cin>>a>>b>>c;
		long p,q,r;
		cin>>p>>q>>r;
		if(p1(a,b,c,p,q,r))
		{
			cout<<"0"<<endl;
			continue;
		}
		
		if(p2(a,b,c,p,q,r))
		{
			cout<<"1"<<endl;
			continue; 
		}
		
		if(p3(a,b,c,p,q,r))
		{
			cout<<"3"<<endl;
			continue;
		}
		cout<<"2"<<endl;
	}
	return 0;
}
