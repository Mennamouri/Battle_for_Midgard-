/*
** functions.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Wed Dec  7 10:03:10 2016 ENNAMOURI Maryem
** Last update Wed Dec  7 10:40:57 2016 ENNAMOURI Maryem
*/

#include "BFM.h"

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
  player->monsters = NULL;
   my_putstr_color("blue", "joueur initialiser!\n");
  return (ship);
}

int             add_inventory(t_player *player)
{
  t_inventory   *inventory;

  my_putstr_color("green", "l'ajout de  l'inventory en cours ...\n");
  the_inventory = malloc(sizeof(t_inventory));
  if (inventory == NULL)
    {
      my_putstr_color("yellow", "l'ajout de l'inventory a échoué :/ !!\n");
      return (0);
    }
  inventory->magicbox = 5;
  inventory->rupees = 420;
  inventory->machrooms = 0;
  my_putstr_color("blue", "l'inventory à bien été rajouté!\n");
  return (1);
}
