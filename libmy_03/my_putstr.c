/*
** my_putstr.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Thu Oct 20 10:04:49 2016 ENNAMOURI Maryem
** Last update Thu Oct 20 20:19:51 2016 ENNAMOURI Maryem
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  while (*str != '\0')
  {
    my_putchar(*str);
    str = str + 1;
  }
}
