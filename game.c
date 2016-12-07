/*
** game.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Tue Dec  6 13:55:06 2016 ENNAMOURI Maryem
** Last update Wed Dec  7 11:09:50 2016 ENNAMOURI Maryem
*/

#include "bfm.h"

int game(int argc, char *argv[] ) 
{
  t_player *player;
  
  if(argc != 3)
  {
    my_putstr("the program must  be launched in the following way:\n./sta -n NAME\n");
    return 1;
  }
  if(my_strcmp(argv[1],"-n") != 0)
  {
    my_putstr("the program must  be launched in the following way:\n./sta -n NAME\n");
    return 1;
  }
  player = create_player(argv[3]);
  add_inventory(player);
  return 0;
}
