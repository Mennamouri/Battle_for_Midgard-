/*
** function_game.c for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Sat Nov 12 10:12:54 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:53:45 2016 ENNAMOURI Maryem
*/

#include "ftl.h"
#include <stdlib.h>
#include <time.h>

static	t_ennemi ennemi = {0,0};

void	stat_ennemi()
{
  my_putstr_color("yellow", "############### **STAT_GAME** #####################\n");
  my_putstr_color("magenta", "******************ENNEMI*************** : \n");
  my_putstr_color("magenta", "point_vie : ");
  my_put_nbr(ennemi.point_vie);
  my_putchar('\n');
  my_putstr_color("magenta", "damage : ");
  my_put_nbr(ennemi.damage);
  my_putchar('\n'); 
}
 
void    create_ennemi()
{
  ennemi.point_vie = 20;
  ennemi.damage = 10;
  if (ennemi.point_vie > 0)
  {
    my_putstr_color("yellow", "un ennemi est apparu\n");
  }
}

void	attack_ennemi(t_ship *ship)
{
  srand (time(NULL));
  if (rand() % 100 > ship->my_navigation->evade)
  {
    my_putstr_color("yellow", "ennemi attack\n");
    ship->hull = ship->hull - ennemi.damage;
  }
  else
    my_putstr_color("yellow", "evade\n");
}

void	cmd_game(t_ship *ship, char *str)
{
  if (my_strcmp(str, "detect") == 0)
    detect_game(ship);
  if (my_strcmp(str, "getbonus") == 0)
    get_bonus(ship);
  if (my_strcmp(str, "jump") == 0)
  {
    if (ennemi.point_vie <= 0)
      jump_game(ship);
    else
      my_putstr_color("cyan", "vous ne pouvez pas jump, un ennemi existe :/ ! \n");
  }
  if (my_strcmp(str, "stat") == 0)
    stat_game(ship);
  if (my_strcmp(str, "help") == 0)
    help_game();
  if (my_strcmp(str, "attack") == 0)
  {
    if (ennemi.point_vie > 0)
    {
      ennemi.point_vie = ennemi.point_vie - ship->my_weapon->damage;
      stat_ennemi();
    }
    else
      my_putstr_color("cyan", "il n'y a pas d'ennemi dans le secteur :) ! \n");
  }
}

int     game(t_ship *ship)
{
  char  *str;

  while ((ship->my_navigation->sector < 10) && (ship->my_drive->energy > 0 && ship->my_navigation->sector < 10) && (ship->hull > 0))
  {
      if (ennemi.point_vie > 0)
      {
	attack_ennemi(ship);
      }
      my_putstr_color("cyan", "quelle est votre action :) ?\n");
      str = readline();
      if (my_strcmp(str, "attack") != 0
	  && my_strcmp(str, "detect") != 0
	  && my_strcmp(str, "jump") != 0
	  && my_strcmp(str, "getbonus") != 0
	  && my_strcmp(str, "exit") != 0
	  && my_strcmp(str, "repair") != 0
	  && my_strcmp(str, "control") != 0
 	  && my_strcmp(str, "stat") && my_strcmp(str, "help"))
	my_putstr_color("red", "erreur argument! faites help pour en savoir plus :D !! \n");
        cmd_game(ship, str);
      if (my_strcmp(str, "exit") == 0)
      {
	my_putstr_color("cyan", "vous avez choisi de quitter le jeu! à bientot ;) \n");
	ship->hull = 0;
      }
      if (my_strcmp(str, "repair") == 0)
      {
	system_repair(ship);
      }
      if (my_strcmp(str, "control") == 0)
      {
	system_control(ship);
      }
  }
  free(ship->my_weapon->system_state);
  free(ship->my_drive->system_state);
  free(ship->my_navigation->system_state);
  get_bonus(ship);
  free(ship->my_navigation);
  free(ship->my_drive);
  free(ship->my_weapon);
  free(ship->my_container);
  free(ship);
  return (0);
}
