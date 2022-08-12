/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:02:04 by ann               #+#    #+#             */
/*   Updated: 2022/08/12 13:10:13 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_HPP
# define TESTING_HPP

#include <iostream>
#include <assert.h>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "additional.hpp"
#include "timer.hpp"
#include "shared.hpp"

#define	myAssert(expr) (static_cast <bool> (expr) ? void (0) : static_cast <void> (std::cout << "\e[31mFailed\e[0m\n"))
#define DEBUG() (std::cout << "\e[33mDEBUGGING\e[0m\n")

#include "tests/tests.hpp"


# define PASS "\e[32mPASS!\e[0m"
# define FAIL "\e[31mFAIL ;(\e[0m"

#endif
