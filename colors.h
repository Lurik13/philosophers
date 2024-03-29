/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:55:24 by lribette          #+#    #+#             */
/*   Updated: 2024/01/24 09:55:32 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RESET "\e[0m"

/* **************** BOLD ONES **************** */
# define RED_ERROR "\x1b[38;2;180;0;0;1m"
# define FORK "\x1b[38;2;6;151;221;1mhas taken a fork\e[0m\n"
# define EATING "\x1b[38;2;226;185;5;1mis eating\e[0m\n"
# define SLEEPING "\x1b[38;2;134;134;134;1mis sleeping\e[0m\n"
# define THINKING "\x1b[38;2;144;71;255;1mis thinking\e[0m\n"
# define DYING "\x1b[38;2;180;0;0;7mdied\e[0m\n"

/* *************** NORMAL ONES *************** */
# define RED "\x1b[38;2;255;0;0m"
# define ORANGE "\x1b[38;2;255;132;0m"
# define YELLOW "\x1b[38;2;255;216;0m"
# define GREEN "\x1b[38;2;0;255;60m"
# define BLUE "\x1b[38;2;0;144;255m"
# define PURPLE "\x1b[38;2;130;25;255m"

#endif