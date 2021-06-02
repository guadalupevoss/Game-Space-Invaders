/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   audio_raspi.h
 * Author: mpaget
 *
 * Created on February 16, 2021, 3:20 PM
 */

#ifndef AUDIO_RASPI_H
#define AUDIO_RASPI_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "libaudio.h"

/*******************************************************************************
 *                    FUNCTION PROTOTYPES WITH GLOBAL SCOPE                    *
 *******************************************************************************/

/***************************************************************
 * Función: play_laser                                         *
 * Se encarga de reproducir el audio correspondiente al laser. *
 ***************************************************************/
void play_laser(void);

/***************************************************************
 * Función: play_play                                          *
 * Se encarga de reproducir el audio correspondiente a play.   *
 ***************************************************************/
void play_play(void);

/***************************************************************
 * Función: play_exit                                          *
 * Se encarga de reproducir el audio correspondiente a exit.   *
 ***************************************************************/
void play_exit(void);

/******************************************************************
 * Función: play_highscore                                        *
 * Se encarga de reproducir el audio correspondiente a highscore. *
 ******************************************************************/
void play_highscore(void);


#endif /* AUDIO_RASPI_H */

