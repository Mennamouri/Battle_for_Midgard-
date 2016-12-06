/*
** my_strcpy.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Fri Oct 21 11:49:47 2016 ENNAMOURI Maryem
** Last update Fri Oct 21 12:26:21 2016 ENNAMOURI Maryem
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = src[i];
  return (dest);
}
