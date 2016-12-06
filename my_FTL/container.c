/*
** container.c for q in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Tue Nov  8 11:41:18 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:48:03 2016 ENNAMOURI Maryem
*/

#include "ftl.h"
#include <stdlib.h>

int	add_container_to_ship(t_ship *the_ship)
{
  t_container	*the_container;
  my_putstr_color("green", "ajout du container en cours...\n");
  the_container = malloc(sizeof(t_container));
  if (the_container == NULL)
  {
    my_putstr_color("yellow", "votre vaisseau a explosé quand vous avez pose le container\n");
    return (0);
  }
  the_container->first = NULL;
  the_container->nb_elem = 0;
  the_container->last = NULL;
  the_ship->my_container = the_container;
  my_putstr_color("blue", "le container a été ajoutés avec succes!\n");
  return (1);
}

void	add_freight_to_container	(t_ship *the_ship, t_freight *the_freight)
{
  if (the_ship->my_container->last != NULL)
  {
    my_putstr(the_freight->item);
    my_putchar('\n');
    the_freight->next = NULL;
    the_freight->prev = the_ship->my_container->last;
    the_ship->my_container->last->next = the_freight;
    the_ship->my_container->last = the_freight;
  }
  else
  {
    the_freight->prev = NULL;
    the_freight->next = NULL;
    the_ship->my_container->last = the_freight;
    the_ship->my_container->first = the_freight;
  }
   the_ship->my_container->nb_elem++;
}

void	del_freight_from_container	(t_ship *the_ship, t_freight *the_freight)
{
  if (the_freight != NULL)
  {
    if (the_ship->my_container->last == the_freight)
    {
      if (the_freight->prev == NULL)
      {
	the_ship->my_container->last = NULL;
	the_ship->my_container->first = NULL;
      }
      else
      {
	the_ship->my_container->last = the_freight->prev;
	the_ship->my_container->last->next = NULL;
      }
    }
    else if (the_ship->my_container->first == the_freight)
    {
      the_ship->my_container->first = the_freight->next;
      the_ship->my_container->first->prev = NULL;
    }
    else if (the_ship->my_container->first != the_freight && the_ship->my_container)
    {
      the_freight->next->prev = the_freight->prev;
      the_freight->prev->next = the_freight->next;
    }
    the_ship->my_container->nb_elem--;
    free(the_freight->item);
    free(the_freight);
  }
}

void	get_bonus	(t_ship *the_ship)
{
  t_freight *temp;

  temp = the_ship->my_container->first;
  while (temp != NULL)
  {
    if (my_strcmp(temp->item, "attackbonus") == 0)
    {
      the_ship->my_weapon->damage =  the_ship->my_weapon->damage + 5; 
    }
    else if (my_strcmp(temp->item, "evadebonus") == 0)
    {
      the_ship->my_navigation->evade = the_ship->my_navigation->evade + 3;
    }
    else if (my_strcmp(temp->item, "energy") == 0)
    {
      the_ship->my_drive->energy++;
    }
    if (temp->next == NULL)
    {
      del_freight_from_container(the_ship, temp);
      temp = NULL;
    }
    else
    {
      temp = temp->next;
    }
  }
}
