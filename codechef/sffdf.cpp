#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, x;

		cin >> n >> x;

		vector<int> v(n);

		for (int i = 0; i < n; i++) cin >> v[i];

		sort(v.begin(), v.end());

		int head = -1, val;

		map<int, multiset<int> >mp;
		for (int i = 0; i < n; i++)
		{
			if (head == -1 || 2 * val < v[i])
			{
				head = v[i];
				val = v[i];
				mp[head].insert(v[i]);
			}
			else {
				mp[head].insert(v[i]);
				val = v[i];
			}
		}

		//only for chacking
		// for (auto e : mp)
		// {
		// 	cout << e.first << "-->";
		// 	for (auto vv : e.second)
		// 	{
		// 		cout << vv << ",";
		// 	}
		// 	cout << endl;
		// }

		int day = 0;
		while (!mp.empty())
		{
			auto choose = mp.lower_bound(x);

			if (choose == mp.end())
				--choose;

			int number = choose->first;
			// cout << "No selected " << number  << endl;

			if (choose != mp.begin() && x < number)
			{
				choose--;
				int last = 0;
				for (int a : choose->second)
					last = a;

				if ((last << 1 ) <= x)
					choose++;
			}

			number = choose->first;
			++day;
			while (x < number)
			{
				++day;
				x <<= 1;
			}

			int last = 0;
			int times = 0;
			for (int a : choose->second)
				last = a, times++;

			day += times - 1;
			x = last << 1;
			// cout << x << endl;

			mp.erase(choose);
		}
		// for (auto e : mp)
		// {
		// 	if (e.first > x) {
		// 		while (e.first > x)
		// 		{
		// 			x = 2 * x;
		// 			day++;
		// 		}
		// 	}
		// 	else {
		// 		// int dd = e.second.size();
		// 		// day += dd;
		// 		// x = 2 * e.second[dd - 1];
		// 	}
		// }
		cout << day << endl;

	}
}
