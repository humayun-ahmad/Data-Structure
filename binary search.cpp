#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>

using namespace std;
int main()
{
	int n, i, arr[50], s, first, last, middle;
	cout << "Enter total number of elements: ";
	cin>>n;
	cout << "Enter " << n << " numbers: ";
	for(i=0; i<n; i++)
		cin >> arr[i];

	cout << "Enter a number to find: ";
	cin >> s;
	first = 0;
	last = n-1;
	middle = (first+last)/2;
	while (first <= last)
	{
		if(arr[middle] < s){
			first = middle + 1;
        }
		else if(arr[middle]==s){
			cout << s << " is found at location "<<middle+1<<"\n";
			break;
		}
		else{
			 last = middle -1;
		}
		middle=(first + last)/2;
	}
	if(first>last)
		cout << "Not found! " << s <<" is not present in the array." << endl;

	return 0;
}
