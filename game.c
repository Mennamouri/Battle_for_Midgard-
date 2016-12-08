/*
** game.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Tue Dec  6 13:55:06 2016 ENNAMOURI Maryem
** Last update Wed Dec  7 22:14:03 2016 DE PADUA Cesare
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
  my_bfm_draw();
  player = create_player(argv[3]);
  add_inventory(player);
  add_container_to_player(player);
  get_instruction_for_oob(player);
  return 0;
}
