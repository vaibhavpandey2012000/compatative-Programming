// C++ implementation to find the 
// minimum number of operations in 
// which the array A can be converted 
// to another array B 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum 
// number of operations in which 
// array A can be converted to array B 
void checkArray(int a[], int b[], int n) 
{ 
	int operations = 0; 
	int i = 0; 
	
	// Loop to iterate over the array 
	while (i < n) { 
		
		// if both elements are equal 
		// then move to next element 
		if (a[i] - b[i] == 0) { 
			i++; 
			continue; 
		} 

		// Calculate the difference 
		// between two elements 
		int diff = a[i] - b[i]; 
		i++; 

		// loop while the next pair of 
		// elements have same difference 
		while (i < n && 
		a[i] - b[i] == diff) { 
			i++; 
		} 

		// Increase the number of 
		// operations by 1 
		operations++; 
	} 

	// Print the number of 
	// operations required 
	cout << operations << "\n"; 
} 

// Driver Code 
int main() 
{ 
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a[3] ;
		cin>>a[0]>>a[1]>>a[2];
		int b[3] ;
		cin>>b[0]>>b[1]>>b[2];
		int size = 3; 
		checkArray(a, b, size); 
	}
	return 0; 
} 

