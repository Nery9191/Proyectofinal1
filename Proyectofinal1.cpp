#include <iostream>
#include <vector>

using namespace std;

struct estudiante {
	string nombre;
	string apellidos;
	
};

vector<estudiante> estudiantes;
vector<string> dp = {"Guatemala", "Peten", "Jutiapa", "Jalapa"};

void mostardepartamentos() {
	
	for(size_t i = 0 ;i < dp.size(); i++){   
		cout<< i + 1 <<"."<<" "<< dp[i] <<endl;
	}
	cout<<endl;
}

void registrarEstudiante();

cout<< "ingresar nombre";
cin>> estudiante.nombre;
cout<< "ingresar apellido";
cin>> estudiante.apellidos;
cout<< "intrese el departamento";
mostrardepartamentos();


int main() {
    int opcion;
    do {
        cout << "Sistema de registro Universitario";
        cout << "1. Registro de estudiantes";
        cout << "2. Asignacion de cursos ";
        cout << "3. Control de notas";
        cout << "4. Reportes Academicos";
        cout << "5. Salir";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                cout << "funcion de agergar curso";
                break;
            case 3:
                cout << "funcion de registrar notas";
                break;
            case 4:
                cout << "funcion de generar reportes";
                break;
            case 5:
                cout << "Saliendo del sistema " << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 5);

    return 0;
}