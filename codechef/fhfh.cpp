#include <bits/stdc++.h> 
using namespace std; 
const int pandigitalMask = ((1 << 10) - 1); 
void computeMaskFrequencies(vector<string> v, map<int, 
										int>& freq) 
{ 
	for (int i = 0; i < v.size(); i++) { 
		int mask = 0; 
		unordered_set<int> digits; 
		for (int j = 0; j < v[i].size(); j++) 
			digits.insert(v[i][j] - '0'); 
		for (auto it = digits.begin(); it != digits.end(); it++) { 
			int digit = (*it); 
			mask += (1 << digit); 
		} 
		freq[mask]++; 
	} 
} 

int pandigitalConcatenations(map<int, int> freq) 
{ 
	int ans = 0; 
	for (int i = 1; i <= 1023; i++) { 
		for (int j = 1; j <= 1023; j++) { 
			if ((i | j) == pandigitalMask) { 
				if (i == j) 
					ans += (freq[i] * (freq[i] - 1));			 
				else
					ans += (freq[i] * freq[j]);			 
			} 
		} 
	} 
	return ans/2; 
} 

int countPandigitalPairs(vector<string> v) 
{ 
	map<int, int> freq; 
	computeMaskFrequencies(v, freq); 
	return pandigitalConcatenations(freq); 
} 
int main() 
{ 
	int n;
	cin>>n;
	
	vector<string> v(n);// = {"1293045", "594827", "0123456", "56789","123456789"}; 
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		v[i]=s;
	}
	cout << countPandigitalPairs(v) << endl; 
	return 0; 
}
