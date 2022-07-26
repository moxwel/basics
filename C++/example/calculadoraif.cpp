#include <iostream>
using namespace std;

int main (){
	int num1, num2, res;
	string op; //operacion
	
	cout << "Calculadora\n=====\n> Ingrese un numero: ";
	cin >> num1;
	cout << "> Ingrese la operacion: ";
	cin >> op;
	cout << "> Ingrese el segundo numero: ";
	cin >> num2;
	
	if (op == "suma"){
		res = num1 + num2;
	}
	
	if (op == "resta"){
		res = num1 - num2;
	}
	
	if (op == "multiplicar"){
		res = num1 * num2;
	}
	
	if (op == "dividir"){
		res = num1 / num2;
	}
	
	cout << res << endl;
	
	return 0;
}
