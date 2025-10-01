#include <cstdlib>
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    float x, y;
    cout << "¬ведите x и y: ";
    cin >> x >> y;

    double R = sqrt(x * x + y * y) / pow(2, log2(x));

    double S = x * tan(M_PI / 2);

    cout << "R = " << R << endl;
    cout << "S = " << S << endl;

    double C = max(R, S);

    cout << "C = " << C << endl;
    system("pause");
    return 0;
}