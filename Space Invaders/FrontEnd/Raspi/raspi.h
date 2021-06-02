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
//Función que imprime el menú.
void printMenu(graphics_t graphics);
//Función que se fija si cambió el estado (si se presionó algún botón o saltó error) y devuelve el estado indicado.
int stateMenu(graphics_t graphics);

#endif /* RASPI_H */

