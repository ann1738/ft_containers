/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:53:57 by ann               #+#    #+#             */
/*   Updated: 2022/08/30 13:43:38 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef	size_t		size_type;

		explicit stack(const container_type& ctnr = container_type())
			: c(ctnr) {}

		bool empty() const{
			return c.empty();
		}

		size_type size() const{
			return c.size();
		}

		value_type& top(){
			return c.back();
		}

		const value_type& top() const{
			return c.back();
		}

		void push(const value_type& val){
			c.push_back(val);
		}

		void pop(){
			c.pop_back();
		}
	
		template <class TI, class ContainerI>
		friend	bool operator==(const ft::stack<TI,ContainerI>& lhs, const ft::stack<TI,ContainerI>& rhs);

		template <class TI, class ContainerI>
		friend	bool operator!=(const ft::stack<TI,ContainerI>& lhs, const ft::stack<TI,ContainerI>& rhs);

		template <class TI, class ContainerI>
		friend	bool operator<(const ft::stack<TI,ContainerI>& lhs, const ft::stack<TI,ContainerI>& rhs);

		template <class TI, class ContainerI>
		friend	bool operator<=(const ft::stack<TI,ContainerI>& lhs, const ft::stack<TI,ContainerI>& rhs);

		template <class TI, class ContainerI>
		friend	bool operator>(const ft::stack<TI,ContainerI>& lhs, const ft::stack<TI,ContainerI>& rhs);

		template <class TI, class ContainerI>
		friend	bool operator>=(const ft::stack<TI,ContainerI>& lhs, const ft::stack<TI,ContainerI>& rhs);
	protected:
		container_type	c;
	};

	template <class T, class Container>
  	bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return lhs.c == rhs.c;
	}

	template <class T, class Container>
  	bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return lhs.c != rhs.c;
	}

	template <class T, class Container>
	bool operator< (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return lhs.c < rhs.c;
	}

	template <class T, class Container>
	bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return lhs.c <= rhs.c;
	}

	template <class T, class Container>
	bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return lhs.c > rhs.c;
	}

	template <class T, class Container>
	bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return lhs.c >= rhs.c;
	}
}

#endif