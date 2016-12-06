/*
** my_strcat.c for  /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Fri Oct 21 15:19:21 2016 ENNAMOURI Maryem
** Last update Fri Oct 21 16:50:05 2016 ENNAMOURI Maryem
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
  {
    i++;
  }
  while (src[j] != '\0')
  {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  return (dest);
}
