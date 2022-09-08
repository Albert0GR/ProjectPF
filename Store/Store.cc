/******************************************************************************
Uso de esrtructuras
*******************************************************************************/
#include <stdio.h>

#define NPROD 3     

int op;

struct producto
{
	int numProducto;
	char nombre[20];
	char desc[50];
	float costo;
	float precio;
	int descuento;
	int cantidad;
};

struct pedido
{
    int numCliente;
    char nombre[20];
    int numProducto;
    int cantidad;
    float total;
};

void imprimePedido(struct pedido p)
{
    printf("# Cliente: %d\n", p.numCliente);
    printf("Nombre: %s\n", p.nombre);
    printf("# Producto: %d\n", p.numProducto);
    printf("Cantidad: %d\n", p.cantidad);
    printf("Total a pagar: $ %8.2f\n", p.total);
}

void imprimeProducto(struct producto producto)
{
    printf("# Producto: %d\n", producto.numProducto);
    printf("Nombre: %s\n", producto.nombre);
    printf("Costo: $ %8.2f\n", producto.costo);
    printf("Precio: $ %8.2f\n", producto.precio);
    printf("Descuento: %d\n", producto.descuento);
}

struct pedido leePedido()
{
    struct pedido daniel;
       /* pedido */
       printf("Num cliente: ");
    scanf("%d",&daniel.numCliente);
        printf("Num Producto: ");
    scanf("%d",&daniel.numProducto);
    printf("Cantidad: ");
    scanf("%d",&daniel.cantidad);
    printf("Nombre: ");
    scanf("%s",&daniel.nombre[0]);
    
    return daniel;
}

struct producto leeProducto(int i)
{
    struct producto producto;
    printf("Num: ");
    scanf("%d",&producto.numProducto);
    printf("Costo: ");
    scanf("%f",&producto.costo);
    printf("Precio: ");
    scanf("%f",&producto.precio);   /* + */
    printf("Descuento: ");
    scanf("%d",&producto.descuento);
    printf("Nombre: ");
    scanf("%s",&producto.nombre[0]);
    printf("Producto : %d registrado con exito\n",i);
    return producto;
}

int main()
{
    printf("Productos de la tienda\n");
    
    struct producto productos[NPROD];
    struct pedido daniel;
    
    for (int i = 0; i < NPROD; i++)
    {
         productos[i] = leeProducto(i);
    }
    
    //desplegar los datos 
    for (int i = 0; i < NPROD; i++)
    {
        imprimeProducto(productos[i]);
    }
    
    

    /* incluir do... while para hacer varios pedidos hasta que teclea la cantidad 0*/

    do
    {
        printf("ingresa tu pedido\n");
            daniel = leePedido();
    
            daniel.total = daniel.cantidad * productos[0].precio;
    
            imprimePedido(daniel);
            printf("\n");
            printf("1- Ingresa otro pedido\n");
            printf("0- Salir\n");
            
            scanf("%d",&op);

    } while (op==1);
    
    


    return 0;
}