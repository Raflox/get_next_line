#include "get_next_line.h"

int main()
{
	int	fd;
	char err[] = "FILE ERROR!";
	char *str;

	fd = open("test.txt", O_RDONLY);

	if (fd < 0)
		write(1, err, ft_strlen(err));

	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);

	close(fd);
}