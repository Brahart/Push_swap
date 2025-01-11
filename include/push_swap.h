#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	struct s_pile	*prev;
	struct s_pile	*next;
	int				value;
}	t_pile;




# endif
