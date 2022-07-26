#include <iostream>
using namespace std;

int n[] = {53,78,6,92,87};

void arr(){ //imprimir arreglo
	cout << "Variable:" << endl;
	for (int i = 0; i < 5; i++){
		cout << i << " es = " << n[i] << endl;
	}
}

void ordenar(){
	int temp;
	
	/*while (true){ MALO(?
		cont = 0;
		
		if (n[i] > n[i+1]){
			menor = n[i+1];
			mayor = n[i];
			n[i] = menor;
			n[i+1] = mayor;
			i++;
		}else{ //esta correcto
			cont++;
			i++;
		}
		
		if (cont == 5){
			break;
		}
	}*/
	
	for (int i = 0; i < 5; i++){
		
		/*if (n[i] > n[i+1]){
			menor = n[i+1];
			mayor = n[i];
			n[i] = menor;
			n[i+1] = mayor;
		}else{ //esta correcto
			cont++;
		}*/
		
		for (int j = 0; j < 4; j++){
			if (n[j] > n[j+1]){ //el numero de al lado es menor
				temp = n[j]; //se guarda el numero mayor
				n[j] = n[j+1];
				n[j+1] = temp;
			}
		}
	}
}

int main(){
	arr();
	cout << "\n===\n\n";
	
	ordenar();
	
	arr();
	
	return 0;
}
