#include "header.h"


void	ft_path_elem_free(t_path *path)
{
	if (path)
	{
		free(path->name);
		free(path);
	}
}

void	ft_path_free(t_path *path)
{
	t_path *buf;

	while (path)
	{
		buf = path->next;
		ft_path_elem_free(path);
		path = buf;
	}
}

void	ft_path_create(t_path **path, char *str)
{
	*path = malloc(sizeof(t_path));
	(*path)->name = ft_strcpy(str);
	(*path)->next = 0;
}

t_path	*ft_path_init(char *str)
{
	char **names;
	t_path *last;
	t_path *path;

	names = ft_split_str(str, "/");
	last = 0;
	while (*names)
	{
		ft_path_create(&path, *names++);
		path->next = last;
		last = path;
	}
	// free(names);//?
	return (path);
}

t_path	*ft_path_get_last(t_path *path)
{
	if (!(path->next)) return (path);
	return (ft_path_get_last(path->next));
}

void	ft_path_clear(t_path **path)
{
	int		minus_path;
	t_path	*now;
	t_path	*last;
	t_path	*buf;

	last = 0;
	now = *path;
	minus_path = 0;
	while (now)
	{
		if (ft_strcmp(now->name, ".") && now->next)
		{
			if (last) last->next = now->next;
			else *path = now->next;
		}
		else if (ft_strcmp(now->name, "..") && now->next)
		{
			if (last)
			{
				last->next = now->next;
			}
			else *path = now->next;
			minus_path--;
		}
		else if (minus_path < 0)
		{
			if (last) last->next = now->next;
			else *path = now->next;
			minus_path++;
		}
		else
		{
			last = now;
			now = now->next;
			continue ;
		}
		buf = now;
		now = now->next;
		ft_path_elem_free(buf);
	}
}

t_path	*ft_path_copy(t_path *src)
{
	t_path *trg;
	t_path *now;
	t_path *last;

	trg = 0;
	while (src)
	{
		now = malloc(sizeof(t_path));
		now->name = ft_strcpy(src->name);
		now->next = 0;
		if (!trg) trg = now;
		else last->next = now;
		last = now;
		src = src->next;
	}
	return (trg);
}

t_path	*ft_path_concat(t_path *old, t_path *new)
{
	t_path *last_elem;

	old = ft_path_copy(old);
	new = ft_path_copy(new);
	last_elem = ft_path_get_last(new);
	last_elem->next = old;
	ft_path_clear(&new);
	return (new);
}

t_path	*ft_path_concat_ps(t_path *old, char *new)
{
	t_path *new_path;
	t_path *result;

	new_path = ft_path_init(new);
	result = ft_path_concat(old, new_path);
	ft_path_free(new_path);
	return (result);
}

t_path	*ft_path_concat_ss(char *old, char *new)
{
	t_path *old_path;
	t_path *new_path;
	t_path *result;

	old_path = ft_path_init(old);
	new_path = ft_path_init(new);
	result = ft_path_concat(old_path, new_path);
	ft_path_free(old_path);
	ft_path_free(new_path);
	return (result);
}

char	*ft_path_get_str_rec(t_path *path)
{
	char *callback;
	char *result;
	if (path->next)
	{
		callback = ft_path_get_str_rec(path->next);
		result = ft_concat_str(3, callback, "/", ft_strcpy(path->name));
		free(callback);
		return (result);
	}
	else return ft_strcpy(path->name);
}

char	*ft_path_get_str(t_path *path)
{
	char *result;
	// char *call;

	if (path)
	{
		result = ft_path_get_str_rec(path);
		// result = ft_concat_str(3, "\"", call, "\"");
		// free(call);
		return (result);
	}
	return (ft_strcpy("None"));
}

char	*ft_path_get_str_with_str(t_path *path, char *str_path)
{
	t_path *other_path;
	char *result;

	other_path = ft_path_init(str_path);
	path = ft_path_concat(path, other_path);
	result = ft_path_get_str(path);
	ft_path_free(other_path);
	ft_path_free(path);
	return (result);
}