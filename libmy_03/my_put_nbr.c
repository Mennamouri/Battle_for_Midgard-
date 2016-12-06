/*
** my_put_nbr.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Oct 24 09:10:31 2016 ENNAMOURI Maryem
** Last update Wed Nov  9 17:53:03 2016 ENNAMOURI Maryem
*/

void	my_putchar(char c);

void	my_putstr(char *str);

void	my_put_nbr(int n)
{
  char	c;
  if (n < 0)
  {
    n = n * (-1);
    my_putchar('-');
  }
  if (n > 9)
  {
    my_put_nbr(n / 10);
    my_put_nbr(n % 10);
  }
  else if ((unsigned int)n == -2147483648u)
  {
    my_putstr("2147483648");
  }
  else
  {
  c = (char)n + '0';
  my_putchar(c);
  }
}
