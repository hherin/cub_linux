/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:38:02 by hherin            #+#    #+#             */
/*   Updated: 2020/04/08 16:00:52 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LGL_DEFINE_H
# define LGL_DEFINE_H
/*
** # define NOEVENTMASK 0L
** # define KEYPRESSMASK (1L<<0)
** # define KEYRELEASEMASK (1L<<1)
** # define BUTTONPRESSMASK (1L<<2)
** # define BUTTONRELEASEMASK (1L<<3)
** # define ENTERWINDOWMASK (1L<<4)
** # define LEAVEWINDOWMASK (1L<<5)
** # define POINTERMOTIONMASK (1L<<6)
** # define POINTERMOTIONHINTMASK (1L<<7)
** # define BUTTON1MOTIONMASK (1L<<8)
** # define BUTTON2MOTIONMASK (1L<<9)
** # define BUTTON3MOTIONMASK (1L<<10)
** # define BUTTON4MOTIONMASK (1L<<11)
** # define BUTTON5MOTIONMASK (1L<<12)
** # define BUTTONMOTIONMASK (1L<<13)
** # define KEYMAPSTATEMASK (1L<<14)
** # define EXPOSUREMASK (1L<<15)
** # define VISIBILITYCHANGEMASK (1L<<16)
** # define STRUCTURENOTIFYMASK (1L<<17)
** # define RESIZEREDIRECTMASK (1L<<18)
** # define SUBSTRUCTURENOTIFYMASK (1L<<19)
** # define SUBSTRUCTUREREDIRECTMASK (1L<<20)
** # define FOCUSCHANGEMASK (1L<<21)
** # define PROPERTYCHANGEMASK (1L<<22)
** # define COLORMAPCHANGEMASK (1L<<23)
** # define OWNERGRABBUTTONMASK (1L<<24)
*/


# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24
/*
** Mouse button keycodes
*/
# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7
/*
** Keyboard keys
*/
/*
** Letters keys
*/
# define A_KEY 97
# define B_KEY 98
# define C_KEY 99
# define D_KEY 100
# define E_KEY 101
# define F_KEY 102
# define G_KEY 103
# define H_KEY 104
# define I_KEY 105
# define J_KEY 106
# define K_KEY 107
# define L_KEY 108
# define M_KEY 109
# define N_KEY 110
# define O_KEY 111
# define P_KEY 112
# define Q_KEY 113
# define R_KEY 114
# define S_KEY 115
# define T_KEY 116
# define U_KEY 117
# define V_KEY 118
# define W_KEY 119
# define X_KEY 120
# define Y_KEY 121
# define Z_KEY 122

/*
** Arrow keys
*/
# define UP_KEY 65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define TAB_KEY 65289
# define ESC_KEY 65307 

#endif
