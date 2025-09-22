#include <iostream>
#include <string>

int main() {
    std::string nombre[5];
    std::string paisorigen[5];
    std::string disiplina[5];
    std::string genero[5];
    int medallas[5];
    int numAtletas = 0;  
    int opcion;

    do {
    std::cout << "Registro de Atletas" << std::endl;
    std::cout << "menu de opciones" << std::endl;
    std::cout << "1. Ingresar Atleta" << std::endl;
    std::cout << "2. Mostrar Atletas" << std::endl;
    std::cout << "3. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";

    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        std::cout << "Ingrese el nombre del atleta: " << std::endl;
        std::cin >> nombre[numAtletas];
        std::cout << "Ingrese el pais de origen: " << std::endl;
        std::cin >> paisorigen[numAtletas];
        std::cout << "Ingrese la disiplina: " << std::endl;
        std::cin >> disiplina[numAtletas];
        std::cout << "Inglrese el genero: " << std::endl;
        std::cin >> genero[numAtletas];
        std::cout << "Ingrese la cantidad de medallas: " << std::endl;
        std::cin >> medallas[numAtletas];
        std::cout << "Atleta registrado con exito" << std::endl;
        numAtletas++;
        break;
        case 2:
        std::cout << "=== Atletas Registrados ===" << std::endl;
        for(int i = 0; i < numAtletas; i++) {
            std::cout << "Atleta " << (i+1) << ":" << std::endl;
            std::cout << "Nombre: " << nombre[i] << std::endl;
            std::cout << "Pais: " << paisorigen[i] << std::endl;
            std::cout << "Disciplina: " << disiplina[i] << std::endl;
            std::cout << "Genero: " << genero[i] << std::endl;
            std::cout << "Medallas: " << medallas[i] << std::endl;
            std::cout << "-------------------" << std::endl;
        }
        break;
    case 3:
        std::cout << "Saliendo del programa." << std::endl;
        break;
    default:
        std::cout << "Opcion no valida. Por favor intente de nuevo." << std::endl;
        break;
    }
    } while (opcion != 3);
    {
        std::cout << "Saliendo del programa." << std::endl;
    }
    return 0;

}