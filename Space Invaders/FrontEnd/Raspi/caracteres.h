/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   caracteres.h
 * Author: Grupo 2
 * En este archivo se lo necesario para utilizar las funciones encargadas de 
 * imprimir las letras del abecedario y los números en la Raspberry Pi.
 * Created on February 12, 2021, 2:20 PM
 */

#ifndef CARACTERES_H
#define CARACTERES_H
/*******************************************************************************
 *                              HEADER FILES                                   *
 *******************************************************************************/
#include <stdio.h>
#include "disdrv.h"
#include "joydrv.h"
#include "../../BackEnd/constantes.h"
#include "fondos.h"

//#define CHANGESCREEN(s) screen_##s##_raspi

/*******************************************************************************
 *                    FUNCTION PROTOTYPES WITH GLOBAL SCOPE                    *
 *******************************************************************************/

/************************************************************************
 * Función: draw_a                                                      *
 * Se encarga de imprimir la letra A en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_a (int ax, int ay);

/************************************************************************
 * Función: draw_b                                                      *
 * Se encarga de imprimir la letra B en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_b (int bx, int by);

/************************************************************************
 * Función: draw_c                                                      *
 * Se encarga de imprimir la letra C en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_c (int cx, int cy);

/************************************************************************
 * Función: draw_d                                                      *
 * Se encarga de imprimir la letra D en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_d (int dx, int dy);

/************************************************************************
 * Función: draw_e                                                      *
 * Se encarga de imprimir la letra E en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_e (int ex, int ey);

/************************************************************************
 * Función: draw_f                                                      *
 * Se encarga de imprimir la letra F en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_f (int fx, int fy);

/************************************************************************
 * Función: draw_g                                                      *
 * Se encarga de imprimir la letra G en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_g (int gx, int gy);

/************************************************************************
 * Función: draw_h                                                      *
 * Se encarga de imprimir la letra H en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_h (int hx, int hy);

/************************************************************************
 * Función: draw_i                                                      *
 * Se encarga de imprimir la letra I en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_i (int ix, int iy);

/************************************************************************
 * Función: draw_j                                                      *
 * Se encarga de imprimir la letra J en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_j (int jx, int jy);

/************************************************************************
 * Función: draw_k                                                      *
 * Se encarga de imprimir la letra K en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_k (int kx, int ky);

/************************************************************************
 * Función: draw_l                                                      *
 * Se encarga de imprimir la letra L en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_l (int lx, int ly);

/************************************************************************
 * Función: draw_m                                                      *
 * Se encarga de imprimir la letra M en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_m (int mx, int my);

/************************************************************************
 * Función: draw_n                                                      *
 * Se encarga de imprimir la letra N en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_n (int nx, int ny);

/************************************************************************
 * Función: draw_o                                                      *
 * Se encarga de imprimir la letra O en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_o (int ox, int oy);

/************************************************************************
 * Función: draw_p                                                      *
 * Se encarga de imprimir la letra P en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_p (int px, int py);

/************************************************************************
 * Función: draw_q                                                      *
 * Se encarga de imprimir la letra Q en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_q (int qx, int qy);

/************************************************************************
 * Función: draw_r                                                      *
 * Se encarga de imprimir la letra R en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_r (int rx, int ry);

/************************************************************************
 * Función: draw_s                                                      *
 * Se encarga de imprimir la letra S en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_s (int sx, int sy);

/************************************************************************
 * Función: draw_t                                                      *
 * Se encarga de imprimir la letra T en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_t (int tx, int ty);

/************************************************************************
 * Función: draw_u                                                      *
 * Se encarga de imprimir la letra U en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_u (int ux, int uy);

/************************************************************************
 * Función: draw_v                                                      *
 * Se encarga de imprimir la letra V en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_v (int vx, int vy);

/************************************************************************
 * Función: draw_w                                                      *
 * Se encarga de imprimir la letra W en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_w (int wx, int wy);

/************************************************************************
 * Función: draw_x                                                      *
 * Se encarga de imprimir la letra X en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_x (int xx, int xy);

/************************************************************************
 * Función: draw_y                                                      *
 * Se encarga de imprimir la letra Y en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_y (int yx, int yy);

/************************************************************************
 * Función: draw_z                                                      *
 * Se encarga de imprimir la letra Z en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.         *
 ************************************************************************/
void draw_z (int zx, int zy);

/*************************************************************************
 * Función: draw_1                                                       *
 * Se encarga de imprimir el número 1 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_1 (int x_1, int y_1);

/*************************************************************************
 * Función: draw_2                                                       *
 * Se encarga de imprimir el número 2 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_2 (int x_2, int y_2);

/*************************************************************************
 * Función: draw_3                                                       *
 * Se encarga de imprimir el número 3 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_3 (int x_3, int y_3);

/*************************************************************************
 * Función: draw_4                                                       *
 * Se encarga de imprimir el número 4 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_4 (int x_4, int y_4);

/*************************************************************************
 * Función: draw_5                                                       *
 * Se encarga de imprimir el número 5 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_5 (int x_5, int y_5);

/*************************************************************************
 * Función: draw_6                                                       *
 * Se encarga de imprimir el número 6 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_6 (int x_6, int y_6);

/*************************************************************************
 * Función: draw_7                                                       *
 * Se encarga de imprimir el número 7 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_7 (int x_7, int y_7);

/*************************************************************************
 * Función: draw_8                                                       *
 * Se encarga de imprimir el número 8 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_8 (int x_8, int y_8);

/*************************************************************************
 * Función: draw_9                                                       *
 * Se encarga de imprimir el número 9 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_9 (int x_9, int y_9);

/*************************************************************************
 * Función: draw_0                                                       *
 * Se encarga de imprimir el número 0 en las coordenadas que se necesita.*
 * Recibe las coordenadas x e y del extremo inferior izquierdo.          *
 *************************************************************************/
void draw_0 (int x_0, int y_0);

void init_keyboard(char letter_keyboard[NUMBER_OF_SCREENS][NAMELENGHT]);
char get_letter(char letter_keyboard[NUMBER_OF_SCREENS][NAMELENGHT]);
void screen_1_raspi();
void screen_2_raspi();
void screen_3_raspi();
void screen_4_raspi();
void screen_5_raspi();
void screen_6_raspi();
void screen_7_raspi();
void screen_8_raspi();
void screen_9_raspi();
void draw_guion_4(int x, int screen_number);
void draw_guion_5(int x, int screen_number);

#endif /* CARACTERES_H */


