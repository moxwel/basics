#include <iostream>
#define sep " | "
#define line "-----------"
#define sub "====="
using namespace std;

char gato[3][3]; //arreglo gato
int t; //turnos

void tablero() {
	cout << " " << gato[0][0] << sep << gato[0][1] << sep << gato[0][2] << "\t   0 0 | 0 1 | 0 2" << endl;
	cout << line << "\t" << line line << endl;
	cout << " " << gato[1][0] << sep << gato[1][1] << sep << gato[1][2] << "\t   1 0 | 1 1 | 1 2" << endl;
	cout << line << "\t" << line line << endl;
	cout << " " << gato[2][0] << sep << gato[2][1] << sep << gato[2][2] << "\t   2 0 | 2 1 | 2 2\t3 3 = SALIR" << endl;
	cout << endl;
}

bool valido(int x, int y) { //deteccion de validez
							//si la coordenada supera el limite del tablero...
	if ((x > 2) || (y > 2)) {
		return false;
	}
	if ((x < 0) || (y < 0)) {
		return false;
	}

	//si la coordenada ya tiene un valor designado anteriormente...
	if ((gato[x][y] == 'X') || (gato[x][y] == 'O')) {
		return false;
	}
	else {
		return true;
	}
}

bool win(char j) { //verificacion de victoria
	int x, y, cont;
	cont = 0;

	for (x = 0; x < 3; x++) { //deteccion horizontal
		cont = 0;
		for (y = 0; y < 3; y++) {
			if (gato[x][y] == j) {
				cont++;
			}
			if (cont == 3) {
				return true;
			}
		}
	}

	cont = 0;

	for (y = 0; y < 3; y++) { //deteccion vertical
		cont = 0;
		for (x = 0; x < 3; x++) {
			if (gato[x][y] == j) {
				cont++;
			}
			if (cont == 3) {
				return true;
			}
		}
	}

	if ((gato[0][0] == j) && (gato[1][1] == j)) { //deteccion diagonal hacia abajo
		if (gato[2][2] == j) {
			return true;
		}
	}

	if ((gato[2][0] == j) && (gato[1][1] == j)) { //deteccion diagonal hacia arriba
		if (gato[0][2] == j) {
			return true;
		}
	}

	return false;
}

int main() {
	//variables
	int i, j, x, y, t;
	bool game, jo, jx;
	game = true;
	jo = true;
	jx = true;
	t = 0;

	//ini. tablero
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			gato[i][j] = ' ';
		}
	}

	cout << "GATO\n" << sub sub sub sub sub sub sub << endl;
	cout << "Tablero\t\tCoordenadas" << endl;
	tablero();

	while (game == true) { //juego en curso

		while (jo == true) { //turno de O
			t++;

			if (t == 10) { //empate
				cout << "> EMPATE <" << endl;
				game = false;
				break;
			}

			cout << "[Turno " << t << "]\nJUGADOR O | Donde quieres jugar?: ";
			cin >> x >> y;

			if ((x == 3) && (y == 3)) { //3 3 = salir del juego
				cout << "< SALIR >" << endl;
				jo = false;
				jx = false;
				game = false;
				break;
			}

			if (valido(x, y) == true) { //jugada valida
				gato[x][y] = 'O';
				tablero();
				jo = false;
				jx = true;
				break;
			}
			else {
				cout << "/// Jugada no valida ///" << endl;
				tablero();
				t--;
			}
		} //fin del turno O

		if (win('O') == true) {
			cout << "> JUGADOR O GANA!!! <" << endl;
			game = false;
			break;
		}

		while (jx == true) { //turno de X
			t++;

			if (t == 10) { //empate
				cout << "> EMPATE <" << endl;
				game = false;
				break;
			}

			cout << "[Turno " << t << "]\nJUGADOR X | Donde quieres jugar?: ";
			cin >> x >> y;

			if ((x == 3) && (y == 3)) { //3 3 = salir del juego
				cout << "< SALIR >" << endl;
				jo = false;
				jx = false;
				game = false;
				break;
			}

			if (valido(x, y) == true) { //jugada valida
				gato[x][y] = 'X';
				tablero();
				jo = true;
				jx = false;
				break;
			}
			else {
				cout << "/// Jugada no valida ///" << endl;
				tablero();
				t--;
			}
		} //fin del turno X

		if (win('X') == true) {
			cout << "> JUGADOR X GANA!!! <" << endl;
			game = false;
			break;
		}
	}
	return 0;
}
