/*
** ftl.h for  in /home/maryem/Piscine/Projet_Final_C/my_FTL
** 
** Made by ENNAMOURI Maryem
** Login   <ennamo_m@etna-alternance.net>
** 
** Started on  Mon Nov  7 11:18:16 2016 ENNAMOURI Maryem
** Last update Sat Nov 12 12:44:16 2016 ENNAMOURI Maryem
*/

#ifndef	_FTL_H
#define _FTL_H

typedef	struct	s_freight
{
  char *item;
  struct s_freight *next;
  struct s_freight *prev;
}		t_freight;

typedef struct	s_container
{
  char	*item;
  struct s_freight *first;
  struct s_freight *last;
  int	nb_elem;
}		t_container;

typedef struct	s_navigation_tools
{
  char	*system_state;
  int	sector;
  int	evade;
}		t_navigation_tools;

typedef	struct	s_ftl_drive
{
  char	*system_state;
  int	energy;
}		t_ftl_drive;

typedef	struct	s_weapon
{
  char	*system_state;
  int	damage;
}		t_weapon;

typedef	struct	s_ship
{
  int hull;
  t_weapon	*my_weapon;
  t_ftl_drive	*my_drive;
  t_navigation_tools	*my_navigation;
  t_container	*my_container;
}		t_ship;

typedef	struct	s_repair_command
{
  char *repair;
  int (*function)(t_ship*);
}		t_repair_command;

typedef	struct	s_ennemi
{
  int	point_vie;
  int	damage;
}		t_ennemi;

#endif

void	my_putstr(char *str);
void	my_putchar(char c);
int	my_strcmp(char *s1, char*s2);
void	my_putstr_color(const char *color, const char *str);
int	add_container_to_ship(t_ship *the_ship);
void	*my_strdup(char *str);
char	*readline(void);	
t_ship	*create_ship();
void	create_ennemi();
int	add_weapon_to_ship(t_ship *ship);
int	add_ftl_drive_to_ship(t_ship *ship);
int	add_navigation_tools_to_ship(t_ship *ship);
int	add_container_to_ship(t_ship *ship);
int	system_repair(t_ship *ship);
void	my_put_nbr(int nb);
int	detect_game(t_ship *ship);
void	get_bonus(t_ship *the_ship);
void	add_freight_to_container(t_ship *ship, t_freight *the_freight);
void	attack_ennemi(t_ship *ship);
void    my_ftl_draw();
void    help_game();
void    stat_game(t_ship *the_ship);
void    jump_game(t_ship *the_ship);
int     detect_game(t_ship *ship);
void	system_control(t_ship *the_ship);
