#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

enum Mes {
    Enero = 1, Febrero, Marzo, Abril, Mayo, Junio,
    Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre
};

struct Cursos {
    string nombrec;
    string codigo;
    string creditos;
    int semestre;
};

struct Estudiante {
    int codigo;
    string nombre;
    string apellido;
    string oficio;
    string departamento;
    string municipio;
    int telefonope;
    int telefonoca;
    int telefonoem;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
    int edad;
    string correo;
};

struct Nota {
    int codigoEstudiante; 
    string codigoCurso;
    float notaParcial1;
    float notaParcial2;
    float notaFinal;
    string estado;
};

struct Asignacion {
    int codigoEstudiante;
    string codigoCurso;
};


vector<Estudiante> estudiantes;
vector<Cursos> cursos; 
vector<Nota> notas;
vector<Asignacion> asignaciones;

vector<string> Carreras= {"Ingenieria en Sistemas","Administracion","Enfermeria"};
vector<vector<vector<string>>> cursosSemestre = {
    {
    	{"Semestre I"},
        {"Desarrollo Humano", "001", "4"},
        {"Contabilidad I", "002", "5"},
        {"Logica de Sistemas", "003", "5"},
        {"Introduccion a sistemas de Computo", "004", "5"},
        {"Metodilogia de la Investigacion", "005", "5"},
    },
    {
    	{"Semestre II"},
        {"Algoritmos", "006", "5"},
        {"Algebra lineal", "007", "5"},
        {"Contabilidad II", "008", "5"},
        {"Matematica Discreta", "009", "5"},
        {"Precalculo", "010", "5"},
    }
};

vector<vector<string>> departamentos = {
    {"Guatemala", "Guatemala", "Mixco", "Villa Nueva"},
    {"Alta Verapaz", "Coban", "San Pedro Carcha", "Tucuru"},
    {"Baja Verapaz", "Salama", "San Miguel Chicaj", "Rabinal"},
    {"Chimaltenango", "Chimaltenango", "San Jose Poaquil", "Tecuaco"},
    {"Escuintla", "Escuintla", "Santa Lucía Cotzumalguapa", "La Democracia"},
    {"Santa Rosa", "Cuilapa", "Barberena", "San Juan Tecuaco"},
    {"Solala", "Solala", "San Jose Chacaya", "Santa Catarina Palopo"},
    {"Totonicapan", "Totonicapan", "San Francisco El Alto", "Momostenango"},
    {"Quetzaltenango", "Quetzaltenango", "Colomba", "San Carlos Sija"},
    {"San Marcos", "San Marcos", "Tecoanapa", "San Miguel Ixtahuacáa"},
    {"Huehuetenango", "Huehuetenango", "Chiantla", "Cuilco"},
    {"El Progreso", "Guastatoya", "San Antonio La Paz", "Sanarate"},
    {"Jalapa", "Jalapa", "Mataquescuintla", "San Pedro Pinula"},
    {"Zacapa", "Zacapa", "La Union", "Estanzuela"},
    {"Chiquimula", "Chiquimula", "Esquipulas", "San Jose La Arada"},
    {"Peten", "Flores", "San Benito", "Santa Elena"},
    {"Izabal", "Puerto Barrios", "Morales", "El Estor"},
};


int generarCodigo() {
    static int codigo = 1; 
    return codigo++;
}

	void mostrarCarrera(Estudiante &nuevoEstudiante){
		cout <<endl;
		for (size_t i = 0; i < Carreras.size(); i++) {
        cout << i + 1 << ". " << Carreras[i] << endl;
    }
    
    int profesionIndice;
    while (true) {
        cout << "\nSeleccione la carrera: ";
        cin >> profesionIndice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada no válida. Por favor, ingrese un número.\n";
            continue; 
        }

        if (profesionIndice > 0 && profesionIndice <= Carreras.size()) {
            nuevoEstudiante.oficio = Carreras[profesionIndice - 1];
            break; 
        } else {
            cout << "Carrera no valida. Intente de nuevo.\n";
        }
        cout <<endl;
    }
	}

void AsignarCursos() {
	cout << "\n----Lista de estudiantes registrados:----\n";
	for (const auto& estudiante : estudiantes) {
        cout << "Codigo: " << estudiante.codigo << " Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
    }
    int codigoEstudiante;
    cout << "Ingrese el código del estudiante: ";
    cin >> codigoEstudiante;

    bool estudianteEncontrado = false;
    for (const auto& estudiante : estudiantes) {
        if (estudiante.codigo == codigoEstudiante) {
            estudianteEncontrado = true;
            break;
        }
    }

    if (!estudianteEncontrado) {
        cout << "Estudiante no encontrado.\n";
        return;
    }

    int ciclo;
    cout << "Ingrese el semestre (1 o 2): ";
    cin >> ciclo;
    if (ciclo < 1 || ciclo > 2) {
        cout << "Semestre no valido.\n";
        return;
    }

    cout << "Ingrese el curso (numero):\n";
    for (size_t i = 1; i < cursosSemestre[ciclo - 1].size(); ++i) { 
        cout << i << ". " << cursosSemestre[ciclo - 1][i][0] << endl; 
    }
    cout << endl;

    int codIndice;
    cin >> codIndice;

    if (codIndice < 1 || codIndice > (cursosSemestre[ciclo - 1].size() - 1)) {
        cout << "Curso no valido.\n";
        return;
    }

    string codigoCurso = cursosSemestre[ciclo - 1][codIndice][1];

    
    bool asignacionExistente = false;
    for (auto& asignacion : asignaciones) {
        if (asignacion.codigoEstudiante == codigoEstudiante && asignacion.codigoCurso == codigoCurso) {
            asignacionExistente = true;
           
            cout << "El estudiante ya está asignado al curso " << asignacion.codigoCurso << ".\n";
            cout << "¿Desea actualizar la asignación? (s/n): ";
            char opcion;
            cin >> opcion;

            if (opcion == 's' || opcion == 'S') {
               
                cout << "Asignación actualizada correctamente.\n";
               
            } else {
                cout << "No se actualizará la asignación.\n";
            }
            break;
        }
    }

    
    if (!asignacionExistente) {
        Cursos nuevoCurso;
        nuevoCurso.nombrec = cursosSemestre[ciclo - 1][codIndice][0];
        nuevoCurso.codigo = codigoCurso;
        nuevoCurso.creditos = cursosSemestre[ciclo - 1][codIndice][2];
        nuevoCurso.semestre = ciclo;

        cursos.push_back(nuevoCurso);

        Asignacion nuevaAsignacion;
        nuevaAsignacion.codigoEstudiante = codigoEstudiante;
        nuevaAsignacion.codigoCurso = nuevoCurso.codigo;
        asignaciones.push_back(nuevaAsignacion);
        cout << "Curso " << nuevoCurso.nombrec << " asignado correctamente al estudiante.\n";
    }

    cout << "----------------------------------\n";
}



void mostrarDyM(Estudiante &nuevoEstudiante) {
    int dptoIndice;
    while (true) {
        
        for (size_t i = 0; i < departamentos.size(); i++) {
            cout << i + 1 << ". " << departamentos[i][0] << endl;
        }
        cout << "Seleccione un departamento: ";
        cin >> dptoIndice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Por favor, ingrese un numero.\n";
            continue;
        }

        if (dptoIndice > 0 && dptoIndice <= departamentos.size()) {
            nuevoEstudiante.departamento = departamentos[dptoIndice - 1][0];

            cout << "\nMunicipios en " << nuevoEstudiante.departamento << ":\n";
            for (size_t i = 1; i < departamentos[dptoIndice - 1].size(); i++) {
                cout << i << ". " << departamentos[dptoIndice - 1][i] << endl;
            }

            int muniIndice;
            cout << "Seleccione un municipio:\n";
            cin >> muniIndice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada no valida. Por favor, ingrese un numero.\n";
                continue;
            }

            if (muniIndice > 0 && muniIndice < departamentos[dptoIndice - 1].size()) {
                nuevoEstudiante.municipio = departamentos[dptoIndice - 1][muniIndice];
                break; 
            } else {
                cout << "Indice de municipio no valido.\n";
            }
        } else {
            cout << "Indice de departamento no valido.\n";
        }
    }
}

void ingresarTelefono(Estudiante &nuevoEstudiante) {
    while (true) {
        cout << "Ingrese el telefono personal del estudiante (max 8 num.): ";
        cin >> nuevoEstudiante.telefonope;

        if (cin.fail() || to_string(nuevoEstudiante.telefonope).length() > 8) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada no válida. Asegúrese de ingresar un numero de hasta 8 dígitos.\n";
        } else {
            break; 
        }
    }

    while (true) {
        cout << "Ingrese el telefono de casa del estudiante (max 8 num.): ";
        cin >> nuevoEstudiante.telefonoca;

        
        if (cin.fail() || to_string(nuevoEstudiante.telefonoca).length() > 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Asegúrese de ingresar un numero de hasta 8 digitos.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Ingrese el telefono de emergencia del estudiante (max 8 num.): ";
        cin >> nuevoEstudiante.telefonoem;

        if (cin.fail() || to_string(nuevoEstudiante.telefonoem).length() > 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Asegúrese de ingresar un numero de hasta 8 digitos.\n";
        } else {
            break;
        }
    }
}

void calcularEdad(Estudiante &estudiante) {
    const int diaActual = 15;
    const int mesActual = 10;
    const int anioActual = 2024;

    estudiante.edad = anioActual - estudiante.anioNacimiento;

    if (mesActual < estudiante.mesNacimiento || 
        (mesActual == estudiante.mesNacimiento && diaActual < estudiante.diaNacimiento)) {
        estudiante.edad--;
    }
}

void registroEstudiantes() {
    Estudiante nuevoEstudiante;
    nuevoEstudiante.codigo = generarCodigo();
    
    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nuevoEstudiante.nombre);
    
    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, nuevoEstudiante.apellido);  
    
    mostrarCarrera(nuevoEstudiante);
    
    cout << "Ingrese la direccion :" << endl;
    mostrarDyM(nuevoEstudiante);
    
    ingresarTelefono(nuevoEstudiante);
    
    cout << "Ingrese su fecha de nacimiento (DD MM AAAA): ";
    cin >> nuevoEstudiante.diaNacimiento >> nuevoEstudiante.mesNacimiento >> nuevoEstudiante.anioNacimiento;
     calcularEdad(nuevoEstudiante);
	 
	 cout << "Fecha de nacimiento ingresada: " 
         << nuevoEstudiante.diaNacimiento << "/" 
         << nuevoEstudiante.mesNacimiento << "/" 
         << nuevoEstudiante.anioNacimiento <<endl;
    cout << "Edad: " << nuevoEstudiante.edad << " anios." << endl;
    
    cout << "Ingrese su correo electronico : ";
    cin >> nuevoEstudiante.correo;
    
    cout << "-------------------------------------\n";
            
    estudiantes.push_back(nuevoEstudiante);
}

void asignarNotas() {
	cout << "\n----Lista de estudiantes registrados:----\n";
	for (const auto& estudiante : estudiantes) {
        cout << "Codigo: " << estudiante.codigo << " Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
    }
    Nota nuevaNota;
    cout << "\nIngrese el codigo del estudiante: ";
    cin >> nuevaNota.codigoEstudiante;

    bool estudianteEncontrado = false;
    for (const auto& estudiante : estudiantes) {
        if (estudiante.codigo == nuevaNota.codigoEstudiante) {
            estudianteEncontrado = true;
            break;
        }
    }
    
    if (!estudianteEncontrado) {
        cout << "Estudiante no encontrado.\n";
        return;
    }

    cout << "Seleccione un curso:\n";
    for (size_t i = 0; i < cursos.size(); i++) {
        cout << i + 1 << ". " << cursos[i].nombrec << endl;
    }
    
    int cursoIndice;
    cin >> cursoIndice;

    if (cursoIndice < 1 || cursoIndice > cursos.size()) {
        cout << "Curso no válido.\n";
        return;
    }
  
    nuevaNota.codigoCurso = cursos[cursoIndice - 1].codigo;

    
    bool notaExistente = false;
    for (auto& nota : notas) {
        if (nota.codigoEstudiante == nuevaNota.codigoEstudiante && nota.codigoCurso == nuevaNota.codigoCurso) {
            notaExistente = true;
            
            cout << "Ya existe una nota registrada para el curso " << nota.codigoCurso << ".\n";
            cout << "¿Desea actualizar la nota? (s/n): ";
            char opcion;
            cin >> opcion;

            if (opcion == 's' || opcion == 'S') {
               
                cout << "Ingrese nota parcial 1: ";
                cin >> nota.notaParcial1;

                cout << "Ingrese nota parcial 2: ";
                cin >> nota.notaParcial2;

                nota.notaFinal = (nota.notaParcial1 + nota.notaParcial2); // Calcular el promedio
                nota.estado = (nota.notaFinal >= 60) ? "Aprobado" : "Reprobado";
                cout << "Notas actualizadas correctamente para el curso " << nota.codigoCurso << endl;
            } else {
                cout << "No se actualizará la nota.\n";
            }
            break;
        }
    }

    // Si no existe la nota, agregar una nueva
    if (!notaExistente) {
        cout << "Ingrese nota parcial 1: ";
        cin >> nuevaNota.notaParcial1;

        cout << "Ingrese nota parcial 2: ";
        cin >> nuevaNota.notaParcial2;

        nuevaNota.notaFinal = (nuevaNota.notaParcial1 + nuevaNota.notaParcial2); // Calcular el promedio
        nuevaNota.estado = (nuevaNota.notaFinal >= 60) ? "Aprobado" : "Reprobado";

        notas.push_back(nuevaNota);
        cout << "Notas asignadas correctamente para el curso " << nuevaNota.codigoCurso << endl;
    }
    
    cout << "----------------------------------\n";
}


void reporteEstudiante() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n---- Reporte de Estudiantes ----\n";
    for (const auto& estudiante : estudiantes) {
        cout << "ID: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellidos: " << estudiante.apellido << endl;
        cout << "Carrera: " << estudiante.oficio << endl;
        cout << "Departamento: " << estudiante.departamento << endl;
        cout << "Municipio: " << estudiante.municipio << endl;
        cout << "Telefono personal: " << estudiante.telefonope << endl;
        cout << "Telefono de casa: " << estudiante.telefonoca << endl;
        cout << "Telefono de emergencia: " << estudiante.telefonoem << endl;
        cout << "Fecha de nacimiento: " 
             << estudiante.diaNacimiento << "/" 
             << estudiante.mesNacimiento << "/" 
             << estudiante.anioNacimiento << endl;
        cout << "Edad: " << estudiante.edad << " anios." << endl;
        cout << "Correo electronico : " << estudiante.correo << endl;
        cout << "----------------------------------\n"; 
    }
}

void reporteCursos() {
    if (cursos.empty()) {
        cout << "No hay cursos registrados.\n";
        return;
    }

    cout << "\n----- Reporte de Cursos -----\n";
    for (const auto& curso : cursos) {
        cout << "Curso: " << curso.nombrec << endl;
        cout << "Codigo de curso: " << curso.codigo << endl;
        cout << "Creditos curso: " << curso.creditos << endl;

        cout << "Estudiantes asignados:\n";
        for (const auto& asignacion : asignaciones) {
            if (asignacion.codigoCurso == curso.codigo) {
                cout << " - " << estudiantes[asignacion.codigoEstudiante - 1].nombre << endl;
            }
        }

        cout << "----------------------------------\n"; 
    }
}

void reporteNotas() {
    if (notas.empty()) {
        cout << "No hay notas registradas.\n";
        return;
    }

    cout << "\n--- Reporte de Notas ---\n";
    for (const auto& nota : notas) {
        cout << "Codigo Estudiante: " << nota.codigoEstudiante << endl;
        cout << "Codigo Curso: " << nota.codigoCurso << endl;
        cout << "Nota Parcial 1: " << nota.notaParcial1 << endl;
        cout << "Nota Parcial 2: " << nota.notaParcial2 << endl;
        cout << "Nota Final: " << nota.notaFinal << endl;
        cout << "Estado: " << nota.estado << endl;
        cout << "----------------------------------\n"; 
    }
}

void reporteRendimientoAcademico() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- Reporte de Rendimiento Academico ---\n";
    for (const auto& estudiante : estudiantes) {
        float sumaNotas = 0;
        int materiasAprobadas = 0;
        int materiasReprobadas = 0;
        int totalMaterias = 0;

        for (const auto& nota : notas) {
            if (nota.codigoEstudiante == estudiante.codigo) {
                sumaNotas += nota.notaFinal;
                totalMaterias++;
                if (nota.estado == "Aprobado") {
                    materiasAprobadas++;
                } else {
                    materiasReprobadas++;
                }
            }
        }

        if (totalMaterias > 0) {
            float promedio = sumaNotas / totalMaterias;
            cout << "ID: " << estudiante.codigo << endl;
            cout << "Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
            cout << "Promedio: " << promedio << endl;
            cout << "Materias Aprobadas: " << materiasAprobadas << endl;
            cout << "Materias Reprobadas: " << materiasReprobadas << endl;
            cout << "----------------------------------\n";
        } else {
            cout << "ID: " << estudiante.codigo << endl;
            cout << "Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
            cout << "No tiene materias registradas.\n";
            cout << "----------------------------------\n";
        }
    }
}


int obtenerOpcion(int min, int max, const string& mensaje) {
    int opcion;

    while (true) {
        cout << mensaje; 
        cin >> opcion;

        if (cin.fail() || opcion < min || opcion > max) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada no valida. Intente de nuevo.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return opcion;
        }
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
        opcion = obtenerOpcion(1, 5, "Seleccione una opcion (1-5): ");
        cout <<endl;

        switch (opcion) {
            case 1:
                registroEstudiantes();
                break;
            case 2:
                AsignarCursos();
                break;
            case 3:
                asignarNotas();
                break;
            case 4:
                int reporteOpcion;
                do {
                    cout << "\nSeleccione el tipo de reporte:\n";
                    reporteOpcion = obtenerOpcion(1, 5, "1. Reporte de Estudiantes\n2. Reporte de Cursos\n3. Reporte de Notas\n4. Reporte de rendimiento\n5. Volver al menu principal\n Seleccione una opcion (1-5): ");
                    
                    switch (reporteOpcion) {
                        case 1:
                            reporteEstudiante();
                            break;
                        case 2:
                            reporteCursos();
                            break;
                        case 3:
                            reporteNotas();
                            break;
                        case 4:
                        	reporteRendimientoAcademico();
                        	break;
                        case 5:
                            cout << "Volviendo al menu principal...\n";
                            cout << "----------------------------------\n"; 
                            break;
                    }
                } while (reporteOpcion != 5);
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
