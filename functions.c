/*
** functions.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Wed Dec  7 10:03:10 2016 ENNAMOURI Maryem
** Last update Wed Dec  7 23:11:59 2016 DE PADUA Cesare
*/

#include "bfm.h"
#include <stdlib.h>

t_player          *create_player(char *name)
{
  t_player        *player;

  my_putstr_color("green", "initialisation du joueur en cours...\n");
  player = malloc(sizeof(t_player));
  if (player == NULL)
    {
      my_putstr_color("yellow", "l'initialisation du jouer a échoué :/ !!\n");
    }
  player->name = name;
  player->inventory = NULL;
  player->team = NULL;
   my_putstr_color("blue", "joueur initialiser!\n");
  return (player);
}

int             add_inventory(t_player *player)
{
  t_inventory   *inventory;

  my_putstr_color("green", "l'ajout de  l'inventory en cours ...\n");
  inventory = malloc(sizeof(t_inventory));
  if (inventory == NULL)
    {
      my_putstr_color("yellow", "l'ajout de l'inventory a échoué :/ !!\n");
      return (0);
    }
  inventory->magicbox = 5;
  inventory->rupees = 420;
  inventory->muchrooms = 0;
  player->inventory = inventory;
  my_putstr_color("blue", "l'inventory à bien été rajouté!\n");
  return (1);
}

int add_container_to_player(t_player *player)
{
  t_container	*container;

  my_putstr_color("blue", "Adding team in progress...\n");
  container = malloc(sizeof(*container));
  if (container == NULL)
  {
    my_putstr_color("red", "Error while adding team, please restart the game\n");
    return (0);
  }
  container->first = NULL;
  container->last = NULL;
  container->nb_monsters = 0;
  player->team = container;
  my_putstr_color("green", "Team has been added succesfully\n");
  return (1);
}
