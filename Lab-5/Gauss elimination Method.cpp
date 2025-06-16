
#include<bits/stdc++.h>
#define Naba ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    Naba

    int n = 3;
    double a[3][4] =
    {
        {3, 1, -1, 3},
        {2, -8, 1, -5},
        {1, -2, 9, 8}
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k < n + 1; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    double x[3];

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }


    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << x[i] << endl;
    }

    return 0;
}
