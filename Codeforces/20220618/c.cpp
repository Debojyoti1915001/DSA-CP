#include <bits/stdc++.h>
using namespace std;

// Function calculates distance
// between two points

// Function to find the maximum
// distance between any two points
double maxDist(int **p, int n,int s)
{
	double Max = 0;

	// Iterate over all possible pairs
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			
			// Update max
			Max = max(Max, (double)((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1])));
		}
	}

	// Return actual distance
	return sqrt(Max)/s;
}

// Driver code
int main()
{
	
	// Number of points
	int n = 5;

	pair<long, long> p[n];

	// Given points
	p[0].first = 4, p[0].second = 0;
	p[1].first = 0, p[1].second = 2;
	p[2].first = -1, p[2].second = -7;
	p[3].first = 1, p[3].second = 10;
	p[4].first = 2, p[4].second = -3;

	// Function call
	cout << fixed << setprecision(14)
		<< maxDist(p, n) <<endl;

	return 0;
}

// This code is contributed by divyeshrabadiya07
