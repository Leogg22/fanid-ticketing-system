#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
using namespace std;
int main()
{
	
	int opc;
	 do
    {
    	system("cls");
	cout<<"=======MENU DE USUARIO=======\n";
	cout<<"[1] CONSULTA DE PARTIDOS"<<endl;
	cout<<"[2] COMPRAR BOLETOS"<<endl;
	cout<<"[3] CONSULTA DE BOLETOS COMPRADOS"<<endl;
	cout<<"[4] SALIR"<<endl;
	cout<<"SELECCIONE UNA OPCION: ";
	cin>>opc;
	
	switch(opc){
		case 1:
			{
		system("cls");
		system("E:\\FANID\\consultasPartidos.exe");
		 system("pause");
		break;
		}
		
		case 2:
			{
		system("cls");
		system("E:\\FANID\\compra.exe");
		 system("pause");
		break;
		}
		
		case 3:
			{
		system("cls");
		system("E:\\FANID\\consultacom.exe");
		 system("pause");
		break;
		}
				case 4:
		system("cls");
		system("E:\\FANID\\inicio.exe");
                break;
	
	
		
	}
	 } while (opc != 4);
}
