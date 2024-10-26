#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string ADMIN_MATRICULA = "admin";
const string ADMIN_CONTRASENA = "1234";

bool usuarioExiste(const string& matricula, const string& contrasena) {
    ifstream archivo("usuarios.txt");
    string linea;

    while (getline(archivo, linea)) {
        
        size_t comaPos = linea.find(',');
        string usuario = linea.substr(0, comaPos);
        string password = linea.substr(comaPos + 1);

        if (usuario == matricula && password == contrasena) {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

int main() {
	setlocale(LC_ALL, "");
    string matricula;
    string contrasena;
        cout << "=========================\n";
        cout << "         LOG IN\n";
        cout << "=========================\n";
    cout << "Ingrese su matricula: ";
    cin >> matricula;

    cout << "Ingrese su contrasena: ";
    cin >> contrasena;

   
    if (matricula == ADMIN_MATRICULA && contrasena == ADMIN_CONTRASENA) {
       	system("cls");
		system("E:\\FANID\\menuad.exe");
		 system("pause");
    
        
        
    } else if (usuarioExiste(matricula, contrasena)) {
              	system("cls");
		system("E:\\FANID\\menuusu.exe");
		 system("pause");
        
    } else {
        cout << "Inicio de sesion fallido. Usuario no autorizado.\n";
        system("cls");
		system("E:\\FANID\\inicio.exe");
		
       
    }

    return 0;
}

