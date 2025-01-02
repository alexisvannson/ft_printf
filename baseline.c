#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h> 
// reste à gérer le cas unsigned, le pointeur vide et les conversion en hexa

/*%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.*/
int	get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	special_cases(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		return (0);
	}
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		return (147483648);
	}
	if (n < 0)
	{
		str[0] = '-';
		return (-n);
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = get_size(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[size] = '\0';
	n = special_cases(n, str);
	while (n != 0)
	{
		str[--size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
int ft_putnb_base(int nb, char *base)
{
	int	len;
	char r;
    int count;
	
	count = 0;
    len = ft_strlen(base);
	if(nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
        count++;
	}
	r =  nb % len;
	if (nb >= len)
		ft_putnb_base(nb / len, base);
	write(1, &base[r], 1);
    count++;
    return (count);
}

char	*ft_strchr(const char *str, int search_str)
{
	while (*str)
	{
		if (*str == (char)search_str)
			return ((char *)str);
		str++;
	}
	if ((char)search_str == '\0')
		return ((char *)str);
	return (0);
}

int handle_variable(char c, va_list args)
{
    if(c == 'c' || c == '%')
    {

        int num = va_arg(args, int); // Récupère l'argument suivant  ADAPTER À LA LOGIQUE PRINTF
        write(1, &num, 1);
        return(1);
    }
    else if(c == 's')
    {
        char *str = va_arg(args, char*);
        ft_putstr(str);
        return (ft_strlen(str));
    }
    else if(c == 'i'|| c == 'd'|| c == 'u')
    {
        int val = va_arg(args, int);
        ft_putstr(ft_itoa(val));
        return (get_size(val));
    }
    else if(c == 'x')
    {
        int val = va_arg(args, int);
        return(ft_putnb_base(val, "0123456789abcdef"));
    }
     else if(c == 'X')
    {
        int val = va_arg(args, int);
        return(ft_putnb_base(val, "0123456789ABCDEF"));
    }
    return(-1);
}
int get_nbarguments(const char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i])
    {
        if (str[i] == '%' && str[i + 1] != '%' )
            count ++;
        i++;
    }
    return (count);
}

int ft_printf(const char *str, ...)
{
    int len;
    int i;
    int count;
    va_list args;  // Déclare une liste d'arguments

    len = 0;
    i = 0;
    //count = get_nbarguments(str);
    va_start(args, str); // Initialise la liste d'arguments avec le nombre d'arguments
    
    while(str[i])
    {
        if(str[i] == '%')
        {
            len += handle_variable(str[i + 1], args);
            i += 2;
        }
        else 
        {
            write(1, &str[i], 1);
            len += 1;
            i++;
        }
    }
    va_end(args);
    return (len);
}
int main(void)
{
    ft_printf("letsgooooooo %s le %c du %X", "francis", 'S', -42);
    return (0);
}