#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main() {
    std::string nombre[50];
    std::string paisorigen[50];
    std::string disiplina[50];
    std::string genero[50];
    int medallas[50];
    int numAtletas = 0;  
    int opcion;

    do {
    std::cout << "Registro de Atletas" << std::endl;
    std::cout << "menu de opciones" << std::endl;
    std::cout << "1. Ingresar Atleta" << std::endl;
    std::cout << "2. Mostrar Atletas" << std::endl;
    std::cout << "3. Buscar Atleta" << std::endl;
    std::cout << "4. Calcular el total de medallas de oro del pais" << std::endl;
    std::cout << "5. Encontrar al atleta con mas medallas de oro" << std::endl;
    std::cout << "6. Cargar datos desde archivo CSV" << std::endl;
    std::cout << "7. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";

    std::cin >> opcion;
    
    switch (opcion)
    {
    case 1:
        if(numAtletas >= 50) {
            std::cout << "Error: Ya se ha alcanzado el numero maximo de atletas (50)." << std::endl;
        } else {
            std::cout << "Ingrese el nombre del atleta: " << std::endl;
            std::cin >> nombre[numAtletas];
            std::cout << "Ingrese el pais de origen: " << std::endl;
            std::cin >> paisorigen[numAtletas];
            std::cout << "Ingrese la disiplina: " << std::endl;
            std::cin >> disiplina[numAtletas];
            std::cout << "Inglrese el genero: " << std::endl;
            std::cin >> genero[numAtletas];
            
            // Validación para medallas - debe ser un número positivo
            do {
                std::cout << "Ingrese la cantidad de medallas (numero positivo): " << std::endl;
                std::cin >> medallas[numAtletas];
                if(medallas[numAtletas] < 0) {
                    std::cout << "Error: El numero de medallas no puede ser negativo." << std::endl;
                }
            } while(medallas[numAtletas] < 0);
            
            // Guardar el atleta en el archivo CSV
            std::ofstream archivo("data/data1.csv", std::ios::app);
            if (archivo.is_open()) {
                // Si el archivo está vacío, agregar el header
                archivo.seekp(0, std::ios::end);
                if (archivo.tellp() == 0) {
                    archivo << "Nombre,Pais,Disciplina,Genero,Medallas" << std::endl;
                }
                
                // Agregar el nuevo atleta
                archivo << nombre[numAtletas] << "," 
                       << paisorigen[numAtletas] << "," 
                       << disiplina[numAtletas] << "," 
                       << genero[numAtletas] << "," 
                       << medallas[numAtletas] << std::endl;
                archivo.close();
                std::cout << "Atleta registrado con exito y guardado en el archivo CSV" << std::endl;
            } else {
                std::cout << "Atleta registrado con exito (pero no se pudo guardar en el archivo CSV)" << std::endl;
            }
            
            numAtletas++;
        }
        break;
        case 2:
        std::cout << "=== Atletas Registrados ===" << std::endl;
        if(numAtletas == 0) {
            std::cout << "No hay atletas registrados." << std::endl;
        } else {
            for(int i = 0; i < numAtletas; i++) {
                std::cout << "Atleta " << (i+1) << ":" << std::endl;
                std::cout << "Nombre: " << nombre[i] << std::endl;
                std::cout << "Pais: " << paisorigen[i] << std::endl;
                std::cout << "Disciplina: " << disiplina[i] << std::endl;
                std::cout << "Genero: " << genero[i] << std::endl;
                std::cout << "Medallas: " << medallas[i] << std::endl;
                std::cout << "-------------------" << std::endl;
            }
        }
        break;

    case 3: {
        std::cout << "=== Buscar Atleta ===" << std::endl;
        if(numAtletas == 0) {
            std::cout << "No hay atletas registrados." << std::endl;
        } else {
            std::cout << "Ingrese el nombre del atleta a buscar: ";
            std::string nombreBuscar;
            std::cin >> nombreBuscar;
            
            bool encontrado = false;
            for(int i = 0; i < numAtletas; i++) {
                if(nombre[i] == nombreBuscar) {
                    std::cout << "Atleta encontrado:" << std::endl;
                    std::cout << "Nombre: " << nombre[i] << std::endl;
                    std::cout << "Pais: " << paisorigen[i] << std::endl;
                    std::cout << "Disciplina: " << disiplina[i] << std::endl;
                    std::cout << "Genero: " << genero[i] << std::endl;
                    std::cout << "Medallas: " << medallas[i] << std::endl;
                    encontrado = true;
                    break;
                }
            }
            if(!encontrado) {
                std::cout << "Atleta no encontrado." << std::endl;
            }
        }
        break;
    }
    case 4: {
        std::cout << "=== Calcular total de medallas de oro del pais ===" << std::endl;
        if(numAtletas == 0) {
            std::cout << "No hay atletas registrados." << std::endl;
        } else {
            std::cout << "Ingrese el nombre del pais: ";
            std::string paisBuscar;
            std::cin >> paisBuscar;
            
            int totalMedallas = 0;
            bool paisEncontrado = false;
            for(int i = 0; i < numAtletas; i++) {
                if(paisorigen[i] == paisBuscar) {
                    totalMedallas += medallas[i];
                    paisEncontrado = true;
                }
            }
            
            if(paisEncontrado) {
                std::cout << "Total de medallas de oro de " << paisBuscar << ": " << totalMedallas << std::endl;
            } else {
                std::cout << "No se encontraron atletas del pais " << paisBuscar << std::endl;
            }
        }
        break;
    }
    case 5: {
        std::cout << "=== Atleta con mas medallas de oro ===" << std::endl;
        if(numAtletas == 0) {
            std::cout << "No hay atletas registrados." << std::endl;
        } else {
            int maxMedallas = medallas[0];
            int indiceMax = 0;
            
            for(int i = 1; i < numAtletas; i++) {
                if(medallas[i] > maxMedallas) {
                    maxMedallas = medallas[i];
                    indiceMax = i;
                }
            }
            
            std::cout << "El atleta con mas medallas de oro es:" << std::endl;
            std::cout << "Nombre: " << nombre[indiceMax] << std::endl;
            std::cout << "Pais: " << paisorigen[indiceMax] << std::endl;
            std::cout << "Disciplina: " << disiplina[indiceMax] << std::endl;
            std::cout << "Genero: " << genero[indiceMax] << std::endl;
            std::cout << "Medallas: " << medallas[indiceMax] << std::endl;
        }
        break;
    }
    case 6: {
        std::cout << "=== Cargar datos desde archivo CSV ===" << std::endl;
        std::ifstream archivo("data/data1.csv");
        
        if (!archivo.is_open()) {
            std::cout << "Error: No se pudo abrir el archivo data/data1.csv" << std::endl;
            break;
        }
        
        std::string linea;
        // Leer la primera línea (header) y descartarla
        if (std::getline(archivo, linea)) {
            int atletasCargados = 0;
            
            // Leer cada línea de datos
            while (std::getline(archivo, linea) && numAtletas < 50) {
                std::stringstream ss(linea);
                std::string campo;
                
                // Leer nombre
                if (std::getline(ss, campo, ',')) {
                    nombre[numAtletas] = campo;
                }
                
                // Leer país
                if (std::getline(ss, campo, ',')) {
                    paisorigen[numAtletas] = campo;
                }
                
                // Leer disciplina
                if (std::getline(ss, campo, ',')) {
                    disiplina[numAtletas] = campo;
                }
                
                // Leer género
                if (std::getline(ss, campo, ',')) {
                    genero[numAtletas] = campo;
                }
                
                // Leer medallas
                if (std::getline(ss, campo, ',')) {
                    medallas[numAtletas] = std::stoi(campo);
                }
                
                numAtletas++;
                atletasCargados++;
            }
            
            std::cout << "Se cargaron " << atletasCargados << " atletas desde el archivo CSV." << std::endl;
            if (numAtletas >= 50) {
                std::cout << "Nota: Solo se cargaron los primeros 50 atletas debido al limite del programa." << std::endl;
            }
        }
        
        archivo.close();
        break;
    }
    case 7:
        std::cout << "Saliendo del programa." << std::endl;
        break;
    default:
        std::cout << "Opcion no valida. Por favor intente de nuevo." << std::endl;
        break;
    }
    } while (opcion != 7);
    
    return 0;
}
