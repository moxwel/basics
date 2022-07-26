#include <iostream>
using namespace std;

bool divisible(int a, int b){ //funcion
	if ((a % b) == 0){
		return 1; //es divisible
	}else{
		return 0;
	}
}

int main(){
	int a, b;
	
	cout << "> Ingrese dos numeros: ";
	cin >> a >> b;
	
	if (divisible(a, b) == true){
		cout << "Son divisibles." << endl;
	}else{
		cout << "No son divisibles." << endl;
	}
	
	return 0;
}