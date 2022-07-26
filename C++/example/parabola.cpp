#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int opc1, h, k, focx, focy, px, py, pabs, dir, lr;
    
    bool fin;
    fin = false;
    while (fin == false){
        cout << "Selecciona modo:\n1 = Vertice/Foco\n2 =\n=====\n> Modo: ";
        cin >> opc1;
        
        switch (opc1){
            case 1: //opcion vertice/foco
            cout << "[Seleccion: Vertice/Foco]\n=====" << endl;
            
            //ingreso de vertice
            cout << "Ingresa las coordenadas del vertice:\n> Vertice (x,y): ";
            cin >> h >> k;
            cout << "[Vertice: (" << h << "," << k << ")]\n" << endl;
            
            //ingreso de foco
            cout << "Ingresa las coordenadas del foco: \n> Foco (x,y): ";
            cin >> focx >> focy;
            cout << "[Foco: (" << focx << "," << focy << ")]\n=====" << endl;
            
            //calculo de p
            px = focx - h;
            py = focy - k;
            
            cout << "Informacion de la parabola:" << endl;
            
            if (py == 0){
                cout << "- Sentido: Horizontal" << endl;
                
                dir = h - px;
                pabs = fabs (px);
                lr = pabs * 4;
                
                if (px > 0){
                    cout << "- Direccion: Derecha" << endl;
                }else if (px < 0){
                    cout << "- Direccion: Izquierda" << endl;
                }
                cout << "- P: " << pabs << endl;
                cout << "- Lado recto: " << lr << endl;
                cout << "- Directriz: X=(" << dir << ")\n=====\n" << endl;
            }else if (px == 0){
                cout << "- Sentido: Vertical" << endl;
                
                dir = k - py;
                pabs = fabs (py);
                lr = pabs * 4;
                    
                if (py > 0){
                    cout << "- Direccion: Arriba" << endl;
                }else if (py < 0){
                    cout << "- Direccion: Abajo" << endl;
                }
                cout << "- P: " << pabs << endl;
                cout << "- Lado recto: " << lr << endl;
                cout << "- Directriz: Y=(" << dir << ")\n=====\n" << endl;
            }else{
                cout << "No se xdxdxd\n=====\n" << endl;
            }
            
            break;
            //=====
            default:
            cout << "[Ingresa un valor valido]\n\n";
            break;
            }
        }
    return 0;
    }