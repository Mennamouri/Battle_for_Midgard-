/*
** my_strlen.c for  in /home/projet/CHIFUMI/libmy_03
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Thu Oct 20 11:20:09 2016 ENNAMOURI Maryem
** Last update Thu Oct 20 20:11:33 2016 ENNAMOURI Maryem
*/

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (*str != '\0')
  {
    counter++;
    str++;
  }
  return (counter);
}
