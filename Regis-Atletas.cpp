#include <iostream>

int main() {
    int nombrepais[5];
    int paisorigen[5];
    int disiplina[5];
    int genero[5];
    int medallas[5];

    std::cout << "Registro de Atletas" << std::endl;
    std::cout << "menu de opciones" << std::endl;
    std::cout << "1. Ingresar Atleta" << std::endl;
    std::cout << "2. Mostrar Atletas" << std::endl;
    std::cout << "3. Salir" << std::endl;

    int opcion;
    switch (opcion)
    {
    case 1:
        std::cout << "Ingrese el nombre del pais: " << std::endl;
        std::cin >> nombrepais[5];
        std::cout << "Ingrese el pais de origen: " << std::endl;
        std::cin >> paisorigen[5];
        std::cout << "Ingrese la disiplina: " << std::endl;
        std::cin >> disiplina[5];
        std::cout << "Inglrese el genero: " << std::endl;
        std::cin >> genero[5];
        std::cout << "Ingrese la cantidad de medallas: " << std::endl;
        std::cin >> medallas[5];
        std::cout << "Atleta registrado con exito" << std::endl;
        break;
    case 2:
        std::cout << "Mostrar Atletas" << std::endl;
        std::cout << "1. Nombre del pais" << std::endl;
        std::cout << "2. Pais de origen" << std::endl;
        std::cout << "3. Disiplina" << std::endl;
        std::cout << "4. Genero" << std::endl;
        std::cout << "5. Cantidad de medallas" << std::endl;
        break;
    case 3:
        /* code */
        break;
    default:
        break;    default:
        break;
    }
    return 0;

}