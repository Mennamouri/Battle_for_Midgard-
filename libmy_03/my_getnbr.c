/*
** my_getnbr.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Oct 24 10:14:33 2016 ENNAMOURI Maryem
** Last update Thu Oct 27 11:25:52 2016 ENNAMOURI Maryem
*/

void	my_putchar(char c);

int	cast(char c)
{
  int	i;
  i = ((char)c - 48);
  return i;
}

int	my_signe(char c)
{
  int	somme;

  somme = 1;
  if (c == 45)
  {
    somme = somme * (-1); 
  }
  if (c == 43)
  {
    somme = somme * 1;
  }
  return (somme);
}

int	my_getnbr(char *str)
{
  int	somme;
  int	tmp;
  int	result;
  int	j;

  j = 0;
  result = 0;
  somme = 1;
  while (str[j] == '-' || str[j] == '+')
  {
    if (my_signe(str[j]) == (-1))
    {
      somme = somme * (-1);
    }
    j++;
  }
  while (str[j] >= 48 && str[j] <= 57)
  {
    tmp = cast(str[j]);
    result = (result * 10) + tmp;
    j++;
  }
  result = result * somme;
  return (result);
}
