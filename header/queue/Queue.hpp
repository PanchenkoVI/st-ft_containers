/*
* Created: 2021/06/27
*/

#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "../MainIncludes.hpp"
#include "../list/List.hpp"

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class queue
	{
		public:
			typedef Container ctype;
		private:
			ctype _qu;
		public:
			typedef size_t size_type;
			typedef T val;	

		explicit queue (ctype const &cct = ctype()) { _qu = cct; }
		queue &operator=(queue const &a)
		{
			*this->_qu = a._qu;
			return (*this);
		}
		size_type	size()	 const 		{ return (_qu.size()); }
		val			&front() 			{ return (_qu.front()); }
		val			&back()				{ return (_qu.back()); }
		const val	&front() const 		{ return (_qu.front()); }
		const val	&back()	 const		{ return (_qu.back()); }
		void 		pop()				{ return (_qu.pop_front()); }
		void 		push(val const &val){ return (_qu.push_back(val)); }
		bool 		empty() const
		{
			bool tmp = false;
			if (_qu.empty())
				tmp = true;
			return tmp;
		}

		friend bool operator!=(queue<T, Container> const &a, queue<T, Container> const &b)
		{
			bool tmp = false;
			if (a._qu != b._qu)
				tmp =  true;
			return tmp;
		}	

		friend bool operator==(queue<T, Container> const &a, queue<T, Container> const &b)
		{
			bool tmp = false;
			if (a._qu == b._qu)
				tmp =  true;
			return tmp;
		}
		
		friend bool operator<(queue<T, Container> const &a, queue<T, Container> const &b)
		{
			bool tmp = false;
			if (a._qu < b._qu)
				tmp =  true;
			return tmp;
		}

		friend bool operator>(queue<T, Container> const &a, queue<T, Container> const &b)
		{
			bool tmp = false;
			if(a._qu > b._qu)
				tmp =  true;
			return tmp;
		}	

		friend bool operator>=(queue<T,Container> const &a, queue<T,Container> const &b)
		{
			bool tmp = false;
			if(a._qu >= b._qu)
				tmp =  true;
			return tmp;
		}

		friend bool operator<=(queue<T, Container> const &a, queue<T, Container> const &b)
		{
			bool tmp = false;
			if(a._qu <= b._qu)
				tmp =  true;
			return tmp;
		}
	};

};

#endif