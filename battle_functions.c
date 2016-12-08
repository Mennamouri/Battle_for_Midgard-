/*
** battle_functions.c for  in /home/cesare/Documents/Battle_for_Midgard/Battle_for_Midgard-
** 
** Made by DE PADUA Cesare
** Login   <depadu_c@etna-alternance.net>
** 
** Started on  Thu Dec  8 11:27:33 2016 DE PADUA Cesare
** Last update Fri Dec  9 00:48:35 2016 ENNAMOURI Maryem
*/

#include <stdlib.h>
#include "bfm.h"

int slash(t_creature *creature, t_player *player)
{
  if (player->team->selected == NULL)
  {
    my_putstr_color("red", "You have no member in your team\n");
    return (1);
  }
  if (player->team->selected->creature->pm <= 0)
  {
    my_putstr_color("red", player->team->selected->creature->name);
    my_putstr_color("red", " has no more pm\n");
    return (1);
  }
  my_putstr_color("green", player->team->selected->creature->name);
  my_putstr_color("green", " use slash\n");
  creature->pv -= 15;
  player->team->selected->creature->pm -= 3;
  my_putstr_color("yellow", "NAME : ");
  my_putstr_color("yellow", creature->name);
  my_putstr_color("yellow", "\n");
  my_putstr_color("yellow", "PV : ");
  my_put_nbr(creature->pv);
  my_putstr_color("yellow", "\n");
  if(creature->pv <= 0)
  {
    my_putstr_color("green", "Your enemy is fainted!\n");
    free(creature);
    return (0);
  }
  return (1);
}

int fire(t_creature *creature, t_player *player)
{
  if (player->team->selected == NULL)
  {
    my_putstr_color("red", "You have no member in your team\n");
    return (1);
  }
  if (player->team->selected->creature->pm <= 0)
  {
    my_putstr_color("red", player->team->selected->creature->name);
    my_putstr_color("red", " has no more pm\n");
    return (1);
  }
  my_putstr_color("green", player->team->selected->creature->name);
  my_putstr_color("green", " use fire\n");
  creature->pv -= 30;
  player->team->selected->creature->pm -= 7;
  my_putstr_color("yellow", "NAME : ");
  my_putstr_color("yellow", creature->name);
  my_putstr_color("yellow", "\n");
  my_putstr_color("yellow", "PV : ");
  my_put_nbr(creature->pv);
  my_putstr_color("yellow", "\n");
  if(creature->pv <= 0)
  {
    my_putstr_color("green", "Your enemy is fainted!\n");
    free(creature);
    return (0);
  }
  return (1);
}

int gamble(t_creature *creature, t_player *player)
{
  int rand_for_damage;
  int rand_for_target;

  rand_for_damage = (rand() % 20);
  rand_for_target = (rand() % 100 + 1);
  if (player->team->selected == NULL)
  {
    my_putstr_color("red", "You have no member in your team\n");
    return (1);
  }
  my_putstr_color("green", player->team->selected->creature->name);
  my_putstr_color("green", " use gamble\n");
  if(rand_for_target < 50)
  {
    my_putstr_color("red", "Your creature hit it self!\n");
    player->team->selected->creature->pv -= rand_for_damage;
    return (1);
  }
  else
  {
    creature->pv -= rand_for_damage;
    my_putstr_color("yellow", "NAME : ");
    my_putstr_color("yellow", creature->name);
    my_putstr_color("yellow", "\n");
    my_putstr_color("yellow", "PV : ");
    my_put_nbr(creature->pv);
    my_putstr_color("yellow", "\n"); 
  }
  if(creature->pv <= 0)
  {
    my_putstr_color("green", "Your enemy is fainted!\n");
    free(creature);
    return (0);
  }
  if(player->team->selected->creature->pv <= 0)
  {
    my_putstr_color("red", "Your creature is fainted!\n");
    if(player->team->selected->next != NULL)
      player->team->selected = player->team->selected->next;
    else
      player->team->selected = player->team->selected->prev;
    return (0);
  }
  return (1);
}

int rest(t_creature *creature, t_player *player)
{
  if (player->team->selected == NULL)
  {
    my_putstr_color("red", "You have no member in your team\n");
    return (1);
  }
  if(creature == NULL)
    return (0);
  my_putstr_color("green", player->team->selected->creature->name);
  my_putstr_color("green", " use restore!\n");
  if((player->team->selected->creature->pm + 10) >= player->team->selected->creature->pmmax)
    player->team->selected->creature->pm = player->team->selected->creature->pmmax;
  else
    player->team->selected->creature->pm += 10;
  return (1);
}
