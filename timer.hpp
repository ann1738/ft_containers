/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:44:09 by anasr             #+#    #+#             */
/*   Updated: 2022/06/12 18:12:05 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_HPP
# define TIMER_HPP

#include <time.h>


/* INCLUDE ORTHODOX STUFF !!!!!!!! */
class timer
{
private:
	clock_t start, end;
public:

	timer() {start = clock();}
	~timer(){end = clock(); std::cout << "\e[32mTimer: " << (static_cast<double>(end) - static_cast<double>(start)) << " microseconds\e[0m" << std::endl;}
};

#endif