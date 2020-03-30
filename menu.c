#include "menu.h"

//  Función para imprimir el menú de bienvenida
int bienvenida(){
    int opcion;
	printf("¡Bienvenido a Ventas!\n");
    printf("(1) Iniciar sesion\n");
    printf("(2) Salir\n");
	printf("\nOpcion: ");
    scanf("%i", &opcion);
    return opcion;
}

int ingresarRut(){
    int rutVendedor;
	printf("\nIngresa tu rut: ");
    scanf("%i", &rutVendedor);
    return rutVendedor;
}

// Función 
int operaciones(int rut){
    int opcion;
	printf("Rut de vendedor: %i\n", rut);
	printf("\n");
	printf("(1) Vender producto\n");
	printf("(2) Total recaudado\n");
	printf("(3) Ventas del empleado\n");
	printf("(4) Promedio de la cantidad que vende cada empleado\n");
    printf("(5) Atras");
	printf("\n");
	printf("\nOpcion: ");
    scanf("%i", &opcion);
    return opcion;
}

void otraOperacion(){
	char input;
	printf("\nDesea realizar otra operacion (Y/N): ");
	scanf("%c", &input);
	tolower(input);
	if (input == 'n'){
		printf("\nAdios!\n");
		exit(0);
	}
}

void venderProducto(){


}