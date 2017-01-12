#include <bits/stdc++.h>

using namespace std; 

const double PI = 3.14159265358979323846264;

double xw, yw, rw, xm, ym, rm, d;

double antiderivative (double x, double r) {
    return (x*sqrt(r*r - x*x) + r*r*asin(x/r))/2;
}

double compute_area(double x, double y) {
    if (x >= d) {
        double window = antiderivative(y, rw) - antiderivative(-y, rw);
        double moon = 2*d*y + (antiderivative(y, rm) - antiderivative(-y, rm));
        return PI*rm*rm - (moon - window);
    } if (x <= 0) {
        double moon = antiderivative(y, rw) - antiderivative(-y, rw);
        double window = 2*d*y + (antiderivative(y, rm) - antiderivative(-y, rm));
        return PI*rm*rm - (moon - window);
    }
    double window = antiderivative(y, rw) - antiderivative(-y, rw);
    double moon = 2*d*y - (antiderivative(y, rm) - antiderivative(-y, rm));
    return window - moon;
}

int main () {
    cin >> xw >> yw >> rw >> xm >> ym >> rm;
    d = sqrt(pow(xw-xm, 2) + pow(yw-ym, 2));
    if (d >= rm + rw) {
        cout << "0.00\n";
        return 0;
    } if (rw >= rm + d) {
        cout << setprecision(2) << fixed << PI*rm*rm << "\n";
        return 0;
    } if (rm >= rw + d) {
        cout << setprecision(2) << fixed << PI*rw*rw << "\n";
        return 0;
    }
    double x = (rw*rw + d*d - rm*rm)/(2*d);
    double y = sqrt(rw*rw - x*x);
    
    double area = compute_area(x, y);
    cout << setprecision(2) << fixed << area << "\n";
}
