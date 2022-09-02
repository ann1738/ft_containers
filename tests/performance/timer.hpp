/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:44:09 by anasr             #+#    #+#             */
/*   Updated: 2022/09/02 11:30:24 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_HPP
# define TIMER_HPP

#include <time.h>
#include <iostream>


/* INCLUDE ORTHODOX STUFF !!!!!!!! */
class timer
{
private:
	clock_t start, end;
public:
	timer() {start = clock();}
	timer(const timer& rhs) : start(rhs.start) {}
	timer & operator=(const timer& rhs) {if (this != &rhs) {start = rhs.start;} return *this;}
	~timer(){end = clock(); std::cout << "\e[32m" << (static_cast<double>(end) - static_cast<double>(start)) << " microseconds ( " << (static_cast<double>(end) - static_cast<double>(start)) / 1e6 << " seconds)\e[0m" << std::endl;}
};

#endif
