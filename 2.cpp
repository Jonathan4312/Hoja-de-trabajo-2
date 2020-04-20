/*
Ejercicio # 2:
El director de un colegio desea realizar un programa que procese un archivo de
registros correspondiente a los diferentes alumnos del centro a fin de obtener los siguientes datos:

Nota más alta y número de identificación del alumno correspondiente.
Nota media del colegio.
Datos de Estudiantes:

Identificación
Nombre
Nota
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

struct estudiantes{
  int item;
  string nombre;
  string apellido;
  float nota;
};

std::vector<estudiantes> alumno;

void calculo_notas(){
  cout << "LA MEJOR NOTA ES: " << endl;
  cout << "=============================================" << endl;
  cout << "ID"<< "\t" << "Nombre" << "\t" << "Apellido" << "\t" << "Nota" << endl;
  cout << "---------------------------------------------" << endl; 

  float nota=0.0;
  float nota_media=0.0;

  estudiantes nota_alta;
  for (int i=0; i<alumno.size(); i++){
    if (alumno[i].nota>=nota){
      nota_alta=alumno[i];
      nota=alumno[i].nota;
    }
    nota_media=nota_media+alumno[i].nota;
  }
    // Calculamos la media de las notas del colegio
  nota_media=nota_media/alumno.size();

  cout <<nota_alta.item << "\t" <<nota_alta.nombre << "\t" <<nota_alta.apellido << "\t" <<nota_alta.nota << endl;
  cout << "--------------------------------------------"<< endl;
  cout << "--------------------------------------------"<< endl;
  cout << "LA NOTA MEDIA ES: " << nota_media << endl;
    
  string empty;
  cin >> empty;
  return;
}

void grabar(){
  estudiantes x;
  cout << "Ingrese Número de Carne del alumno"<< "\n";
  cin >> x.item;
  cout << "Ingrese Primer Nombre del alumno"<< "\n";
  cin >> x.nombre;
  cout << "Ingrese Primer apellido del alumno"<< "\n";
  cin >> x.apellido;
  cout << "Ingrese Nota del alumno"<< "\n";
  cin >> x.nota;
  // grabamos en el archivo
  ofstream miarchivo("estudiantes.txt", std::ios_base::app);
  miarchivo << x.item << "\t" << x.nombre << "\t" << x.apellido << "\t" << x.nota << endl;
  //Cerramos la escritura del archivo.
  miarchivo.close();
}

void leer(){
    ifstream miarchivo;
    alumno.clear();
    estudiantes alum;
    miarchivo.open("estudiantes.txt",ios::in);
    while(miarchivo >> alum.item >> alum.nombre >> alum.apellido >> alum.nota)
    {
        alumno.push_back(alum);
    }
    miarchivo.close();
    calculo_notas();
    return;
}

int main(){
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Control de notas del Colegio" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Ingresar alumno" <<endl;
        cout << "\t2 .- Leer registros y mostrar reporte" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        grabar();
        break;
 
			case '2':
        system("clear");
        leer();
        break;
      
      case '3':
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("clear");
				cout << "Opcion no valida.\a\n";
				getchar();
        getline(cin, empty);
				break;
		}
    }while(bandera!=true);
  return 0;
}
