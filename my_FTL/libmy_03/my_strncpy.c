/*
** my_strncpy.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Fri Oct 21 12:29:07 2016 ENNAMOURI Maryem
** Last update Thu Oct 27 14:30:29 2016 ENNAMOURI Maryem
*/

void	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n)
  {
    if (src[i] == '\0')
    {
      dest[i] = '\0';
    }
    dest[i] = src[i];
    i++;
  }
  if (*dest != '\0')
  {
      return (dest);
  }  
  dest[i] = '\0';
  return (dest);
}
