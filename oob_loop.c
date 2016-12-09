/*
** OoB_loop.c for  in /home/cesare/Documents/Battle_for_Midgard/Battle_for_Midgard-
** 
** Made by DE PADUA Cesare
** Login   <depadu_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 10:38:08 2016 DE PADUA Cesare
** Last update Fri Dec  9 03:28:16 2016 DE PADUA Cesare
*/

#include <stdlib.h>
#include "bfm.h"

static const t_command_oob	oob_command[] = {
  {"team", &team},
  {"you are the chosen one", &the_chosen_one},
  {"let's fight", &start_fight},
  {"buy magicbox", &buy_magic_box},
  {"quit", &quit},
  {NULL, NULL}
};

int team(t_player *player)
{
  t_monster     *current;

  current = player->team->first;
  if (player->team->first == NULL)
    my_putstr_color("red", "Your team is empty!\n");
  while (current != NULL)
    {
      my_putstr_color("yellow", "NAME : ");
      my_putstr(current->creature->name);
      my_putchar('\n');
      my_putstr_color("yellow", "LVL : ");
      my_put_nbr(current->creature->lvl);
      my_putchar('\n');
      my_putstr_color("yellow", "PV : ");
      my_put_nbr(current->creature->pv);
      my_putchar('\n');
      my_putstr_color("yellow", "PV MAX : ");
      my_put_nbr(current->creature->pvmax);
      my_putchar('\n');
      my_putstr_color("yellow", "PM : ");
      my_put_nbr(current->creature->pm);
      my_putchar('\n');
      my_putstr_color("yellow", "PM MAX : ");
      my_put_nbr(current->creature->pmmax);
      my_putchar('\n');
      my_putstr_color("yellow", "************************************ ");
      my_putchar('\n');
      current = current->next;
    }
  return 1;
}

int the_chosen_one(t_player *player)
{
  char	*monster_name;
  t_monster   *monster;

  monster = player->team->first;
  my_putstr("what is your chosen monster??\n");
  monster_name = readline();
  while (monster != NULL)
  {
    if (my_strcmp(monster_name, monster->creature->name) == 0)
    {
      player->team->selected = monster;
    }
    monster =  monster->next;
  }
  my_putstr("your chosen one is : ");
  my_putstr(player->team->selected->creature->name);
  my_putchar('\n');
  return 1;
}

int start_fight(t_player *player)
{
  t_creature	*creature;

  creature = getCreature();
  if(get_instruction_for_ib(player, creature) == 2)
    return (0);
  return 1;
}

int quit(t_player *player)
{
  if(player != NULL)
    my_putstr("quit\n");
  return 0;
}

int	get_instruction_for_oob(t_player *player)
{
  char	*user_input;
  int	i;
  int	playing;

  playing = 1;
  while (playing)
  {
    i = 0;
    my_putstr_color("blue", "choose an action -> ");
    user_input = readline();
    if(!user_input)
    {
      my_putstr_color("red", "Ther's some problem whit the command system, please retry or restart game\n");
      return (0);
    }
    while (oob_command[i].commande != NULL)
    {
      if(my_strcmp(oob_command[i].commande, user_input) == 0)
      {
	if(oob_command[i].function(player) == 0)
	   playing = 0;
      }
      ++ i;
    }
  }
  return (0);
}
