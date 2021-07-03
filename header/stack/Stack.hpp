/*
* Created: 2021/06/27
*/

#ifndef STACK_HPP
# define STACK_HPP

#include "../MainIncludes.hpp"
#include "../list/List.hpp"

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{
		public:
			typedef Container container_type;
		private:
			container_type _ctype;
		public:
			typedef T val;
			typedef size_t st;

		stack &operator=(stack const &x)
		{
			*this->_ctype = x._ctype;
			return (*this);
		} 
		explicit 	stack (container_type const &ctnr = container_type()) { _ctype = ctnr; }
		val 		&top() 					{ return (_ctype.back()); }
		const val	&top() const 			{ return (_ctype.back()); }
		st			size() const 			{ return (_ctype.size()); }
		void		push (val const &val)	{ return (_ctype.push_back(val)); }
		void 		pop() 					{ return (_ctype.pop_back()); }
		
		bool empty() const 
		{
			if (_ctype.empty())
				return true;
			else
				return false;
		}

		friend bool operator!=(stack<T, Container> const &a, stack<T, Container> const &b)
		{
			bool tmp = false;
			if (a._ctype != b._ctype)
				tmp = true;
			return tmp;
		}

		friend bool operator==(stack<T, Container> const &a, stack<T, Container> const &b)
		{
			bool tmp = false;
			if (a._ctype == b._ctype)
				tmp = true;
			return tmp;
		}

		friend bool operator<(stack<T, Container> const &a, stack<T, Container> const &b)
		{
			bool tmp = false;
			if (a._ctype < b._ctype)
				tmp = true;
			return tmp;
		}

		friend bool operator>(stack<T, Container> const &a, stack<T, Container> const &b)
		{
			bool tmp = false;
			if (a._ctype > b._ctype)
				tmp = true;
			return tmp;
		}

		friend bool operator<=(stack<T, Container> const &a, stack<T, Container> const &b)
		{
			bool tmp = false;
			if (a._ctype <= b._ctype)
				tmp = true;
			return tmp;
		}

		friend bool operator>=(stack<T, Container> const &a, stack<T, Container> const &b)
		{
			bool tmp = false;
			if (a._ctype >= b._ctype)
				tmp = true;
			return tmp;
		}
	};
};

#endif