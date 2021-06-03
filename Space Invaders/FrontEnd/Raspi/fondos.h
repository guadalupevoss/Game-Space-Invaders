/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fondos.h
 * Author: Grupo 2
 * En este archivo se encuentra todo lo necesario para poder imprimir los fondos
 * en la Raspberry Pi.
 * Created on February 13, 2021, 12:53 PM
 */

#ifndef FONDOS_H
#define FONDOS_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "disdrv.h"

/*********************************************************************************
 * Función: draw_play                                                            *
 * Esta función se encarga de imprimir play en el display de la Raspberry Pi.    *
 *********************************************************************************/
void draw_play (void);

/**********************************************************************************
 * Función: draw_highscore                                                        *
 * Esta función se encarga de imprimir highscore en el display de la Raspberry Pi.*
 **********************************************************************************/
void draw_highscore (void);

/*********************************************************************************
 * Función: draw_exit                                                            *
 * Esta función se encarga de imprimir exit en el display de la Raspberry Pi.    *
 *********************************************************************************/
void draw_exit (void);

/*********************************************************************************
 * Función: draw_pause                                                           *
 * Esta función se encarga de imprimir pause en el display de la Raspberry Pi.   *
 *********************************************************************************/
//void draw_pause (void);

/**********************************************************************************
 * Función: draw_gameover                                                         *
 * Esta función se encarga de imprimir game over en el display de la Raspberry Pi.*
 **********************************************************************************/
void draw_gameover(void);

/**********************************************************************************
 * Función: draw_flechitas                                                        *
 * Esta función se encarga de imprimir flechitas en el display de la Raspberry Pi.*
 **********************************************************************************/
void draw_flechitas (void);

/**********************************************************************************
 * Función: draw_palitos                                                          *
 * Esta función se encarga de imprimir palitos en el display de la Raspberry Pi.  *
 **********************************************************************************/
void draw_palitos(void);

/**********************************************************************************
 * Función: draw_pause_exit                                                       *
 * Esta función se encarga de imprimir exit en el display de la Raspberry Pi.	  *
 **********************************************************************************/
void draw_pause_exit (void);

/**********************************************************************************
 * Función: draw_pause_play                                                       *
 * Esta función se encarga de imprimir play en el display de la Raspberry Pi.	  *
 **********************************************************************************/
void draw_pause_play (void);

/**********************************************************************************
 * Función: draw_pause_menu                                                       *
 * Esta función se encarga de imprimir menu en el display de la Raspberry Pi.	  *
 **********************************************************************************/
void draw_pause_menu (void);

#endif /* FONDOS_H */

