/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:49:59 by ann               #+#    #+#             */
/*   Updated: 2022/06/12 17:16:29 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <limits>



namespace ft
{

	template <typename T> class vectorIterator;

	template < typename T, typename _Alloc = std::allocator<T> > 
	class	vector
	{
	public:
		/*			Member Types			*/
    	typedef T 							value_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
    	typedef std::size_t					size_type;
    	typedef _Alloc						allocator_type;
    	typedef typename allocator_type::pointer	pointer;
    	typedef typename allocator_type::const_pointer	const_pointer;

		// typedef	std::iterator<pointer, value_type>	iterator;
		// typedef	std::iterator<const_pointer, value_type>	const_iterator;
		typedef		ft::vectorIterator<T>	iterator;
	private:
		/*			Private Members			*/
		pointer _start;
		pointer _end;
		pointer _end_of_memory;
	public:

		vector(const vector& other){
			allocator_type alloc = allocator_type();
			this->_start = alloc.allocate(other.capacity());

			for (size_type i = 0; i < other.size(); ++i) alloc.construct(this->_start + i, other[i]);
			this->_end = this->_start + other.size();
			this->_end_of_memory = this->_start + other.capacity();
		}
		vector<value_type> & operator=(const vector& other){
			if (this != &other)
			{
				allocator_type alloc = allocator_type();
				this->_start = alloc.allocate(other.capacity());

				for (size_type i = 0; i < other.size(); ++i) alloc.construct(this->_start + i, other[i]);
				this->_end = this->_start + other.size();
				this->_end_of_memory = this->_start + other.capacity();
			}
			return *(this);
		}
		/*			Constuctor			*/
		vector(void): _start(nullptr), _end(nullptr), _end_of_memory(nullptr) {}
		// explicit vector( const Allocator& alloc );
		// template< class InputIt >
		// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		explicit vector( size_type count, const_reference value = value_type(), allocator_type alloc = allocator_type())
		{
			this->_start = alloc.allocate(count);
			/*not needed*/
			this->_end = this->_start;
			this->_end_of_memory = this->_end + count;
			/************/

			for (size_type i = 0; i < count; ++i) alloc.construct(this->_start + i, value);
			this->_end = this->_start + count;
			this->_end_of_memory = this->_end;
		}
		
		/*			Destructor		*/
		~vector(){
			allocator_type alloc = allocator_type();
		
			for (size_type i = 0; i < this->size(); ++i) alloc.destroy(this->_start + i);
			alloc.deallocate(this->_start, this->capacity());
		}

		/*			Element access		*/
		reference	at(size_type pos){
			if (pos < this->size()) return *(this->_start + pos);
			throw std::out_of_range("vector::range_check error");
		}

		const_reference at( size_type pos ) const{
			if (pos < this->size()) return *(this->_start + pos);
			throw std::out_of_range("vector::range_check error");
		}

		reference	operator[](size_type pos){
			return  *(this->_start + pos);
		}

		const_reference operator[](size_type pos) const{
			return  *(this->_start + pos);
		}

		reference	front(void){
			return *(this->_start);
		}

		const_reference front() const{
			return *(this->_start);
		}

		reference	back(void){
			return *(this->_end - 1);
		}

		const_reference back() const{
			return *(this->_end - 1);
		}

		T* data(){
			return (this->_start);
		}

		const T* data() const{
			return (this->_start);
		}

		/*			Iterators			*/
		iterator	begin(void) const{
			return (iterator(this->_start));
		}

		// const_iterator begin() const{
		// 	return (iterator(this->_start));
		// }

		iterator	end(void) const{
			return (iterator(this->_end));
		}

		/*			Capacity			*/
		bool	empty(void) const{
			return (this->_start == this->_end);
		}
		
		size_type	size(void) const{
			return (static_cast<size_type>(this->_end - this->_start));
		}

		size_type	max_size() const{
			return (std::numeric_limits<size_type>::max());
		}

		void	reserve(size_type new_cap){
			if (new_cap > this->max_size()) throw std::length_error("Invalid reserve() input");
			if (new_cap > this->capacity())
			{
				allocator_type alloc = allocator_type();
				/* allocate and construct copies of previous memory */
				pointer temp = alloc.allocate(new_cap);
				size_type temp_size = this->size();
				for (size_type i = 0; i < this->size(); ++i)
					alloc.construct(temp + i, *(this->_start + i));

				/* destroy and deallocate */
				for (size_type i = 0; i < temp_size; ++i) alloc.destroy(this->_start + i);
				alloc.deallocate(this->_start, temp_size);
				
				/* replace the old memory (maybe i could use swap) */
				this->_start = temp;
				this->_end = temp + temp_size + 1;
				this->_end_of_memory = temp + new_cap;
			}
		}

		size_type	capacity(void) const{
			return (static_cast<size_type>(this->_end_of_memory - this->_start));
		}

		/*			Modifiers			*/
		void	push_back( const_reference value ){
			allocator_type alloc = allocator_type();
			if (this->size() != this->capacity())
			{

				alloc.construct(this->_start + this->size(), value);
				++this->_end;
			}
			else
			{
				/* allocate and construct copies of previous memory */
				pointer temp = alloc.allocate(this->capacity() * 2);
				size_type temp_size = this->size();
				for (size_type i = 0; i < this->size(); ++i)
					alloc.construct(temp + i, *(this->_start + i));

				/* add the new element */
				alloc.construct(temp + this->size(), value);

				/* destroy and deallocate */
				for (size_type i = 0; i < temp_size; ++i) alloc.destroy(this->_start + i);
				alloc.deallocate(this->_start, temp_size);
				
				/* replace the old memory (maybe i could use swap) */
				this->_start = temp;
				this->_end = temp + temp_size + 1;
				this->_end_of_memory = temp + (temp_size * 2);
			}
		}

		// iterator erase(iterator pos){
		// 	allocator_type alloc = allocator_type();
		// 	size_type offset = pos - this->begin();
		// 	for(; pos != (--this->end()); ++pos, ++offset)
		// 		alloc.construct(this->_start + offset, *(this->_start + offset + 1));
		// 	alloc.destroy(this->_end - 1);
		// }
		
		void pop_back(){
			allocator_type alloc = allocator_type();
			
			alloc.destroy(--this->_end);
		}

		// void swap( vector& other ){
		// 	/*replace with iterators later and maybe use XOR to swap */
		// 	/* orr just use copy constructor */
		// 	T temp;
		// 	for (size_type i = 0; i < this->size(); ++i)
		// 	{
		// 		temp = this
		// 	}
		// }
				

		
		/*			Operators				*/



	};

	template <typename T>
	class vectorIterator : std::iterator< std::random_access_iterator_tag, vector<T> >
	{
		friend class vector<T>;
		typedef typename	vector<T>::pointer pointer;
	public:
		vectorIterator(pointer temp) : it_start(temp) {}

		T &	operator*(void){
			return *(this->it_start);
		}

		vectorIterator operator++(void){
			return (vectorIterator(++(this->it_start)));
		}

		vectorIterator operator++(int){
			vectorIterator temp;
			temp.it_start = this->it_start++;
			return (temp);
		}

		vectorIterator operator--(void){
			return (vectorIterator(--(this->it_start)));
		}

		vectorIterator operator--(int){
			vectorIterator temp;
			temp.it_start = this->it_start--;
			return (temp);
		}

		bool	operator<(const vectorIterator & rhs) {return (this->it_start < rhs.it_start);}
		bool	operator<=(const vectorIterator & rhs) {return (this->it_start <= rhs.it_start);}
		bool	operator>(const vectorIterator & rhs) {return (this->it_start > rhs.it_start);}
		bool	operator>=(const vectorIterator & rhs) {return (this->it_start >= rhs.it_start);}
		bool	operator==(const vectorIterator & rhs) {return (this->it_start == rhs.it_start);}
		bool	operator!=(const vectorIterator & rhs) {return (this->it_start != rhs.it_start);}

	private:
		pointer	it_start;
	};
}

#endif