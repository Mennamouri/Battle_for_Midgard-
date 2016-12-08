/*
** readline.c for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Wed Nov  9 15:38:47 2016 ENNAMOURI Maryem
** Last update Wed Nov  9 15:43:12 2016 ENNAMOURI Maryem
*/

#include <stdlib.h>
#include <unistd.h>

char	*readline(void)
{
  ssize_t	ret;
  char	        *buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
  {
    return (NULL);
  }
  if ((ret = read(0, buff, 50)) > 1)
  {
    buff[ret - 1] = '\0';
    return (buff);
  }
  free(buff);
  return (NULL);
}
