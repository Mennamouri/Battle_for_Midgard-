/*
** OoB_loop.c for  in /home/cesare/Documents/Battle_for_Midgard/Battle_for_Midgard-
** 
** Made by DE PADUA Cesare
** Login   <depadu_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 10:38:08 2016 DE PADUA Cesare
** Last update Wed Dec  7 13:49:09 2016 DE PADUA Cesare
*/

#include <stdlib.h>
#include "bfm.h"

static const t_command_oob	oob_command[] = {
  {"team", &show_team},
  {"you are the choosen one", &the_chosen_one},
  {"let's fight", &start_fight},
  {"quit", &quit},
  {NULL, NULL}
};

int show_team(t_player *player)
{
  if(player != NULL)
    my_putstr("show team\n");
  return 1;
}

int the_chosen_one(t_player *player)
{
  if(player != NULL)
    my_putstr("the chosen one\n");
  return 1;
}

int start_fight(t_player *player)
{
  t_creature *creature;

  creature = getCreature();
  get_instruction_for_ib(creature, player);
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
    my_putstr_color("blue", "choose an action ->");
    user_input = "";
    //user_input = readline();
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
