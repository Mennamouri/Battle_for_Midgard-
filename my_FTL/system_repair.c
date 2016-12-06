/*
** system_repair.c for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Wed Nov  9 10:21:08 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:38:26 2016 ENNAMOURI Maryem
*/

#include "ftl.h"
#include <stdlib.h>

int		ftl_drive_system_repair(t_ship *the_ship)
{
  my_putstr_color("green", "reparation du reacteur en cours...\n");
  free(the_ship->my_drive->system_state);
  the_ship->my_drive->system_state = my_strdup("online");
  if (my_strcmp(the_ship->my_drive->system_state, "online") != 0)
  {
    my_putstr_color("yellow", "les reparations du reacteur ont echoue\n");
    return (0);
  }
  my_putstr_color("blue", "reparation termine!systeme reacteur OK!");
  return (1);
}

int		navigation_tools_system_repair(t_ship *the_ship)
{
  my_putstr_color("green", "reparation du systeme de navigation en cours...\n");
  free(the_ship->my_navigation->system_state);
  the_ship->my_navigation->system_state = my_strdup("online");
  if (my_strcmp(the_ship->my_navigation->system_state, "online") != 0)
  {
    my_putstr_color("yellow", "les reparations des outils de navigations ont echoue\n");
    return (0);
  }
  my_putstr_color("blue", "reparation termine!systeme de navigation OK!");
  return (1);
}

int		weapon_system_repair(t_ship *the_ship)
{
  my_putstr_color("green", "reparation du systeme d'armement en cours...\n");
  if (my_strcmp(the_ship->my_weapon->system_state, "online") != 0)
  {
    free(the_ship->my_weapon->system_state);
  }
  the_ship->my_weapon->system_state = my_strdup("online");
  if (my_strcmp(the_ship->my_weapon->system_state, "online") == 1)
  {
    my_putstr_color("yellow", "les reparations du systeme d'armement ont echoue\n");
    return (0);
  }
  my_putstr_color("blue", "reparation termine!systeme d'armement OK!");
  return (1);
}

static	const	t_repair_command tab[] = {
  {"ftl_drive", &ftl_drive_system_repair},
  {"navigation_tools", &navigation_tools_system_repair},
  {"weapon", &weapon_system_repair},
  {NULL, NULL}
};

int		system_repair(t_ship *the_ship)
{
  char	*str;
  int i;

  i = 0;
  my_putstr_color("green", "repair_system~>");
  str = readline();
  if (!str)
    my_putstr_color("yellow", "[SYSTEM FAILURE]: le lecteur de commande est bloque\n");
  while (tab[i].repair != NULL)
  {
      if (my_strcmp(str, tab[i].repair) == 0)
      {
	if (tab[i].function(the_ship) == 0)
	{
	  return (0);
	}
      }
      i++;
  }
  my_putstr_color("blue", "[SYSTEM FAILURE]: commande inconnue\n");
 return (0);
}
