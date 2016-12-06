/*
** air_shed.c for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Nov  7 11:31:58 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:39:21 2016 ENNAMOURI Maryem
*/

#include "ftl.h"
#include <stdlib.h>

t_ship		*create_ship()
{
  t_ship	*ship;
  
  my_putstr_color("green", "construction du vaisseau en cours ...\n");
  ship = malloc(sizeof(t_ship));
  if (ship == NULL)
  {
    my_putstr_color("yellow", "le vaisseau n'a pas pu etre contruit par manque de materiaux\n");
  }
  ship->hull = 50;
  ship->my_weapon = NULL;
  ship->my_drive = NULL;
  ship->my_navigation = NULL;
  ship->my_container = NULL;
  my_putstr_color("blue", "amelioration du vaisseau terminer!\n");
  return (ship);
}

int		add_weapon_to_ship(t_ship *the_ship)
{
  t_weapon	*the_weapon;

  my_putstr_color("green", "ajout des armes en cours...\n");
  the_weapon = malloc(sizeof(t_weapon));
  if (the_weapon == NULL)
  {
    my_putstr_color("yellow", "votre vaisseau a explosé quand vous avez tenté d'ajouter les armes\n");
    return (0);
  }
  the_weapon->damage = 10;
  the_weapon->system_state = my_strdup("online");
  the_ship->my_weapon = the_weapon;
  my_putstr_color("blue", "les armes ont été ajoutés avec succes!\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *the_ship)
{
  t_ftl_drive	*the_drive;

  my_putstr_color("green", "ajout du reacteur en cours...\n");
  the_drive = malloc(sizeof(t_ftl_drive));
  if (the_drive == NULL)
  {
    my_putstr_color("yellow", "votre vaisseau a explose quand vous avez tenté d'ajouter le reacteur\n");
    return (0);
  }
  the_drive->energy = 10;
  the_drive->system_state = my_strdup("online");
  the_ship->my_drive = the_drive;
  my_putstr_color("blue", "le reacteur a été ajouté avec succes!\n");
  return (1);
}

int			add_navigation_tools_to_ship(t_ship *the_ship)
{
  t_navigation_tools	*the_navigation_tools;

  my_putstr_color("green", "ajout des outils de navigations...\n");
  the_navigation_tools = malloc(sizeof(t_navigation_tools));
  if (the_navigation_tools == NULL)
  {
    my_putstr_color("yellow", "votre vaisseau a explose lorsque vous avez pose les outils de navigations\n");
    return (0);
  }
  the_navigation_tools->sector = 0;
  the_navigation_tools->evade = 25;
  the_navigation_tools->
  system_state = my_strdup("online");
  the_ship->my_navigation = the_navigation_tools;
  my_putstr_color("blue", "les outils de navigations ont ete ajoutes avec succes!\n");
  return (1);
}
