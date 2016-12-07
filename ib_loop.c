/*
** ib_loop.c for  in /home/cesare/Documents/Battle_for_Midgard/Battle_for_Midgard-
** 
** Made by DE PADUA Cesare
** Login   <depadu_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 13:23:31 2016 DE PADUA Cesare
** Last update Wed Dec  7 14:06:35 2016 DE PADUA Cesare
*/
#include <stdlib.h>
#include "bfm.h"

static const t_command_ib	ib_command[] = {
  {"magic catch", &magic_catch},
  {"help me", &help_me},
  {NULL, NULL}
};

int	magic_catch (t_creature creature, t_player player)
{
  if (creature !⁼ NULL && player != NULL)
    my_putstr("MAGIC CATCH\n");
  return 1;
}
int	help_me(t_creature creature, t_player player)
{
  if (creature != NULL && player != NULL)
  {
    my_putstr_color("blue", "You escaped the battle\n");
    return 0;
  }
}
