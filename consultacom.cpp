#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Partido {
    string matriculaUsuario;
    string local;
    string visitante;
    string estadio;
    string fecha;
    string tipoAsiento;
    string precio;
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

void mostrarInformacion(const vector<Partido>& partidos) {
    for (size_t i = 0; i < partidos.size(); ++i) {
        const Partido& partido = partidos[i];
        
        cout << "Matricula del usuario: " << partido.matriculaUsuario << endl;
        cout << "Partido: " << partido.local << " vs " << partido.visitante << endl;
        cout << "Estadio: " << partido.estadio << endl;
        cout << "Fecha: " << partido.fecha << endl;
        cout << "Tipo de Asiento: " << partido.tipoAsiento << endl;
        cout << "Precio: " << partido.precio << endl;
        cout << endl;
    }
}

int main() {
	    cout << "=========================\n";
        cout << "   BOLETOS COMPRADOS\n";
        cout << "=========================\n";
    string matricula;
    cout << "Ingrese su matricula de usuario: ";
    cin >> matricula;

    if (!verificarMatricula(matricula)) {
        cout << "Matricula no encontrada en el archivo de usuarios." << endl;
        return 1;
    }

    vector<Partido> partidos;

    ifstream archivo("comprados.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo de comprados." << endl;
        return 1;
    }

    Partido partido;
    while (archivo >> partido.matriculaUsuario >> partido.local >> partido.visitante >> partido.estadio >> partido.fecha >> partido.tipoAsiento >> partido.precio) {
        if (partido.matriculaUsuario == matricula) {
            partidos.push_back(partido);
        }
    }

    archivo.close();

    if (partidos.empty()) {
        cout << "No se encontraron partidos comprados para la matricula especificada." << endl;
    } else {
        cout << "Partidos encontrados:" << endl;
        mostrarInformacion(partidos);
    }

    return 0;
}

