#include "tablero.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
Tablero::Tablero(){
	nivel = 0;
	tiempoJuego = 0;
	gemasMente = 0;
	Puntaje = 0;
	chasquido = false;
  jugadas=20;
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

/*
Nombre:victoria
 Parametros: Ninguno
 Funcion: Comprobar si se ha alcanzado el puntaje requerido en la cantidad de jugadas disponible,lanzando un mensaje dependiendo del caso 
 Salida:Ninguna.
 */ 
void Tablero::victoria(){	
  if(Puntaje>=100000){
		cout<<"Thanos ha cumplido su acometido, la mitad del mundo ha sido borrada y el equilibrio esta reestablecido"<<endl;
    cout<<"FELICITACIONES"<<endl;
	}else if(Puntaje<=100000&&jugadas==0){
		cout<<"Thanos no ha sido capaz de reestablecer el equilibrio y ha sido derrotado"<<endl;
    cout<<"GAME OVER"<<endl;
	}
}

/*
Nombre:selectLevel
Parametros: String
Funcion: Esta funcion selecciona el nivel a jugar y extrae lo datos del txt para mostrar el nivel
Salida:Ninguna
*/

void Tablero::selectLevel(string nombre_archivo){
	ifstream archivo(nombre_archivo.c_str());
	int aux = 0;
	archivo >> aux;
	nivel = aux;
	archivo >> aux;
	tiempoJuego = aux;
  	for(int i = 0;i<=5;i++){
		archivo >> aux;
		Puntaje += aux;
		aux = 0;
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
/*
Nombre:mostrarTablero
Parametros:Ninguno
Funcion:Mostrar el tablero de juego, una vez todos los matches surgidos tras una jugada se hallan calculado ademas de imprimir el puntaje.
Salida:Ninguna
*/
void Tablero::mostrarTablero(){   
 	srand(time(NULL));
 	cout << "|---|---|---|---|---|---|---|---|" << endl;
	cout << "|X Y| 0 | 1 | 2 | 3 | 4 | 5 | 6 |" << endl;
	cout << "|---|---|---|---|---|---|---|---|" << endl;
	for(int i=0;i<7;i++){
		cout<<"| " << i << " |";
		desbloqueo();
		for(int j = 0; j<7; j++){
      		if (matriz[i][j]==0){      
      			int num=1+rand()%(6-1);
      			matriz[i][j]=num;
      		}
			cout << " "<< matriz[i][j] << " |";
		}
		cout << endl;
		cout << "|---|---|---|---|---|---|---|---|" << endl;
	}  
	cout << endl;
	cout << "El Puntaje actual es: " << Puntaje << endl;
  contador();

 //Aqui se resuelven todos lo matches posibles
  for(int i = 0;i < 7; i++){
	  for(int j = 0; j < 7; j++){      
     	int x=matriz[i][j];
		  if(x == matriz[i-1][j]){
           match();
		  }
		  else if(x == matriz[i+1][j]){
       		match();
   		  }
   		  else if(x == matriz[i][j-1]){
       		match();
   		  }
   	  	else if(x == matriz[i][j+1]){
       		match();
		  }
	  }
  }



}
/*
Nombre:guardarTablero
Parametros:Ninguno
Funcion:Una vez el usuario quiera dejar el juego,esta funcion le permite darle un nombre a la partida para posteriormente guardar los datos de la partida en un txt.
Salida:Ninguna
*/
void Tablero::guardarTablero(){
	ofstream Guardando;
	cout << "ingresa el nombre de esta partida" << endl;
	string aux;
	cin >> aux;
	Guardando.open(aux + ".txt");//Apesar de que esta linea parece tirar error, realmente no hay problema alguno
	Guardando << nivel << endl;
	Guardando << tiempoJuego << endl;
	for(int i = 0;i<=4;i++){
		Guardando << 0 << endl;
  	}
	Guardando << Puntaje << endl;
	for(int i=0;i<7;i++){
		for(int j = 0; j<7; j++){
			Guardando << matriz[i][j] << " ";
		}
		Guardando << endl;
	}
}
/*
Nombre:movimiento
Parametros:Ninguno
Funcion:Pide al usuario ingresar los datos de las gemas que quiera mover, verifica si el movimiento es valido, en caso contrario tira un mensaje indicando esto,de ser valido cambia las posiciones de las gemas,llama a match y a mostrartablero,le resta 1 al numero de jugadas y llama a la funcion victoria
Salida:Ninguna
*/
void Tablero::movimiento(){
  if(jugadas>0)
  {
    	int posX1,posY1,posX2,posY2;
	cout << "ingrese la posicion Y, X del primer punto" << endl;
	
	cin >> posX1; //Posicion x de la gema 1
	cin >> posY1; //Posicion y de la gema 1

  //En caso de que el usuario ingrese un numero fuera de rango se acomada a un valor predeterminado
	if(posX1 > 6){posX1 = 6;}
	if(posX1 < 0){posX1 = 0;}
	if(posY1 > 6){posY1 = 6;}
	if(posY1 < 0){posY1 = 0;}
	
	cout << "["<< posX1 <<"]["<< posY1 <<"]" << endl;
	cout << "ingrese la posicion Y, X del segundo punto" << endl;
	
	cin >> posX2; //Posicion x de la gema 2
	cin >> posY2; //Posicion y de la gema 2

  //En caso de que el usuario ingrese un numero fuera de rango se acomada a un valor predeterminado
	if(posX2 > 6){posX2 = 6;}
	if(posX2 < 0){posX2 = 0;}
	if(posY2 > 6){posY2 = 6;}
	if(posY2 < 0){posY2 = 0;}
	
	cout << "["<< posX2 <<"]["<< posY2 <<"]" << endl;
  //Se revisa que las posiciones no sean las mismas
	if(posX1 == posX2 && posY1 == posY2){
		cout << "no puedes realizar este intercambio" << endl;
	}
	else if((posX1 == posX2 || posY1 == posY2) && ((posX1+1 == posX2 || posX1-1 == posX2) || (posY1+1 == posY2 || posY1-1 == posY2))){
		if((matriz[posX1][posX2] != 9) && (matriz[posX2][posY2] != 9)){
			swap(matriz[posX1][posY1],matriz[posX2][posY2]);
		}
		else{
			cout << "no puedes realizar este intercambio" << endl;
		}
    	match();
		mostrarTablero();
	}
	else{
		cout << "no puedes realizar este intercambio" << endl;
	}
 cout<<"Numero de jugadas restante: "<<jugadas<<endl; } jugadas-=1;
 victoria();
}
/*
Nombre:contador
Parametros:Ninguno
Funcion:Contabilizar cuantas gemas de cada tipo hay y madar un mensaje con la cantidad total de cada una.
*/
void Tablero::contador(){
	int a1=0, a2=0, a3=0, a4=0, a5=0, a6=0;
	for(int i=0;i<7;i++){
     	for(int j = 0; j<7; j++){
			if (matriz[i][j]==1)/*Poder*/{
         		a1=a1+1;
       		} else if (matriz[i][j]==2)/*Espacio*/{
         		a2=a2+1;
       		} else if (matriz[i][j]==3)/*Tiempo*/{
         		a3=a3+1;
       		} else if (matriz[i][j]==4)/*Alma*/{
         		a4=a4+1;
       		} else if (matriz[i][j]==5)/*Realidad*/{
         		a5=a5+1;
       		} else if (matriz[i][j]==6 || matriz[i][j]==9)/*Mente*/{
         		a6=a6+1;
       		}      
    	}    
  	}
  	cout<<"Cantidad de gemas (1) poder: "<<a1<<endl;
  	cout<<"Cantidad de gemas (2) espacio: "<<a2<<endl;
  	cout<<"Cantidad de gemas (3) tiempo: "<<a3<<endl;
  	cout<<"Cantidad de gemas (4) alma: "<<a4<<endl;
  	cout<<"Cantidad de gemas (5) realidad: "<<a5<<endl;
  	cout<<"Cantidad de gemas (6 o 9 si esta bloqueada) mente: "<<a6<<endl;        
}
/*
Nombre:match
Parametros:Ninguno
Funcion:Recorrer el tablero,ver si hay match y darle puntos al jugador de ser asi,luego llama a mostrartablero
*/
void Tablero::match()
{
 //recorre el tablero analizando igualdad entre las gemas de los lados
  for(int i = 6;i >= 0; i--){
	  for(int j = 6; j >= 0; j--){      
     	int x=matriz[i][j];
		  if(x == matriz[i-1][j]){
           matriz[i][j]=0;
   			  matriz[i-1][j]=0;
			  Puntaje += 1000;
		  }
		  if(x == matriz[i+1][j]){
       		matriz[i][j]=0;
       	  matriz[i+1][j]=0;
			  Puntaje += 1000;
   		  }
   		  if(x == matriz[i][j-1]){
       		matriz[i][j]=0;
       	  matriz[i][j-1]=0;
			  Puntaje += 1000;
   		  }
   	  	if(x == matriz[i][j+1]){
       		matriz[i][j]=0;        
       	  matriz[i][j+1]=0;
			  Puntaje += 1000;
		  }
	  }
  }
  mostrarTablero();
}  
/*
Nombre:desbloqueo
Parametros:Ninguno
Funcion:se encarga de revisar si se realiza un match cerca de un 9(gema mente bloqueda) para poder deblosquearla, hay un match cerca si un numero cercano es igual a 0.
*/
void Tablero::desbloqueo(){
	for(int i = 6;i >= 0; i--){
		for(int j = 6; j >= 0; j--){
      		int x=matriz[i][j];
			if(matriz[i-1][j]==0&&x==9){
        		matriz[i][j]=6;
      		}
      		if(matriz[i+1][j]==0&&x==9){
        		matriz[i][j]=6;
    		}
			if(matriz[i][j-1]==0&&x==9){
        		matriz[i][j]=6;
      		}	
      		if(matriz[i][j+1]==0&&x==9){
        		matriz[i][j]=6; 
      		}
		}
	}
}
void Tablero::ordenarlos(int temporal){
	if(temporal < 7){
		if(matriz[temporal][0] != matriz[temporal+1][0]){
			ordenarlos(temporal+1);
		}
		if(matriz[0] != matriz[1]){ordenarlos(temporal+1);}
	}
}