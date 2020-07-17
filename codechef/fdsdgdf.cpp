#include <bits/stdc++.h> 
#define ll long long
#define REP(i,a,n) for(ll i=a;i<n;++i)
using namespace std; 
#define INF 10000 

struct Point 
{ 
	int x; 
	int y; 
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
		return true; 
	return false; 
} 

int orientation(Point p, Point q, Point r) 
{ 
	int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0; 
	return (val > 0)? 1: 2; 
} 
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	if (o1 != o2 && o3 != o4) 
		return true; 

	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false;
} 
bool isInside(vector<Point> polygon, int n, Point p) 
{ 
	if (n < 3) return false; 
	Point extreme = {INF, p.y}; 
	int count = 0, i = 0; 
	do
	{ 
		int next = (i+1)%n; 
		if (doIntersect(polygon[i], polygon[next], p, extreme)) 
		{ 
			if (orientation(polygon[i], p, polygon[next]) == 0) 
			return onSegment(polygon[i], p, polygon[next]); 
			count++; 
		} 
		i = next; 
	} while (i != 0); 
	return count&1; 
} 



	Point p0;
	Point next_to_top(stack<pair<Point,int> >&s)
	{
		pair<Point,int> p=s.top();
		s.pop();
		Point res=s.top().first;
		s.push(p);
		return res;
	}
	void swap(Point &p1,Point &p2)
	{
		Point temp=p1;
		p1=p2;
		p2=temp;
	}
	int distsq(Point p1,Point p2)
	{
		return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
	}

	int compare(const void *vp1,const void *vp2)
	{
		Point *p1=(Point*)vp1;
		Point *p2=(Point*)vp2;
		int o=orientation(p0,*p1,*p2);
		if(o==0)
		{
			return distsq(p0,*p2)>=distsq(p0,*p1)?-1:1;
		}
		return (o==2)?-1:1;
	}


	void convexHull(vector<Point> points,int n)
	{
		int ymin=points[0].y,min=0,m=1;
		REP(i,1,n)
		{
			int y=points[i].y;
			if((y<ymin)||((ymin==y)&&(points[i].x<points[min].x)))
			{
				ymin=points[i].y;
				min=i;
			}
		}
		swap(points[0],points[min]);
		p0=points[0];
		qsort(&points[1],n-1,sizeof(Point),compare);
		REP(i,1,n)
		{
			while(i<(n-1) && orientation(p0,points[i],points[i+1])==0)
			i++;
			points[m]=points[i];
			m++;
		}
		if(m<3)return;
		stack<pair<Point,int> >s;
		s.push({points[0],0});
		s.push({points[1],1});
		s.push({points[2],2});
		REP(i,3,m)
		{
			while(orientation(next_to_top(s),s.top().first,points[i])!=2)
				s.pop();
			s.push({points[i],i});
		}
		while(!s.empty())
		{
			Point p=s.top().first;
			int index=s.top().second;
			cout<<"("<<p.x<<","<<p.y<<","<<index<<")"<<endl;
			s.pop();
		}

	}
		
int main() 
{ 
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,q;
		cin>>n>>q;
		vector<Point>polygon1(n);
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			polygon1[i].x=a;
			polygon1[i].y=b;
		}
		while(q--){
			int a,b;
			cin>>a>>b;
			Point p = {a,b}; 
			if(!isInside(polygon1, n, p))
			{
				cout<<"0"<<endl;
				continue;
			}
			else{
				convexHull(polygon1, n);
			}
		} 
	}
	

	
	return 0; 
}

