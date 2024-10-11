#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Cursos {
	string nombrec;
	string codigo;
	string creditos;
	string semestre;
	string codigoest;
	string Ciclo;
};

struct Estudiante {
	string nombre;
	string departamento;
	string municipio;
	
};

vector<Estudiante> estudiantes;
vector<Cursos> curso;

vector<vector<string>> departamentos = {
        {"Guatemala", "Guatemala", "Mixco", "Villa Nueva"},
        {"Alta Verapaz", "Cobán", "San Pedro Carchá", "Tucurú"},
        {"Baja Verapaz", "Salamá", "San Miguel Chicaj", "Rabinal"},
        {"Chimaltenango", "Chimaltenango", "San José Poaquil", "Tecuaco"},
        {"Escuintla", "Escuintla", "Santa Lucía Cotzumalguapa", "La Democracia"},
        {"Santa Rosa", "Cuilapa", "Barberena", "San Juan Tecuaco"},
        {"Solala", "Solala", "San José Chacaya", "Santa Catarina Palopo"},
        {"Totonicapán", "Totonicapán", "San Francisco El Alto", "Momostenango"},
        {"Quetzaltenango", "Quetzaltenango", "Colomba", "San Carlos Sija"},
        {"San Marcos", "San Marcos", "Tecoanapa", "San Miguel Ixtahuacán"},
        {"Huehuetenango", "Huehuetenango", "Chiantla", "Cuilco"},
        {"El Progreso", "Guastatoya", "San Antonio La Paz", "Sanarate"},
        {"Jalapa", "Jalapa", "Mataquescuintla", "San Pedro Pinula"},
        {"Zacapa", "Zacapa", "La Union", "Estanzuela"},
        {"Chiquimula", "Chiquimula", "Esquipulas", "San Jose La Arada"},
        {"Petén", "Flores", "San Benito", "Santa Elena"},
        {"Izabal", "Puerto Barrios", "Morales", "El Estor"},
        {"Baja Verapaz", "Salamá", "San Miguel Chicaj", "Rabinal"},
    }; 

vector<vector<string>> cursos = {
		{"Algoritmos","5","001"},
		{"Matematica Discreta","5","002"},
		{"Algebra lineal","5","003"},
		{"Contabilidad","5","004"},
		{"Precalculo","5","005"},		
};

vector<string> Semestres = {"Semestre I","Semestre II"};



void MostrarCursos(){
	Cursos asigcurso;
	
	for (size_t i = 0; i < Semestres.size(); i++) {
        cout << i + 1 << ". " << Semestres[i] << endl;
	}
	int SeleccionIndice;
	cout << "Ingrese el semestre"<<endl;
	cin >> SeleccionIndice;
	cout << endl;
	if (SeleccionIndice > 0 && SeleccionIndice <= Semestres.size()) {
        asigcurso.Ciclo = Semestres[SeleccionIndice - 1];
        }
    
	int Codindice;
	cout << "Ingrese el codigo del estudiante"<< endl;
	cin >> asigcurso.codigoest;
	cout <<endl;
	cout << "ingrese el curso" << endl;
	for (size_t i = 0; i < cursos.size(); i++) {
        cout << i + 1 << ". " << cursos[i][0] << endl;
	}
	cin >> Codindice;
	
	
	if (Codindice > 0 && Codindice <= cursos.size()) {
        asigcurso.nombrec = cursos[Codindice - 1][0];
    	asigcurso.codigo = cursos[Codindice - 1][2];
    	asigcurso.creditos = cursos[Codindice - 1][1];
        }
    curso.push_back(asigcurso);

}

void mostrarDyM(Estudiante &nuevoEstudiante){
	 int dptoIndice;
    cout << "Seleccione un departamento:\n";
    cout <<endl;
    for (size_t i = 0; i < departamentos.size(); i++) {
        cout << i + 1 << ". " << departamentos[i][0] << endl;
    }
    cin >> dptoIndice;
    
    if (dptoIndice > 0 && dptoIndice <= departamentos.size()) {
        nuevoEstudiante.departamento = departamentos[dptoIndice - 1][0];

	
	cout << "Municipios en " << nuevoEstudiante.departamento << ":\n";
        for (size_t i = 1; i < departamentos[dptoIndice - 1].size(); i++) {
            cout << i << ". " << departamentos[dptoIndice - 1][i] << endl;
        }
	
	int muniIndice;
        cout << "Seleccione un municipio:\n";
        cin >> muniIndice;
        
    if (muniIndice > 0 && muniIndice <= departamentos[dptoIndice -1].size()){
    	nuevoEstudiante.municipio = departamentos[dptoIndice - 1][muniIndice];
		}
	}else {
		 cout << "Indice de departamento no valido.\n";
	} 
}

void registroEstudiantes() {
	Estudiante nuevoEstudiante;
	
	cout << "Ingrese el nombres del estudiante: "<<endl;
    cin.ignore();
	getline(cin, nuevoEstudiante.nombre);
    
    cout << "Ingrese el departamento del estudiante: "<<endl;
    mostrarDyM(nuevoEstudiante);
    
    estudiantes.push_back(nuevoEstudiante);
	
}
void reportarEstudiantes() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- Reporte de Estudiantes ---\n";
    for (const auto& estudiante : estudiantes) {
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Departamento: " << estudiante.departamento << endl;
        cout << "Municipio: " << estudiante.municipio << endl;
    }
}
void reporteEstudiante1 (){   
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    for (const auto& Cursos : curso) {
        cout << "Curso: " << Cursos.nombrec << endl;
        cout << "Codigo de curso: " << Cursos.codigo << endl;
        cout << "Creditos curso: " << Cursos.creditos << endl;
        cout << "Semestre : " << Cursos.Ciclo << endl;
}
}

int main() {
    int opcion;
    do {
        cout << "\n--- Sistema de Gestion de Estudiantes ---\n";
        cout << "1. Registro de Estudiantes\n";
        cout << "2. Asignacion de cursos\n";
        cout << "3. Control de notas\n";
        cout << "4. Reportes Academicos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
		cout <<endl; 
        
        switch (opcion) {
            case 1:
                registroEstudiantes();
                break;
            case 2:
                MostrarCursos();
                break;
            case 3:
                cout << "Funcion";
                break;
            case 4:
                reportarEstudiantes();
                reporteEstudiante1();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion no válida.\n";
        }
    } while (opcion != 5);
    
    return 0;
}
 