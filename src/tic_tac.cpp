#include <iostream>
#include <string>
using namespace std;


int main (){
    char tablero [3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char jugador = 'X';
    bool terminado = false;
    int decision;
    int fila, columna;


         while (!terminado){

            cout<<"Tic-Tac-Toe"<<endl;
            cout<<"Jugador 1(X) - Jugador 2(O)\n";

            cout<<"Tablero de juego\n";
            for(int i = 0; i < 3; i++){
                for(int j=0; j<3; j++){
                    cout << " " << tablero[i][j]; 
                    if(j < 2) cout << " |";      
                }
                cout << endl;
                if(i < 2) cout << "-----------" << endl; 
            }

            cout<<"Jugador "<< jugador << ", ingresa tu movimiento(1-9, o 0 para reiniciar): ";
            cin>> decision;

            if(cin.fail() || (decision < 0 || decision > 9)){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada inválida. Ingresa un número del 1 al 9, o 0 para reiniciar.\n";
                continue;
            }

            if(decision == 0){

                char nuevo_tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        tablero[i][j] = nuevo_tablero[i][j];
                    }
                }
                jugador = 'X'; 
                cout << "Juego reiniciado!\n";
                continue;
            }


            fila = (decision - 1) / 3;
            columna = (decision - 1) % 3;


            if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O'){
                    tablero[fila][columna] = jugador;
            }else{
                cout << "Casilla ocupada, elige otra\n";
                    continue;
            }    

            for (int i = 0; i < 3; i++){

                if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]){
                    cout << "Jugador" << jugador << "gana!\n";
                        terminado = true;
                            break;
                }

                if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]){
                    cout << "Jugador" << jugador << "gana!\n";
                        terminado = true;
                            break;
                }
            }

            if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]){
                    cout << "Jugador" << jugador << " gana!\n";
                        terminado = true;
                            break;
            };
            if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]){
                cout << "Jugador " << jugador << " gana!\n";
                     terminado = true;
                        break;
            };


            bool completo = true;
            for (int i=0; i<3; i++ ){
                for (int j=0; j<3; j++){
                    if(tablero[i][j]!='O' && tablero[i][j]!='X'){
                        completo = false;
                        break;
                    }
                }
            }
            if(completo){
                cout<<"Empate. \n";
                     terminado = true;
            }


            if(!terminado){
                jugador = (jugador == 'X') ? 'O' : 'X'; 
            }
        }




        cout << "\n\tTic-Tac-Toe\n\n";
        for(int i = 0; i < 3; i++){
            for(int j=0; j<3; j++){
                cout << " " << tablero[i][j]; 
                if(j < 2) cout << " |";      
            }
            cout << endl;
            if(i < 2) cout << "-----------" << endl; 
        }

    return 0;
}