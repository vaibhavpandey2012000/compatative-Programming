#include<bits/stdc++.h>
#define ll long long
using namespace std;
class ss{
	ll result = 3;
	public:
		void fast()
		{
			ios_base::sync_with_stdio(false); cin.tie(NULL);
		}
	void funct(ll xx[], ll yy[], ll ans, ll nn) 
	{
		if (nn == 1) 
		{
			if (xx[0] != yy[0])ans += 1;
			result = min(result, ans);
			return ;
		}
		if (xx[0] == yy[0])
		 {
			ll ttt1[nn], ttt2[nn];
			for(ll i=0;i<nn;i++) 
			{
				ttt1[i] = xx[i];
				ttt2[i] = yy[i];
			}
			if (nn > 1)
			funct(ttt1 + 1, ttt2 + 1, ans, nn - 1);
			return;
		}
		if ((xx[0] != 0) && ((xx[0] + yy[0]) % xx[0]) == 0 ) {
		ll ttt1[nn], ttt2[nn];
		for(ll i=0;i<nn;i++)
		{
			ttt1[i] = xx[i];
			ttt2[i] = yy[i];
		}
		ll dv = yy[0] / xx[0];
		ttt1[0] = xx[0] * dv;
		if (nn == 3) {
		ttt1[0] = xx[0] * dv;
		ttt1[1] = xx[1];
		ttt1[2] = xx[2];

		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
		ttt1[0] = xx[0] * dv;
		ttt1[1] = xx[1] * dv;
		ttt1[2] = xx[2];

		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
		ttt1[0] = xx[0] * dv;
		ttt1[1] = xx[1];
		ttt1[2] = xx[2] * dv;

		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
		ttt1[1] = xx[1] * dv;
		ttt1[2] = xx[2] * dv;
		ttt1[0] = xx[0] * dv;

		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
	}
		if (nn == 2) {
		ttt1[0] = xx[0] * dv;
		ttt1[1] = xx[1] ;
	
		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
		ttt1[0] = xx[0] * dv;
		ttt1[1] = xx[1] * dv;
		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
		}
	}
	ll ttt1[nn], ttt2[nn];
	for(ll i=0;i<nn;i++) 
	{
		ttt1[i] = xx[i];
		ttt2[i] = yy[i];
	}
	ll diff = yy[0] - xx[0];
	ttt1[0] = xx[0] + diff;
	if (nn == 3) 
	{
		ttt1[0] = xx[0] + diff;
		ttt1[1] = xx[1];
		ttt1[2] = xx[2];
		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
	
		ttt1[1] = xx[1] + diff;
		ttt1[0] = xx[0] + diff;
		ttt1[2] = xx[2];
		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);

		ttt1[0] = xx[0] + diff;
		ttt1[1] = xx[1];
		ttt1[2] = xx[2] + diff;
		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);

		ttt1[0] = xx[0] + diff;
		ttt1[1] = xx[1] + diff;
		ttt1[2] = xx[2] + diff;
		funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
	}
	if (nn == 2) {
	ttt1[0] = xx[0] + diff;
	ttt1[1] = xx[1];
	funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
	ttt1[1] = xx[1] + diff;
	ttt1[0] = xx[0] + diff;
	funct(ttt1 + 1, ttt2 + 1, ans + 1, nn - 1);
	}
	return;
}
void solve() 
{
	result = 3;

	ll xx[3],yy[3];
	for(int i=0;i<3;i++)
	cin>>xx[i];
	for(int i=0;i<3;i++)
	cin>>yy[i];
	ll chack_area;
	ll solution = 0;
	ll distn1 = abs(xx[0] - yy[0]);
	ll distn2 = abs(xx[1] - yy[1]);
	ll dist3 = abs(yy[2] - yy[0]);
	if ((xx[1] - xx[0]) != 0 && (yy[1] - yy[0]) % (xx[1] - xx[0]) == 0)solution = 1;
	if ((xx[2] - xx[0]) != 0 && (yy[2] - yy[0]) % (xx[2] - xx[0]) == 0)solution = 1;
	if ((xx[1] - xx[2]) != 0 && (yy[1] - yy[2]) % (xx[1] - xx[2]) == 0)solution = 1;	
	ll f = 0;
	ll mai = 1;
	ll delet = 0;
	if (yy[0] == yy[1] || yy[1] == yy[2] || yy[2] == yy[0])mai = 0;
	chack_area = xx[0] * (yy[1] - yy[2]) + xx[1] * (yy[2] - yy[0]) + xx[2] * (yy[0] - yy[1]);
	if (chack_area == 0 && solution == 1 ) 
	{
		result = 2;
	}
	if (xx[0] != xx[1] && yy[0] - ((yy[1] - yy[0]) / (xx[1] - xx[0]))*xx[0] + xx[2] == yy[2] && (yy[1] - yy[0]) % (xx[1] - xx[0]) == 0)delet = 1;
	if (xx[2] != xx[1] && yy[2] - ((yy[1] - yy[2]) / (xx[1] - xx[2]))*xx[2] + xx[0] == yy[0] && (yy[1] - yy[2]) % (xx[1] - xx[2]) == 0)delet = 1;
	if (xx[0] != xx[2] && yy[0] - ((yy[2] - yy[0]) / (xx[2] - xx[0]))*xx[0] + xx[1] == yy[1] && (yy[2] - yy[0]) % (xx[2] - xx[0]) == 0)delet = 1;
	if (delet == 1)result = 2;
	ll x[3], y[3];
	x[0] = xx[0]; y[0] = yy[0];
	x[1] = xx[2]; y[1] = yy[2];
	x[2] = xx[1]; y[2] = yy[1];
	funct(x, y, 0, 3);
	x[0] = xx[0] ; y[0] = yy[0];
	x[1] = xx[1] ; y[1] = yy[1];
	x[2] = xx[2] ; y[2] = yy[2];
	funct(x, y, 0, 3);
	x[0] = xx[1] ; y[0] = yy[1];
	x[1] = xx[0] ; y[1] = yy[0];
	x[2] = xx[2] ; y[2] = yy[2];
	funct(x, y, 0, 3);
	x[0] = xx[1] ; y[0] = yy[1];
	x[1] = xx[2] ; y[1] = yy[2];
	x[2] = xx[0] ; y[2] = yy[0];
	funct(x, y, 0, 3);
	x[0] = xx[2] ; y[0] = yy[2];
	x[1] = xx[1] ; y[1] = yy[1];
	x[2] = xx[0] ; y[2] = yy[0];
	funct(x, y, 0, 3);
	x[0] = xx[2] ; y[0] = yy[2];
	x[1] = xx[0] ; y[1] = yy[0];
	x[2] = xx[1] ; y[2] = yy[1];

	funct(x, y, 0, 3);

	cout << result << endl ;
}
};
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ss s;
		s.fast();
		s.solve();
	}
}
