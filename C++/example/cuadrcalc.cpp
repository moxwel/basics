#include <iostream>
#include <cmath>
using namespace std;

int main (){
	float a, b, c, det, sol1, sol2;
	
	cout << "Ingrese los valores de A, B y C respectivamente:\n\nAx^2+Bx+C=0" << endl;
	cin >> a >> b >> c;
	
	det = pow (b, 2.0) - 4.0*a*c; //calculo de determinante
	
	sol1 = (-b + sqrt(pow (b, 2.0) - 4.0*a*c))/(2*a);
	sol2 = (-b - sqrt(pow (b, 2.0) - 4.0*a*c))/(2*a);
	
	if (det > 0){
		cout << "\nSoluciones reales y diferentes." << endl;
	}
	if (det == 0){
		cout << "\nSoluciones reales e iguales." << endl;
	}
	if (det < 0){
		cout << "\nSolucion imaginaria." << endl;
	}
	
	cout << "X = \"" << sol1 << "\" y \"" << sol2 << "\""<< endl;
	
	return 0;
}
