/*
** inventory_functions.c for  in /home/cesare/Documents/Battle_for_Midgard/Battle_for_Midgard-
** 
** Made by DE PADUA Cesare
** Login   <depadu_c@etna-alternance.net>
** 
** Started on  Fri Dec  9 03:18:43 2016 DE PADUA Cesare
** Last update Fri Dec  9 03:31:00 2016 DE PADUA Cesare
*/

#include <stdlib.h>
#include "bfm.h"

int buy_magic_box(t_player *player)
{
  if(player->inventory->rupees < 90)
  {
    my_putstr_color("red", "You have not enough rupees!\n");
    return (1);
  }
  player->inventory->magicbox++;
  player->inventory->rupees -= 90;
  my_putstr_color("green", "You bought a magicbox, you now have ");
  my_put_nbr(player->inventory->magicbox);
  my_putstr_color("green", " magicbox!\n");
  return (1);
}
