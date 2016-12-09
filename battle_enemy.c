/*
** battle_enemy.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Thu Dec  8 21:20:59 2016 ENNAMOURI Maryem
** Last update Fri Dec  9 04:24:34 2016 DE PADUA Cesare
*/

#include <stdlib.h>
#include "bfm.h"

static const t_command_ib       ib_command_ennemy[] = {
  {"slash", &slash_ennemy},
  {"fire", &fire_ennemy},
  {"gamble",&gamble_ennemy},
  {"rest", &rest_ennemy},
  {NULL, NULL}
};


int slash_ennemy(t_creature *creature, t_player *player)
{
  if (creature->pm <= 0)
    {
      my_putstr_color("red", creature->name);
      my_putstr_color("red", " has no more pm\n");
      return (1);
    }
  my_putstr_color("green", creature->name);
  my_putstr_color("green", " use slash\n");
  player->team->selected->creature->pv -= 15;
  creature->pm -= 3;
  my_putstr_color("cyan", "Your Monster: ");
  my_putstr_color("cyan", player->team->selected->creature->name);
  my_putstr_color("cyan", "\n"); 
  my_putstr_color("cyan", "PV : ");
  my_put_nbr(player->team->selected->creature->pv);
  my_putstr_color("cyan", "\n");
  if(player->team->selected->creature->pv <= 0)
  {
      t_monster	*current;

      current = player->team->first;
      remove_monster_from_list(player, player->team->selected);
      player->team->selected = NULL;
      my_putstr_color("red", "Your creature is fainted!\n");
      while (current != NULL)
      {
	if(current->creature->pv > 0)
	{  
	  player->team->selected = current;
	  return (0);
	}
	current = current->next;
      }
      return (0);
  }
  return (1);
}

int fire_ennemy(t_creature *creature, t_player *player)
{
  if (creature->pm <= 0)
    {
      my_putstr_color("red", creature->name);
      my_putstr_color("red", " has no more pm\n");
      return (1);
    }
  my_putstr_color("green", creature->name);
  my_putstr_color("green", " use fire\n");
  player->team->selected->creature->pv -= 30;
  creature->pm -= 7;
  my_putstr_color("cyan", "Your Monster: ");
  my_putstr_color("cyan",player->team->selected->creature->name);
  my_putstr_color("cyan", "\n");
  my_putstr_color("cyan", "PV: ");
  my_put_nbr(player->team->selected->creature->pv);
  my_putstr_color("cyan", "\n");
  if (player->team->selected->creature->pv <= 0)
  {
      t_monster	*current;

      current = player->team->first;
      remove_monster_from_list(player, player->team->selected);
      player->team->selected = NULL;
      my_putstr_color("red", "Your creature is fainted!\n");
      while (current != NULL)
      {
	if(current->creature->pv > 0)
	{  
	  player->team->selected = current;
	  return (0);
	}
	current = current->next;
      }
      return (0);
  }
  return (1);
}

int rest_ennemy(t_creature *creature, t_player *player)
{
  if (player == NULL)
    return 0;
  my_putstr_color("green", creature->name);
  my_putstr_color("green", " use restore!\n");
  if((creature->pm + 10) >= creature->pmmax)
        creature->pm = creature->pmmax;
  else
    creature->pm += 10;
  return (1);
}

int gamble_ennemy(t_creature *creature, t_player *player)
{
  int rand_for_damage;
  int rand_for_target;

  rand_for_damage = (rand() % 20);
  rand_for_target = (rand() % 100 + 1);
  my_putstr_color("green", creature->name);
  my_putstr_color("green", " use gamble\n");
  if(rand_for_target < 50)
    {
      my_putstr_color("red", "Your Monster hit it self!");
      creature->pv -= rand_for_damage;
      return (1);
    }
  else
    {
      player->team->selected->creature->pv -= rand_for_damage;
      my_putstr_color("cyan", "Your Monster: ");
      my_putstr_color("cyan", player->team->selected->creature->name);
      my_putstr_color("cyan", "\n");
      my_putstr_color("cyan", "PV : ");
      my_put_nbr(player->team->selected->creature->pv);
      my_putstr_color("cyan", "\n");
    }
  if (player->team->selected->creature->pv <= 0)
  {
      t_monster	*current;

      current = player->team->first;
      remove_monster_from_list(player, player->team->selected);
      player->team->selected = NULL;
      my_putstr_color("red", "Your creature is fainted!\n");
      while (current != NULL)
      {
	if(current->creature->pv > 0)
	{  
	  player->team->selected = current;
	  return (0);
	}
	current = current->next;
      }
      return (0);
  }
  if(creature->pv <= 0)
  {
      my_putstr_color("red", "Your enemy is fainted!\n");
      gain_rupees(player);
      free(creature->name);
      free(creature);
      return (0);
  }
  return (1);
}

int     select_attack_for_monster(t_player *player, t_creature *creature)
{
  int	nb;
  int res;
  
  nb = rand() % 4;
  res = ib_command_ennemy[nb].function(creature, player);
  return (res);
}
