#include <iostream>
using namespace std;

string text;

void conv(){
	for(int i = 0; text[i]; i++){
		if(text[i] == 'c'){
			text[i] = 'p';
		}else if(text[i] == 'e'){
			text[i] = 'o';
		}else if(text[i] == 'n'){
			text[i] = 'l';
		}else if(text[i] == 'i'){
			text[i] = 'a';
		}else if(text[i] == 't'){
			text[i] = 'r';
		}else if(text[i] == 'p'){
			text[i] = 'c';
		}else if(text[i] == 'o'){
			text[i] = 'e';
		}else if(text[i] == 'l'){
			text[i] = 'n';
		}else if(text[i] == 'a'){
			text[i] = 'i';
		}else if(text[i] == 'r'){
			text[i] = 't';
		}
	}
}

int main(){
	cout << "> Escriba algun texto (sin espacios):\n";
	cin >> text;
	
	conv();
	
	cout << "\nTraduccion:\n" << text << endl;
	
	return 0;
}
