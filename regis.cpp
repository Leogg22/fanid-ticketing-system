#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <sstream> 

using namespace std;

    string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

string generarMatricula(const std::string& nombre) {
    string matricula = nombre.substr(0, 3); 

    
    int numAleatorio = rand() % 9000 + 1000;

 
    matricula += intToString(numAleatorio);

    return matricula;
}

int main() {
	setlocale(LC_ALL, "");
    string nombre;
    string contrasena;
        cout << "==============================\n";
        cout << "         Registrarse\n";      
        cout << "==============================\n";
    cout << "Ingrese su nombre: ";
    cin >> nombre;

   
    string matricula = generarMatricula(nombre);
    cout << "Su matricula generada es: " << matricula << endl;

    cout << "Ingrese su contrasena: ";
    cin >> contrasena;

   
   ofstream archivo("usuarios.txt", ios::app); 

    if (archivo.is_open()) {
        archivo << matricula << "," << contrasena << endl;
        archivo.close();
        cout << "Usuario registrado correctamente.\n";
               	system("cls");
		system("E:\\FANID\\inicio.exe");
		
    } else {
        cout << "Error al abrir el archivo.\n";
        system("cls");
		system("E:\\FANID\\inicio.exe");
		system("pause");
    }

    return 0;
}

