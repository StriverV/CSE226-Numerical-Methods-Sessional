#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return  3 * x - cos(x) - 1;
}

int main()
{
    double x0 = 0.0, x1 = 1.0, x_n;
    double tol = 0.000001;

    int max_iter;
    cin >> max_iter;




    for (int i = 0; i < max_iter; i++)
    {
        double f0 = f(x0);
        double f1 = f(x1);

        x_n = x1 - f1 * (x1 - x0) / (f1 - f0);

        if (fabs(f(x_n)) < tol)
        {
            cout << "Root : " << x_n << endl;
            return 0;
        }

        x0 = x1;
        x1 = x_n;
    }

    cout << "Not converge.\n";
    return 0;
}

