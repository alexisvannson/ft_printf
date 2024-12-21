/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   *.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:33:30 by avannson          #+#    #+#             */
/*   Updated: 2024/12/21 18:55:03 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
int handle_conversion(const char c, ...)
{
    if(c == 'c')
    {
        write(1, &c, 1);
        return(1);
    }
}
int ft_printf(const char *str, ...)
{
    int i;
    
    i = 0;
    len = 0
    while(str[i])
    {
        if(str[i] == '%')
        {
            i++;
            len += handle_conversion(str[i]);
            i++;
        }
        write(1, &str, 1);
        i++;
    }
}