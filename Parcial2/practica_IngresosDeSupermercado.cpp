#include <iostream>
#include <iomanip>
using namespace std;

double ingresos[100];
double totalIngresos = 0;

int main() {
    cout << " " << endl;
    cout << " ============================================================= " << endl;
    cout << "  Ingrese los 100 importes de venta " << endl;
    cout << " ============================================================= " << endl;
    cout << " " << endl;

    for (int i = 0; i < 100; i++) {
        cout << "Venta del cliente " << i + 1 << ": $";
        cin >> ingresos[i];
        totalIngresos += ingresos[i];
    }
    cout << " " << endl;
    cout << " ============================================================= " << endl;
    cout << fixed << setprecision(2)<< "  Total de ingresos: $" << totalIngresos << endl;
    cout << " ============================================================= " << endl;
    cout << " " << endl;


    return 0;
}