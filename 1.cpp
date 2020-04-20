/*
Ejercicio # 1:
Se dispone de un archivo STOCK correspondiente a la existencia de art�culos de un almac�n 
y se desea se�alar aquellos art�culos cuyo nivel est� por debajo del m�nimo y que visualicen un mensaje �hacer pedido�.
 Cada art�culo contiene un registro con los siguientes campos: n�mero del c�digo del art�culo, nivel m�nimo, nivel actual, proveedor, precio.
 
El programa debe tener un menu que se especifiquen las siguientes opciones:
1) Agregar productos (Grabar datos a un archivo)
2) Leer archivo y mostrar en pantalla que productos tiene nivel minimo. 

*if (nivel actual==nivel m�nimo)
    cout<<"Nivel Minimo";
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

struct items{
  string codigo;
  int minimo;
  int actual;
  string proveedor;
  float precio;
};

std::vector<items> producto;

void agregar_producto(){
  items x;
  cout << "Digite el c�digo del producto"<< "\n";
  cin >> x.codigo;
  cout << "Digite el minimo del producto"<< "\n";
  cin >> x.minimo;
  cout << "Digite la cantidad actual del producto"<< "\n";
  cin >> x.actual;
  cout << "Digite el proveedor del producto"<< "\n";
  cin >> x.proveedor;
  cout << "Digite el precio del producto"<< "\n";
  cin >> x.precio;

    //producto en el archivo.
    ofstream miarchivo("stock.txt", std::ios_base::app);
    miarchivo << x.codigo << "\t" << x.minimo << "\t" << x.actual << "\t" << x.proveedor << "\t" << x.precio << endl;
    //Cerrar la escritura 
    miarchivo.close();
}

void mostrar_informacion(){
  
cout << "LOS SIGUIENTES PRODUCTOS NECESITAN SER REABASTECIDOS" << endl;
cout << "---------------------------------------------" << endl;
cout << "COD"<< "\t" << "MIN" << "\t" << "EXI" << "\t" << "PROVEEDOR" << "\t" << "PRE" << endl;
cout << "---------------------------------------------" << endl; 

 for (int i=0; i< producto.size(); i++){
   if (producto[i].minimo>=producto[i].actual){
      cout << producto[i].codigo << "\t" << producto[i] .minimo << "\t" << producto[i].actual << "\t" <<   producto[i].proveedor << "\t" << producto[i].precio <<  "\t" << endl;
   }
 }
   string empty;
    cin >> empty;
    return;
}

void leer_archivo(){
    ifstream miarchivo;

    producto.clear();

    items prod;

    //abrimos archivo 
    miarchivo.open("stock.txt",ios::in);
    
    while(miarchivo >> prod.codigo >> prod.minimo >> prod.actual >> prod.proveedor >> prod.precio)
    {

        producto.push_back(prod);
    }

    //Cerramos el archivo
    miarchivo.close();
    mostrar_informacion();
    return;
}

int main() {
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Productos" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Agregar Producto" <<endl;
        cout << "\t2 .- Leer archivo y mostrar minimos" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        agregar_producto();
        break;
 
			case '2':
        system("clear");
        leer_archivo();
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
