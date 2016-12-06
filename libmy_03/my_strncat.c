/*
** my_strncat.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Fri Oct 21 16:53:46 2016 ENNAMOURI Maryem
** Last update Fri Oct 21 17:21:10 2016 ENNAMOURI Maryem
*/

char	*my_strncat(char *dest, char *src, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
  {
    i++;
  }
  while (j < n)
  {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  return (dest);
}
