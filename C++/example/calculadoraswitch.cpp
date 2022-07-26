#include <iostream>
#include <cmath>
using namespace std;

int main (){
	int num1, num2, res, opc;
	
	cout << "Calculadora\n=====\nSeleccionar:\n1 = Sumar\n2 = Restar\n3 = Multiplicar\n4 = Dividir\n\nAccion: ";
	cin >> opc;
	
	switch (opc){
		case 1: //seleccionar suma
		cout << "[Seleccionado: Suma]\n=====\nIngresa dos numeros para sumarse: ";
		cin >> num1 >> num2;
		res = num1 + num2;
		cout << "[Operacion: " << num1 << " + " << num2 << "]\n=====\n[Resultado: " << res << "]" << endl;
		break;
		
		case 2: //seleccionar resta
		cout << "[Seleccionado: Resta]\n=====\nIngresa dos numeros para restarse: ";
		cin >> num1 >> num2;
		res = num1 - num2;
		cout << "[Operacion: " << num1 << " - " << num2 << "]\n=====\n[Resultado: " << res << "]" << endl;
		break;
		
		case 3: //seleccionar mult
		cout << "[Seleccionado: Multiplicar]\n=====\nIngresa dos numeros para multiplicarse: ";
		cin >> num1 >> num2;
		res = num1 * num2;
		cout << "[Operacion: " << num1 << " * " << num2 << "]\n=====\n[Resultado: " << res << "]" << endl;
		break;
		
		case 4: //seleccionar divid
		cout << "[Seleccionado: Dividir]\n=====\nIngresa dos numeros para dividirse: ";
		cin >> num1 >> num2;
		res = num1 / num2;
		cout << "[Operacion: " << num1 << " / " << num2 << "]\n=====\n[Resultado: " << res << "]" << endl;
		break;
		
		default:
		cout << "[Ingresa una opcion valida]" << endl;
		break;
	}
	
	return 0;
}
