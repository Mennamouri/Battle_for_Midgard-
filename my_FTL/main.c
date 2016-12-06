/*
** main.c for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Nov  7 12:08:39 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:33:53 2016 ENNAMOURI Maryem
*/

#include "ftl.h"

int	game();

int	main()
{
  t_ship *ship;
  my_ftl_draw();
  ship = create_ship();
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  my_putstr_color("cyan", "waiting_for_orders\n");
  game(ship);
  return (0);
}
