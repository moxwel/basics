#include <iostream>
using namespace std;

int main(){
	float a;
	
	cout << "Ingresa un numero: ";
	cin >> a;
	
	if (a%2 == 0){
		cout << "El numero es PAR" << endl;
	}else{
		cout << "El numero es IMPAR" << endl;
	}
	
	return 0;
}
