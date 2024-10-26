#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Definiendo las variables necesarias
	
 string local, auxlocal, visitante, estadio, fecha, sVIP, sOK, sBleh;
 int matricula=0, auxmatricula=0;
 char opca;
 bool encontrado = false;
 
int main()
{
	ofstream aux;
	ifstream lectura;
	encontrado==false;
	aux.open("auxiliar.txt", ios::out);
	lectura.open("partidos.txt", ios::in);
	
	if(aux.is_open() && lectura.is_open())
	{
			cout<<"=======BAJA PARTIDOS=======\n";
		cout << "\n";
		cout << "\tclave del partido a eliminar: ";
		cin >> auxmatricula;
			//De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
			//llegar al final del archivo gracias a la funcion.eof()
		lectura >> matricula;
		
		while(!lectura.eof())
		{
			lectura >> local >> visitante >> estadio >> fecha >> sVIP >> sOK >> sBleh;
			
			if (auxmatricula==matricula)
			{
				encontrado=true;
				
				cout << "\n";
				cout << "\tMatricula: " << matricula << endl;
				cout << "\tEquipo local: " << local << endl;
				cout << "\tEquipo visitante: " << visitante << endl;
				cout << "\tEstadio: " << estadio << endl;
				cout << "\tFecha: " << fecha << endl;
				cout << "\tCosto VIP: " << sVIP << endl;
				cout << "\tCosto medio: " << sOK << endl;
				cout << "\tCosto economico: " << sBleh << endl;
				cout << "\t___________________________\n\n";
				cout << "\tEsta seguro de querer eliminar el registro actual (S/N)? ---> ";
				cin >> opca;
					if (opca=='S' or opca=='s')
					{
						cout << "\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
					}
					
					else {
						aux << auxmatricula << " " << local << " " << visitante << " " << estadio << " " << fecha << " " << sVIP << " " << sOK << " " << sBleh << endl;
					}
			}
			else {
				aux << auxmatricula << " " << local << " " << visitante << " " << estadio << " " << fecha << " " << sVIP << " " << sOK << " " << sBleh << endl;
			}
			lectura >> matricula;
		}
	}
	else {
		cout << "\n\tEl archivo no se pudo abrir \n";
	}
		if(encontrado==false)
		{
			cout << "\n\tNo se encontro ningun registro con la matricula: " << auxmatricula << "\n\n\t\t\t";
		}
		aux.close();
		lectura.close();
		remove("partidos.txt");
		rename("auxiliar.txt", "partidos.txt");
}
