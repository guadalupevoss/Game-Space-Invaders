#ifdef RASPI

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fondos.c
 * Author: Grupo 2
 * En este archivo se encuentran las funciones que imprimen los fondos en la 
 * Raspberry Pi.
 * Created on February 13, 2021, 12:53 PM
 */

#include "fondos.h"

void draw_play (void)
{	
	//PLAY
	dcoord_t myPoint_play = {0,1};
	disp_write (myPoint_play, D_ON);
	dcoord_t myPoint_play0 = {0,2};
	disp_write (myPoint_play0, D_ON);
	dcoord_t myPoint_play1 = {0,3};
	disp_write (myPoint_play1, D_ON);
	dcoord_t myPoint_play2 = {0,4};
	disp_write (myPoint_play2, D_ON);
	
	dcoord_t myPoint_play3 = {1,1};
	disp_write (myPoint_play3, D_ON);
	dcoord_t myPoint_play4 = {1,3};
	disp_write (myPoint_play4, D_ON);
	
	dcoord_t myPoint_play5 = {2,1};
	disp_write (myPoint_play5, D_ON);
	dcoord_t myPoint_play6 = {2,2};
	disp_write (myPoint_play6, D_ON);
	dcoord_t myPoint_play7 = {2,3};
	disp_write (myPoint_play7, D_ON);
	
	dcoord_t myPoint_play8 = {4,1};
	disp_write (myPoint_play8, D_ON);
	dcoord_t myPoint_play889 = {4,2};
	disp_write (myPoint_play889, D_ON);
	dcoord_t myPoint_play9 = {4,3};
	disp_write (myPoint_play9, D_ON);
	dcoord_t myPoint_play10 = {4,4};
	disp_write (myPoint_play10, D_ON);
	
	dcoord_t myPoint_play11 = {5,4};
	disp_write (myPoint_play11, D_ON);
	
	dcoord_t myPoint_play12 = {6,4};
	disp_write (myPoint_play12, D_ON);
	
	dcoord_t myPoint_play13 = {8,1};
	disp_write (myPoint_play13, D_ON);
	dcoord_t myPoint_play14 = {8,2};
	disp_write (myPoint_play14, D_ON);
	dcoord_t myPoint_play15 = {8,3};
	disp_write (myPoint_play15, D_ON);
	dcoord_t myPoint_play1555 = {8,4};
	disp_write (myPoint_play1555, D_ON);
	
	dcoord_t myPoint_play16 = {9,1};
	disp_write (myPoint_play16, D_ON);
	dcoord_t myPoint_play17 = {9,3};
	disp_write (myPoint_play17, D_ON);
	
	dcoord_t myPoint_play18 = {10,1};
	disp_write (myPoint_play18, D_ON);
	dcoord_t myPoint_play19 = {10,2};
	disp_write (myPoint_play19, D_ON);
	dcoord_t myPoint_play20 = {10,3};
	disp_write (myPoint_play20, D_ON);
	dcoord_t myPoint_play21 = {10,4};
	disp_write (myPoint_play21, D_ON);
	
	dcoord_t myPoint_play22 = {12,1};
	disp_write (myPoint_play22, D_ON);
	dcoord_t myPoint_play23 = {12,2};
	disp_write (myPoint_play23, D_ON);
	
	dcoord_t myPoint_play24 = {13,2};
	disp_write (myPoint_play24, D_ON);
	dcoord_t myPoint_play25 = {13,3};
	disp_write (myPoint_play25, D_ON);
	dcoord_t myPoint_play26 = {13,4};
	disp_write (myPoint_play26, D_ON);
	
	dcoord_t myPoint_play27 = {14,1};
	disp_write (myPoint_play27, D_ON);
	dcoord_t myPoint_play28 = {14,2};
	disp_write (myPoint_play28, D_ON);
	
	//Cosito de PLAY
	dcoord_t myPoint_play29 = {6,6};
	disp_write (myPoint_play29, D_ON);
	dcoord_t myPoint_play30 = {6,7};
	disp_write (myPoint_play30, D_ON);
	dcoord_t myPoint_play31 = {6,8};
	disp_write (myPoint_play31, D_ON);
	dcoord_t myPoint_play32 = {6,9};
	disp_write (myPoint_play32, D_ON);
	dcoord_t myPoint_play33 = {6,10};
	disp_write (myPoint_play33, D_ON);
	
	dcoord_t myPoint_play34 = {7,7};
	disp_write (myPoint_play34, D_ON);
	dcoord_t myPoint_play35 = {7,8};
	disp_write (myPoint_play35, D_ON);
	dcoord_t myPoint_play37 = {7,9};
	disp_write (myPoint_play37, D_ON);
	
	dcoord_t myPoint_play38 = {8,8};
	disp_write (myPoint_play38, D_ON);
	
	draw_flechitas();
	
	disp_update();	
}

void draw_highscore (void)
{
	
	//COPA
	dcoord_t myPoint_highscore = {3,1};
	disp_write (myPoint_highscore, D_ON);
	dcoord_t myPoint_highscore1 = {4,1};
	disp_write (myPoint_highscore1, D_ON);
	dcoord_t myPoint_highscore2 = {5,1};
	disp_write (myPoint_highscore2, D_ON);
	dcoord_t myPoint_highscore3 = {6,1};
	disp_write (myPoint_highscore3, D_ON);
	dcoord_t myPoint_highscore4 = {7,1};
	disp_write (myPoint_highscore4, D_ON);
	dcoord_t myPoint_highscore5 = {8,1};
	disp_write (myPoint_highscore5, D_ON);
	dcoord_t myPoint_highscore6 = {9,1};
	disp_write (myPoint_highscore6, D_ON);
	dcoord_t myPoint_highscore7 = {10,1};
	disp_write (myPoint_highscore7, D_ON);
	dcoord_t myPoint_highscore8 = {11,1};
	disp_write (myPoint_highscore8, D_ON);
	dcoord_t myPoint_highscore9 = {12,1};
	disp_write (myPoint_highscore9, D_ON);
	
	dcoord_t myPoint_highscore10 = {3,2};
	disp_write (myPoint_highscore10, D_ON);
	dcoord_t myPoint_highscore11 = {4,2};
	disp_write (myPoint_highscore11, D_ON);
	dcoord_t myPoint_highscore12 = {5,2};
	disp_write (myPoint_highscore12, D_ON);
	dcoord_t myPoint_highscore13 = {6,2};
	disp_write (myPoint_highscore13, D_ON);
	dcoord_t myPoint_highscore14 = {7,2};
	disp_write (myPoint_highscore14, D_ON);
	dcoord_t myPoint_highscore15 = {8,2};
	disp_write (myPoint_highscore15, D_ON);
	dcoord_t myPoint_highscore16 = {9,2};
	disp_write (myPoint_highscore16, D_ON);
	dcoord_t myPoint_highscore17 = {10,2};
	disp_write (myPoint_highscore17, D_ON);
	dcoord_t myPoint_highscore18 = {11,2};
	disp_write (myPoint_highscore18, D_ON);
	dcoord_t myPoint_highscore19 = {12,2};
	disp_write (myPoint_highscore19, D_ON);
	
	dcoord_t myPoint_highscore20 = {4,3};
	disp_write (myPoint_highscore20, D_ON);
	dcoord_t myPoint_highscore21 = {5,3};
	disp_write (myPoint_highscore21, D_ON);
	dcoord_t myPoint_highscore22 = {6,3};
	disp_write (myPoint_highscore22, D_ON);
	dcoord_t myPoint_highscore23 = {7,3};
	disp_write (myPoint_highscore23, D_ON);
	dcoord_t myPoint_highscore24 = {8,3};
	disp_write (myPoint_highscore24, D_ON);
	dcoord_t myPoint_highscore25 = {9,3};
	disp_write (myPoint_highscore25, D_ON);
	dcoord_t myPoint_highscore26 = {10,3};
	disp_write (myPoint_highscore26, D_ON);
	dcoord_t myPoint_highscore27 = {11,3};
	disp_write (myPoint_highscore27, D_ON);
	
	dcoord_t myPoint_highscore28 = {5,4};
	disp_write (myPoint_highscore28, D_ON);
	dcoord_t myPoint_highscore29 = {6,4};
	disp_write (myPoint_highscore29, D_ON);
	dcoord_t myPoint_highscore30 = {7,4};
	disp_write (myPoint_highscore30, D_ON);
	dcoord_t myPoint_highscore31 = {8,4};
	disp_write (myPoint_highscore31, D_ON);
	dcoord_t myPoint_highscore32 = {9,4};
	disp_write (myPoint_highscore32, D_ON);
	dcoord_t myPoint_highscore33 = {10,4};
	disp_write (myPoint_highscore33, D_ON);
	
	dcoord_t myPoint_highscore34 = {6,5};
	disp_write (myPoint_highscore34, D_ON);
	dcoord_t myPoint_highscore35 = {7,5};
	disp_write (myPoint_highscore35, D_ON);
	dcoord_t myPoint_highscore36 = {8,5};
	disp_write (myPoint_highscore36, D_ON);
	dcoord_t myPoint_highscore37 = {9,5};
	disp_write (myPoint_highscore37, D_ON);
	
	dcoord_t myPoint_highscore38 = {7,6};
	disp_write (myPoint_highscore38, D_ON);
	dcoord_t myPoint_highscore39 = {8,6};
	disp_write (myPoint_highscore39, D_ON);
	
	dcoord_t myPoint_highscore40 = {7,7};
	disp_write (myPoint_highscore40, D_ON);
	dcoord_t myPoint_highscore41 = {8,7};
	disp_write (myPoint_highscore41, D_ON);
	
	dcoord_t myPoint_highscore42 = {7,8};
	disp_write (myPoint_highscore42, D_ON);
	dcoord_t myPoint_highscore43 = {8,8};
	disp_write (myPoint_highscore43, D_ON);
	
	dcoord_t myPoint_highscore44 = {5,9};
	disp_write (myPoint_highscore44, D_ON);
	dcoord_t myPoint_highscore45 = {6,9};
	disp_write (myPoint_highscore45, D_ON);
	dcoord_t myPoint_highscore46 = {7,9};
	disp_write (myPoint_highscore46, D_ON);
	dcoord_t myPoint_highscore47 = {8,9};
	disp_write (myPoint_highscore47, D_ON);
	dcoord_t myPoint_highscore48 = {9,9};
	disp_write (myPoint_highscore48, D_ON);
	dcoord_t myPoint_highscore49 = {10,9};
	disp_write (myPoint_highscore49, D_ON);
	
	dcoord_t myPoint_highscore50 = {5,10};
	disp_write (myPoint_highscore50, D_ON);
	dcoord_t myPoint_highscore51 = {6,10};
	disp_write (myPoint_highscore51, D_ON);
	dcoord_t myPoint_highscore52 = {7,10};
	disp_write (myPoint_highscore52, D_ON);
	dcoord_t myPoint_highscore53 = {8,10};
	disp_write (myPoint_highscore53, D_ON);
	dcoord_t myPoint_highscore54 = {9,10};
	disp_write (myPoint_highscore54, D_ON);
	dcoord_t myPoint_highscore55 = {10,10};
	disp_write (myPoint_highscore55, D_ON);
	
	
	draw_flechitas();
	
	
	disp_update();	
}

void draw_exit (void)
{
	
	dcoord_t myPoint_exit1 = {1,1};
	disp_write (myPoint_exit1, D_ON);
	dcoord_t myPoint_exit2 = {2,1};
	disp_write (myPoint_exit2, D_ON);
	dcoord_t myPoint_exit3 = {3,1};
	disp_write (myPoint_exit3, D_ON);
	dcoord_t myPoint_exit4 = {5,1};
	disp_write (myPoint_exit4, D_ON);
	dcoord_t myPoint_exit5 = {9,1};
	disp_write (myPoint_exit5, D_ON);
	dcoord_t myPoint_exit6 = {11,1};
	disp_write (myPoint_exit6, D_ON);
	dcoord_t myPoint_exit7 = {13,1};
	disp_write (myPoint_exit7, D_ON);
	dcoord_t myPoint_exit8 = {14,1};
	disp_write (myPoint_exit8, D_ON);
	dcoord_t myPoint_exit9 = {15,1};
	disp_write (myPoint_exit9, D_ON);
	
	dcoord_t myPoint_exit10 = {1,2};
	disp_write (myPoint_exit10, D_ON);
	dcoord_t myPoint_exit11 = {6,2};
	disp_write (myPoint_exit11, D_ON);
	dcoord_t myPoint_exit12 = {8,2};
	disp_write (myPoint_exit12, D_ON);
	dcoord_t myPoint_exit13 = {11,2};
	disp_write (myPoint_exit13, D_ON);
	dcoord_t myPoint_exit14 = {14,2};
	disp_write (myPoint_exit14, D_ON);
	
	dcoord_t myPoint_exit15 = {1,3};
	disp_write (myPoint_exit15, D_ON);
	dcoord_t myPoint_exit16 = {2,3};
	disp_write (myPoint_exit16, D_ON);
	dcoord_t myPoint_exit17 = {3,3};
	disp_write (myPoint_exit17, D_ON);
	dcoord_t myPoint_exit18 = {7,3};
	disp_write (myPoint_exit18, D_ON);
	dcoord_t myPoint_exit19 = {11,3};
	disp_write (myPoint_exit19, D_ON);
	dcoord_t myPoint_exit20 = {14,3};
	disp_write (myPoint_exit20, D_ON);
	
	dcoord_t myPoint_exit21 = {1,4};
	disp_write (myPoint_exit21, D_ON);
	dcoord_t myPoint_exit22 = {6,4};
	disp_write (myPoint_exit22, D_ON);
	dcoord_t myPoint_exit23 = {8,4};
	disp_write (myPoint_exit23, D_ON);
	dcoord_t myPoint_exit24 = {11,4};
	disp_write (myPoint_exit24, D_ON);
	dcoord_t myPoint_exit25 = {14,4};
	disp_write (myPoint_exit25, D_ON);
	
	dcoord_t myPoint_exit26 = {1,5};
	disp_write (myPoint_exit26, D_ON);
	dcoord_t myPoint_exit27 = {2,5};
	disp_write (myPoint_exit27, D_ON);
	dcoord_t myPoint_exit29 = {3,5};
	disp_write (myPoint_exit29, D_ON);
	dcoord_t myPoint_exit30 = {5,5};
	disp_write (myPoint_exit30, D_ON);
	dcoord_t myPoint_exit31 = {9,5};
	disp_write (myPoint_exit31, D_ON);
	dcoord_t myPoint_exit32 = {11,5};
	disp_write (myPoint_exit32, D_ON);
	dcoord_t myPoint_exit33 = {14,5};
	disp_write (myPoint_exit33, D_ON);
	
	//CRUZ
	
	dcoord_t myPoint_exit34 = {6,7};
	disp_write (myPoint_exit34, D_ON);
	dcoord_t myPoint_exit35 = {9,7};
	disp_write (myPoint_exit35, D_ON);
	
	dcoord_t myPoint_exit36 = {7,8};
	disp_write (myPoint_exit36, D_ON);
	dcoord_t myPoint_exit37 = {8,8};
	disp_write (myPoint_exit37, D_ON);
	
	dcoord_t myPoint_exit38 = {6,9};
	disp_write (myPoint_exit38, D_ON);
	dcoord_t myPoint_exit39 = {9,9};
	disp_write (myPoint_exit39, D_ON);
	
	//FLECHITAS
	draw_flechitas();
	
	disp_update();
}

void draw_pause_menu (void)
{
    
    //palitos
    draw_palitos();
    
    //menu
    dcoord_t myPoint_menu = {1,6};
    disp_write (myPoint_menu, D_ON);
    dcoord_t myPoint_menu1 = {1,7};
    disp_write (myPoint_menu1, D_ON);
    dcoord_t myPoint_menu2 = {1,8};
    disp_write (myPoint_menu2, D_ON);
    dcoord_t myPoint_menu3 = {1,9};
    disp_write (myPoint_menu3, D_ON);
    dcoord_t myPoint_menu4 = {1,10};
    disp_write (myPoint_menu4, D_ON);
    
    dcoord_t myPoint_menu5 = {2,7};
    disp_write (myPoint_menu5, D_ON);
    
    dcoord_t myPoint_menu6 = {3,6};
    disp_write (myPoint_menu6, D_ON);
    dcoord_t myPoint_menu7 = {3,7};
    disp_write (myPoint_menu7, D_ON);
    dcoord_t myPoint_menu8 = {3,8};
    disp_write (myPoint_menu8, D_ON);
    dcoord_t myPoint_menu9 = {3,9};
    disp_write (myPoint_menu9, D_ON);
    dcoord_t myPoint_menu10 = {3,10};
    disp_write (myPoint_menu10, D_ON);
    
    dcoord_t myPoint_menu11 = {5,6};
    disp_write (myPoint_menu11, D_ON);
    dcoord_t myPoint_menu12 = {5,7};
    disp_write (myPoint_menu12, D_ON);
    dcoord_t myPoint_menu13 = {5,8};
    disp_write (myPoint_menu13, D_ON);
    dcoord_t myPoint_menu14 = {5,9};
    disp_write (myPoint_menu14, D_ON);
    dcoord_t myPoint_menu15 = {5,10};
    disp_write (myPoint_menu15, D_ON);
    
    dcoord_t myPoint_menu16 = {6,6};
    disp_write (myPoint_menu16, D_ON);
    dcoord_t myPoint_menu17 = {6,8};
    disp_write (myPoint_menu17, D_ON);
    dcoord_t myPoint_menu18 = {6,10};
    disp_write (myPoint_menu18, D_ON);
    
    dcoord_t myPoint_menu19 = {8,6};
    disp_write (myPoint_menu19, D_ON);
    dcoord_t myPoint_menu20 = {8,7};
    disp_write (myPoint_menu20, D_ON);
    dcoord_t myPoint_menu21 = {8,8};
    disp_write (myPoint_menu21, D_ON);
    dcoord_t myPoint_menu22 = {8,9};
    disp_write (myPoint_menu22, D_ON);
    dcoord_t myPoint_menu23 = {8,10};
    disp_write (myPoint_menu23, D_ON);

    dcoord_t myPoint_menu24 = {9,7};
    disp_write (myPoint_menu24, D_ON);
    
    dcoord_t myPoint_menu25 = {10,8};
    disp_write (myPoint_menu25, D_ON);
    
    dcoord_t myPoint_menu26 = {11,6};
    disp_write (myPoint_menu26, D_ON);
    dcoord_t myPoint_menu27 = {11,7};
    disp_write (myPoint_menu27, D_ON);
    dcoord_t myPoint_menu28 = {11,8};
    disp_write (myPoint_menu28, D_ON);
    dcoord_t myPoint_menu29 = {11,9};
    disp_write (myPoint_menu29, D_ON);
    dcoord_t myPoint_menu30 = {11,10};
    disp_write (myPoint_menu30, D_ON);
    
    dcoord_t myPoint_menu31 = {13,6};
    disp_write (myPoint_menu31, D_ON);
    dcoord_t myPoint_menu32 = {13,7};
    disp_write (myPoint_menu32, D_ON);
    dcoord_t myPoint_menu33 = {13,8};
    disp_write (myPoint_menu33, D_ON);
    dcoord_t myPoint_menu34 = {13,9};
    disp_write (myPoint_menu34, D_ON);
    dcoord_t myPoint_menu35 = {13,10};
    disp_write (myPoint_menu35, D_ON);
    
    dcoord_t myPoint_menu36 = {14,10};
    disp_write (myPoint_menu36, D_ON);
    
    dcoord_t myPoint_menu37 = {15,6};
    disp_write (myPoint_menu37, D_ON);
    dcoord_t myPoint_menu38 = {15,7};
    disp_write (myPoint_menu38, D_ON);
    dcoord_t myPoint_menu39 = {15,8};
    disp_write (myPoint_menu39, D_ON);
    dcoord_t myPoint_menu40 = {15,9};
    disp_write (myPoint_menu40, D_ON);
    dcoord_t myPoint_menu41 = {15,10};
    disp_write (myPoint_menu41, D_ON);
    
    draw_flechitas();
	
    disp_update();
}

void draw_pause_play (void)
{
    
    //PLAY
    dcoord_t myPoint_pause_play = {1,6};
    disp_write (myPoint_pause_play, D_ON);
    dcoord_t myPoint_pause_play1 = {2,6};
    disp_write (myPoint_pause_play1, D_ON);
    dcoord_t myPoint_pause_play2 = {3,6};
    disp_write (myPoint_pause_play2, D_ON);
    
    dcoord_t myPoint_pause_play3 = {5,6};
    disp_write (myPoint_pause_play3, D_ON);
    
    dcoord_t myPoint_pause_play4 = {8,6};
    disp_write (myPoint_pause_play4, D_ON);
    dcoord_t myPoint_pause_play5 = {9,6};
    disp_write (myPoint_pause_play5, D_ON);
    dcoord_t myPoint_pause_play6 = {10,6};
    disp_write (myPoint_pause_play6, D_ON);
    
    dcoord_t myPoint_pause_play7 = {12,6};
    disp_write (myPoint_pause_play7, D_ON);
    dcoord_t myPoint_pause_play8 = {14,6};
    disp_write (myPoint_pause_play8, D_ON);
    
    dcoord_t myPoint_pause_play9 = {1,7};
    disp_write (myPoint_pause_play9, D_ON);
    dcoord_t myPoint_pause_play10 = {3,7};
    disp_write (myPoint_pause_play10, D_ON);
    
    dcoord_t myPoint_pause_play11 = {5,7};
    disp_write (myPoint_pause_play11, D_ON);
    
    dcoord_t myPoint_pause_play12 = {8,7};
    disp_write (myPoint_pause_play12, D_ON);
    dcoord_t myPoint_pause_play13 = {10,7};
    disp_write (myPoint_pause_play13, D_ON);
    
    dcoord_t myPoint_pause_play14 = {12,7};
    disp_write (myPoint_pause_play14, D_ON);
    dcoord_t myPoint_pause_play15 = {14,7};
    disp_write (myPoint_pause_play15, D_ON);
    
    dcoord_t myPoint_pause_play16 = {1,8};
    disp_write (myPoint_pause_play16, D_ON);
    dcoord_t myPoint_pause_play17 = {2,8};
    disp_write (myPoint_pause_play17, D_ON);
    dcoord_t myPoint_pause_play18 = {3,8};
    disp_write (myPoint_pause_play18, D_ON);
    
    dcoord_t myPoint_pause_play19 = {5,8};
    disp_write (myPoint_pause_play19, D_ON);
    
    dcoord_t myPoint_pause_play20 = {8,8};
    disp_write (myPoint_pause_play20, D_ON);
    dcoord_t myPoint_pause_play21 = {9,8};
    disp_write (myPoint_pause_play21, D_ON);
    dcoord_t myPoint_pause_play22 = {10,8};
    disp_write (myPoint_pause_play22, D_ON);
    
    dcoord_t myPoint_pause_play23 = {12,8};
    disp_write (myPoint_pause_play23, D_ON);
    dcoord_t myPoint_pause_play24 = {13,8};
    disp_write (myPoint_pause_play24, D_ON);
    dcoord_t myPoint_pause_play25 = {14,8};
    disp_write (myPoint_pause_play25, D_ON);
    
    dcoord_t myPoint_pause_play26 = {1,9};
    disp_write (myPoint_pause_play26, D_ON);
    
    dcoord_t myPoint_pause_play27 = {5,9};
    disp_write (myPoint_pause_play27, D_ON);
    
    dcoord_t myPoint_pause_play28 = {8,9};
    disp_write (myPoint_pause_play28, D_ON);
    dcoord_t myPoint_pause_play29 = {10,9};
    disp_write (myPoint_pause_play29, D_ON);
    
    dcoord_t myPoint_pause_play30 = {13,9};
    disp_write (myPoint_pause_play30, D_ON);
    
    dcoord_t myPoint_pause_play31 = {1,10};
    disp_write (myPoint_pause_play31, D_ON);
    
    dcoord_t myPoint_pause_play32 = {5,10};
    disp_write (myPoint_pause_play32, D_ON);
    dcoord_t myPoint_pause_play33 = {6,10};
    disp_write (myPoint_pause_play33, D_ON);
    
    dcoord_t myPoint_pause_play34 = {8,10};
    disp_write (myPoint_pause_play34, D_ON);
    dcoord_t myPoint_pause_play35 = {10,10};
    disp_write (myPoint_pause_play35, D_ON);
    
    dcoord_t myPoint_pause_play36 = {13,10};
    disp_write (myPoint_pause_play36, D_ON);
    
    draw_palitos();
    draw_flechitas();
    
    disp_update();
}

void draw_pause_exit (void)
{
    
    //EXIT
    dcoord_t myPoint_pause_exit = {1,6};
    disp_write (myPoint_pause_exit, D_ON);
    dcoord_t myPoint_pause_exit1 = {2,6};
    disp_write (myPoint_pause_exit1, D_ON);
    
    dcoord_t myPoint_pause_exit2 = {4,6};
    disp_write (myPoint_pause_exit2, D_ON);
    dcoord_t myPoint_pause_exit3 = {8,6};
    disp_write (myPoint_pause_exit3, D_ON);
    
    dcoord_t myPoint_pause_exit4 = {10,6};
    disp_write (myPoint_pause_exit4, D_ON);
    
    dcoord_t myPoint_pause_exit5 = {12,6};
    disp_write (myPoint_pause_exit5, D_ON);
    dcoord_t myPoint_pause_exit6 = {13,6};
    disp_write (myPoint_pause_exit6, D_ON);
    dcoord_t myPoint_pause_exit7 = {14,6};
    disp_write (myPoint_pause_exit7, D_ON);
    
    dcoord_t myPoint_pause_exit8 = {1,7};
    disp_write (myPoint_pause_exit8, D_ON);
    
    dcoord_t myPoint_pause_exit9 = {5,7};
    disp_write (myPoint_pause_exit9, D_ON);
    dcoord_t myPoint_pause_exit10 = {7,7};
    disp_write (myPoint_pause_exit10, D_ON);
    
    dcoord_t myPoint_pause_exit11 = {10,7};
    disp_write (myPoint_pause_exit11, D_ON);
    
    dcoord_t myPoint_pause_exit12 = {13,7};
    disp_write (myPoint_pause_exit12, D_ON);
    
    dcoord_t myPoint_pause_exit13 = {1,8};
    disp_write (myPoint_pause_exit13, D_ON);
    dcoord_t myPoint_pause_exit14 = {2,8};
    disp_write (myPoint_pause_exit14, D_ON);
    
    dcoord_t myPoint_pause_exit15 = {6,8};
    disp_write (myPoint_pause_exit15, D_ON);
    
    dcoord_t myPoint_pause_exit16 = {10,8};
    disp_write (myPoint_pause_exit16, D_ON);
    
    dcoord_t myPoint_pause_exit17 = {13,8};
    disp_write (myPoint_pause_exit17, D_ON);
    
    dcoord_t myPoint_pause_exit18 = {1,9};
    disp_write (myPoint_pause_exit18, D_ON);
    
    dcoord_t myPoint_pause_exit19 = {5,9};
    disp_write (myPoint_pause_exit19, D_ON);
    dcoord_t myPoint_pause_exit20 = {7,9};
    disp_write (myPoint_pause_exit20, D_ON);
    
    dcoord_t myPoint_pause_exit21 = {10,9};
    disp_write (myPoint_pause_exit21, D_ON);
    
    dcoord_t myPoint_pause_exit22 = {13,9};
    disp_write (myPoint_pause_exit22, D_ON);
    
    dcoord_t myPoint_pause_exit23 = {1,10};
    disp_write (myPoint_pause_exit23, D_ON);
    dcoord_t myPoint_pause_exit24 = {2,10};
    disp_write (myPoint_pause_exit24, D_ON);
    
    dcoord_t myPoint_pause_exit25 = {4,10};
    disp_write (myPoint_pause_exit25, D_ON);
    dcoord_t myPoint_pause_exit26 = {8,10};
    disp_write (myPoint_pause_exit26, D_ON);
    
    dcoord_t myPoint_pause_exit27 = {10,10};
    disp_write (myPoint_pause_exit27, D_ON);
    
    dcoord_t myPoint_pause_exit28 = {13,10};
    disp_write (myPoint_pause_exit28, D_ON);
    
    draw_palitos();
    draw_flechitas();
    
    disp_update();
}

void draw_gameover(void)
{
    
    //GAME OVER
    dcoord_t myPoint_gameover = {0,3};
    disp_write (myPoint_gameover, D_ON);
    dcoord_t myPoint_gameover1 = {1,3};
    disp_write (myPoint_gameover1, D_ON);
    dcoord_t myPoint_gameover2 = {2,3};
    disp_write (myPoint_gameover2, D_ON);
    
    dcoord_t myPoint_gameover3 = {4,3};
    disp_write (myPoint_gameover3, D_ON);
    dcoord_t myPoint_gameover4 = {5,3};
    disp_write (myPoint_gameover4, D_ON);
    dcoord_t myPoint_gameover5 = {6,3};
    disp_write (myPoint_gameover5, D_ON);
    
    dcoord_t myPoint_gameover6 = {8,3};
    disp_write (myPoint_gameover6, D_ON);
    dcoord_t myPoint_gameover7 = {9,3};
    disp_write (myPoint_gameover7, D_ON);
    dcoord_t myPoint_gameover8 = {11,3};
    disp_write (myPoint_gameover8, D_ON);
    dcoord_t myPoint_gameover9 = {12,3};
    disp_write (myPoint_gameover9, D_ON);
    
    dcoord_t myPoint_gameover10 = {14,3};
    disp_write (myPoint_gameover10, D_ON);
    dcoord_t myPoint_gameover11 = {15,3};
    disp_write (myPoint_gameover11, D_ON);
    
    dcoord_t myPoint_gameover12 = {0,4};
    disp_write (myPoint_gameover12, D_ON);
    
    dcoord_t myPoint_gameover13 = {4,4};
    disp_write (myPoint_gameover13, D_ON);
    dcoord_t myPoint_gameover14 = {6,4};
    disp_write (myPoint_gameover14, D_ON);
    
    dcoord_t myPoint_gameover15 = {8,4};
    disp_write (myPoint_gameover15, D_ON);
    dcoord_t myPoint_gameover16 = {10,4};
    disp_write (myPoint_gameover16, D_ON);
    dcoord_t myPoint_gameover17 = {12,4};
    disp_write (myPoint_gameover17, D_ON);
    
    dcoord_t myPoint_gameover18 = {14,4};
    disp_write (myPoint_gameover18, D_ON);
    
    dcoord_t myPoint_gameover19 = {0,5};
    disp_write (myPoint_gameover19, D_ON);
    dcoord_t myPoint_gameover20 = {1,5};
    disp_write (myPoint_gameover20, D_ON);
    dcoord_t myPoint_gameover21 = {2,5};
    disp_write (myPoint_gameover21, D_ON);
    
    dcoord_t myPoint_gameover22 = {4,5};
    disp_write (myPoint_gameover22, D_ON);
    dcoord_t myPoint_gameover23 = {5,5};
    disp_write (myPoint_gameover23, D_ON);
    dcoord_t myPoint_gameover24 = {6,5};
    disp_write (myPoint_gameover24, D_ON);
    
    dcoord_t myPoint_gameover25 = {8,5};
    disp_write (myPoint_gameover25, D_ON);
    dcoord_t myPoint_gameover26 = {12,5};
    disp_write (myPoint_gameover26, D_ON);
    
    dcoord_t myPoint_gameover27 = {13,5};
    disp_write (myPoint_gameover27, D_ON);
    dcoord_t myPoint_gameover28 = {14,5};
    disp_write (myPoint_gameover28, D_ON);
    
    dcoord_t myPoint_gameover29 = {0,6};
    disp_write (myPoint_gameover29, D_ON);
    dcoord_t myPoint_gameover30 = {2,6};
    disp_write (myPoint_gameover30, D_ON);
    
    dcoord_t myPoint_gameover31 = {4,6};
    disp_write (myPoint_gameover31, D_ON);
    dcoord_t myPoint_gameover32 = {6,6};
    disp_write (myPoint_gameover32, D_ON);
    
    dcoord_t myPoint_gameover33 = {8,6};
    disp_write (myPoint_gameover33, D_ON);
    dcoord_t myPoint_gameover34 = {12,6};
    disp_write (myPoint_gameover34, D_ON);
    
    dcoord_t myPoint_gameover35 = {14,6};
    disp_write (myPoint_gameover35, D_ON);
    
    dcoord_t myPoint_gameover36 = {0,7};
    disp_write (myPoint_gameover36, D_ON);
    dcoord_t myPoint_gameover37 = {1,7};
    disp_write (myPoint_gameover37, D_ON);
    dcoord_t myPoint_gameover38 = {2,7};
    disp_write (myPoint_gameover38, D_ON);
    
    dcoord_t myPoint_gameover39 = {4,7};
    disp_write (myPoint_gameover39, D_ON);
    dcoord_t myPoint_gameover40 = {6,7};
    disp_write (myPoint_gameover40, D_ON);
    
    dcoord_t myPoint_gameover41 = {8,7};
    disp_write (myPoint_gameover41, D_ON);
    dcoord_t myPoint_gameover42 = {12,7};
    disp_write (myPoint_gameover42, D_ON);
    
    dcoord_t myPoint_gameover43 = {14,7};
    disp_write (myPoint_gameover43, D_ON);
    dcoord_t myPoint_gameover44 = {15,7};
    disp_write (myPoint_gameover44, D_ON);
    
    dcoord_t myPoint_gameover45 = {0,9};
    disp_write (myPoint_gameover45, D_ON);
    dcoord_t myPoint_gameover46 = {1,9};
    disp_write (myPoint_gameover46, D_ON);
    dcoord_t myPoint_gameover47 = {2,9};
    disp_write (myPoint_gameover47, D_ON);
    
    dcoord_t myPoint_gameover48 = {4,9};
    disp_write (myPoint_gameover48, D_ON);
    dcoord_t myPoint_gameover49 = {8,9};
    disp_write (myPoint_gameover49, D_ON);
    
    dcoord_t myPoint_gameover50 = {10,9};
    disp_write (myPoint_gameover50, D_ON);
    dcoord_t myPoint_gameover51 = {11,9};
    disp_write (myPoint_gameover51, D_ON);
    
    dcoord_t myPoint_gameover52 = {13,9};
    disp_write (myPoint_gameover52, D_ON);
    dcoord_t myPoint_gameover53 = {14,9};
    disp_write (myPoint_gameover53, D_ON);
    dcoord_t myPoint_gameover54 = {15,9};
    disp_write (myPoint_gameover54, D_ON);
    
    dcoord_t myPoint_gameover55 = {0,10};
    disp_write (myPoint_gameover55, D_ON);
    dcoord_t myPoint_gameover56 = {2,10};
    disp_write (myPoint_gameover56, D_ON);
    
    dcoord_t myPoint_gameover57 = {4,10};
    disp_write (myPoint_gameover57, D_ON);
    dcoord_t myPoint_gameover58 = {8,10};
    disp_write (myPoint_gameover58, D_ON);
    
    dcoord_t myPoint_gameover59 = {10,10};
    disp_write (myPoint_gameover59, D_ON);
    
    dcoord_t myPoint_gameover60 = {13,10};
    disp_write (myPoint_gameover60, D_ON);
    dcoord_t myPoint_gameover61 = {15,10};
    disp_write (myPoint_gameover61, D_ON);
    
    dcoord_t myPoint_gameover62 = {0,11};
    disp_write (myPoint_gameover62, D_ON);
    dcoord_t myPoint_gameover63 = {2,11};
    disp_write (myPoint_gameover63, D_ON);
    
    dcoord_t myPoint_gameover64 = {4,11};
    disp_write (myPoint_gameover64, D_ON);
    dcoord_t myPoint_gameover65 = {8,11};
    disp_write (myPoint_gameover65, D_ON);
    
    dcoord_t myPoint_gameover66 = {10,11};
    disp_write (myPoint_gameover66, D_ON);
    dcoord_t myPoint_gameover67 = {11,11};
    disp_write (myPoint_gameover67, D_ON);
    
    dcoord_t myPoint_gameover68 = {13,11};
    disp_write (myPoint_gameover68, D_ON);
    dcoord_t myPoint_gameover69 = {14,11};
    disp_write (myPoint_gameover69, D_ON);
    dcoord_t myPoint_gameover70 = {15,11};
    disp_write (myPoint_gameover70, D_ON);
    
    dcoord_t myPoint_gameover71 = {0,12};
    disp_write (myPoint_gameover71, D_ON);
    dcoord_t myPoint_gameover72 = {2,12};
    disp_write (myPoint_gameover72, D_ON);
    
    dcoord_t myPoint_gameover73 = {5,12};
    disp_write (myPoint_gameover73, D_ON);
    dcoord_t myPoint_gameover74 = {7,12};
    disp_write (myPoint_gameover74, D_ON);
    
    dcoord_t myPoint_gameover75 = {10,12};
    disp_write (myPoint_gameover75, D_ON);
    
    dcoord_t myPoint_gameover76 = {13,12};
    disp_write (myPoint_gameover76, D_ON);
    dcoord_t myPoint_gameover77 = {14,12};
    disp_write (myPoint_gameover77, D_ON);
    
    dcoord_t myPoint_gameover78 = {0,13};
    disp_write (myPoint_gameover78, D_ON);
    dcoord_t myPoint_gameover79 = {1,13};
    disp_write (myPoint_gameover79, D_ON);
    dcoord_t myPoint_gameover80 = {2,13};
    disp_write (myPoint_gameover80, D_ON);
    
    dcoord_t myPoint_gameover81 = {6,13};
    disp_write (myPoint_gameover81, D_ON);
    
    dcoord_t myPoint_gameover82 = {10,13};
    disp_write (myPoint_gameover82, D_ON);
    dcoord_t myPoint_gameover83 = {11,13};
    disp_write (myPoint_gameover83, D_ON);
    
    dcoord_t myPoint_gameover84 = {13,13};
    disp_write (myPoint_gameover84, D_ON);
    dcoord_t myPoint_gameover85 = {15,13};
    disp_write (myPoint_gameover85, D_ON);
    
    disp_update();
}

void draw_palitos(void)
{
    dcoord_t myPoint_palitos = {5,1};
    disp_write (myPoint_palitos, D_ON);
    dcoord_t myPoint_palitos1 = {6,1};
    disp_write (myPoint_palitos1, D_ON);
    
    dcoord_t myPoint_palitos2 = {9,1};
    disp_write (myPoint_palitos2, D_ON);
    dcoord_t myPoint_palitos3 = {10,1};
    disp_write (myPoint_palitos3, D_ON);
    
    dcoord_t myPoint_palitos4 = {5,2};
    disp_write (myPoint_palitos4, D_ON);
    dcoord_t myPoint_palitos5 = {6,2};
    disp_write (myPoint_palitos5, D_ON);
    
    dcoord_t myPoint_palitos6 = {9,2};
    disp_write (myPoint_palitos6, D_ON);
    dcoord_t myPoint_palitos7 = {10,2};
    disp_write (myPoint_palitos7, D_ON);
    
    dcoord_t myPoint_palitos8 = {5,3};
    disp_write (myPoint_palitos8, D_ON);
    dcoord_t myPoint_palitos9 = {6,3};
    disp_write (myPoint_palitos9, D_ON);
    
    dcoord_t myPoint_palitos10 = {9,3};
    disp_write (myPoint_palitos10, D_ON);
    dcoord_t myPoint_palitos11 = {10,3};
    disp_write (myPoint_palitos11, D_ON);
    
    dcoord_t myPoint_palitos12 = {5,4};
    disp_write (myPoint_palitos12, D_ON);
    dcoord_t myPoint_palitos13 = {6,4};
    disp_write (myPoint_palitos13, D_ON);
    
    dcoord_t myPoint_palitos14 = {9,4};
    disp_write (myPoint_palitos14, D_ON);
    dcoord_t myPoint_palitos15 = {10,4};
    disp_write (myPoint_palitos15, D_ON);
}

void draw_flechitas(void)
{
    //FLECHITAS
    dcoord_t myPoint_flecha1 = {3,13};
    disp_write (myPoint_flecha1, D_ON);
    dcoord_t myPoint_flecha2 = {4,12};
    disp_write (myPoint_flecha2, D_ON);
    dcoord_t myPoint_flecha3 = {4,13};
    disp_write (myPoint_flecha3, D_ON);
    dcoord_t myPoint_flecha4 = {4,14};
    disp_write (myPoint_flecha4, D_ON);
	
    dcoord_t myPoint_flecha5 = {11,12};
    disp_write (myPoint_flecha5, D_ON);
    dcoord_t myPoint_flecha6 = {11,13};
    disp_write (myPoint_flecha6, D_ON);
    dcoord_t myPoint_flecha7 = {11,14};
    disp_write (myPoint_flecha7, D_ON);
    dcoord_t myPoint_flecha8 = {12,13};
    disp_write (myPoint_flecha8, D_ON);
}

#endif