
#include <unistd.h>


void	ft_putchar(char c)
{

	write(1, &c, 1);

}

void	prt_fisrtline(int x, char *a)
{

	int	nowx;

	nowx = 0;

	while (nowx < x)
	{

		if (nowx == 0)

			ft_putchar(a[0]);

		else if (nowx == x - 1)

			ft_putchar(a[2]);

		else

			ft_putchar(a[1]);

		nowx++;

	}

	ft_putchar('\n');

}

​

void prt_midline(int x, int y, char *a){

	int	nowx;

	int	nowy;

​

	nowy = 0;

	while (nowy < y - 2)
	{

		nowx = 0;

		while (nowx < x)
		{

			if (nowx == 0 || nowx == x - 1)

				ft_putchar(a[1]);

			else

				ft_putchar(' ');

			nowx++;

		}

		ft_putchar('\n');

		nowy++;

	}

}

​

void	prt_lastline(int x, char *a)
{

	int	nowx;
​
	nowx = 0;

	while (nowx < x)
	{

		if (nowx == 0)

			ft_putchar(a[2]);

		else if (nowx == x - 1)

			ft_putchar(a[0]);

		else

			ft_putchar(a[1]);

		nowx++;

	}

	ft_putchar('\n');

}

​

void	rush(int x, int y)
{

	char	a[3];

​

	a[0] = '/';

	a[1] = '*';

	a[2] = '\\';

​

	prt_fisrtline(x, a);

	prt_midline(x, y, a);

	prt_lastline(x, a);

}

​

int	main()
{

	rush(5, 5);

	return 0;

}

