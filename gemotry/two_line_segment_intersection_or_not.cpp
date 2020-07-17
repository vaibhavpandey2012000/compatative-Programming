#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
//chack on line pr ,q is lies
bool onsegment(point p,point q,point r)
{
	if(q.x<=max(p.x,r.x)&&q.x>=min(p.x,r.x)&&q.y<=max(p.y,r.y)&&q.y>=min(p.y,r.y))
	return true;
	return false;
}
//clockwise(1) or anticlockwise(2) or nodiraction(0) by cross product of pr*qr

int orintation(point p,point q,point r)
{
	int val=(p.x-r.x)*(q.y-r.y)-(p.y-r.y)*(q.x-r.x);
	if(val==0) return 0;
	return val>0 ? 1:2;
}
bool dointersect(point p1,point q1,point p2,point q2)
{
	int o1=orintation(p1,q1,p2);
	int o2=orintation(p1,q1,q2);
	int o3=orintation(p2,q2,p1);
	int o4=orintation(p2,q2,q1);
	
	if(o1!=o2 && o3!=o4) return true;
	
	if(o1==0 && onsegment(p1,q1,p2)) return true;
	if(o2==0 && onsegment(p1,q1,q2)) return true;
	if(o3==0 && onsegment(p2,q2,p1)) return true;
	if(o4==0 && onsegment(p2,q2,q1)) return true;
	
	return false;
}
int main()
{
	point p1,q1,p2,q2;
	cin>>p1.x>>p1.y>>q1.x>>q1.y;
	cin>>p2.x>>p2.y>>q2.x>>q2.y;
	dointersect(p1,q1,p2,q2)? cout<<"YES\n":cout<<"NO\n";
	
}