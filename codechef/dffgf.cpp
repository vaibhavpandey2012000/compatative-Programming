#include<bits/stdc++.h>
using namespace std;
int GCD(int a,int b)
{
	if(b==0) return a;
	return GCD(b,a%b);
}
bool p1(int a,int b,int c,int p,int q,int r)
{
	if(a==p && b==q && r==c)
	return 1;
	return 0;
}
bool p2(int a,int b,int c,int p,int q,int r)
{
	set<int> s;
	int aa=a-p;
	int bb=b-q;
	int cc=c-r;
	if(aa!=0)
	s.insert(aa);
	if(bb!=0)
	s.insert(bb);
	if(cc!=0)
	s.insert(cc);
	if(s.size()==1)
	return 1;
	int g=GCD(aa,GCD(bb,cc))+1;
	if(a==p && ((b*g==q && c*g==r) || (q*g==b && r*g==c)))
	return 1;
	if(b==q && ((a*g==p && c*g==r) || (p*g==a && r*g==c)))
	return 1;
	if(c==r && ((a*g==p && b*g==q) || (p*g==a && q*g==b)))
	return 1;
	if((a*g==p && b*g==q && c*g==r) ||(p*g==a && q*g==b && r*g==c))
	return 1;
	return 0;
}
bool p3(int a,int b,int c,int p,int q,int r)
{
	set<int> s;
	int aa=a-p;
	int bb=b-q;
	int cc=c-r;
	if(aa!=0)
	s.insert(aa);
	if(bb!=0)
	s.insert(bb);
	if(cc!=0)
	s.insert(cc);
	if(s.size()!=3)
	return 0;
	int g=GCD(aa,GCD(bb,cc))+1;
	if((g*a==p && g*b==q)||(g*a==p && g*c==r)||(g*c==r && g*b==q))
	return 0;
	if((g*p==a && g*q==b)||(g*p==a && g*r==c)||(g*r==c && g*q==b))
	return 0;
	if(g==2)
	return 1;
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
}
