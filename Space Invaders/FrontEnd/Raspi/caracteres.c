/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   caracteres.h
 * Author: Grupo 2
 * En este archivo se encuentran todas las funciones encargadas de imprimir las 
 * letras del abecedario y los números en la Raspberry Pi.
 * Created on February 12, 2021, 2:20 PM
 */

#ifdef RASPI

/*******************************************************************************
 *                              HEADER FILES                                   *
 *******************************************************************************/
#include "caracteres.h"

void changeScreen(int screenNumber);
void clear_guion(void);
/*******************************************************************************
 *                        GLOBAL FUNCTIONS DEFINITIONS                         *
 *******************************************************************************/

//Letras
void draw_a (int ax, int ay)
{
	dcoord_t myPoint_a1 = {ax+1,ay-4};
	disp_write (myPoint_a1, D_ON);
	dcoord_t myPoint_a2 = {ax+2,ay-4};
	disp_write (myPoint_a2, D_ON);
	dcoord_t myPoint_a3 = {ax,ay-3};
	disp_write (myPoint_a3, D_ON);
	dcoord_t myPoint_a4 = {ax+3,ay-3};
	disp_write (myPoint_a4, D_ON);
	dcoord_t myPoint_a5 = {ax,ay-2};
	disp_write (myPoint_a5, D_ON);
	dcoord_t myPoint_a6 = {ax+1,ay-2};
	disp_write (myPoint_a6, D_ON);
	dcoord_t myPoint_a7 = {ax+2,ay-2};
	disp_write (myPoint_a7, D_ON);
	dcoord_t myPoint_a8 = {ax+3,ay-2};
	disp_write (myPoint_a8, D_ON);
	dcoord_t myPoint_a9 = {ax,ay-1};
	disp_write (myPoint_a9, D_ON);
	dcoord_t myPoint_a10 = {ax+3,ay-1};
	disp_write (myPoint_a10, D_ON);
	dcoord_t myPoint_a11 = {ax,ay};
	disp_write (myPoint_a11, D_ON);
	dcoord_t myPoint_a12 = {ax+3,ay};
	disp_write (myPoint_a12, D_ON);
	return;
}

void draw_b (int bx, int by)
{
	dcoord_t myPoint_b1 = {bx,by-4};
	disp_write (myPoint_b1, D_ON);
	dcoord_t myPoint_b2 = {bx+1,by-4};
	disp_write (myPoint_b2, D_ON);
	dcoord_t myPoint_b3 = {bx+2,by-4};
	disp_write (myPoint_b3, D_ON);
	dcoord_t myPoint_b4 = {bx,by-3};
	disp_write (myPoint_b4, D_ON);
	dcoord_t myPoint_b5 = {bx+3,by-3};
	disp_write (myPoint_b5, D_ON);
	dcoord_t myPoint_b6 = {bx+3,by-1};
	disp_write (myPoint_b6, D_ON);
	dcoord_t myPoint_b7 = {bx,by-2};
	disp_write (myPoint_b7, D_ON);
	dcoord_t myPoint_b8 = {bx+1,by-2};
	disp_write (myPoint_b8, D_ON);
	dcoord_t myPoint_b9 = {bx+2,by-2};
	disp_write (myPoint_b9, D_ON);
	dcoord_t myPoint_b10 = {bx,by-1};
	disp_write (myPoint_b10, D_ON);
	dcoord_t myPoint_b11 = {bx,by};
	disp_write (myPoint_b11, D_ON);
	dcoord_t myPoint_b12 = {bx+1,by};
	disp_write (myPoint_b12, D_ON);
	dcoord_t myPoint_b13 = {bx+2,by};
	disp_write (myPoint_b13, D_ON);
	return;
}

void draw_c (int cx, int cy)
{
	dcoord_t myPoint_c1 = {cx,cy-4};
	disp_write (myPoint_c1, D_ON);
	dcoord_t myPoint_c2 = {cx+1,cy-4};
	disp_write (myPoint_c2, D_ON);
	dcoord_t myPoint_c3 = {cx+2,cy-4};
	disp_write (myPoint_c3, D_ON);
	dcoord_t myPoint_c4 = {cx+3,cy-4};
	disp_write (myPoint_c4, D_ON);
	dcoord_t myPoint_c5 = {cx,cy-3};
	disp_write (myPoint_c5, D_ON);
	dcoord_t myPoint_c6 = {cx,cy-2};
	disp_write (myPoint_c6, D_ON);
	dcoord_t myPoint_c7 = {cx,cy-1};
	disp_write (myPoint_c7, D_ON);
	dcoord_t myPoint_c8 = {cx,cy};
	disp_write (myPoint_c8, D_ON);
	dcoord_t myPoint_c9 = {cx+1,cy};
	disp_write (myPoint_c9, D_ON);
	dcoord_t myPoint_c10 = {cx+2,cy};
	disp_write (myPoint_c10, D_ON);
	dcoord_t myPoint_c11 = {cx+3,cy};
	disp_write (myPoint_c11, D_ON);
	return;
}

void draw_d (int dx, int dy)
{
	dcoord_t myPoint_d1 = {dx,dy-4};
	disp_write (myPoint_d1, D_ON);
	dcoord_t myPoint_d2 = {dx+1,dy-4};
	disp_write (myPoint_d2, D_ON);
	dcoord_t myPoint_d3 = {dx+2,dy-4};
	disp_write (myPoint_d3, D_ON);
	dcoord_t myPoint_d4 = {dx,dy-3};
	disp_write (myPoint_d4, D_ON);
	dcoord_t myPoint_d5 = {dx+3,dy-3};
	disp_write (myPoint_d5, D_ON);
	dcoord_t myPoint_d6 = {dx,dy-2};
	disp_write (myPoint_d6, D_ON);
	dcoord_t myPoint_d7 = {dx+3,dy-2};
	disp_write (myPoint_d7, D_ON);
	dcoord_t myPoint_d8 = {dx,dy-1};
	disp_write (myPoint_d8, D_ON);
	dcoord_t myPoint_d9 = {dx+3,dy-1};
	disp_write (myPoint_d9, D_ON);
	dcoord_t myPoint_d10 = {dx,dy};
	disp_write (myPoint_d10, D_ON);
	dcoord_t myPoint_d11 = {dx+1,dy};
	disp_write (myPoint_d11, D_ON);
	dcoord_t myPoint_d12 = {dx+2,dy};
	disp_write (myPoint_d12, D_ON);


}

void draw_e (int ex, int ey)
{
	dcoord_t myPoint_e1 = {ex,ey-4};
	disp_write (myPoint_e1, D_ON);
	dcoord_t myPoint_e2 = {ex+1,ey-4};
	disp_write (myPoint_e2, D_ON);
	dcoord_t myPoint_e3 = {ex+2,ey-4};
	disp_write (myPoint_e3, D_ON);
	dcoord_t myPoint_e4 = {ex+3,ey-4};
	disp_write (myPoint_e4, D_ON);
	dcoord_t myPoint_e5 = {ex,ey-3};
	disp_write (myPoint_e5, D_ON);
	dcoord_t myPoint_e6 = {ex,ey-2};
	disp_write (myPoint_e6, D_ON);
	dcoord_t myPoint_e7 = {ex+1,ey-2};
	disp_write (myPoint_e7, D_ON);
	dcoord_t myPoint_e8 = {ex+2,ey-2};
	disp_write (myPoint_e8, D_ON);
	dcoord_t myPoint_e9 = {ex,ey-1};
	disp_write (myPoint_e9, D_ON);
	dcoord_t myPoint_e10 = {ex,ey};
	disp_write (myPoint_e10, D_ON);
	dcoord_t myPoint_e11 = {ex+1,ey};
	disp_write (myPoint_e11, D_ON);
	dcoord_t myPoint_e12 = {ex+2,ey};
	disp_write (myPoint_e12, D_ON);
	dcoord_t myPoint_e13 = {ex+3,ey};
	disp_write (myPoint_e13, D_ON);
}

void draw_f (int fx, int fy)
{
	dcoord_t myPoint_f1 = {fx,fy-4};
	disp_write (myPoint_f1, D_ON);
	dcoord_t myPoint_f2 = {fx+1,fy-4};
	disp_write (myPoint_f2, D_ON);
	dcoord_t myPoint_f3 = {fx+2,fy-4};
	disp_write (myPoint_f3, D_ON);
	dcoord_t myPoint_f4 = {fx+3,fy-4};
	disp_write (myPoint_f4, D_ON);
	dcoord_t myPoint_f5 = {fx,fy-3};
	disp_write (myPoint_f5, D_ON);
	dcoord_t myPoint_f6 = {fx,fy-2};
	disp_write (myPoint_f6, D_ON);
	dcoord_t myPoint_f7 = {fx+1,fy-2};
	disp_write (myPoint_f7, D_ON);
	dcoord_t myPoint_f8 = {fx+2,fy-2};
	disp_write (myPoint_f8, D_ON);
	dcoord_t myPoint_f9 = {fx,fy-1};
	disp_write (myPoint_f9, D_ON);
	dcoord_t myPoint_f10 = {fx,fy};
	disp_write (myPoint_f10, D_ON);	
}

void draw_g (int gx, int gy)
{
	dcoord_t myPoint_g1 = {gx,gy-4};
	disp_write (myPoint_g1, D_ON);
	dcoord_t myPoint_g2 = {gx+1,gy-4};
	disp_write (myPoint_g2, D_ON);
	dcoord_t myPoint_g3 = {gx+2,gy-4};
	disp_write (myPoint_g3, D_ON);
	dcoord_t myPoint_g4 = {gx+3,gy-4};
	disp_write (myPoint_g4, D_ON);
	dcoord_t myPoint_g5 = {gx,gy-3};
	disp_write (myPoint_g5, D_ON);
	dcoord_t myPoint_g6 = {gx,gy-2};
	disp_write (myPoint_g6, D_ON);
	dcoord_t myPoint_g7 = {gx+1,gy-2};
	disp_write (myPoint_g7, D_ON);
	dcoord_t myPoint_g8 = {gx+2,gy-2};
	disp_write (myPoint_g8, D_ON);
	dcoord_t myPoint_g9 = {gx+3,gy-2};
	disp_write (myPoint_g9, D_ON);
	dcoord_t myPoint_g10 = {gx,gy-1};
	disp_write (myPoint_g10, D_ON);
	dcoord_t myPoint_g11 = {gx+3,gy-1};
	disp_write (myPoint_g11, D_ON);
	dcoord_t myPoint_g12 = {gx,gy};
	disp_write (myPoint_g12, D_ON);
	dcoord_t myPoint_g13 = {gx+1,gy};
	disp_write (myPoint_g13, D_ON);
	dcoord_t myPoint_g14 = {gx+2,gy};
	disp_write (myPoint_g14, D_ON);
	dcoord_t myPoint_g15 = {gx+3,gy};
	disp_write (myPoint_g15, D_ON);
}

void draw_h (int hx, int hy)
{
	dcoord_t myPoint_h1 = {hx,hy-4};
	disp_write (myPoint_h1, D_ON);
	dcoord_t myPoint_h2 = {hx,hy-3};
	disp_write (myPoint_h2, D_ON);
	dcoord_t myPoint_h3 = {hx,hy-2};
	disp_write (myPoint_h3, D_ON);
	dcoord_t myPoint_h4 = {hx,hy-1};
	disp_write (myPoint_h4, D_ON);
	dcoord_t myPoint_h5 = {hx,hy};
	disp_write (myPoint_h5, D_ON);
	dcoord_t myPoint_h6 = {hx+3,hy-4};
	disp_write (myPoint_h6, D_ON);
	dcoord_t myPoint_h7 = {hx+3,hy-3};
	disp_write (myPoint_h7, D_ON);
	dcoord_t myPoint_h8 = {hx+3,hy-2};
	disp_write (myPoint_h8, D_ON);
	dcoord_t myPoint_h9 = {hx+3,hy-1};
	disp_write (myPoint_h9, D_ON);
	dcoord_t myPoint_h10 = {hx+3,hy};
	disp_write (myPoint_h10, D_ON);
	dcoord_t myPoint_h11 = {hx+1,hy-2};
	disp_write (myPoint_h11, D_ON);
	dcoord_t myPoint_h12 = {hx+2,hy-2};
	disp_write (myPoint_h12, D_ON);
}

void draw_i (int ix, int iy) //5x5
{
	dcoord_t myPoint_i1 = {ix,iy-4};
	disp_write (myPoint_i1, D_ON);
	dcoord_t myPoint_i2 = {ix+1,iy-4};
	disp_write (myPoint_i2, D_ON);
	dcoord_t myPoint_i3 = {ix+2,iy-4};
	disp_write (myPoint_i3, D_ON);
	dcoord_t myPoint_i4 = {ix+3,iy-4};
	disp_write (myPoint_i4, D_ON);
	dcoord_t myPoint_i44 = {ix+4,iy-4};
	disp_write (myPoint_i44, D_ON);
	
	dcoord_t myPoint_i5 = {ix+2,iy-3};
	disp_write (myPoint_i5, D_ON);
	dcoord_t myPoint_i6 = {ix+2,iy-2};
	disp_write (myPoint_i6, D_ON);
	dcoord_t myPoint_i7 = {ix+2,iy-1};
	disp_write (myPoint_i7, D_ON);
	
	dcoord_t myPoint_i8 = {ix,iy};
	disp_write (myPoint_i8, D_ON);
	dcoord_t myPoint_i9 = {ix+1,iy};
	disp_write (myPoint_i9, D_ON);
	dcoord_t myPoint_i10 = {ix+2,iy};
	disp_write (myPoint_i10, D_ON);
	dcoord_t myPoint_i11 = {ix+3,iy};
	disp_write (myPoint_i11, D_ON);
	dcoord_t myPoint_i12 = {ix+4,iy};
	disp_write (myPoint_i12, D_ON);
}

void draw_j (int jx, int jy)
{
    dcoord_t myPoint_j = {jx,jy-1};
    disp_write (myPoint_j, D_ON);
    dcoord_t myPoint_j1 = {jx,jy-4};
    disp_write (myPoint_j1, D_ON);
    
    dcoord_t myPoint_j2 = {jx+1,jy};
    disp_write (myPoint_j2, D_ON);
    dcoord_t myPoint_j3 = {jx+1,jy-4};
    disp_write (myPoint_j3, D_ON);
    
    dcoord_t myPoint_j4 = {jx+2,jy};
    disp_write (myPoint_j4, D_ON);
    dcoord_t myPoint_j5 = {jx+2,jy-1};
    disp_write (myPoint_j5, D_ON);
    dcoord_t myPoint_j6 = {jx+2,jy-2};
    disp_write (myPoint_j6, D_ON);
    dcoord_t myPoint_j7 = {jx+2,jy-3};
    disp_write (myPoint_j7, D_ON);
    dcoord_t myPoint_j8 = {jx+2,jy-4};
    disp_write (myPoint_j8, D_ON);
    
    dcoord_t myPoint_j9 = {jx+3,jy-4};
    disp_write (myPoint_j9, D_ON);
}

void draw_k (int kx, int ky)
{
    dcoord_t myPoint_k = {kx,ky};
    disp_write (myPoint_k, D_ON);
    dcoord_t myPoint_k1 = {kx,ky-1};
    disp_write (myPoint_k1, D_ON);
    dcoord_t myPoint_k2 = {kx,ky-2};
    disp_write (myPoint_k2, D_ON);
    dcoord_t myPoint_k3 = {kx,ky-3};
    disp_write (myPoint_k3, D_ON);
    dcoord_t myPoint_k4 = {kx,ky-4};
    disp_write (myPoint_k4, D_ON);
    
    dcoord_t myPoint_k5 = {kx+1,ky-2};
    disp_write (myPoint_k5, D_ON);
    
    dcoord_t myPoint_k6 = {kx+2,ky-1};
    disp_write (myPoint_k6, D_ON);
    dcoord_t myPoint_k7 = {kx+2,ky-3};
    disp_write (myPoint_k7, D_ON);
    
    dcoord_t myPoint_k8 = {kx+3,ky};
    disp_write (myPoint_k8, D_ON);
    dcoord_t myPoint_k9 = {kx+3,ky-4};
    disp_write (myPoint_k9, D_ON);
}

void draw_l (int lx, int ly)
{
	dcoord_t myPoint_l = {lx,ly};
    disp_write (myPoint_l, D_ON);
    dcoord_t myPoint_l1 = {lx,ly-1};
    disp_write (myPoint_l1, D_ON);
    dcoord_t myPoint_l2 = {lx,ly-2};
    disp_write (myPoint_l2, D_ON);
    dcoord_t myPoint_l3 = {lx,ly-3};
    disp_write (myPoint_l3, D_ON);
    dcoord_t myPoint_l4 = {lx,ly-4};
    disp_write (myPoint_l4, D_ON);
    
    dcoord_t myPoint_l5 = {lx+1,ly};
    disp_write (myPoint_l5, D_ON);
    dcoord_t myPoint_l6 = {lx+2,ly};
    disp_write (myPoint_l6, D_ON);
    dcoord_t myPoint_l7 = {lx+3,ly};
    disp_write (myPoint_l7, D_ON);
}

void draw_m (int mx, int my)
{
    dcoord_t myPoint_m = {mx,my};
    disp_write (myPoint_m, D_ON);
    dcoord_t myPoint_m1 = {mx,my-1};
    disp_write (myPoint_m1, D_ON);
    dcoord_t myPoint_m2 = {mx,my-2};
    disp_write (myPoint_m2, D_ON);
    dcoord_t myPoint_m3 = {mx,my-3};
    disp_write (myPoint_m3, D_ON);
    dcoord_t myPoint_m4 = {mx,my-4};
    disp_write (myPoint_m4, D_ON);
    
    dcoord_t myPoint_m5 = {mx+1,my-3};
    disp_write (myPoint_m5, D_ON);
    
    dcoord_t myPoint_m6 = {mx+2,my-2};
    disp_write (myPoint_m6, D_ON);
    
    dcoord_t myPoint_m7 = {mx+3,my-3};
    disp_write (myPoint_m7, D_ON);
    
    dcoord_t myPoint_m8 = {mx+4,my};
    disp_write (myPoint_m8, D_ON);
    dcoord_t myPoint_m9 = {mx+4,my-1};
    disp_write (myPoint_m9, D_ON);
    dcoord_t myPoint_m10 = {mx+4,my-2};
    disp_write (myPoint_m10, D_ON);
    dcoord_t myPoint_m11 = {mx+4,my-3};
    disp_write (myPoint_m11, D_ON);
    dcoord_t myPoint_m12 = {mx+4,my-4};
    disp_write (myPoint_m12, D_ON);
}

//LETRA N 5x4
void draw_n (int nx, int ny)
{
	dcoord_t myPoint_n = {nx,ny};
	disp_write (myPoint_n, D_ON);
	dcoord_t myPoint_n1 = {nx,ny-1};
	disp_write (myPoint_n1, D_ON);
	dcoord_t myPoint_n2 = {nx,ny-2};
	disp_write (myPoint_n2, D_ON);
	dcoord_t myPoint_n3 = {nx,ny-3};
	disp_write (myPoint_n3, D_ON);
	dcoord_t myPoint_n4 = {nx,ny-4};
	disp_write (myPoint_n4, D_ON);
	
	dcoord_t myPoint_n5 = {nx+1,ny-3};
	disp_write (myPoint_n5, D_ON);
	
	dcoord_t myPoint_n6 = {nx+2,ny-2};
	disp_write (myPoint_n6, D_ON);
	
	dcoord_t myPoint_n7 = {nx+3,ny};
	disp_write (myPoint_n7, D_ON);
	dcoord_t myPoint_n8 = {nx+3,ny-1};
	disp_write (myPoint_n8, D_ON);
	dcoord_t myPoint_n9 = {nx+3,ny-2};
	disp_write (myPoint_n9, D_ON);
	dcoord_t myPoint_n10 = {nx+3,ny-3};
	disp_write (myPoint_n10, D_ON);
	dcoord_t myPoint_n11 = {nx+3,ny-4};
	disp_write (myPoint_n11, D_ON);
	
}

//LETRA O 5x4
void draw_o (int ox, int oy)
{
	dcoord_t myPoint_o = {ox,oy-1};
	disp_write (myPoint_o, D_ON);
	dcoord_t myPoint_o1 = {ox,oy-2};
	disp_write (myPoint_o1, D_ON);
	dcoord_t myPoint_o2 = {ox,oy-3};
	disp_write (myPoint_o2, D_ON);
	
	dcoord_t myPoint_o3 = {ox+1,oy};
	disp_write (myPoint_o3, D_ON);
	dcoord_t myPoint_o4 = {ox+1,oy-4};
	disp_write (myPoint_o4, D_ON);
	
	dcoord_t myPoint_o5 = {ox+2,oy};
	disp_write (myPoint_o5, D_ON);
	dcoord_t myPoint_o6 = {ox+2,oy-4};
	disp_write (myPoint_o6, D_ON);
	
	dcoord_t myPoint_o7 = {ox+3,oy-1};
	disp_write (myPoint_o7, D_ON);
	dcoord_t myPoint_o8 = {ox+3,oy-2};
	disp_write (myPoint_o8, D_ON);
	dcoord_t myPoint_o9 = {ox+3,oy-3};
	disp_write (myPoint_o9, D_ON);
}

//LETRA P 5x4
void draw_p (int px, int py)
{
	dcoord_t myPoint_p = {px,py};
	disp_write (myPoint_p, D_ON);
	dcoord_t myPoint_p1 = {px,py-1};
	disp_write (myPoint_p1, D_ON);
	dcoord_t myPoint_p2 = {px,py-2};
	disp_write (myPoint_p2, D_ON);
	dcoord_t myPoint_p3 = {px,py-3};
	disp_write (myPoint_p3, D_ON);
	dcoord_t myPoint_p4 = {px,py-4};
	disp_write (myPoint_p4, D_ON);
	
	dcoord_t myPoint_p5 = {px+1,py-2};
	disp_write (myPoint_p5, D_ON);
	dcoord_t myPoint_p6 = {px+1,py-4};
	disp_write (myPoint_p6, D_ON);
	
	dcoord_t myPoint_p7 = {px+2,py-2};
	disp_write (myPoint_p7, D_ON);
	dcoord_t myPoint_p8 = {px+2,py-4};
	disp_write (myPoint_p8, D_ON);
	
	dcoord_t myPoint_p9 = {px+3,py-2};
	disp_write (myPoint_p9, D_ON);
	dcoord_t myPoint_p10 = {px+3,py-3};
	disp_write (myPoint_p10, D_ON);
	dcoord_t myPoint_p11 = {px+3,py-4};
	disp_write (myPoint_p11, D_ON);
}

//LETRA Q 5x4
void draw_q (int qx, int qy)
{
	dcoord_t myPoint_q = {qx,qy-1};
	disp_write (myPoint_q, D_ON);
	dcoord_t myPoint_q1 = {qx,qy-2};
	disp_write (myPoint_q1, D_ON);
	dcoord_t myPoint_q2 = {qx,qy-3};
	disp_write (myPoint_q2, D_ON);	
	dcoord_t myPoint_q3 = {qx,qy-4};
	disp_write (myPoint_q3, D_ON);		
	
	
	dcoord_t myPoint_q4 = {qx+1,qy};
	disp_write (myPoint_q4, D_ON);	
	dcoord_t myPoint_q5 = {qx+1,qy-4};
	disp_write (myPoint_q5, D_ON);	
	
	dcoord_t myPoint_q6 = {qx+2,qy-1};
	disp_write (myPoint_q6, D_ON);
	dcoord_t myPoint_q7 = {qx+2,qy-2};
	disp_write (myPoint_q7, D_ON);
	dcoord_t myPoint_q8 = {qx+2,qy-3};
	disp_write (myPoint_q8, D_ON);	
	dcoord_t myPoint_q9 = {qx+2,qy-4};
	disp_write (myPoint_q9, D_ON);
	
	dcoord_t myPoint_q10 = {qx+3,qy};
	disp_write (myPoint_q10, D_ON);
	
}

//LETRA R 5x4
void draw_r (int rx, int ry)
{
	dcoord_t myPoint_r = {rx,ry};
	disp_write (myPoint_r, D_ON);
	dcoord_t myPoint_r1 = {rx,ry-1};
	disp_write (myPoint_r1, D_ON);
	dcoord_t myPoint_r2 = {rx,ry-2};
	disp_write (myPoint_r2, D_ON);
	dcoord_t myPoint_r3 = {rx,ry-3};
	disp_write (myPoint_r3, D_ON);
	dcoord_t myPoint_r4 = {rx,ry-4};
	disp_write (myPoint_r4, D_ON);
	
	dcoord_t myPoint_r5 = {rx+1,ry-2};
	disp_write (myPoint_r5, D_ON);
	dcoord_t myPoint_r6 = {rx+1,ry-4};
	disp_write (myPoint_r6, D_ON);
	
	dcoord_t myPoint_r7 = {rx+2,ry-1};
	disp_write (myPoint_r7, D_ON);
	dcoord_t myPoint_r8 = {rx+2,ry-2};
	disp_write (myPoint_r8, D_ON);
	dcoord_t myPoint_r9 = {rx+2,ry-4};
	disp_write (myPoint_r9, D_ON);
	
	dcoord_t myPoint_r10 = {rx+3,ry};
	disp_write (myPoint_r10, D_ON);
	dcoord_t myPoint_r11 = {rx+3,ry-2};
	disp_write (myPoint_r11, D_ON);
	dcoord_t myPoint_r12 = {rx+3,ry-3};
	disp_write (myPoint_r12, D_ON);
	dcoord_t myPoint_r13 = {rx+3,ry-4};
	disp_write (myPoint_r13, D_ON);
}
	
//LETRA S 5x4
void draw_s (int sx, int sy)
{
	dcoord_t myPoint_s = {sx,sy};
	disp_write (myPoint_s, D_ON);
	dcoord_t myPoint_s1 = {sx,sy-2};
	disp_write (myPoint_s1, D_ON);
	dcoord_t myPoint_s2 = {sx,sy-3};
	disp_write (myPoint_s2, D_ON);
	dcoord_t myPoint_s3 = {sx,sy-4};
	disp_write (myPoint_s3, D_ON);
	
	dcoord_t myPoint_s4 = {sx+1,sy};
	disp_write (myPoint_s4, D_ON);
	dcoord_t myPoint_s5 = {sx+1,sy-2};
	disp_write (myPoint_s5, D_ON);
	dcoord_t myPoint_s6 = {sx+1,sy-4};
	disp_write (myPoint_s6, D_ON);

	dcoord_t myPoint_s7 = {sx+2,sy};
	disp_write (myPoint_s7, D_ON);
	dcoord_t myPoint_s8 = {sx+2,sy-2};
	disp_write (myPoint_s8, D_ON);	
	dcoord_t myPoint_s88 = {sx+2,sy-4};
	disp_write (myPoint_s88, D_ON);
	
	dcoord_t myPoint_s9 = {sx+3,sy};
	disp_write (myPoint_s9, D_ON);
	dcoord_t myPoint_s10 = {sx+3,sy-1};
	disp_write (myPoint_s10, D_ON);	
	dcoord_t myPoint_s11 = {sx+3,sy-2};
	disp_write (myPoint_s11, D_ON);	
	dcoord_t myPoint_s12 = {sx+3,sy-4};
	disp_write (myPoint_s12, D_ON);			

}

//LETRA T 5x5
void draw_t (int tx, int ty)
{
	dcoord_t myPoint_t = {tx,ty-4};
	disp_write (myPoint_t, D_ON);
	
	dcoord_t myPoint_t1 = {tx+1,ty-4};
	disp_write (myPoint_t1, D_ON);
	
	dcoord_t myPoint_t2 = {tx+2,ty};
	disp_write (myPoint_t2, D_ON);
	dcoord_t myPoint_t3 = {tx+2,ty-1};
	disp_write (myPoint_t3, D_ON);
	dcoord_t myPoint_t4 = {tx+2,ty-2};
	disp_write (myPoint_t4, D_ON);
	dcoord_t myPoint_t5 = {tx+2,ty-3};
	disp_write (myPoint_t5, D_ON);
	dcoord_t myPoint_t6 = {tx+2,ty-4};
	disp_write (myPoint_t6, D_ON);
	
	dcoord_t myPoint_t7 = {tx+3,ty-4};
	disp_write (myPoint_t7, D_ON);
	
	dcoord_t myPoint_t8 = {tx+4,ty-4};
	disp_write (myPoint_t8, D_ON);
}

//LETRA U 5x4
void draw_u (int ux, int uy)
{
	dcoord_t myPoint_u = {ux,uy};
	disp_write (myPoint_u, D_ON);
	dcoord_t myPoint_u1 = {ux,uy-1};
	disp_write (myPoint_u1, D_ON);
	dcoord_t myPoint_u2 = {ux,uy-2};
	disp_write (myPoint_u2, D_ON);
	dcoord_t myPoint_u3 = {ux,uy-3};
	disp_write (myPoint_u3, D_ON);
	dcoord_t myPoint_u4 = {ux,uy-4};
	disp_write (myPoint_u4, D_ON);
	
	dcoord_t myPoint_u5 = {ux+1,uy};
	disp_write (myPoint_u5, D_ON);
	
	dcoord_t myPoint_u6 = {ux+2,uy};
	disp_write (myPoint_u6, D_ON);
	
	dcoord_t myPoint_u7 = {ux+3,uy};
	disp_write (myPoint_u7, D_ON);
	dcoord_t myPoint_u8 = {ux+3,uy-1};
	disp_write (myPoint_u8, D_ON);
	dcoord_t myPoint_u9 = {ux+3,uy-2};
	disp_write (myPoint_u9, D_ON);
	dcoord_t myPoint_u10 = {ux+3,uy-3};
	disp_write (myPoint_u10, D_ON);
	dcoord_t myPoint_u11 = {ux+3,uy-4};
	disp_write (myPoint_u11, D_ON);
	
}

//LETRA V 5x5
void draw_v (int vx, int vy)
{
	dcoord_t myPoint_v = {vx,vy-2};
	disp_write (myPoint_v, D_ON);
	dcoord_t myPoint_v1 = {vx,vy-3};
	disp_write (myPoint_v1, D_ON);
	dcoord_t myPoint_v2 = {vx,vy-4};
	disp_write (myPoint_v2, D_ON);
	
	dcoord_t myPoint_v3 = {vx+1,vy-1};
	disp_write (myPoint_v3, D_ON);
	
	dcoord_t myPoint_v4 = {vx+2,vy};
	disp_write (myPoint_v4, D_ON);
	
	dcoord_t myPoint_v5 = {vx+3,vy-1};
	disp_write (myPoint_v5, D_ON);
	
	dcoord_t myPoint_v6 = {vx+4,vy-2};
	disp_write (myPoint_v6, D_ON);
	dcoord_t myPoint_v7 = {vx+4,vy-3};
	disp_write (myPoint_v7, D_ON);
	dcoord_t myPoint_v8 = {vx+4,vy-4};
	disp_write (myPoint_v8, D_ON);
}

//LETRA W 5x5
void draw_w (int wx, int wy)
{
	dcoord_t myPoint_w = {wx,wy};
	disp_write (myPoint_w, D_ON);
	dcoord_t myPoint_w1 = {wx,wy-1};
	disp_write (myPoint_w1, D_ON);
	dcoord_t myPoint_w2 = {wx,wy-2};
	disp_write (myPoint_w2, D_ON);
	dcoord_t myPoint_w3 = {wx,wy-3};
	disp_write (myPoint_w3, D_ON);
	dcoord_t myPoint_w4 = {wx,wy-4};
	disp_write (myPoint_w4, D_ON);
	
	dcoord_t myPoint_w5 = {wx+1,wy};
	disp_write (myPoint_w5, D_ON);
	
	dcoord_t myPoint_w6 = {wx+2,wy-1};
	disp_write (myPoint_w6, D_ON);
	
	dcoord_t myPoint_w7 = {wx+3,wy};
	disp_write (myPoint_w7, D_ON);
	
	dcoord_t myPoint_w8 = {wx+4,wy};
	disp_write (myPoint_w8, D_ON);
	dcoord_t myPoint_w9 = {wx+4,wy-1};
	disp_write (myPoint_w9, D_ON);
	dcoord_t myPoint_w10 = {wx+4,wy-2};
	disp_write (myPoint_w10, D_ON);
	dcoord_t myPoint_w11 = {wx+4,wy-3};
	disp_write (myPoint_w11, D_ON);
	dcoord_t myPoint_w12 = {wx+4,wy-4};
	disp_write (myPoint_w12, D_ON);
}

//LETRA X 5x4
void draw_x (int xx, int xy)
{
	dcoord_t myPoint_x = {xx,xy};
	disp_write (myPoint_x, D_ON);
	dcoord_t myPoint_x1 = {xx,xy-4};
	disp_write (myPoint_x1, D_ON);
	
	dcoord_t myPoint_x2 = {xx+1,xy-3};
	disp_write (myPoint_x2, D_ON);
	dcoord_t myPoint_x3 = {xx+1,xy-1};
	disp_write (myPoint_x3, D_ON);
	
	dcoord_t myPoint_x4 = {xx+2,xy-2};
	disp_write (myPoint_x4, D_ON);
	
	dcoord_t myPoint_x5 = {xx+3,xy-1};
	disp_write (myPoint_x5, D_ON);
	dcoord_t myPoint_x6 = {xx+3,xy-3};
	disp_write (myPoint_x6, D_ON);
	
	dcoord_t myPoint_x7 = {xx+4,xy};
	disp_write (myPoint_x7, D_ON);
	dcoord_t myPoint_x8 = {xx+4,xy-4};
	disp_write (myPoint_x8, D_ON);
}

//LETRA Y 5x5
void draw_y (int yx, int yy)
{
	dcoord_t myPoint_y = {yx,yy-4};
	disp_write (myPoint_y, D_ON);
	
	dcoord_t myPoint_y1 = {yx+1,yy-3};
	disp_write (myPoint_y1, D_ON);
	
	dcoord_t myPoint_y3 = {yx+2,yy};
	disp_write (myPoint_y3, D_ON);
	dcoord_t myPoint_y4 = {yx+2,yy-1};
	disp_write (myPoint_y4, D_ON);
	dcoord_t myPoint_y5 = {yx+2,yy-2};
	disp_write (myPoint_y5, D_ON);
	
	dcoord_t myPoint_y6 = {yx+3,yy-3};
	disp_write (myPoint_y6, D_ON);
	
	dcoord_t myPoint_y7 = {yx+4,yy-4};
	disp_write (myPoint_y7, D_ON);
}

//LETRA Z 5x4
void draw_z (int zx, int zy)
{
	dcoord_t myPoint_z = {zx,zy};
	disp_write (myPoint_z, D_ON);
	dcoord_t myPoint_z1 = {zx,zy-1};
	disp_write (myPoint_z1, D_ON);
	dcoord_t myPoint_z2 = {zx,zy-4};
	disp_write (myPoint_z2, D_ON);
	
	dcoord_t myPoint_z3 = {zx+1,zy};
	disp_write (myPoint_z3, D_ON);
	dcoord_t myPoint_z4 = {zx+1,zy-2};
	disp_write (myPoint_z4, D_ON);
	dcoord_t myPoint_z5 = {zx+1,zy-4};
	disp_write (myPoint_z5, D_ON);
	
	dcoord_t myPoint_z6 = {zx+2,zy};
	disp_write (myPoint_z6, D_ON);
	dcoord_t myPoint_z7 = {zx+2,zy-3};
	disp_write (myPoint_z7, D_ON);
	dcoord_t myPoint_z8 = {zx+2,zy-4};
	disp_write (myPoint_z8, D_ON);
	
	dcoord_t myPoint_z9 = {zx+3,zy};
	disp_write (myPoint_z9, D_ON);
	dcoord_t myPoint_z10 = {zx+3,zy-3};
	disp_write (myPoint_z10, D_ON);
	dcoord_t myPoint_z11 = {zx+3,zy-4};
	disp_write (myPoint_z11, D_ON);
}	
	
//NÚMERO 1
void draw_1 (int x_1, int y_1)
{
    dcoord_t myPoint1_1 = {x_1,y_1};
    disp_write (myPoint1_1, D_ON);
    dcoord_t myPoint1_2 = {x_1,y_1+2};
    disp_write (myPoint1_2, D_ON);
    
    dcoord_t myPoint1_3 = {x_1+1,y_1};
    disp_write (myPoint1_3, D_ON);
    dcoord_t myPoint1_4 = {x_1+1,y_1+3};
    disp_write (myPoint1_4, D_ON);
    
    dcoord_t myPoint1_5 = {x_1+2,y_1};
    disp_write (myPoint1_5, D_ON);
    dcoord_t myPoint1_6 = {x_1+2,y_1+1};
    disp_write (myPoint1_6, D_ON);
    dcoord_t myPoint1_7 = {x_1+2,y_1+2};
    disp_write (myPoint1_7, D_ON);
    dcoord_t myPoint1_8 = {x_1+2,y_1+3};
    disp_write (myPoint1_8, D_ON);
    dcoord_t myPoint1_9 = {x_1+2,y_1+4};
    disp_write (myPoint1_9, D_ON);
    
    dcoord_t myPoint1_10 = {x_1+3,y_1};
    disp_write (myPoint1_10, D_ON);
}

//NÚMERO 2 
void draw_2 (int x_2, int y_2)
{
    dcoord_t myPoint2_1 = {x_2,y_2};
    disp_write (myPoint2_1, D_ON);
    dcoord_t myPoint2_2 = {x_2,y_2-4};
    disp_write (myPoint2_2, D_ON);
    
    dcoord_t myPoint2_3 = {x_2+1,y_2};
    disp_write (myPoint2_3, D_ON);
    dcoord_t myPoint2_4 = {x_2+1,y_2-1};
    disp_write (myPoint2_4, D_ON);
    dcoord_t myPoint2_5 = {x_2+1,y_2-4};
    disp_write (myPoint2_5, D_ON);
    
    dcoord_t myPoint2_6 = {x_2+2,y_2};
    disp_write (myPoint2_6, D_ON);
    dcoord_t myPoint2_7 = {x_2+2,y_2-2};
    disp_write (myPoint2_7, D_ON);
    dcoord_t myPoint2_8 = {x_2+2,y_2-4};
    disp_write (myPoint2_8, D_ON);
    
    dcoord_t myPoint2_9 = {x_2+3,y_2};
    disp_write (myPoint2_9, D_ON);
    dcoord_t myPoint2_10 = {x_2+3,y_2-3};
    disp_write (myPoint2_10, D_ON);
    dcoord_t myPoint2_11 = {x_2+3,y_2-4};
    disp_write (myPoint2_11, D_ON);
}

//NÚMERO 3
void draw_3 (int x_3, int y_3)
{
    dcoord_t myPoint3_1 = {x_3,y_3};
    disp_write (myPoint3_1, D_ON);
    dcoord_t myPoint3_2 = {x_3,y_3-4};
    disp_write (myPoint3_2, D_ON);
    
    dcoord_t myPoint3_3 = {x_3+1,y_3};
    disp_write (myPoint3_3, D_ON);
    dcoord_t myPoint3_4 = {x_3+1,y_3-2};
    disp_write (myPoint3_4, D_ON);
    dcoord_t myPoint3_5 = {x_3+1,y_3-4};
    disp_write (myPoint3_5, D_ON);

    dcoord_t myPoint3_6 = {x_3+2,y_3};
    disp_write (myPoint3_6, D_ON);
    dcoord_t myPoint3_7 = {x_3+2,y_3-1};
    disp_write (myPoint3_7, D_ON);
    dcoord_t myPoint3_8 = {x_3+2,y_3-3};
    disp_write (myPoint3_8, D_ON);
    dcoord_t myPoint3_9 = {x_3+2,y_3-4};
    disp_write (myPoint3_9, D_ON);

    dcoord_t myPoint3_10 = {x_3+3,y_3-4};
    disp_write (myPoint3_10, D_ON);
}

//NÚMERO 4
void draw_4 (int x_4, int y_4)
{
    dcoord_t myPoint4_1 = {x_4,y_4-2};
    disp_write (myPoint4_1, D_ON);
    dcoord_t myPoint4_2 = {x_4,y_4-3};
    disp_write (myPoint4_2, D_ON);
    dcoord_t myPoint4_3 = {x_4,y_4-4};
    disp_write (myPoint4_3, D_ON);
    
    dcoord_t myPoint4_4 = {x_4+1,y_4-2};
    disp_write (myPoint4_4, D_ON);
    
    dcoord_t myPoint4_5 = {x_4+2,y_4-2};
    disp_write (myPoint4_5, D_ON);
    
    dcoord_t myPoint4_6 = {x_4+3,y_4};
    disp_write (myPoint4_6, D_ON);
    dcoord_t myPoint4_7 = {x_4+3,y_4-1};
    disp_write (myPoint4_7, D_ON);
    dcoord_t myPoint4_8 = {x_4+3,y_4-2};
    disp_write (myPoint4_8, D_ON);
    dcoord_t myPoint4_9 = {x_4+3,y_4-3};
    disp_write (myPoint4_9, D_ON);
    dcoord_t myPoint4_10 = {x_4+3,y_4-4};
    disp_write (myPoint4_10, D_ON);
}

//NÚMERO 5
void draw_5 (int x_5, int y_5)
{
    dcoord_t myPoint5_1 = {x_5,y_5};
    disp_write (myPoint5_1, D_ON);
    dcoord_t myPoint5_2 = {x_5,y_5-2};
    disp_write (myPoint5_2, D_ON);
    dcoord_t myPoint5_3 = {x_5,y_5-3};
    disp_write (myPoint5_3, D_ON);
    dcoord_t myPoint5_4 = {x_5,y_5-4};
    disp_write (myPoint5_4, D_ON);
    
    dcoord_t myPoint5_5 = {x_5+1,y_5};
    disp_write (myPoint5_5, D_ON);
    dcoord_t myPoint5_6 = {x_5+1,y_5-2};
    disp_write (myPoint5_6, D_ON);
    dcoord_t myPoint5_7 = {x_5+1,y_5-4};
    disp_write (myPoint5_7, D_ON);
    
    dcoord_t myPoint5_8 = {x_5+2,y_5};
    disp_write (myPoint5_8, D_ON);
    dcoord_t myPoint5_9 = {x_5+2,y_5-2};
    disp_write (myPoint5_9, D_ON);
    dcoord_t myPoint5_10 = {x_5+2,y_5-4};
    disp_write (myPoint5_10, D_ON);
    
    dcoord_t myPoint5_11 = {x_5+3,y_5};
    disp_write (myPoint5_11, D_ON);
    dcoord_t myPoint5_12 = {x_5+3,y_5-1};
    disp_write (myPoint5_12, D_ON);
    dcoord_t myPoint5_13 = {x_5+3,y_5-2};
    disp_write (myPoint5_13, D_ON);
    dcoord_t myPoint5_14 = {x_5+3,y_5-4};
    disp_write (myPoint5_14, D_ON);
}
//NÚMERO 6
void draw_6 (int x_6, int y_6)
{
    dcoord_t myPoint6_1 = {x_6,y_6};
    disp_write (myPoint6_1, D_ON);
    dcoord_t myPoint6_2 = {x_6,y_6-1};
    disp_write (myPoint6_2, D_ON);
    dcoord_t myPoint6_3 = {x_6,y_6-2};
    disp_write (myPoint6_3, D_ON);
    dcoord_t myPoint6_4 = {x_6,y_6-3};
    disp_write (myPoint6_4, D_ON);
    dcoord_t myPoint6_5 = {x_6,y_6-4};
    disp_write (myPoint6_5, D_ON);
    
    dcoord_t myPoint6_6 = {x_6+1,y_6};
    disp_write (myPoint6_6, D_ON);
    dcoord_t myPoint6_7 = {x_6+1,y_6-2};
    disp_write (myPoint6_7, D_ON);
    dcoord_t myPoint6_8 = {x_6+1,y_6-4};
    disp_write (myPoint6_8, D_ON);
    
    dcoord_t myPoint6_9 = {x_6+2,y_6};
    disp_write (myPoint6_9, D_ON);
    dcoord_t myPoint6_10 = {x_6+2,y_6-2};
    disp_write (myPoint6_10, D_ON);
    dcoord_t myPoint6_11 = {x_6+2,y_6-4};
    disp_write (myPoint6_11, D_ON);
    
    dcoord_t myPoint6_12 = {x_6+2,y_6};
    disp_write (myPoint6_12, D_ON);
    
}

//NÚMERO 7
void draw_7 (int x_7, int y_7)
{
    dcoord_t myPoint7_1 = {x_7,y_7-4};
    disp_write (myPoint7_1, D_ON);
    
    dcoord_t myPoint7_2 = {x_7+1,y_7-4};
    disp_write (myPoint7_2, D_ON);
    
    dcoord_t myPoint7_3 = {x_7+2,y_7-4};
    disp_write (myPoint7_3, D_ON);
    
    dcoord_t myPoint7_4 = {x_7+3,y_7};
    disp_write (myPoint7_4, D_ON);
    dcoord_t myPoint7_5 = {x_7+3,y_7-1};
    disp_write (myPoint7_5, D_ON);
    dcoord_t myPoint7_6 = {x_7+3,y_7-2};
    disp_write (myPoint7_6, D_ON);
    dcoord_t myPoint7_7 = {x_7+3,y_7-3};
    disp_write (myPoint7_7, D_ON);
    dcoord_t myPoint7_8 = {x_7+3,y_7-4};
    disp_write (myPoint7_8, D_ON);
}

//NÚMERO 8
void draw_8 (int x_8, int y_8)
{
    dcoord_t myPoint8_1 = {x_8,y_8};
    disp_write (myPoint8_1, D_ON);
    dcoord_t myPoint8_2 = {x_8,y_8-1};
    disp_write (myPoint8_2, D_ON);
    dcoord_t myPoint8_3 = {x_8,y_8-2};
    disp_write (myPoint8_3, D_ON);
    dcoord_t myPoint8_4 = {x_8,y_8-3};
    disp_write (myPoint8_4, D_ON);
    dcoord_t myPoint8_5 = {x_8,y_8-4};
    disp_write (myPoint8_5, D_ON);
    
    dcoord_t myPoint8_6 = {x_8+1,y_8};
    disp_write (myPoint8_6, D_ON);
    dcoord_t myPoint8_7 = {x_8+1,y_8-2};
    disp_write (myPoint8_7, D_ON);
    dcoord_t myPoint8_8 = {x_8+1,y_8-4};
    disp_write (myPoint8_8, D_ON);
   
    dcoord_t myPoint8_9 = {x_8+2,y_8};
    disp_write (myPoint8_9, D_ON);
    dcoord_t myPoint8_10 = {x_8+2,y_8-2};
    disp_write (myPoint8_10, D_ON);
    dcoord_t myPoint8_11 = {x_8+2,y_8-4};
    disp_write (myPoint8_11, D_ON);
    
    dcoord_t myPoint8_12 = {x_8+3,y_8};
    disp_write (myPoint8_12, D_ON);
    dcoord_t myPoint8_13 = {x_8+3,y_8-1};
    disp_write (myPoint8_13, D_ON);
    dcoord_t myPoint8_14 = {x_8+3,y_8-2};
    disp_write (myPoint8_14, D_ON);
    dcoord_t myPoint8_15 = {x_8+3,y_8-3};
    disp_write (myPoint8_15, D_ON);
    dcoord_t myPoint8_16 = {x_8+3,y_8-4};
    disp_write (myPoint8_16, D_ON);
}

//NÚMERO 9
void draw_9 (int x_9, int y_9)
{
    dcoord_t myPoint9_1 = {x_9,y_9};
    disp_write (myPoint9_1, D_ON);
    dcoord_t myPoint9_2 = {x_9,y_9-2};
    disp_write (myPoint9_2, D_ON);
    dcoord_t myPoint9_3 = {x_9,y_9-3};
    disp_write (myPoint9_3, D_ON);
    dcoord_t myPoint9_4 = {x_9,y_9-4};
    disp_write (myPoint9_4, D_ON);
    
    dcoord_t myPoint9_5 = {x_9+1,y_9};
    disp_write (myPoint9_5, D_ON);
    dcoord_t myPoint9_6 = {x_9+1,y_9-2};
    disp_write (myPoint9_6, D_ON);
    dcoord_t myPoint9_7 = {x_9+1,y_9-4};
    disp_write (myPoint9_7, D_ON);
    
    dcoord_t myPoint9_8 = {x_9+2,y_9};
    disp_write (myPoint9_8, D_ON);
    dcoord_t myPoint9_9 = {x_9+2,y_9-2};
    disp_write (myPoint9_9, D_ON);
    dcoord_t myPoint9_10 = {x_9+2,y_9-4};
    disp_write (myPoint9_10, D_ON);
    
    dcoord_t myPoint9_11 = {x_9+3,y_9};
    disp_write (myPoint9_11, D_ON);
    dcoord_t myPoint9_12 = {x_9+3,y_9-1};
    disp_write (myPoint9_12, D_ON);
    dcoord_t myPoint9_13 = {x_9+3,y_9-2};
    disp_write (myPoint9_13, D_ON);
    dcoord_t myPoint9_14 = {x_9+3,y_9-3};
    disp_write (myPoint9_14, D_ON);
    dcoord_t myPoint9_15 = {x_9+3,y_9-4};
    disp_write (myPoint9_15, D_ON);
}

//NÚMERO 0
void draw_0 (int x_0, int y_0)
{
    dcoord_t myPoint0_1 = {x_0,y_0};
    disp_write (myPoint0_1, D_ON);
    dcoord_t myPoint0_2 = {x_0,y_0-1};
    disp_write (myPoint0_2, D_ON);
    dcoord_t myPoint0_98 = {x_0,y_0-2};
    disp_write (myPoint0_98, D_ON);
    dcoord_t myPoint0_3 = {x_0,y_0-3};
    disp_write (myPoint0_3, D_ON);
    dcoord_t myPoint0_4 = {x_0,y_0-4};
    disp_write (myPoint0_4, D_ON);
    
    dcoord_t myPoint0_5 = {x_0+1,y_0};
    disp_write (myPoint0_5, D_ON);
    dcoord_t myPoint0_6 = {x_0+1,y_0-4};
    disp_write (myPoint0_6, D_ON);
    
    dcoord_t myPoint0_7 = {x_0+2,y_0};
    disp_write (myPoint0_7, D_ON);
    dcoord_t myPoint0_8 = {x_0+2,y_0-4};
    disp_write (myPoint0_8, D_ON);
    
    dcoord_t myPoint0_9 = {x_0+3,y_0};
    disp_write (myPoint0_9, D_ON);
    dcoord_t myPoint0_10 = {x_0+3,y_0-1};
    disp_write (myPoint0_10, D_ON);
    dcoord_t myPoint0_11 = {x_0+3,y_0-2};
    disp_write (myPoint0_11, D_ON);
    dcoord_t myPoint0_12 = {x_0+3,y_0-3};
    disp_write (myPoint0_12, D_ON);
    dcoord_t myPoint0_13 = {x_0+3,y_0-4};
    disp_write (myPoint0_13, D_ON);
}

//TECLADO

// Esta funcion se encarga de cargar la matriz del teclado de la raspi con sus respectivas letras. 				
void init_keyboard(char letter_keyboard[NUMBER_OF_SCREENS][NAMELENGHT])
{
	letter_keyboard[0][0] = 'A';
	letter_keyboard[0][1] = 'B';
	letter_keyboard[0][2] = 'C';
	letter_keyboard[1][0] = 'D';
	letter_keyboard[1][1] = 'E';
	letter_keyboard[1][2] = 'F';
	letter_keyboard[2][0] = 'G';
	letter_keyboard[2][1] = 'H';
	letter_keyboard[2][2] = 'I';
	letter_keyboard[3][0] = 'J';
	letter_keyboard[3][1] = 'K';
	letter_keyboard[3][2] = 'L';
	letter_keyboard[4][0] = 'M';
	letter_keyboard[4][1] = 'N';
	letter_keyboard[4][2] = 'O';
	letter_keyboard[5][0] = 'P';
	letter_keyboard[5][1] = 'Q';
	letter_keyboard[5][2] = 'R';
	letter_keyboard[6][0] = 'S';
	letter_keyboard[6][1] = 'T';
	letter_keyboard[6][2] = 'U';
	letter_keyboard[7][0] = 'V';
	letter_keyboard[7][1] = 'W';
	letter_keyboard[7][2] = '\0'; //esta pantalla solo tiene dos letras
	letter_keyboard[8][0] = 'X';
	letter_keyboard[8][1] = 'Y';
	letter_keyboard[8][2] = 'Z';
}

/*******************************************************************************
*	Esta funcion se encarga de mostrarle al usuario todas las letras		   *
*	hasta que se selecciona una. Imprime las letras, responde al joystick	   *
*	y finalmente devuelve la letra seleccionada.							   *
*******************************************************************************/

char get_letter(char letter_keyboard[NUMBER_OF_SCREENS][NAMELENGHT])
{
	int screen_number = 1;                //arranca mostrando la primer pantalla
	screen_1_raspi();
	jswitch_t mySwitch = 0;
	jcoord_t myCoords;

	while (mySwitch != J_PRESS)            //mientras que no se aprete el joystick
	{
		joy_update();
		mySwitch = joy_get_switch();
		myCoords = joy_get_coord();        //agarra las coordenadas
		if (myCoords.x > 10)                //si se mueve el joystick a la derecha, cambia a la pantalla correspondiente
		{
			if (screen_number == 9)        //si esta mostrando la ultima vuelve a la primera
			{
				screen_number = 1;
			}
			else
			{
				screen_number += 1;        //pasa a la proxima pantalla
			}
			changeScreen(screen_number); //imprime la pantalla 
		}
		else if (myCoords.x < -10)    //lo mismo pero si va para la izquierda
		{
			if (screen_number == 1)    //de la primer pantalla pasa a la ultima
			{
				screen_number = 9;
			}
			else
			{
				screen_number -= 1;    //pasa a la pantalla anterior
			}
			changeScreen(screen_number); //imprime la pantalla
		}
		disp_update();
	}
	//aca seria una vez que toca el boton del joystick
	while (mySwitch == J_PRESS)
	{
		joy_update();
		mySwitch = joy_get_switch();
		myCoords = joy_get_coord();
	}
	int guion_number = 1; //el guion se "para" sobre la primer letra

	while (mySwitch != J_PRESS) //mientras que no se presione el 
	{

		joy_update();
		mySwitch = joy_get_switch();
		myCoords = joy_get_coord();
		if (screen_number == 8)
		{
			if (guion_number == 1)
			{
				guion_number = 2;
			}
			else
			{
				guion_number = 1;
			}
			draw_guion_5(guion_number, screen_number);
		}
		else if (myCoords.x > 10)                //si se mueve el joystick a la derecha, cambia a la pantalla correspondiente
		{
			if (guion_number == 3)
			{
				guion_number = 1;
			}
			else
			{
				guion_number += 1;
			}
		}
		else if (myCoords.x < -10)
		{
			if (guion_number == 1)
			{
				guion_number = 3;
			}
			else
			{
				guion_number -= 1;
			}
		}

		switch (screen_number) //cada pantalla es un caso especial, ya que hay letras 4x5 y letras 5x5
		{
		case 1:
		case 2:
		case 4:
		case 6:
		{
			//todas estas pantallas tienen 3 letras 4x5
			draw_guion_4(guion_number, screen_number);
			break;
		}
		case 3:
		{
			//la tercera letra es 5x5
			guion_number == 3 ? draw_guion_5(guion_number, screen_number) : draw_guion_4(guion_number, screen_number);
			break;
		}
		case 5:
		{
			//la primer letra es 5x5
			guion_number == 1 ? draw_guion_5(guion_number, screen_number) : draw_guion_4(guion_number, screen_number);
			break;
		}
		case 7:
		{
			//la segunda letra es 5x5
			guion_number == 2 ? draw_guion_5(guion_number, screen_number) : draw_guion_4(guion_number, screen_number);
			break;
		}
		case 9:
		{
			guion_number == 3 ? draw_guion_4(guion_number, screen_number) : draw_guion_5(guion_number, screen_number);
		}
		}
		disp_update();

	}
	while (mySwitch == J_PRESS)
	{
		joy_update();
		mySwitch = joy_get_switch();
		myCoords = joy_get_coord();
	}

	return letter_keyboard[screen_number - 1][guion_number - 1]; //una vez seleccionada la letra, la devuelve

}

/*******************************************************************************
*   Estas funciones dibujan cada pantalla que ve el usuario. Cada una muestra  *
*	tres letras (excepto una)												   *
*******************************************************************************/
void screen_1_raspi(){
	disp_clear();
	draw_a(1, 6);
	draw_b(6, 6);
	draw_c(11, 6);
	draw_flechitas();
}
void screen_2_raspi(){
	disp_clear();
	draw_d(1, 6);
	draw_e(6, 6);
	draw_f(11, 6);
	draw_flechitas();
}
void screen_3_raspi(){
	disp_clear();
	draw_g(1, 6);
	draw_h(6, 6);
	draw_i(11, 6);
	draw_flechitas();
}
void screen_4_raspi(){
	disp_clear();
	draw_j(1, 6);
	draw_k(6, 6);
	draw_l(11, 6);
	draw_flechitas();
}
void screen_5_raspi(){
	disp_clear();
	draw_m(0, 6);
	draw_n(6, 6);
	draw_o(11, 6);
	draw_flechitas();
}
void screen_6_raspi(){
	disp_clear();
	draw_p(1, 6);
	draw_q(6, 6);
	draw_r(11, 6);
	draw_flechitas();
}
void screen_7_raspi(){
	disp_clear();
	draw_s(0, 6);
	draw_t(5, 6);
	draw_u(11, 6);
	draw_flechitas();
}
void screen_8_raspi(){
	disp_clear();
	draw_v(2, 6);
	draw_w(9, 6);
	draw_flechitas();
}
void screen_9_raspi(){
	disp_clear();
	draw_x(0, 6);
	draw_y(6, 6);
	draw_z(12, 6);
	draw_flechitas();
}

/*******************************************************************************
*	Estas funciones se encargan de dibujar los guiones. Reciben el numero de   *
*	guion y el numero de pantalla, con el fin de establecer una coordenada x   *
*	de referencia para dibujar el guion.									   *
*	El fin de los guiones, es mostrarle al usuario sobre que letra esta parado *
*	una vez seleccionada la pantalla. 										   *
*******************************************************************************/

void draw_guion_4(int x, int screen_number){ //para las letras 4x5
	clear_guion();
	if (x == 1){
		if (screen_number == 7){ //caso especial 
			x = 0; //acomodo el guion para que apunte a la primer letra
		}
		else{
			//deja el x=1
		}
	}
	else if (x == 2){
		x = 6;	//acomoda el guion para que apunte a la segunda letra
	}
	else if (x == 3){
		if (screen_number == 9){
			x = 12; //caso especial
		}
		else{
			x = 11;	//acomoda el guion para que apunte a la tercera letra
		}
	}
	dcoord_t myPoint_guion41 = { x,8 };
	disp_write(myPoint_guion41, D_ON);
	dcoord_t myPoint_guion42 = { x + 1,8 };
	disp_write(myPoint_guion42, D_ON);
	dcoord_t myPoint_guion43 = { x + 2,8 };
	disp_write(myPoint_guion43, D_ON);
	dcoord_t myPoint_guion44 = { x + 3,8 };
	disp_write(myPoint_guion44, D_ON);
}

void draw_guion_5(int x, int screen_number){ //para las letras 5x5
	clear_guion();
	if (x == 1){
		switch (screen_number) {
			case 5:
			case 9:
				x = 0;		//acomoda el guion para que apunte a la primer letra
				break;
			case 8:			//acomoda el guion para que apunte a la primer letra
				x = 2;
				break;
		}
	}
	else if (x == 2){
		switch (screen_number) {
			case 7:
				x = 5;		//acomoda el guion para que apunte a la segunda letra
				break;
			case 8:
				x = 9;		//acomoda el guion para que apunte a la segunda letra
				break;
			case 9:
				x = 6;
				break;
		}
	}
	else if (x == 3){
		if (screen_number == 3){ //para comprobar que haya entrado bien
			x = 11;		//acomoda el guion para que apunte a la tercera letra
		}
	}
	dcoord_t myPoint_guion51 = { x,8 };
	disp_write(myPoint_guion51, D_ON);
	dcoord_t myPoint_guion52 = { x + 1,8 };
	disp_write(myPoint_guion52, D_ON);
	dcoord_t myPoint_guion53 = { x + 2,8 };
	disp_write(myPoint_guion53, D_ON);
	dcoord_t myPoint_guion54 = { x + 3,8 };
	disp_write(myPoint_guion54, D_ON);
	dcoord_t myPoint_guion55 = { x + 4,8 };
	disp_write(myPoint_guion55, D_ON);
}

void changeScreen(int screenNumber) {
	switch (screenNumber) {
	case 1:
		screen_1_raspi();
		break;
	case 2:
		screen_2_raspi();
		break;
	case 3:
		screen_3_raspi();
		break;
	case 4:
		screen_4_raspi();
		break;
	case 5:
		screen_5_raspi();
		break;
	case 6:
		screen_6_raspi();
		break;
	case 7:
		screen_7_raspi();
		break;
	case 8:
		screen_8_raspi();
		break;
	case 9:
		screen_9_raspi();
		break;
	}
}

void clear_guion(void)
{
	dcoord_t myPoint_guion1 = { 0,8 };
	disp_write(myPoint_guion1, D_OFF);
	dcoord_t myPoint_guion2 = { 1,8 };
	disp_write(myPoint_guion2, D_OFF);
	dcoord_t myPoint_guion3 = { 2,8 };
	disp_write(myPoint_guion3, D_OFF);
	dcoord_t myPoint_guion4 = { 3,8 };
	disp_write(myPoint_guion4, D_OFF);
	dcoord_t myPoint_guion5 = { 4,8 };
	disp_write(myPoint_guion5, D_OFF);
	dcoord_t myPoint_guion6 = { 5,8 };
	disp_write(myPoint_guion6, D_OFF);
	dcoord_t myPoint_guion7 = { 6,8 };
	disp_write(myPoint_guion7, D_OFF);
	dcoord_t myPoint_guion8 = { 7,8 };
	disp_write(myPoint_guion8, D_OFF);
	dcoord_t myPoint_guion9 = { 8,8 };
	disp_write(myPoint_guion9, D_OFF);
	dcoord_t myPoint_guion10 = { 9,8 };
	disp_write(myPoint_guion10, D_OFF);
	dcoord_t myPoint_guion11 = { 10,8 };
	disp_write(myPoint_guion11, D_OFF);
	dcoord_t myPoint_guion12 = { 11,8 };
	disp_write(myPoint_guion12, D_OFF);
	dcoord_t myPoint_guion13 = { 12,8 };
	disp_write(myPoint_guion13, D_OFF);
	dcoord_t myPoint_guion14 = { 13,8 };
	disp_write(myPoint_guion14, D_OFF);
	dcoord_t myPoint_guion15 = { 14,8 };
	disp_write(myPoint_guion15, D_OFF);
	dcoord_t myPoint_guion16 = { 15,8 };
	disp_write(myPoint_guion16, D_OFF);
}

#endif