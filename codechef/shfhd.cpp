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
		map<int, vector<int> >mp;
		for (int i = 0; i < n; i++)
		{
			if (head == -1 || 2 * val < v[i])
			{
				head = v[i];
				val = v[i];
				mp[head].push_back(v[i]);
			}
			else {
				mp[head].push_back(v[i]);
				val = v[i];
			}
		}
		
		int day = 0;
		while (!mp.empty())
		{
			auto choose = mp.lower_bound(x);

			if (choose == mp.end())
				--choose;

			int number = choose->first;

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

			mp.erase(choose);
		}
		cout << day << endl;

		
	}
}
