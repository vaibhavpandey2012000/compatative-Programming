#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
class solution{
	public:
	void range2(ll left,ll right)
	{
		if(right<left)
		return;
		ll l=0;
		ll g=0;
		ll mid=(left+right)/2;
		cout<<mid<<endl;
		char prev;
		cin>>prev;
		if(prev=='E')
		exit(0);
		else if(prev=='L')
		l+=1;
		else
		g+=1;
		cout<<mid<<endl;
		char ans;
		cin>>ans;
		if(ans=='E') exit(0);
		else if(ans=='L') l+=1;
		else g+=1;
		if(ans==prev)
		{
			if(ans=='L')
			range2(left,mid-1);
			else
			range2(mid+1,right);
		}
		for(int i=0;i<7;i++)
		{
			prev=ans;
			cout<<mid<<endl;
			cin>>ans;
			if(ans=='E')
			exit(0);
			else if(ans=='L')
			l+=1;
			else
			g+=1;
			if(ans==prev)
			{
				if(ans=='L')
				range2(left,mid-1);
				else
				range2(mid+1,right);
			}
		}
		if(g>l)
		range2(mid+1,right);
		else
		range2(left,mid-1);	
	}
	void range1(ll start,ll mid,ll mid1,ll mid2,ll end)
	{
		if(start>end)
		return;
		cout<<mid<<endl;
		char ans1;
		cin>>ans1;
		if(ans1=='L')
		{
			cout<<mid2<<endl;
			ll ans2;
			cin>>ans2;
			if(ans2=='L')
			{	
				ll s=start;
				ll e=mid2-1;
				ll m=s+(e-s)/2;
				ll m1=s+(m-s)/2;
				ll m2=m+(e-m)/2;
				range1(s,m,m1,m2,e);
			}
			else if(ans2=='G')
			{
				ll s=start;
				ll e=mid-1;
				ll m=s+(e-s)/2;
				ll m1=s+(m-s)/2;
				ll m2=m+(e-m)/2;
				ll _s=mid2+1;
				ll _e=end;
				ll _m=_s+(_e-_s)/2;
				ll _m1=s+(_m-_s)/2;
				ll _m2=m+(_e-_m)/2;
				range1(s,m,m1,m2,e);
				range1(_s,_m,_m1,_m2,_e);
			}
			else
			{
				exit(0);
			}
		}
		else if(ans1=='G')
		{
			cout<<mid1<<endl;
			ll ans2;
			cin>>ans2;
			if(ans2=='G')
			{
				ll s=mid1+1;
				ll e=end;
				ll m=s+(e-s)/2;
				ll m1=s+(m-s)/2;
				ll m2=m+(e-m)/2;
				range1(s,m,m1,m2,e);
			}
			else if(ans2=='L')
			{
				ll s=start;
				ll e=mid1-1;
				ll m=s+(e-s)/2;
				ll m1=s+(m-s)/2;
				ll m2=m+(e-m)/2;
				ll _s=mid+1;
				ll _e=end;
				ll _m=s+(_e-_s)/2;
				ll _m1=_s+(_m-_s)/2;
				ll _m2=_m+(_e-_m)/2;
				range1(_s,_m,_m1,_m2,_e);
				range1(s,m,m1,m2,e);
			}
			else
			exit(0);
		}
		else
		exit(0);
	}
};
int main()
{
	fast();
	ll n;
	cin>>n;
	ll left=1,right=n;
	cout<<left<<endl;
	ll mid=left+(right-left)/2;
	ll mid_left=left+(mid-left)/2;
	ll mid_right=mid+(right-mid)/2;
	solution ss;
	if(n<=100000)
	ss.range1(left,mid,mid_left,mid_right,right);
	else if(n==1000000000)
	ss.range1(left,mid,mid_left,mid_right,right);
	else{
		ll l=100001;
		ll r=n;
		ss.range2(l,r);
	}
}
