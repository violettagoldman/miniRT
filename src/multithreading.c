#include "../rt.h"

int		threads_init(t_rt *rt)
{
	pthread_t		threads[THREADS];
	t_args			x[THREADS];
	int				i;
	pthread_attr_t	attr;

	i = -1;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	camera_init(rt);
	while (++i < THREADS)
	{
		x[i].x = i;
		x[i].rt = rt;
	}
	i = -1;
	while (++i < THREADS)
		pthread_create(&threads[i], NULL, &render, (void *)&x[i]);
	i = -1;
	pthread_attr_destroy(&attr);
	while (++i < THREADS)
		pthread_join(threads[i], NULL);
	if (rt->save == 1)
	{
		screenshot(rt);
		program_exited(rt);
	}
	return (1);
}
