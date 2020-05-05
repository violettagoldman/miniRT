#include "../rt.h"

int		threads_init(t_rt *rt)
{
	pthread_t		threads[16];
	t_test			x[16];
	int				i;

	i = -1;
	while (++i < 16)
	{
		x[i].x = i;
		x[i].rt = rt;
	}
	i = -1;
	while (++i < 16)
		pthread_create(&threads[i], NULL, &render, (void *)&x[i]);
	i = -1;
	while (++i < 16)
		pthread_join(threads[i], NULL);
	return (1);
}
