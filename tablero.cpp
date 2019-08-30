#include "tablero.h"
#include<stdlib.h>
#include<time.h>

using namespace std;
Tablero::Tablero(){
	nivel = 0;
	tiempoJuego = 0;
	gemasMente = 0;
	Puntaje.resize(6);
	for(int i=0;i<5;i++){
		Puntaje[i] = 0;
	}
	chasquido = false;
}
Tablero::~Tablero(){
}
/* 
Debido a incompatibilidad con replit la funcion cronometro esta en comentada
void Tablero::cronometro(int limite){
	// funcion que cuenta cada segundo para ser mostrado en un timer en pantalla
	int mm = 0, ss = 0;
	while (mm < limite) {
		ss++;
		if (ss == 60) {
			ss = 0;
			mm++;
			tiempoJuego -= 1
		}
		system("cls");
		cout << mm << ":" << ss << endl;
		Sleep(1000);
	}
	
}
*/
//Esta funcion revisa si se ha hecho un chasquido y retorna un true o false de acuerdo a esto
bool Tablero::victoria(){
	if(chasquido){
		return true;
	}else{
		return false;
	}
}
//Esta funcion selecciona el nivel a jugar y extrae lo datos del txt para mostrar el nivel
void Tablero::selectLevel(string nombre_archivo) {
	ifstream archivo(nombre_archivo.c_str());
	int aux = 0;
	archivo >> aux;
	nivel = aux;
	archivo >> aux;
	tiempoJuego = aux;
  	for(int i = 0;i<=5;i++){
    	archivo >> Puntaje[i];
  	}
	for(int i=0;i<7;i++){
		for(int j = 0; j<7; j++){
			archivo >> matriz[i][j];
			if(matriz[i][j] == 6){
				matriz[i][j] = 9;
			}
			if(matriz[i][j] == 9 && gemasMente == 3){
				matriz[i][j] = rand() %(6-1);
			}
			if((gemasMente <= 2) && (matriz[i][j] == 9 || matriz[i][j] == 6)){
				gemasMente+=1;
			}
		}
	}
}
void Tablero::mostrarTablero(){
  srand(time(NULL));
	cout<<"   0|1|2|3|4|5|6"<<endl;
	for(int i=0;i<7;i++){
		cout<<i<<"| ";
		desbloqueo();
		for(int j = 0; j<7; j++){
      if (matriz[i][j]==0)
      {      
      {
        matriz[i][j]=0;        
        matriz[i][j+1]=0;
      }

		}
	}  
}
void Tablero::desbloqueo(){
	for(int i = 6;i >= 0; i--){
		for(int j = 6; j >= 0; j--){
      int x=matriz[i][j];
	if(matriz[i-1][j]==0&&x==9)
      {
        matriz[i][j]=6;
      }
      	if(matriz[i+1][j]==0&&x==9)
      {
        matriz[i][j]=6;
      }
      	if(matriz[i][j-1]==0&&x==9)
      {
        matriz[i][j]=6;
      }
      	if(matriz[i][j+1]==0&&x==9)
      {
        matriz[i][j]=6; 
      }

		}
	}
}
