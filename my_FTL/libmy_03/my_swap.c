/*
** my_swap.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Thu Oct 20 12:16:47 2016 ENNAMOURI Maryem
** Last update Thu Oct 20 20:23:15 2016 ENNAMOURI Maryem
*/

void	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
