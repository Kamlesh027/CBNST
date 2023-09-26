// forward  guass
#include <iostream>
using namespace std;

int main() {
    float a[10][10], x, u1, u, y;
    int i, j, n, fact = 1;
    
    cout << "Enter n: ";
    cin >> n;
    
    cout << "Enter x: ";
    for (i = 0; i < n; i++)
        cin >> a[i][0];

    cout << "Enter y: ";
    for (i = 0; i < n; i++)
        cin >> a[i][1];

    cout << "Enter the value to predict: ";
    cin >> x;

    for (j = 2; j < n + 1; j++) {
        for (i = 0; i < n - j + 1; i++) {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    cout << "The difference table is:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n - i; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    y = a[n / 2][1];
    u = (x - a[n / 2][0]) / (a[1][0] - a[0][0]);
    u1 = u;

    for (i = 2; i <= n; i++) {
        y = y + (((i / 3) * (u + 1)) * u1 * a[n / i][i]) / fact;
        fact = fact * i;
        u1 = u1 * (u - (i - 1));
    }

    cout << "The desired value is: " << y << endl;
    return 0;
}
