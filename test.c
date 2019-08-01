#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_display(char u, char d, char c)
{
	if (u == 9 && d == 8 && c == 7)
	{
		ft_putchar (c + 48);
		ft_putchar (d + 48);
		ft_putchar (u + 48);
		return ;
	}

	if (u > d && d > c)
	{
		ft_putchar (c + 48);
		ft_putchar (d + 48);
		ft_putchar (u + 48);
		ft_putchar (',');
		ft_putchar (' ');
	}

}
void    ft_print_comb(void)
{
	char u;
	char d;
	char c;

	u = 2;
	d = 1;
	c = 0;

	while (u <= 10 && d <= 10 && c <= 10)
	{
		ft_display(u, d, c);
		if (u == 9)
		{
			u = 0;
			d++;
			if (d == 10)
			{
				d = 0;
				c++;
			}
		}
		u++;
	}
}

int main()
{
	ft_print_comb();
	return(0);
}
