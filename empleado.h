#include "libreriasBasicas.h"

#ifndef __EMPLEADOS__H__
#define __EMPLEADOS__H__

/*
    Estructura venta
*/
typedef struct venta{
    int rutVendedor;
    int rutComprador;
    int montoProducto;
    int numeroVenta;
}Venta;

/*
Estructura que guarda el nodo, un puntero apunta a las Ventas,
y otro apunta al nodo siguiente
*/
typedef struct nodo{
    Venta *datos;
    struct nodo *siguiente;
}Nodo;

/*
    Estructura que guarda la Lista, con un puntero que apunta
    al inici y al fin de ésta. Además, almacena el tamaño de
     la lista.
*/
typedef struct lista{
    Nodo *inicio;
    Nodo *final;
    int cantidad;
}Lista;

Lista *constructorLista();
Nodo *constructorNodo(Venta *venta);
Venta *constructorVenta(int monto, int rutComprador, int rutVendedor, int numeroVenta);
int calcularPosicion(Lista *lista, int monto);
int insertarNodo(Lista *lista, Nodo *nuevoNodo, int pos);
void appendLista(Lista *lista, int monto, int rutComprador, int rutVendedor, int numeroVenta);
void mostrarLista(Lista *L);
void montoTotal(Lista *lista);
void mostrarDatos(Venta *venta);
void listarVentasEmpleado(Lista *lista, int rut);
int cantidadRutVendedor(Lista *lista);
void promedioCadaEmpleado(Lista *lista);
#endif