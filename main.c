#include "main.h"

void pausa(){
    printf("\nPresione cualquier tecla para continuar...");
    getchar();
    getchar();
}

int main(){
    int opcion,rutVendedor, rutComprador, monto, total;
    bool getOut = false;
    Lista *lista;
    lista = constructorLista();
    while (true){
        opcion = bienvenida();
        switch (opcion){
            // Inicio de sesión
            case 1: 
                system("clear");
                rutVendedor = ingresarRut();
                system("clear");
                while (!getOut){
                    opcion = operaciones(rutVendedor);
                    switch(opcion){
                        // Vender product1o
                        case 1:
                            system("clear");
                            printf("\nRut comprador: ");
                            scanf("%i", &rutComprador);
                            printf("Ingrese el monto: ");
                            scanf("%i", &monto);
                            appendLista(lista, monto, rutComprador, rutVendedor, lista->cantidad+1);
                            pausa();
                            break;
                        // Total de ventas
                        case 2:
                            system("clear");
                            montoTotal(lista);
                            pausa();
                            break;
                        // Ventas de un empleado
                        case 3:
                            system("clear");
                            listarVentasEmpleado(lista, rutVendedor);
                            pausa();
                            break;
                        // Promedio de la cantidad que vende cada empleado
                        case 4:
                            system("clear");
                            promedioCadaEmpleado(lista);
                            pausa();
                            break;
                        // Atras
                        case 5:
                            getOut = true;
                            break;
                        default:
                            printf("Opcion no válida.");
                            break;
                    }
                    system("clear");             
                }
                break;
            // Salir    
            case 2: 
                system("clear");
                exit(1);
                break;
            default:
                printf("Opción no valida.\n");
                break;
        }
        getOut = false;
    }
    return 0;
}