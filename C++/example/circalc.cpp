#include <iostream>
using namespace std;

int main()
{
	float rad, per, are;
	cout << "Ingresa el radio del circulo: ";
	cin >> rad;
	per = 2 * 3.14 * rad; //calculo de perimetro
	are = 3.14 * rad * rad; //calculo de area
	cout << "El perimetro del circulo es: " << per << endl;
	cout << "El area del circulo es: " << are << endl;
	return 0;
}
