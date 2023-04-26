#include "miniRT.h"

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
