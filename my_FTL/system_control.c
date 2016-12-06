/*
** system_control.c for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Wed Nov  9 09:45:14 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:27:18 2016 ENNAMOURI Maryem
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *the_ship)
{
  my_putstr_color("green", "verification du reacteur en cours...\n");
  if (my_strcmp(the_ship->my_weapon->system_state, "online") == 1)
  {
    my_putstr_color("yellow", "reacteur hors service!\n");
  }
  my_putstr_color("blue", "reacteur OK!\n");
}

void	navigation_tools_system_check(t_ship *the_ship)
{
  my_putstr_color("green", "verification du systeme de navigation en cours...\n");
 if (my_strcmp(the_ship->my_weapon->system_state, "online") == 1)
 {
   my_putstr_color("yellow", "systeme de navigation hors service!\n");
 }
 my_putstr_color("blue", "systeme de navigation OK!\n");
}

void	weapon_system_check(t_ship *the_ship)
{
  my_putstr_color("green", "verification du systeme d'armement en cours...\n");
 if (my_strcmp(the_ship->my_weapon->system_state, "online") == 1)
 {
   my_putstr_color("yellow", "systeme d'armement hors service!\n");
 }
 my_putstr_color("blue", "systeme d'armement OK!\n");
}

void	system_control(t_ship *the_ship)
{
  ftl_drive_system_check(the_ship);
  navigation_tools_system_check(the_ship);
  weapon_system_check(the_ship);
}
