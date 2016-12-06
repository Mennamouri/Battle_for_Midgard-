/*
** BFM.h for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem & DE PADUA Cesare
** Login   <ennamo_m@etna-alternance.net>  <depadu_c@etna-alternance.net>
** 
** Started on  Tue Dec  6 12:01:24 2016 ENNAMOURI Maryem
** Last update Tue Dec  6 15:56:12 2016 ENNAMOURI Maryem
*/

#ifndef	_BFM_H
#define _BFM_H

typedef	struct	s_monster
{
  char *name;
  int	PV;
  int	PM;
}		t_monster;

typedef	struct	s_inventory
{
  int	magicbox;
  int	rupees;
  int	muchrooms;
}		t_inventory;

typedef	struct	s_player
{
  char *name;
  t_monster*	monsters;
  t_inventory	inventory;
}		t_player;


typedef	struct	s_oob
{
  char *commande;
  int (*function)(t_player*);
}		t_command_oob;

typedef	struct	s_ib
{
  char *commande;
  int (*function)(t_player*, t_monster*);
}		t_command_ib;

void my_putstr(char *str);
int my_strcmp(char *str1, char *str2);
#endif
