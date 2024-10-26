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

int main(){	setlocale(LC_ALL, "");
	
int op=0;
	 do
    {
	system("cls");
    cout << "=========================\n";
    cout << "|       INICIO          |\n";
    cout << "=========================\n";
    cout << "| [1] Log in            |\n";
    cout << "| [2] Registrarse       |\n";
    cout << "| [3] SALIR             |\n";
    cout << "=========================\n";
    cout << "| Elige una opción:     ";
    cin>>op;
if (op==1){
		system("cls");
		system("E:\\FANID\\login.exe");
		system("pause");
}
if (op==2){
		system("cls");
		system("E:\\FANID\\regis.exe");
		 system("pause");
}
if (op==3){
		     cout<<"\n\n\tHa elegido salir...\n\n\t\t";
                system("pause");
                break;
}
 } while (op != 3);
}
