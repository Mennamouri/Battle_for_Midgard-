/*
** main.c for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Tue Dec  6 12:27:18 2016 ENNAMOURI Maryem
** Last update Wed Dec  7 14:48:23 2016 DE PADUA Cesare
*/

#include <stdlib.h>
#include <time.h>
#include "bfm.h"

int game(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  srand (time(NULL));
  game(argc, argv);
  return (0);
}
