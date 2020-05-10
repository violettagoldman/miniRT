#include "../rt.h"

void	make_header(int fd, int w, int h)
{
	static unsigned char	header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, \
		0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};
	unsigned int			*sizeoffileentry;
	unsigned int			*widthentry;
	unsigned int			*heightentry;

	sizeoffileentry = (unsigned int *)&header[2];
	*sizeoffileentry = 54 + (w * sizeof(char) + (4 - \
						((w * sizeof(char)) % 4)) % 4) * h;
	widthentry = (unsigned int *)&header[18];
	*widthentry = w;
	heightentry = (unsigned int *)&header[22];
	*heightentry = h;
	write(fd, header, 54);
}

void	writedata(int w, int h, char **img_data, int fd)
{
	char					*ro;
	int						i;
	int						ln;
	static unsigned char	zeroes[3] = {0, 0, 0};

	ln = 0;
	i = 0;
	ro = (char *)malloc(sizeof(char) * (w * 4 * h + 1));
	while (ln++ < w)
	{
		(*img_data)--;
		*ro++ = *(*img_data)--;
		*ro++ = *(*img_data)--;
		*ro++ = *(*img_data)--;
	}
	ro--;
	while (i++ < w)
	{
		write(fd, ro--, sizeof(char));
		write(fd, ro--, sizeof(char));
		write(fd, ro--, sizeof(char));
	}
	write(fd, zeroes, (4 - ((w * sizeof(char)) % 4)) % 4);
	free(++ro);
}

int		writebmp(int w, int h, char *img_data)
{
	int				fd;
	int				row;

	img_data--;
	row = 0;
	fd = open("save_image.bmp", O_WRONLY | O_CREAT | O_TRUNC, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	make_header(fd, w, h);
	while (row++ < h)
		writedata(w, h, &img_data, fd);
	close(fd);
	return (0);
}
