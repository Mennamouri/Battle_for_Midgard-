/*
** jeu.c for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Thu Nov 10 17:53:15 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:46:16 2016 ENNAMOURI Maryem
*/

#include "ftl.h"
#include <stdlib.h>
#include <time.h>

void	my_ftl_draw()
{
  my_putchar('\n');
  my_putchar('\n');
  my_putstr_color("red",     "                              ************************************************************\n");
  my_putstr_color("cyan",    "                                             ***************************                  \n");
  my_putstr_color("yellow",  "                                             ***************************                  \n");
  my_putstr_color("red",     "                              ************************************************************\n\n");
  my_putstr_color("cyan",    "                             '##    '## '##   '##           '######## '######## '##       \n");
  my_putstr_color("yellow",  "                              ###  '###   ## '## ::::::::::: ##           ##     ##       \n");
  my_putstr_color("magenta", "                              ####'####    ####  ::::::::::: ##           ##     ##       \n");
  my_putstr_color("cyan",    "                              ## ### ##     ##   ::::::::::: ######       ##     ##       \n");
  my_putstr_color("yellow",  "                              ##  #  ##     ##   ::::::::::: ##           ##     ##       \n");
  my_putstr_color("magenta", "                              ##     ##     ##   ::::::::::: ##           ##     ##       \n");
  my_putstr_color("cyan",    "                              ##     ##     ##   ::#######:: ##           ##     ######## \n\n");
  my_putstr_color("red",     "                              ************************************************************\n");
  my_putstr_color("yellow",  "                                             ***************************                  \n");
  my_putstr_color("cyan",    "                                             ***************************                  \n");
  my_putstr_color("red",     "                              ************************************************************\n\n");
}

void	help_game()
{
  my_putstr_color("green", "############### **MENU_HELP** #####################\n");
  my_putstr_color("red","attack\n");
  my_putstr_color("red","detect\n");
  my_putstr_color("red","getbonus\n");
  my_putstr_color("red","jump\n");
  my_putstr_color("red","stat\n");
  my_putstr_color("red","help\n");
  my_putstr_color("red","exit\n");
  my_putstr_color("red","repair\n");
  my_putstr_color("red","control\n");
  my_putstr_color("green", "############### ************** #####################\n");
}

void	stat_game(t_ship *the_ship)
{
  my_putstr_color("yellow", "############### **STAT_GAME** #####################\n");
  my_putstr_color("magenta","******************YOU*************** : \n");
  my_putstr_color("magenta","Hull : ");
  my_put_nbr(the_ship->hull);
  my_putchar('\n');
  my_putstr_color("magenta","Sector : ");
  my_put_nbr(the_ship->my_navigation->sector);
  my_putchar('\n');
  my_putstr_color("magenta","Evade : ");
  my_put_nbr(the_ship->my_navigation->evade);
  my_putchar('\n');
  my_putstr_color("magenta","Damage : ");
  my_put_nbr(the_ship->my_weapon->damage);
  my_putchar('\n');
  my_putstr_color("magenta","Energy : ");
  my_put_nbr(the_ship->my_drive->energy);
  my_putchar('\n');
  my_putstr_color("yellow", "############### ************** #####################\n");
}
void	jump_game(t_ship *the_ship)
{
  srand (time(NULL));
  the_ship->my_navigation->sector++;
  the_ship->my_drive->energy--;
  if (rand() % 100 < 19)
  {
    create_ennemi();
    my_putstr_color("magenta","l'ennemi a été crée : \n");
  }
}

int	detect_game(t_ship *ship)
{
  t_freight	*the_freight;
  int		i;

  i = 0;
  srand (time(NULL));
  while (i < 10)
  {
    the_freight = malloc(sizeof(*the_freight));
    if (rand() % 100 < 69)
      the_freight->item = my_strdup("scrap");
    else
    {
      if (rand() % 100 > 69 && rand() % 100 < 78)
	the_freight->item = my_strdup("energy");
      else if (rand() % 100 > 78 && rand() % 100 < 88)
	the_freight->item = my_strdup("attackbonus");
      else if (rand() % 100 >88 && rand() % 100 < 98)
	the_freight->item = my_strdup("evadebonus");
      else
	the_freight->item = my_strdup("scrap");
    }
    the_freight->prev = NULL;
    the_freight->next = NULL;
    add_freight_to_container(ship, the_freight);
    i++;
  }
  return (0);
}
