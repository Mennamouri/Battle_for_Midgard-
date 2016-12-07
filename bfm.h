/*
** BFM.h for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem & DE PADUA Cesare
** Login   <ennamo_m@etna-alternance.net>  <depadu_c@etna-alternance.net>
** 
** Started on  Tue Dec  6 12:01:24 2016 ENNAMOURI Maryem
** Last update Wed Dec  7 11:08:22 2016 ENNAMOURI Maryem
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

void    my_putstr(char *str);
void    my_putchar(char c);
int     my_strcmp(char *s1, char*s2);
void    my_putstr_color(const char *color, const char *str);
void    *my_strdup(char *str);
char    *readline(void);
void    my_put_nbr(int nb);

/***************************************************/
int	game(int argc, char *argv[]);
t_player	*create_player(char *name);
int             add_inventory(t_player *player);
void    my_bfm_draw();
void    help_game_oob();
void    help_game_ib();
void    stat_game(t_ship *the_ship);
int	show_team(t_player *player);
int	the_chosen_one(t_player *player);
int	start_fight(t_player *player);
int	get_instruction_for_oob(t_player *player);

#endif
