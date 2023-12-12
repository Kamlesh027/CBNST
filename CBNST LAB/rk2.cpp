#include<iostream>
using namespace std;

float f(float x, float y) {
    float a;
    a = x * y;
    return a;
}

int main() {
    float x, xf, y, h, s, s1, s2;

    cout << "Enter the First value: ";
    cin >> x;

    cout << "Enter the Second value: ";
    cin >> xf;

    cout << "Enter the Length y: ";
    cin >> y;

    cout << "Enter the Width h: ";
    cin >> h;

    while (x < xf) {
        s1 = f(x, y);
        s2 = f(x + h, y + h * s1);
        s = (s1 + s2) / 2;
        y = y + (h * s);
        x = x + h;
    }

    cout << "Output: " << y;

    return 0;
}
