#include <iostream>
#include <string>
using namespace std;

int main(){
	int x1, x2, x3, y1, y2, y3;
	float area;
	
	cout << "Calculadora de areas triangulares | v.2.0\n=====\n";
	cout << "[1/3] Ingrese las coordenadas del traingulo:" << endl;
	cin >> x1 >> y1;
	cout << "Coordenada 1 (" << x1 << "," << y1 << ")" << endl;
	
	cout << "\n[2/3] Ingrese las coordenadas del traingulo:" << endl;
	cin >> x2 >> y2;
	cout << "Coordenada 2 (" << x2 << "," << y2 << ")" << endl;
	
	cout << "\n[3/3] Ingrese las coordenadas del traingulo:" << endl;
	cin >> x3 >> y3;
	cout << "Coordenada 3 (" << x3 << "," << y3 << ")" << endl;
	
	area = (x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2)/2.0;
	
	cout << "=====\nArea del triangulo: " << area << endl;
	
	return 0;
}
