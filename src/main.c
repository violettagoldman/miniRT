#include "../rt.h"

int main(int argc, char **argv)
{
	(void)argc;
	t_rt rt;

	//if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
	//	return (-1);
	init(&rt);
	parse(argv[1], &rt);
	check_parse(rt);
	smth(&rt);
    return (0);
}

/*
int	main(int argc, char **argv)
{
	(void)argc;
	t_rt rt;
	
	init(&rt);
	parse(argv[1], &rt);
	printf("R: x = %d, y = %d\nA: range = %f, r = %d, g = %d, b = %d\n",
			rt.res.x, rt.res.y, rt.amb.range, rt.amb.col.r, rt.amb.col.g, rt.amb.col.b);
	while (rt.c)
	{
		printf("c: vec: %f, %f, %f, norm: %f, %f, %f, fov = %f\n", rt.c->vec.x, rt.c->vec.y, rt.c->vec.z, rt.c->norm.x, rt.c->norm.y, rt.c->norm.z, rt.c->fov);
			rt.c = rt.c->next;
	}
	while (rt.l)
	{
		printf("l: vec: %f, %f, %f, col: %d, %d, %d, brightness = %f\n", 
			rt.l->vec.x, rt.l->vec.y, rt.l->vec.z, rt.l->col.r, rt.l->col.g, 
			rt.l->col.b, rt.l->bright);
		rt.l = rt.l->next;
	}
	while (rt.obj)
	{
		if (rt.obj->type == 0)
		{
			printf("sp: vec: %f, %f, %f, col: %d, %d, %d, rayon = %f\n",
				rt.obj->sh.sp.c.x, rt.obj->sh.sp.c.y, rt.obj->sh.sp.c.z,
				rt.obj->sh.sp.col.r, rt.obj->sh.sp.col.g, rt.obj->sh.sp.col.b,
				rt.obj->sh.sp.r);
		}
		else if (rt.obj->type == 1)
		{
			printf("pl: vec: %f, %f, %f, col: %d, %d, %d, norm = %f, %f, %f\n",
				rt.obj->sh.pl.vec.x, rt.obj->sh.pl.vec.y, rt.obj->sh.pl.vec.z,
				rt.obj->sh.pl.col.r, rt.obj->sh.pl.col.g, rt.obj->sh.pl.col.b,
				rt.obj->sh.pl.norm.x, rt.obj->sh.pl.norm.y, rt.obj->sh.pl.norm.z);
		}
		else if (rt.obj->type == 2)
		{
			printf("sq: vec: %f, %f, %f, col: %d, %d, %d, norm = %f, %f, %f, size = %f\n",
				rt.obj->sh.sq.vec.x, rt.obj->sh.sq.vec.y, rt.obj->sh.sq.vec.z,
				rt.obj->sh.sq.col.r, rt.obj->sh.sq.col.g, rt.obj->sh.sq.col.b,
				rt.obj->sh.sq.norm.x, rt.obj->sh.sq.norm.y, rt.obj->sh.sq.norm.z,
				rt.obj->sh.sq.size);
		}
		else if (rt.obj->type == 3)
		{
			printf("cy: vec: %f, %f, %f, col: %d, %d, %d, norm = %f, %f, %f, diam = %f, h = %f\n",
				rt.obj->sh.cy.vec.x, rt.obj->sh.cy.vec.y, rt.obj->sh.cy.vec.z,
				rt.obj->sh.cy.col.r, rt.obj->sh.cy.col.g, rt.obj->sh.cy.col.b,
				rt.obj->sh.cy.norm.x, rt.obj->sh.cy.norm.y, rt.obj->sh.cy.norm.z,
				rt.obj->sh.cy.d, rt.obj->sh.cy.h);
		}
		else if (rt.obj->type == 4)
		{
			printf("tr: 1: %f, %f, %f, 2 = %f, %f, %f, 3 = %f, %f, %f, col = %d, %d, %d\n",
				rt.obj->sh.tr.first.x, rt.obj->sh.tr.first.y, rt.obj->sh.tr.first.z,
				rt.obj->sh.tr.second.x, rt.obj->sh.tr.second.y, rt.obj->sh.tr.second.z,
				rt.obj->sh.tr.third.x, rt.obj->sh.tr.third.y, rt.obj->sh.tr.third.z,
				rt.obj->sh.tr.col.r, rt.obj->sh.tr.col.g, rt.obj->sh.tr.col.b);
		}
		rt.obj = rt.obj->next;
	}
	check_parse(rt);
	
}*/
