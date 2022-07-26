#include <iostream>
#include <cmath>
using namespace std;

int main (){
	int age;
		
	cout << "Ingresa año:" << endl;
	cin >> age;
	cout << endl;
	
	if (age%4 == 0){
		if (!(age%100 == 0) || (age%400 == 0)){
			cout << "Bisiesto." << endl;
		}else{
			cout << "No es bisiesto." << endl;
		}
	}else{
		cout << "No es bisiesto.." << endl;
	}
	
	return 0;
}
