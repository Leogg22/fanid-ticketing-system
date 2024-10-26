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
	//Variables de la biblioteca fstream para el manejo de archivos
	ofstream escritura;
	ifstream consulta;
	do {
		escritura.open("partidos.txt", ios::out | ios::app);
		//Crea y escribe, si ya tiene texto une al final del archivo
		consulta.open("partidos.txt", ios::in);
		//Solamente consulta o lee usando la variable sobre el archivo fisico alumnos.txt
		
		if(escritura.is_open() && consulta.is_open())
		{
			bool repetido = false;
				cout<<"=======ALTA PARTIDOS=======\n";
			cout << "\n";
			cout << "Matricula del partido: ";
			cin >> auxmatricula;
				//A continuacion se aplica el tipo de lectura de archivos secuencial
			consulta >> matricula;
			
			while(!consulta.eof())
			{
				consulta >> local >> visitante >> estadio >> fecha >> sVIP >> sOK >> sBleh;
				
				if (auxmatricula == matricula)
				{
					cout << "\t\tEsta matricula ya existe...\n";
					repetido = true;
					break;
				}
				consulta >> matricula;
			}
				if (repetido == false)
				{
					cout << "\tEquipo local: ";
					cin >> local;
					
					cout << "\tEquipo visitante: ";
					cin >> visitante;
					
					cout << "\tEstadio del partido: ";
					cin >> estadio;
					
					cout << "\tFecha del partido: ";
					cin >> fecha;
					
					cout << "\tCosto de la seccion VIP: ";
					cin >> sVIP;
					
					cout << "\tCosto de la seccion media: ";
					cin >> sOK;
					
					cout << "\tCosto de la seccion economica: ";
					cin >> sBleh;
					
					//Escribiendo los datos capturados por el usuario en el archivo
					
					escritura << auxmatricula << " " << local << " " << visitante << " " << estadio << " " << fecha << " " << sVIP << " " << sOK << " " << sBleh << endl;
					
					cout << "\n\tRegistro agregado...\n";
				}
				
				cout << "\n\tDesea agregar otro partido? (S/N): ";
				cin >> opca;
		}
		else {
			cout << "El archivo no se pudo abrir \n";
		}
		escritura.close();
		consulta.close();
	} while (opca=='S' or opca=='s');
}
