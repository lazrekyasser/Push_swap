/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:02:46 by yasser            #+#    #+#             */
/*   Updated: 2021/06/26 19:56:43 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFFER_SIZE 1

typedef enum e_type
{
	NONE,
	SA,
	SB
}			t_type;

typedef struct s_stack
{
	t_list			*chunk;
	t_list			*chunk_size;
	t_type			type_swap;
	unsigned int	size;
	t_list			*node;
	int				*pivot;
}				t_stack;

void	stack_new(t_stack *stack);
void	init_stackb(t_stack *b);
void	stack_clear(t_stack *c);
void	clear_stacks(t_stack *a, t_stack *b);
void	stack_show(t_stack *a);
void	stack_addback(t_stack *a, int val);
int		stack_dupl(t_stack *a);
int		ft_duplc(char **s);
int		ft_strcmp(char *s1, char *s2);
int		is_num(char *s);
int		ft_compaire(char *s, char *n);
int		ft_lentab(char **s);
void	affiche_tab(char **s);
int		check_arg(char **av);
int		check_arg2(char **splt_av, int *j);
void	free_tab(char **tab);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
int		sort_stack2(t_stack *stack_a, t_stack *stack_b, int size_b,
			int s_chunk_a);
int		handle_upper_chunk_b(t_stack *stack_a, t_stack *stack_b);
void	push_greater_pivot_to_a(t_stack *a, t_stack *b, int rot,
			int *s_chunk_a);
void	push_less_pivot_to_b(t_stack *a, t_stack *b, int *p_c, int *s_chunk_a);
int		push_a_to_b(t_stack *stack_a, t_stack *stack_b);
int		total_chunks(t_stack *stack);
int		*get_closestless(t_stack *stack, int pivot);
int		get_closestless2(int *tab, int size, int pivot, int type);
int		check_greater_pivot(t_list *lst, int pivot);
int		check_less_pivot(t_list *lst, int pivot);
int		*get_pivot(t_list *lst);
int		is_desc(t_list *lst);
void	get_chunk(t_stack *stack, int size);
void	get_chunk_a(t_stack *stack, int size);
int		*list_to_tab(t_list *lst);
int		*alloc_size(int size);
void	quicksort(int arr[], int low, int high);
void	exec_ins(char *line, t_stack *stack_a, t_stack *stack_b);
void	check_ins(char *line, t_stack *stack_a, t_stack *stack_b);
int		check_sorted(t_stack *stack_a);
t_stack	*copy_stack(t_stack *stack);
void	deletefirstnode(t_list **lst);
int		free_exit(char **splt_av);
int		cas_pos(char *s, int *i, int *cnt_digit, int *plus);
int		cas_neg(char *s, int *i, int *cnt_digit);
void	greater_to_a(t_stack *stack_a, t_stack *stack_b, int *push_count,
			int *s_chunk_a);
void	add_push_to_b(t_stack *stack_a, t_stack *stack_b, int *push_count,
			int *push_c);
int		work_a(t_stack *stack_a, t_stack *stack_b, int *push_count,
			int *s_chunk_a);
int		nor_handle_up(t_stack *stack_a, t_stack *stack_b, int size_b);
void	check_rot(t_stack *stack_a, t_stack *stack_b);
void	r_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
void	raise_error(t_list *node, char **tab);
void	print_error(char *er, t_stack *a, t_stack *b);
void	sort_stack3(t_stack *a, t_stack *b);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		index_of(char *s, char c);
int		cas_null(char **str);
void	free_err(t_stack *a, t_stack *b);

#endif