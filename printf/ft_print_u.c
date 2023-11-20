void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int ft_print_unsigned(unsigned int n)
{
    unsigned int len;

    if(n > 10)
    {
        n = n / 10;
        ft_print_unsigned(n);
    }
    ft_putchar(n);
    if (n <= 9)
        ft_putchar(n + '0');
}