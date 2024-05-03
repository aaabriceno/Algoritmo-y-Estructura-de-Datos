#include <iostream>
#include <list>
#include <array>

template <size_t ARRAY_SIZE>
class ArrayManager {
public:
    ArrayManager() {}

    ~ArrayManager() {}

    void add(int num) {
        if (arrays.empty() || arrays.back().back() != 0) {
            arrays.push_back(std::array<int, ARRAY_SIZE>());
        }

        auto it = arrays.end();
        --it;
        for (auto& element : *it) {
            if (element == 0) {
                element = num;
                return;
            }
        }
    }

    void remove(int num) {
        for (auto& array : arrays) {
            for (size_t i = 0; i < array.size(); i++) {
                if (array[i] == num) {
                    for (size_t j = i; j < array.size() - 1; j++) {
                        array[j] = array[j + 1];
                    }
                    array.back() = 0;
                    if (arrays.size() > 1 && arrays.back().front() != 0) {
                        arrays.front()[ARRAY_SIZE - 1] = arrays.back().front();
                        auto it = arrays.end();
                        --it;
                        for (size_t k = 0; k < ARRAY_SIZE - 1; k++) {
                            (*it)[k] = (*it)[k + 1];
                        }
                        (*it)[ARRAY_SIZE - 1] = 0;
                    }
                    return;
                }
            }
        }
    }

    bool find(int num) {
        for (const auto& array : arrays) {
            for (int element : array) {
                if (element == num) {
                    return true;
                }
            }
        }
        return false;
    }

    void printArrays() {
        int index = 1;
        for (const auto& array : arrays) {
            std::cout << "Nodo " << index << " --> [";
            for (int i = 0; i < array.size(); i++) {
                if (i != 0) {
                    std::cout << ", ";
                }
                std::cout << array[i];
            }
            std::cout << "]" << std::endl;
            index++;
        }
    }

private:
    std::list<std::array<int, ARRAY_SIZE>> arrays;
};

int main() {
    ArrayManager<10> manager;

    while (true) {
        int choice;
        std::cout << "1. Agregar\n2. Eliminar\n3. Buscar\n4. Imprimir\n5. Salir\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Ingrese un numero: ";
                int num;
                std::cin >> num;
                manager.add(num);
                break;
            }
            case 2: {
                std::cout << "Ingrese el numero a eliminar: ";
                int num;
                std::cin >> num;
                manager.remove(num);
                break;
            }
            case 3: {
                std::cout << "Ingrese el numero a buscar: ";
                int num;
                std::cin >> num;
                if (manager.find(num)) {
                    std::cout << "Numero encontrado." << std::endl;
                } else {
                    std::cout << "Numero no encontrado." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Arrays actuales:" << std::endl;
                manager.printArrays();
                break;
            case 5:
                std::cout << "Saliendo..." << std::endl;
                return 0;
            default:
                std::cout << "Opcion no valida. Por favor ingrese una opcion valida." << std::endl;
                break;
        }
    }

    return 0;
}
//MI CODE HACE LO QUE PIDE EL GUSTAVO OSEA QUE CUANDO SE LLENA EL ARRAY SE CREA UN NUEVO NODO DE ARRAYS Y SI SE ELIMINA UN DATO DEL PRIMER NODO, EL PRIMER DATO DEL SEGUNDO NODO PASA A SER EL ULTIMO DATO DEL PRIMER NODO