#include "empleado.h"

Lista *constructorLista(){
    Lista *nuevaLista;
    if (nuevaLista = (Lista*) malloc(sizeof(Lista))){
        nuevaLista->cantidad = 0;
        nuevaLista->inicio = nuevaLista->final = NULL;
    }else {
        printf("Error en la asignación de memoria\n");
    }
    return nuevaLista;
}

Nodo *constructorNodo(Venta *venta){
    Nodo *nuevoNodo;
    if (nuevoNodo = (Nodo *)malloc(sizeof(Nodo))){
        nuevoNodo->datos = venta;
    }else {
        printf("Error en la asignación de memoria\n");
    }
    return nuevoNodo;
}

Venta *constructorVenta(int monto, int rutComprador, int rutVendedor, int numeroVenta){
    Venta *nuevaVenta;
    if (nuevaVenta = (Venta *)malloc(sizeof(Venta))){
        nuevaVenta->montoProducto = monto;
        nuevaVenta->rutComprador = rutComprador;
        nuevaVenta->rutVendedor = rutVendedor;
        nuevaVenta->numeroVenta = numeroVenta;
    }else {
        printf("Error en la asignación de memoria\n");
    }
    return nuevaVenta;
}

int calcularPosicion(Lista *lista, int monto){
    Nodo *aux;
    // Si lista esta vacia retornamos posicion 0
    if (lista->cantidad == 0){
        return 0;
    }

    // Recorremos la lista hasta su ultimo nodo y verificamos el monto
    aux = lista->inicio;
    for (int indice = 1; indice <= lista->cantidad; indice++){
        if (monto <= aux->datos->montoProducto){
            return indice;
        }
        aux = aux->siguiente;
    }

    // Si el monto es mayor que todos los montos de la lista, retornamos la cantidad de la lista + 1
    return lista->cantidad + 1;
}

int insertarNodo(Lista *lista, Nodo *nuevoNodo, int pos){
	// Insertar en lista vacía
    if (pos == 0){
        lista->inicio = nuevoNodo;
        lista->final = nuevoNodo;
        nuevoNodo->siguiente = NULL;
        return 1;
    }
    
    // Insertar 1era posición
    if (pos == 1){
        nuevoNodo->siguiente = lista->inicio;
        lista->inicio = nuevoNodo;    
        return 1;
    }

	// Declaramos las variables
    Nodo *nodoRecorrer = lista->inicio;
	
	// Insertar nodo en última posición
	if (pos == lista->cantidad + 1){
		lista->final->siguiente = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		lista->final = nuevoNodo;
		return 1;
	}
	
    // Nos movemos a la posición señalada
    for (int i=0; i<pos-2; i++){
        nodoRecorrer = nodoRecorrer->siguiente;
    }

	// Insertamos el nodo en la posición señalada
    nuevoNodo->siguiente = nodoRecorrer->siguiente;
    nodoRecorrer->siguiente = nuevoNodo;
    return 1;
}

void appendLista(Lista *lista, int monto, int rutComprador, int rutVendedor, int numeroVenta){
    Nodo *nuevoNodo;
    Venta *nuevaVenta;

    // Construimos estructura venta y le asignamos los datos
    nuevaVenta = constructorVenta(monto, rutComprador, rutVendedor, numeroVenta);
    // Construimos un nodo y le agregamos la venta
    nuevoNodo = constructorNodo(nuevaVenta);
    // Calculamos la posición donde será insertado el nodo
    int posicion = calcularPosicion(lista, nuevaVenta->montoProducto);
    // Insertamos el nodo en la posición calculada
    insertarNodo(lista, nuevoNodo, posicion);
    // Aumentar tamano lista
    lista->cantidad++;
}

void montoTotal(Lista *lista){
    Nodo *aux;
    int total = 0;
    aux = lista->inicio;
    for (int indice = 1; indice <= lista->cantidad; indice++){
        total += aux->datos->montoProducto;
        aux = aux->siguiente;
    }
    printf("El total recaudado es: %i\n", total);
}

void mostrarDatos(Venta *venta){
    printf("Rut del vendedor: %i\n", venta->rutVendedor);
    printf("Rut del comprador: %i\n", venta->rutComprador);
    printf("Monto del producto: %i\n", venta->montoProducto);
    printf("Numero de la venta: %i\n", venta->numeroVenta);
}

void listarVentasEmpleado(Lista *lista, int rut){
    Nodo *aux;
    int contador = 1;
    aux = lista->inicio;
    for (int indice = 1; indice <= lista->cantidad; indice++){
        if (aux->datos->rutVendedor == rut){
            printf("\nVenta numero %i:\n", contador);
            mostrarDatos(aux->datos);
            contador++;
        }
        aux = aux->siguiente;
    }
}

int cantidadRutVendedor(Lista *lista){
    Nodo *aux;
    aux = lista->inicio;
    int total = 0, cantidad = 1, primerRut = aux->datos->rutVendedor;
    for (int indice = 1; indice <= lista->cantidad; indice++){
        if (aux->datos->rutVendedor != primerRut) cantidad++;
        aux = aux->siguiente;
    }
    return cantidad;
}

bool comprobarRepeticion(int *arreglo, int rut, int largo){
    for (int indice = 0; indice < largo ; indice++){
        if (arreglo[indice] == rut) return true;
    }
    return false;
}

/*void llenarArregloRuts(Lista *lista, int *arregloRutVendedores, int largo){
    Nodo *aux;
    aux = lista->inicio;
    for (int indice = 0; indice < lista->cantidad; indice++){
        if (aux->datos->rutVendedor != primerRut) cantidad++;
        aux = aux->siguiente;
    }
}*/

void promedioCadaEmpleado(Lista *lista){
    Nodo *aux;
    aux = lista->inicio;
    int cantidadRut = cantidadRutVendedor(lista), rutActual = aux->datos->rutVendedor, cantidadVentas;
    int arregloRutVendedores[cantidadRut];
    for (int i = 1; i <= lista->cantidad; i++){
        cantidadVentas = 0;
        rutActual = arregloRutVendedores[i];
        aux = lista->inicio;
        for (int j = 1; j <= lista->cantidad; j++){
            if(rutActual == aux->datos->rutVendedor)cantidadVentas++;
            aux = aux->siguiente;
        }
        printf("Rut vendedor: %i\nPromedio de cantidad de ventas: %i", rutActual, (cantidadVentas/lista->cantidad));
    }
}  

void mostrarLista(Lista *L){
    int posicion = 1;
	Nodo *aux;
	aux = L->inicio;

	while (aux != NULL)
	{
		printf("%i, %i\n", aux->datos->montoProducto, aux->datos->rutComprador);
		aux = aux->siguiente;
        // printf("Posicion: %i\n", posicion);
        posicion++;
	}
	printf("cantidad: %i\n", L->cantidad);
}
