/*
** ib_loop.c for  in /home/cesare/Documents/Battle_for_Midgard/Battle_for_Midgard-
** 
** Made by DE PADUA Cesare
** Login   <depadu_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 13:23:31 2016 DE PADUA Cesare
** Last update Thu Dec  8 12:17:01 2016 DE PADUA Cesare
*/
#include <stdlib.h>
#include "bfm.h"

static const t_command_ib	ib_command[] = {
  {"slash", &slash},
  {"magic catch", &magic_catch},
  {"help me", &help_me},
  {"quit", &quit_from_fight},
  {NULL, NULL}
};

void show_monster_stats(t_creature creature)
{
  my_putstr_color("blue", "name: ");
  my_putstr_color("blue", creature.name);
  my_putstr_color("blue", "\n");
  my_putstr_color("blue", "lvl: ");
  my_put_nbr(creature.lvl);
  my_putstr_color("blue", "\n");
  my_putstr_color("blue", "pv: ");
  my_put_nbr(creature.pv);
  my_putstr_color("blue", "\n");
  my_putstr_color("blue", "pm: ");
  my_put_nbr(creature.pm);
  my_putstr_color("blue", "\n");
}

void	add_creature_to_container(t_player *player, t_monster *monster)
{
  if(player->team->first == NULL)
  {
    player->team->first = monster;
    player->team->last = monster;
    player->team->selected = monster;
  }
  else
  {
    monster->prev = player->team->last;
    player->team->last->next = monster;
    player->team->last = monster;
  }
  ++player->team->nb_monsters;
}

int	magic_catch (t_creature *creature, t_player *player)
{
  int random;

  if(player->inventory->magicbox <= 0)
    my_putstr_color("red","You have no more magicbox!\n");
  --player->inventory->magicbox;
  random = (rand() % 3 + 1);
  if(random == 1)
  {
    t_monster *monster;

    monster = malloc(sizeof(*monster));
    if (monster == NULL)
    {
      my_putstr_color("red", "An error occurred while monster creation\n");
      return 0;
    }
    monster->creature = creature;
    monster->prev = NULL;
    monster->next = NULL;
    add_creature_to_container(player, monster);
    my_putstr_color("green", "You caught the monster!\n");
    show_monster_stats(*creature);
    return (0);
  }
  my_putstr_color("red", "The enemy attack..\n");
  help_me(creature, player);
  return 0;
}

int	help_me(t_creature *creature, t_player *player)
{
  if (creature != NULL && player != NULL)
  {
    my_putstr_color("blue", "You escaped the battle\n");
  }
  return (0);
}

int	quit_from_fight(t_creature *creature, t_player *player)
{
  if (creature != NULL && player != NULL)
    return (2);
  return (2);
}

int	get_instruction_for_ib(t_player *player, t_creature *creature)
{
  char	*user_input;
  int	i;
  int	fighting;

  fighting = 1;

  my_putstr_color("yellow", "Wild creature appears...\n");
  my_putstr_color("yellow", "NAME : ");
  my_putstr_color("yellow", creature->name);
  my_putstr_color("yellow", "\n");
  my_putstr_color("yellow", "PV : ");
  my_put_nbr(creature->pv);
  my_putstr_color("yellow", "\n");
  while(fighting)
  {
    i = 0;
    my_putstr_color("blue","figth!-> ");
    user_input = readline();
    if (!user_input)
    {
      my_putstr_color("red", "Ther's some problem whit the command system, please retry or restart gam\
e\n");
      return (0);
    }
    while (ib_command[i].commande != NULL)
    {
      if(my_strcmp(ib_command[i].commande, user_input) == 0)
      {
	int result;

	result = ib_command[i].function(creature, player);
	if(result == 0)
	  fighting = 0;
	else if(result == 2)
	  return (2);
      }
      ++i;
    }
  }
  return (0);
}
