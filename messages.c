/*
** messages.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Tue Dec  6 16:19:21 2016 ENNAMOURI Maryem
** Last update Wed Dec  7 09:49:58 2016 ENNAMOURI Maryem
*/

#include "BFM.h"
#include <stdlib.h>
#include <time.h>

void	my_bfm_draw()
{
  my_putchar('\n');
  my_putchar('\n');
  my_putstr_color("red",     "                              ************************************************************\n");
  my_putstr_color("cyan",    "                                             ***************************                  \n");
  my_putstr_color("yellow",  "                                             ***************************                  \n");
  my_putstr_color("red",     "                              ************************************************************\n\n");
  my_putstr_color("cyan",    "                             '▀█████████▄          ▄████████        ▄▄▄▄███▄▄▄▄        \n");
  my_putstr_color("yellow",  "                                ███    ███        ███    ███      ▄██▀▀▀███▀▀▀██▄      \n");
  my_putstr_color("magenta", "                                ███    ███        ███    █▀       ███   ███   ███      \n");
  my_putstr_color("cyan",    "                               ▄███▄▄▄██▀        ▄███▄▄▄          ███   ███   ███      \n");
  my_putstr_color("magenta", "                              ▀▀███▀▀▀██▄       ▀▀███▀▀▀          ███   ███   ███      \n");
  my_putstr_color("cyan",    "                                ███    ██▄        ███             ███   ███   ███      \n");
  my_putstr_color("red",     "                                ███    ███        ███             ███   ███   ███      \n");
  my_putstr_color("yellow",  "                              ▄█████████▀         ███              ▀█   ███   █▀       \n");
  my_putstr_color("cyan",    "                                             ***************************                  \n");
  my_putstr_color("red",     "                              ************************************************************\n\n");
}

void	help_game_oob()
{
  my_putstr_color("green", "############### **MENU_OUT_OF_BATTLE** #####################\n");
  my_putstr_color("red","team : see all memember of your team\n");
  my_putstr_color("red","you are the chosen one : choose a creature from your team\n");
  my_putstr_color("red","let's fight : search for a battle\n");
  my_putstr_color("red","quit : quit the game\n");
  my_putstr_color("green", "############### ************** #####################\n");
}


void	help_game_ib()
{
  my_putstr_color("green", "############### **MENU_IN_BATTLE** #####################\n");
  my_putstr_color("red","slash : an attack who make lost 15 PV to your enemy,  it cost 3 PM\n");
  my_putstr_color("red","fire : a spell who make lost 30 PV to your enemy, it cost 7 PM \n");
  my_putstr_color("red","gamble : an attack who make lost between 0 and 20 PM ( 50% of chance )\n");
  my_putstr_color("red","rest : you lost a turn to restore 10 PM\n");
  my_putstr_color("green", "############### ************** #####################\n");
}


void	stat_game(t_ship *the_ship)
{
  my_putstr_color("yellow", "############### **STAT_GAME** #####################\n");
  my_putstr_color("magenta","******************YOU*************** : \n");
  my_putstr_color("yellow", "############### ************** #####################\n");
}

