#include <iostream>

int main() {
    int opcion;
    do {
        std::cout << "Sistema de registro Universitario";
        std::cout << "1. Registro de estudiantes";
        std::cout << "2. Asignacion de cursos ";
        std::cout << "3. Control de notas";
        std::cout << "4. Reportes Academicos";
        std::cout << "5. Salir";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                asignarCurso();
                break;
            case 3:
                registrarNotas();
                break;
            case 4:
                generarReportes();
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