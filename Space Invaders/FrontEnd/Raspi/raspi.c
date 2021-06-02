/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raspi.c
 * Author: mpaget
 * 
 * Created on February 21, 2021, 11:21 AM
 */

#include "raspi.h"

void init_raspi (void)
{
    disp_init();
    joy_init();
    //init_sound();
    draw_play();
}
