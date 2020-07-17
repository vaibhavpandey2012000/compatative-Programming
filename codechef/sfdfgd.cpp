#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
using namespace std;
void fast()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
}
class chack{
	public:
	ll res = 3;
	void function(ll a[], ll p[], ll ans, ll ln) {
		if (ln == 1) {
		if (a[0] != p[0])ans += 1;
		res = min(res, ans);
		return ;
		}
		if (a[0] == p[0]) {
		ll temp1[ln], temp2[ln];
		rep(i, 0, ln) {
		temp1[i] = a[i];
		temp2[i] = p[i];
	}
	if (ln > 1)
	function(temp1 + 1, temp2 + 1, ans, ln - 1);
	return;

	}
	if ((a[0] != 0) && ((a[0] + p[0]) % a[0]) == 0 ) {
	ll temp1[ln], temp2[ln];
	rep(i, 0, ln) {
	temp1[i] = a[i];
	temp2[i] = p[i];
	}
	ll dv = p[0] / a[0];
	temp1[0] = a[0] * dv;
	if (ln == 3) {
	temp1[0] = a[0] * dv;
	temp1[1] = a[1];
	temp1[2] = a[2];

	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	temp1[0] = a[0] * dv;
	temp1[1] = a[1] * dv;
	temp1[2] = a[2];
	
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	temp1[0] = a[0] * dv;
	temp1[1] = a[1];
	temp1[2] = a[2] * dv;
	
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	temp1[1] = a[1] * dv;
	temp1[2] = a[2] * dv;
	temp1[0] = a[0] * dv;

	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	}
	if (ln == 2) {
	temp1[0] = a[0] * dv;
	temp1[1] = a[1] ;
	
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	temp1[0] = a[0] * dv;
	temp1[1] = a[1] * dv;
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	}
	}
	ll temp1[ln], temp2[ln];
	rep(i, 0, ln) {
	temp1[i] = a[i];
	temp2[i] = p[i];
	}
	ll diff = p[0] - a[0];
	temp1[0] = a[0] + diff;
	if (ln == 3) {
	temp1[0] = a[0] + diff;
	temp1[1] = a[1];
	temp1[2] = a[2];
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	
	temp1[1] = a[1] + diff;
	temp1[0] = a[0] + diff;
	temp1[2] = a[2];
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);

	temp1[0] = a[0] + diff;
	temp1[1] = a[1];
	temp1[2] = a[2] + diff;
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	
	temp1[0] = a[0] + diff;
	temp1[1] = a[1] + diff;
	temp1[2] = a[2] + diff;
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	}
	if (ln == 2) {
	temp1[0] = a[0] + diff;
	temp1[1] = a[1];
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	temp1[1] = a[1] + diff;
	temp1[0] = a[0] + diff;
	function(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
	}
	return;
	}
	int solve(int i) 
	{
		res = 3;
	//	ll a, b, c, p, q, r;
		ll xx[3],yy[3];
		for(int i=0;i<3;i++) cin>>xx[i];
		for(int i=0;i<3;i++) cin>>yy[i];
		ll area;
		ll slo = 0;
		ll distn1 = abs(xx[0] - yy[0]);
		ll distn2 = abs(xx[1] - yy[1]);
		ll dist3 = abs(yy[2] - yy[0]);
		if ((xx[1] - xx[0]) != 0 && (yy[1] - yy[0]) % (xx[1] - xx[0]) == 0)slo = 1;
		if ((xx[2] - xx[0]) != 0 && (yy[2] - yy[0]) % (xx[2] - xx[0]) == 0)slo = 1;
		if ((xx[1] - xx[2]) != 0 && (yy[1] - yy[2]) % (xx[1] - xx[2]) == 0)slo = 1;
		ll f = 0;
		ll ma = 1;
		ll del = 0;
		if (yy[0] == yy[1] || yy[1] == yy[2] || yy[2] == yy[0])ma = 0;
		area = xx[0] * (yy[1] - yy[2]) + xx[1] * (yy[2] - yy[0]) + xx[2] * (yy[0] - yy[1]);
		if (area == 0 && slo == 1 ) {
		res = 2;
		}
		if (xx[0] != xx[1] && yy[0] - ((yy[1] - yy[0]) / (xx[1] - xx[0]))*xx[0] + xx[2] == yy[2] && (yy[1] - yy[0]) % (xx[1] - xx[0]) == 0)del = 1;
		if (xx[2] != xx[1] && yy[2] - ((yy[1] - yy[2]) / (xx[1] - xx[2]))*xx[2] + xx[0] == yy[0] && (yy[1] - yy[2]) % (xx[1] - xx[2]) == 0)del = 1;
		if (xx[0] != xx[2] && yy[0] - ((yy[2] - yy[0]) / (xx[2] - xx[0]))*xx[0] + xx[1] == yy[1] && (yy[2] - yy[0]) % (xx[2] - xx[0]) == 0)del = 1;
		if (del == 1)res = 2;
		ll x[3], y[3];
		x[0] = xx[0]; y[0] = yy[0];
		x[1] = xx[2]; y[1] = yy[2];
		x[2] = xx[1]; y[2] = yy[1];

		function(x, y, 0, 3);
	
		x[0] = xx[0] ; y[0] = yy[0];
		x[1] = xx[1] ; y[1] = yy[1];
		x[2] = xx[2] ; y[2] = yy[2];
		function(x, y, 0, 3);

		x[0] = xx[1] ; y[0] = yy[1];
		x[1] = xx[0] ; y[1] = yy[0];
		x[2] = xx[2] ; y[2] = yy[2];

		function(x, y, 0, 3);
		x[0] = xx[1] ; y[0] = yy[1];
		x[1] = xx[2] ; y[1] = yy[2];
		x[2] = xx[0] ; y[2] = yy[0];

		function(x, y, 0, 3);

		x[0] = xx[2] ; y[0] = yy[2];
		x[1] = xx[1] ; y[1] = yy[1];
		x[2] = xx[0] ; y[2] = yy[0];

		function(x, y, 0, 3);
		x[0] = xx[2] ; y[0] = yy[2];
		x[1] = xx[0] ; y[1] = yy[0];
		x[2] = xx[1] ; y[2] = yy[1];


		function(x, y, 0, 3);

		cout << res << endl;
		return i;
	}
};
int main()
{
	fast();
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++)
	{
		chack p;
		int ii=p.solve(i);
	}
}
