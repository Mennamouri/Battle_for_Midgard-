/*
** strstr.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Wed Oct 26 11:29:11 2016 ENNAMOURI Maryem
** Last update Wed Nov  9 17:54:14 2016 ENNAMOURI Maryem
*/

#include <stdlib.h>

int	my_strncmp(char *s1, char *s2, int n);

int	my_strlen(char *str);

char	*my_strstr(char *str, char *to_find)
{
  int size;

  size = my_strlen(to_find);

  if (*to_find == 0)
  {
    return NULL;
  }
  while (*str != '\0')
  {
    if (my_strncmp(str, to_find, size) != 0)
    {
      str++;
    }
    else
    {
      return (str);
    }
  }
  return NULL;
}
