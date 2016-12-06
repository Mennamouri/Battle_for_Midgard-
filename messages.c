/*
** messages.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Tue Dec  6 16:19:21 2016 ENNAMOURI Maryem
** Last update Tue Dec  6 16:35:28 2016 ENNAMOURI Maryem
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
  my_putstr_color("cyan",    "                             '#########   '##           '######## '######## '##       \n");
  my_putstr_color("yellow",  "                              ##         ## '## ::::::::::: ##           ##     ##       \n");
  my_putstr_color("magenta", "                              #########    ####  ::::::::::: ##           ##     ##       \n");
  my_putstr_color("cyan",    "                              #########     ##   ::::::::::: ######       ##     ##       \n");
  my_putstr_color("yellow",  "                                     ##     ##   ::::::::::: ##           ##     ##       \n");
  my_putstr_color("magenta", "                                     ##     ##   ::::::::::: ##           ##     ##       \n");
  my_putstr_color("cyan",    "                              #########  ##   ::#######:: ##           ##     ######## \n\n");
  my_putstr_color("red",     "                              ************************************************************\n");
  my_putstr_color("yellow",  "                                             ***************************                  \n");
  my_putstr_color("cyan",    "                                             ***************************                  \n");
  my_putstr_color("red",     "                              ************************************************************\n\n");
}

void	help_game_oob()
{
  my_putstr_color("green", "############### **MENU_OUT_OF_BATTLE** #####################\n");
  my_putstr_color("red","team\n");
  my_putstr_color("red","you are the chosen one\n");
  my_putstr_color("red","let's fight\n");
  my_putstr_color("red","quit\n");
  my_putstr_color("green", "############### ************** #####################\n");
}


void	help_game_ib()
{
  my_putstr_color("green", "############### **MENU_IN_BATTLE** #####################\n");
  my_putstr_color("red","slash\n");
  my_putstr_color("red","fire\n");
  my_putstr_color("red","gamble\n");
  my_putstr_color("red","rest\n");
  my_putstr_color("green", "############### ************** #####################\n");
}


void	stat_game(t_ship *the_ship)
{
  my_putstr_color("yellow", "############### **STAT_GAME** #####################\n");
  my_putstr_color("magenta","******************YOU*************** : \n");
  my_putstr_color("yellow", "############### ************** #####################\n");
}

