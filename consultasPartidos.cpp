#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Definiendo las variables necesarias
	
 string local, visitante, estadio, fecha, sVIP, sOK, sBleh;
 int matricula=0, auxmatricula=0;
 char opca;
 bool encontrado = false;

int main()
{
	//lectura de archivos
	ifstream lectura;
	lectura.open("partidos.txt", ios::out | ios::in); //crea, escribe o lee
	
	if (lectura.is_open())
	{
		//leyendo y mostrando cada campo del archivo de forma secuencial
		lectura >> matricula;
		
		while (!lectura.eof())
		{
			lectura >> local >> visitante >> estadio >> fecha >> sVIP >> sOK >> sBleh;
				cout<<"\t=======PARTIDOS=======\n";
			cout << "\n";
			cout << "\tMatricula: " << matricula << endl;
			cout << "\tEquipo local: " << local << endl;
			cout << "\tEquipo visitante: " << visitante << endl;
			cout << "\tEstadio: " << estadio << endl;
			cout << "\tFecha: " << fecha << endl;
			cout << "\tCosto VIP: " << sVIP << endl;
			cout << "\tCosto medio: " << sOK << endl;
			cout << "\tCosto economico: " << sBleh << endl;
			lectura >> matricula;
			cout << "\t___________________________\n";
		}
	}
	else {
		cout << "El archivo no se pudo abrir \n";
	}
	lectura.close();
}
