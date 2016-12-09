/*
** inventory_functions.c for  in /home/cesare/Documents/Battle_for_Midgard/Battle_for_Midgard-
** 
** Made by DE PADUA Cesare
** Login   <depadu_c@etna-alternance.net>
** 
** Started on  Fri Dec  9 03:18:43 2016 DE PADUA Cesare
** Last update Fri Dec  9 04:01:00 2016 DE PADUA Cesare
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

int buy_mushrooms(t_player *player)
{
  if(player->inventory->rupees < 30)
  {
    my_putstr_color("red", "You have not enough rupees!\n");
    return (1);
  }
  player->inventory->mushrooms++;
  player->inventory->rupees -= 30;
  my_putstr_color("green", "You bought a mushroom, you now have ");
  my_put_nbr(player->inventory->mushrooms);
  my_putstr_color("green", " mushrooms!\n");
  return (1);
}

int use_mushroom(t_player *player)
{
  int	gain_pv_pourcent;
  int	gain_pv;

  if(player->inventory->mushrooms <= 0)
  {
    my_putstr_color("red", "You have no mushrooms!\n");
    return (1);
  }
  if(player->team->selected == NULL)
  {
    my_putstr_color("red", "Your team is empty!\n");
    return (1);
  }
  gain_pv_pourcent = (rand() % 10 + 1) + 15;
  gain_pv = player->team->selected->creature->pvmax * gain_pv_pourcent / 100;
  if (player->team->selected->creature->pv + gain_pv >= player->team->selected->creature->pvmax)
    player->team->selected->creature->pv = player->team->selected->creature->pvmax;
  else
    player->team->selected->creature->pv += gain_pv;
  my_putstr_color("green", "You restored ");
  my_put_nbr(gain_pv);
  my_putstr_color("green", " pvs of ");
  my_putstr_color("green", player->team->selected->creature->name);
  my_putstr_color("green", "\n");
  my_putstr_color("green", "It now have ");
  my_put_nbr(player->team->selected->creature->pv);
  my_putstr_color("green", " pvs!\n");
  return (1);
}
