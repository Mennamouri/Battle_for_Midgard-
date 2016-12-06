/*
** my_putchar.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Oct 17 12:56:04 2016 ENNAMOURI Maryem
** Last update Mon Oct 17 14:06:21 2016 ENNAMOURI Maryem
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
