#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int; 
using namespac std;
int main()
{
	cpp_int x;
	cin>>x;
	cpp_int ans=4*(x*x*x)+5*(x*x)-6*x+14;
	cout<<ans<<endl;
}