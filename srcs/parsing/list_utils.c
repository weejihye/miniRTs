#include "miniRT.h"

int	remove_list(t_obj **objs)
{
	t_obj	*temp;

	while (*objs)
	{
		temp = (*objs)->next;
		free((*objs)->p_obj);
		free(*objs);
		*objs = temp;
	}
	return (1);
}

int	remove_first_node(t_obj **objs)
{
	t_obj	*temp;

	temp = (*objs)->next;
	free((*objs)->p_obj);
	(*objs)->p_obj = NULL;
	free(*objs);
	*objs = temp;
	return (1);
}

void	*find_obj(t_obj *objs, enum e_type type)
{
	while (objs && objs->type != type)
		objs = objs->next;
	return (objs);
}

void	*ft_lstnew_obj(t_obj **objs, void *content, int type)
{
	t_obj	*new;

	if (!content)
		return (NULL);
	new = malloc(sizeof(t_obj));
	if (!new)
	{
		free(content);
		return (NULL);
	}
	new->p_obj = content;
	new->type = type;
	new->next = *objs;
	*objs = new;
	return (new);
}
