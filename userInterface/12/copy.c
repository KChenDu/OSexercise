#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char**argv)
{
	if (argc != 3)
	{
		printf("usage: copy src dst\n");
		return -1;
	}
	int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
	char buf[8192];
	int src = open(argv[1], O_RDONLY), n;
	while ((n = read(src, buf, 8192)) > 0)
		if (write(dst, buf, n) != n)
			printf("write error!\n");
	if (n < 0)
		printf("read error!\n");
	close(src);
	close(dst);
	return 0;
}
