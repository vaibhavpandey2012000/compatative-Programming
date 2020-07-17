#include<bits/stdc++.h>
using namespace std;
 string minWindow(string S, string T) {
        string window = "";
        int j = 0, min = S.length() + 1;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == T[j]) {
                j++;
                if (j == T.length()) {
                    int end = i + 1;
                    j--;
                    while (j >= 0) {
                        if (S[i] == T[j]) j--;
                        i--;
                    }
                    j++;
                    i++;
                    if (end - i < min) {
                        min = end - i;
                        window = S.substr(i, end);
                    }
                }
            }
        }
        return window;
    }
int main()
{
	string str,pat;
	getline(cin,str);
	getline(cin,pat);
	string ss=minWindow(str,pat);
	if(ss=="")
	{
		cout<<"No string"<<endl;
	}
	else
	{
		cout<<ss<<endl;
	}
}