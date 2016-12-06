/*
** my_str_to_wordtab.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Oct 24 20:28:45 2016 ENNAMOURI Maryem
** Last update Thu Oct 27 12:17:27 2016 ENNAMOURI Maryem
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src, int n);

int	my_alphanum(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c >= 90))
    {
      return (1);
    }
    if ((c >= 97) && (c <= 122))
    {
      return (1);
    }
    return (0);
}

int	nb_word(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
  {
    if (my_alphanum(str[i]) && !my_alphanum(str[i + 1]))
    {
      nb++;
    }
    i++;
  }
  return (nb);
}

char	**my_str_to_wordtab(char *str)
{
  char	**copy;
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  copy = malloc(sizeof(*str) * ((nb_word(str)) + 1));
  while(*str != '\0')
  {
    nb = 0;
    while ((my_alphanum(*str) == 1) && *str != '\0')
    {
      nb++;
      str++;
    }
    if (nb != 0)
    {
    copy[i] = malloc(sizeof(*str) * (nb + 1));
    str = str - nb;
    copy[i] = my_strcpy(copy[i], str, (nb - 1));
    }
    str = (str + nb) + 1;
  }
  copy[i] = NULL;
  return (copy);
}
