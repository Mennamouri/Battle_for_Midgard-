/*
** BFM.h for  in /home/maryem/projet_C
** 
** Made by ENNAMOURI Maryem & DE PADUA Cesare
** Login   <ennamo_m@etna-alternance.net>  <depadu_c@etna-alternance.net>
** 
** Started on  Tue Dec  6 12:01:24 2016 ENNAMOURI Maryem
** Last update Fri Dec  9 03:42:27 2016 DE PADUA Cesare
** Last update Thu Dec  8 21:52:56 2016 DE PADUA Cesare
** Last update Thu Dec  8 12:35:56 2016 DE PADUA Cesare
** Last update Thu Dec  8 12:34:14 2016 ENNAMOURI Maryem
*/

#ifndef	_BFM_H
#define _BFM_H

typedef struct  s_creature
{
  char          *name;
  int           lvl;
  int           pv;
  int           pvmax;
  int           pm;
  int           pmmax;
}               t_creature;

typedef	struct	s_monster
{
  t_creature		*creature;
  struct s_monster	*prev;
  struct s_monster	*next;
}		t_monster;

typedef struct	s_container
{
  t_monster	*selected;
  t_monster	*first;
  t_monster	*last;
  int		nb_monsters;
}		t_container;

typedef	struct	s_inventory
{
  int	magicbox;
  int	rupees;
  int	mushrooms;
}		t_inventory;

typedef	struct	s_player
{
  char		*name;
  t_container	*team;
  t_inventory	*inventory;
}		t_player;


typedef	struct	s_oob
{
  char *commande;
  int (*function)(t_player*);
}		t_command_oob;

typedef	struct	s_ib
{
  char *commande;
  int (*function)(t_creature*, t_player*);
}		t_command_ib;

void    my_putstr(char *str);
void    my_putchar(char c);
int     my_strcmp(char *s1, char*s2);
void    my_putstr_color(const char *color, const char *str);
void    *my_strdup(char *str);
char    *readline(void);
void    my_put_nbr(int nb);
t_creature	*getCreature(void);
void	my_put_nbr(int n);

/***************************************************/
int	game(int argc, char *argv[]);
t_player	*create_player(char *name);
int             add_inventory(t_player *player);
void    my_bfm_draw();
void    help_game_oob();
void    help_game_ib();
void    stat_game();
int	team(t_player *player);
int	the_chosen_one(t_player *player);
int	start_fight(t_player *player);
int	quit(t_player *player);
int	get_instruction_for_oob(t_player *player);
int	magic_catch(t_creature *creature, t_player *player);
int	help_me(t_creature *creature, t_player *player);
int     get_instruction_for_ib(t_player *player, t_creature *creature);
int	add_container_to_player(t_player *player);
void    add_creature_to_container(t_player *player, t_monster *monster);
void	show_monster_stats(t_creature creature);
int	slash(t_creature *creature, t_player *player);
int	fire(t_creature *creature, t_player *player);
int	gamble(t_creature *creature, t_player *player);
int	rest(t_creature *creature, t_player *player);
int     select_attack_for_monster(t_player *player, t_creature *creature);
int slash_ennemy(t_creature *creature, t_player *player);
int fire_ennemy(t_creature *creature, t_player *player);
int rest_ennemy(t_creature *creature, t_player *player);
int gamble_ennemy(t_creature *creature, t_player *player);  
void remove_monster_from_list(t_player *player, t_monster *monster);
int buy_magic_box(t_player *player);
int buy_mushrooms(t_player *player);
int use_mushroom(t_player *player);
#endif
  
