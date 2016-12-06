/*
** my_strncmp.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Fri Oct 21 15:32:48 2016 ENNAMOURI Maryem
** Last update Fri Oct 21 16:08:10 2016 ENNAMOURI Maryem
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] >= '\0' || s2[i] >= '\0') && i < n)
  {
    if (s1[i] < s2[i])
    {
      return (-1);
    }
    else if (s1[i] > s2[i])
    {
      return (1);
    }
    i++;
  }
  return (0);
}
