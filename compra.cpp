#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Partido {
    int matricula;
    string local;
    string visitante;
    string estadio;
    string fecha;
    string sVIP;
    string sOK;
    string sBleh;
};

bool verificarMatricula(const string& matricula) {
    ifstream archivo("usuarios.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(",");
        if (pos != string::npos) {
            string matriculaUsuario = linea.substr(0, pos);
            if (matriculaUsuario == matricula) {
                archivo.close();
                return true;
            }
        }
    }

    archivo.close();
    return false;
}

int main() { setlocale(LC_ALL, "");
    string matricula;
    	cout<<"=======COMPRA DE BOLETO=======\n";
    cout << "Ingrese su matricula de usuario: ";
    cin >> matricula;

    if (!verificarMatricula(matricula)) {
        cout << "Matricula no encontrada en el archivo de usuarios." << endl;
        return 1;
    }

    ofstream archivoComprados("comprados.txt", ios::app);
    if (!archivoComprados) {
        cout << "Error al abrir el archivo de comprados." << endl;
        return 1;
    }
    archivoComprados << matricula << " ";

    int matriculaPartido;
    cout << "Ingrese la matricula del partido: ";
    cin >> matriculaPartido;

    ifstream archivoPartidos("partidos.txt");
    if (!archivoPartidos) {
        cout << "Error al abrir el archivo de partidos." << endl;
        return 1;
    }

    Partido partido;
    bool encontrado = false;

    while (archivoPartidos >> partido.matricula >> partido.local >> partido.visitante >> partido.estadio >> partido.fecha >> partido.sVIP >> partido.sOK >> partido.sBleh) {
        if (partido.matricula == matriculaPartido) {
            encontrado = true;
            break;
        }
    }

    archivoPartidos.close();

    if (encontrado) {
        cout << "\nPartido encontrado:" << endl;
        cout << "Local: " << partido.local << endl;
        cout << "Visitante: " << partido.visitante << endl;
        cout << "Estadio: " << partido.estadio << endl;
        cout << "Fecha: " << partido.fecha << endl;

        cout << "\nPrecios disponibles:" << endl;
        cout << "1. VIP - Precio: " << partido.sVIP << endl;
        cout << "2. Media - Precio: " << partido.sOK << endl;
        cout << "3. Economica - Precio: " << partido.sBleh << endl;

        int opcion;
        cout << "Seleccione el tipo de asiento (1-3): ";
        cin >> opcion;

        string tipoAsiento;
        string precio;
        
        switch (opcion) {
            case 1:
                tipoAsiento = "VIP";
                precio = partido.sVIP;
                break;
            case 2:
                tipoAsiento = "Media";
                precio = partido.sOK;
                break;
            case 3:
                tipoAsiento = "Economica";
                precio = partido.sBleh;
                break;
            default:
                cout << "Opcion invalida." << endl;
                return 1;
        }

        archivoComprados << partido.local << " " << partido.visitante << " " << partido.estadio  << " " << partido.fecha << " " << tipoAsiento << " " << precio << endl;
        archivoComprados.close();

        cout << "Compra guardada exitosamente en el archivo de comprados." << endl;
    } else {
        cout << "No se encontro ningun partido con la matricula especificada." << endl;
    }

    return 0;
}

