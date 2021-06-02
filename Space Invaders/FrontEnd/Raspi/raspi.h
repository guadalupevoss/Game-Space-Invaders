/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raspi.h
 * Author: mpaget
 *
 * Created on February 21, 2021, 11:21 AM
 */

#ifndef RASPI_H
#define RASPI_H

#include "joydrv.h"
#include "disdrv.h"
//#include "libaudio.h"
#include "fondos.h"

//Inicializa Raspi y sus variables.
int initGraphics(graphics_t allegro);
//Destruye Raspi y las variables.
int destroyGraphics(graphics_t allegro);
//Funci�n que imprime el men�.
void printMenu(graphics_t graphics);
//Funci�n que se fija si cambi� el estado (si se presion� alg�n bot�n o salt� error) y devuelve el estado indicado.
int stateMenu(graphics_t graphics);

#endif /* RASPI_H */

