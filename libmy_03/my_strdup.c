/*
** my_strdup.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Oct 24 19:50:22 2016 ENNAMOURI Maryem
** Last update Thu Oct 27 11:39:09 2016 ENNAMOURI Maryem
*/

#include<stdlib.h>

int	my_strlen(char *str);

char	*my_strdup(char *str)
{
  int	i;
  char	*copy;

  i = 0;
  copy = malloc(sizeof(*str) * (my_strlen(str) + 1));
  while (str[i] != '\0')
  {
    copy[i] = str[i];
    i++;
  }
  return copy;
}
