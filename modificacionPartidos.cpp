#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Definiendo las variables necesarias

 string local, auxlocal, visitante, auxvisitante, estadio, auxestadio, fecha, auxfecha, sVIP, auxsVIP, sOK, auxsOK, sBleh, auxsBleh;
 int matricula=0, auxmatricula=0;
 char opca;
 bool encontrado = false;

int main()
{
	ofstream aux;
	ifstream lectura;
	encontrado=false;
	aux.open("auxiliar.txt", ios::out);
	lectura.open("partidos.txt", ios::in);
	
	if (aux.is_open() && lectura.is_open())
	{
			cout<<"=======MODIFICAR PARTIDOS=======\n";
		cout << "\n";
		cout << "\tMatricula del partido a modificar: ";
		cin >> auxmatricula;
		lectura >> matricula;
		
		while (!lectura.eof())
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
				cout << "\t___________________________\n";
				
				cout << "\n\tNuevo equipo local del producto " << auxmatricula << " : ";
				cin >> auxlocal;
				
				cout << "\n\tNuevo equipo visitante : ";
				cin >> auxvisitante;
				
				cout << "\n\tNuevo estadio : ";
				cin >> auxestadio;
				
				cout << "\n\tNueva fecha : ";
				cin >> auxfecha;
				
				cout << "\n\tNuevo costo VIP : ";
				cin >> auxsVIP;
				
				cout << "\n\tNuevo costo medio : ";
				cin >> auxsOK;
				
				cout << "\n\tNuevo costo economico : ";
				cin >> auxsBleh;
				
				aux << auxmatricula << " " << auxlocal << " " << auxvisitante << " " << auxestadio << " " << auxfecha << " " << auxsVIP << " " << auxsOK << " " << auxsBleh << endl;
				cout << "\n\n\t\t\tRegistro modificado...\n\t\t\a";
				
				system("pause");
				break;
			}
			else
			{
				aux << matricula << " " << local << " " << visitante << " " << estadio << " " << fecha << " " << sVIP << " " << sOK << " " << sBleh << endl;
			}
			lectura >> matricula;
		}
	}
	else {
		cout << "\n\tEl archivo no se pudo abrir \n";
	}
	
	if (encontrado==false)
	{
		cout << "\n\tNo se encontro ningun registro con la clave: " << auxmatricula << "\n\n\t\t\t";
	}
	aux.close();
	lectura.close();
	remove("partidos.txt");
	rename("auxiliar.txt", "partidos.txt");
}
