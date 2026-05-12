#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a[3][4];

    cout << "Введіть розширену матрицю (коефіцієнти рівнянь та вільні члени):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int k = i + 1; k < 3; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j <= 3; j++) {
                a[k][j] = a[k][j] - factor * a[i][j];
            }
        }
    }
    double x[3];
    x[2] = a[2][3] / a[2][2];
    x[1] = (a[1][3] - a[1][2] * x[2]) / a[1][1];
    x[0] = (a[0][3] - a[0][2] * x[2] - a[0][1] * x[1]) / a[0][0];
    
    cout << fixed << setprecision(2);
    cout << "\nРезультати:\n";
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;
    cout << "x3 = " << x[2] << endl;

    return 0;
}
