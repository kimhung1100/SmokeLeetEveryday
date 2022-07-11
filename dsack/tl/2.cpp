// C++ program to implement interpolation search
#include<bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int n, int x)
{
	// Find indexes of two corners
	int lo = 0, hi = (n - 1);
    int count = 0;
	// Since array is sorted, an element present
	// in array must be in range defined by corner
	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == x) return lo;
			return -1;
		}
        count ++;
		// Probing the position with keeping
		// uniform distribution in mind.
		int pos = lo + (((double)(hi - lo) /
			(arr[hi] - arr[lo])) * (x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x){
            cout << count;
			return pos;
        }
		// If x is larger, x is in upper part
		if (arr[pos] < x)
			lo = pos + 1;

		// If x is smaller, x is in the lower part
		else
			hi = pos - 1;
	}
	return -1;
}

// Driver Code
int main()
{
	// Array of items on which search will
	// be conducted.
	int arr[] = {1, 5, 7, 8, 16, 30, 33, 35, 41, 49, 51, 52, 59, 61, 65, 68, 69, 71, 72, 75, 76, 83, 85, 89, 97};
	int n = sizeof(arr)/sizeof(arr[0]);

	int x = 49; // Element to be searched
	int index = interpolationSearch(arr, n, x);

	// If element was found
	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";
	return 0;
}

// This code is contributed by Mukul Singh.
