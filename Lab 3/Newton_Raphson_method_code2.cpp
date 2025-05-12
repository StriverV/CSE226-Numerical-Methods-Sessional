
#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x - 12;
}

double f_deriv(double x)
{
    return 2 * x;
}

int main()
{
    double a, b, x0, x1;
    double tol = 0.0001;

    int max_iter;
    cin >> a >> b >> max_iter;
    if (f(a) * f(b) >= 0)
    {
        return -1;
    }

    x0 = a;
    x1 = x0 - f(x0) / f_deriv(x0);
    int i = 0;
    while (fabs(f(x1)) > tol && i < max_iter)
    {

        cout <<  x0 << "\t " << f(x0) << "\t " << f_deriv(x0) << "\t " << x1 << endl;


        if (fabs(x1 - x0) < tol)
        {
            cout << "Successive values are close enough to be considered equal." << endl;
            break;
        }


        x0 = x1;
        x1 = x0 - f(x0) / f_deriv(x0);
        i++;
    }

    if (fabs(f(x1)) <= tol)
    {
        cout << "Root is: " << x1 << endl;
    }
    else
    {
        cout << "\nDid not converge after " << max_iter << " iterations." << endl;
    }

    return 0;
}
