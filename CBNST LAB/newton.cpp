#include <iostream>
#include <vector>
using namespace std;

void create_table(vector<vector<int>> &v, int n) {
    for (int i = 0; i < n; i++) {
        cin >> v[i][0];
        cin >> v[i][1];
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            v[j][i] = v[j + 1][i - 1] - v[j][i - 1];
        }
    }
}

float forward_interpolation(vector<vector<int>> &v, int n, int x) {
    float y = v[0][1];
    float u = (float)(x - v[0][0]) / (v[1][0] - v[0][0]);
    float u1 = 0;
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        y += (u1 * v[0][i]) / fact;
        u1 *= (u - (i - 1));
        fact = fact * i;
    }
    return y;
}

float backword_interpolation(vector<vector<int>> &v, int n, int x) {
    float y = v[n - 1][1];
    float u = (float)(x - v[n - 1][0]) / (v[1][0] - v[0][0]);
    float u1 = 0;
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        y += (u1 * v[n - i][i]) / fact;
        u1 *= (u + (i - 1));
        fact = fact * i;
    }
    return y;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n + 1, 0));
    create_table(v, n);
    cout << "Table is " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    int x;
    cout << "Enter the value that you want to get from forward method: ";
    cin >> x;
    cout << "Solution from backward: " << backword_interpolation(v, n, x) << endl;

    cout << "Enter the value that you want from forward method: ";
    cin >> x;
    cout << "Solution from forward method: " << forward_interpolation(v, n, x) << endl;

    return 0;
}
