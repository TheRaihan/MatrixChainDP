#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int dims[] = { 5, 4, 6, 2, 7};
	int n = sizeof(dims) / sizeof(dims[0]);
	int c[10][10], s[10][10];

    // c[i,j] = Minimum number of scalar multiplications (i.e., cost)
	// needed to compute the matrix M[i]M[i+1]...M[j] = M[i..j]
	// The cost is zero when multiplying one matrix

	for (int i = 1; i <= n; i++)
		c[i][i] = 0;


	for (int len = 2; len <= n; len++) // 'len' hoilo koyta kore nitesi
	{
		for (int i = 1; i <= n - len + 1; i++) // m[i,j]
		{
			int j = i + len - 1; 
			c[i][j] = INT_MAX;

			for (int k = i; j < n && k <= j - 1; k++)
			{
				int cost = c[i][k] + c[k + 1][j] +
				            dims[i - 1]*dims[k]*dims[j];

				if (cost < c[i][j]){
					c[i][j] = cost;
                    s[i][j] = k;
                }
			}
		}
	}

	cout << "Minimum cost is " << c[1][n - 1]<< endl;

	return 0;
}

