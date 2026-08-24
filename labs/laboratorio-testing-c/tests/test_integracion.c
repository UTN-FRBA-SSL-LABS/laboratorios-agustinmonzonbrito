#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void){
    printf("\n[Compra con descuento:]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 3}; /*subtotal: $600*/ 
    carrito_agregar(&c, p);
    Producto p1 = {"Leche", 350, 2}; /*subtotal: $700 */
    carrito_agregar(&c, p1);
    printf("\n[Total esperado: $1300]\n");
    ASSERT_IGUAL(1300, carrito_total(&c)); /*Total esperado: $1300*/
    printf("\n[Total con descuento: $1170]\n");
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void){
    printf("\n[Agregar hasta llenar el carrito:]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 2}; /*subtotal: $400*/ 
    carrito_agregar(&c, p);
    Producto p1 = {"Leche", 350, 1}; /*subtotal: $350 */
    carrito_agregar(&c, p1);
    Producto p2 = {"Agua", 200, 1}; /*subtotal: $200*/
    carrito_agregar(&c, p2);
    Producto p3 = {"Azucar", 350, 1}; /*Subtotal: $350*/
    carrito_agregar(&c, p3);
    /*Intentamos agregar otra leche*/
    printf("\n[Carrito lleno: MAX_ITEMS = 4]\n");
    ASSERT_IGUAL(0, carrito_agregar(&c, p1));/*Se espera que devuelva error al intentar agregar el producto*/
    printf("\n[MAX_ITEMS == 4:]\n");
    ASSERT_IGUAL(4, carrito_contar(&c));/*Se espera que el valor maximo no haya cambiado*/
}


int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
