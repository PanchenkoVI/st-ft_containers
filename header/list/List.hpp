/*
* Created: 2021/06/27
*/

#ifndef LIST_HPP
# define LIST_HPP

#include "../MainIncludes.hpp"

namespace ft 
{
	template <class Iterator>
	class rvIterator
	{
	public:
		typedef Iterator liter;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::iterator_category iterator_category;

		rvIterator() {this->_iter = 0; }
		virtual	~rvIterator() {}
		template<class Iter>
		rvIterator(rvIterator<Iter> const &a) { this->_iter = a._iter; }
		explicit rvIterator(liter be2) { this->_iter = be2; }
		liter		base() const						{ return _iter; }
		rvIterator 	operator+(difference_type dt) const	{ return (rvIterator<liter>(this->base() - dt)); }
		rvIterator 	operator-(difference_type dt) const	{ return (rvIterator<liter>(this->base() + dt)); }
		rvIterator 	operator++() 						{ --_iter; return (*this); }
		rvIterator 	operator--() 						{ ++_iter; return (*this); }
		rvIterator 	operator++(int) { rvIterator<liter> tmp(*this); --_iter; return (tmp); }
		rvIterator 	operator--(int) { rvIterator<liter> tmp(*this); ++_iter; return (tmp); }
		rvIterator 	&operator+=(difference_type dt) { _iter = _iter - dt; return (*this); }
		rvIterator 	&operator-=(difference_type dt) { _iter = _iter + dt; return (*this); }
		pointer 	operator->() const 					{ return &(operator*()); }
		reference	operator*() 						{ return (*_iter); }
		reference	operator[](difference_type dt)		{ return (*(_iter - dt)); }
		
	private:
		liter	_iter;
	};
	
	template <class I>
	typename rvIterator<I>::difference_type operator-(rvIterator<I> const &a, rvIterator<I> const &b)
	{ return (a.base() - b.base()); }
	template <class I>
	rvIterator<I> operator+(typename rvIterator<I>::difference_type dt, rvIterator<I> const &be2)
	{ return (rvIterator<I>(be2 - dt)); }

	template <class I>
	bool operator<(rvIterator<I> const &a, rvIterator<I> const &b)
	{
		bool tmp = false;
		if (b < a)
			tmp = true;
		return tmp;
	}

	template <class I>
	bool operator>(rvIterator<I> const &a, rvIterator<I> const &b)
	{
		bool tmp = false;
		if (a > b)
			tmp = true;
		return tmp;
	}

	template <class I>
	bool operator!=(rvIterator<I> const &a, rvIterator<I> const &b)
	{
		bool tmp = false;
		if (a.base() != b.base())
			tmp = true;
		return tmp;
	}

	template <class I>
	bool operator<=(rvIterator<I> const &a, rvIterator<I> const &b)
	{
		bool tmp = false;
		if (a == b || a < b )
			tmp = true;
		return tmp;
	}

	template <class I>
	bool operator>=(rvIterator<I> const &a, rvIterator<I> const &b)
	{
		bool tmp = false;
		if (a == b || a > b )
			tmp = true;
		return tmp;
	}

	template <class I>
	bool operator==(rvIterator<I> const &a, rvIterator<I> const &b)
	{
		bool tmp = false;
		if (a.base() == b.base())
			tmp = true;
		return tmp;
	}

	template < bool B, class T = void > struct enable_if {};
	template < class T > struct enable_if <true, T> { typedef T type; };

	template<class T>
	void swap(T &a, T &b) 
	{
		T tmp1 = a;
		T tmp2 = b;
		a = tmp2;
		b = tmp1;
	}

	template <class T, class Node>
	class LBIterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		Node *_prnode;

	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef LBIterator<T, Node> BiIterator;
		typedef typename std::iterator<std::bidirectional_iterator_tag, T>::difference_type difference_type;
		typedef typename std::iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
		
		LBIterator() { this->_prnode = 0; } 
		LBIterator(BiIterator const &a) { this->_prnode = a._prnode; }
		LBIterator(Node *ptr) { this->_prnode = ptr; }
		virtual ~LBIterator() {}
		BiIterator 	operator+(int) { BiIterator tmp(*this); return (tmp); }
		BiIterator 	operator-(int) { BiIterator tmp(*this); return (tmp); }
		BiIterator operator--() { this->_prnode = this->_prnode->lprev; return (*this); }
		BiIterator operator++() { this->_prnode = this->_prnode->lnext; return (*this); }
		BiIterator operator--(int) { BiIterator tmp(*this); this->_prnode = this->_prnode->lprev; return (tmp); }
		BiIterator operator++(int) { BiIterator tmp(*this); this->_prnode = this->_prnode->lnext; return (tmp); }
		BiIterator &operator=(BiIterator const &a) { if (this != &a) _prnode = a._prnode; return (*this); }
		reference	operator*() 		 { return (_prnode->value); }
		pointer		operator->()		 { return (&_prnode->value); }
		Node		*get_pointer() const { return (_prnode); }
	};

	template<class T, class Node>
	bool operator!=(LBIterator<T, Node> const &a, LBIterator<T, Node> const &b)
	{
		bool tmp = false;
		if (a.get_pointer() != b.get_pointer())
			tmp = true;
		return tmp;
	}

	template<class T, class Node>
	bool operator==(LBIterator<T, Node> const &a, LBIterator<T, Node> const &b)
	{
		bool tmp = false;
		if (a.get_pointer() == b.get_pointer())
			tmp = true;
		return tmp;
	}

	template <class T, class Alloc = std::allocator<T> > 
	class list 
	{
	private: struct StctList
	{
		StctList *lnext;
		StctList *lprev;
		T value;
	};

	public:
		typedef	T value_type;
		typedef	size_t size_type;
		typedef	Alloc allocator_type;
		typedef	ptrdiff_t difference_type;
		typedef	LBIterator<T, StctList> iterator;
		typedef	rvIterator<iterator> reverse_iterator;
		typedef	typename allocator_type::pointer pointer;
		typedef	typename allocator_type::reference reference;
		typedef	LBIterator<const T, const StctList> const_iterator;
		typedef	rvIterator<const_iterator> const_reverse_iterator;
		typedef	typename allocator_type::const_pointer const_pointer;
		typedef	typename allocator_type::const_reference const_reference;

	private:
		StctList *_node;
		size_type _size;
		allocator_type _alloc;
		std::allocator<StctList> _salloc;

		StctList *const_list(value_type const &a)
		{
			StctList *StctList;
			StctList = _salloc.allocate(1);
			StctList->lnext = StctList;
			StctList->lprev = StctList;
			StctList->value = value_type();
			_alloc.construct(&StctList->value, a);
			return StctList;
		}

		void in_list(StctList *elist, const value_type &a)
		{
			StctList	*new_StctList = const_list(a);
			new_StctList->lnext = elist;
			new_StctList->lprev = elist->lprev;
			elist->lprev->lnext = new_StctList;
			elist->lprev = new_StctList;
		}

	public:
		explicit list (size_type st, value_type const &v = value_type(), allocator_type const &al = allocator_type())
		{
			this->_node = NULL;
			this->_size = 0;
			this->_alloc = al;
			size_type i = 0;
			StctList *StctList;
			StctList = _salloc.allocate(1);
			StctList->lnext = StctList;
			StctList->lprev = StctList;
			StctList->value = value_type();
			_node = StctList;
			_size = st;
			while (i < st)
			{
				in_list(_node, v);
				++i;
			}
		}

		template <class Ip>
		list (Ip a, Ip b, const allocator_type& al = allocator_type(), typename enable_if <!std::numeric_limits<Ip>::is_specialized>::type* = 0)
		{
			this->_node = NULL;
			this->_size = 0;
			this->_alloc = al;
			size_type i = 0;
			size_type dist = (size_type)std::distance(a, b);
			StctList *StctList;
			StctList = _salloc.allocate(1);
			StctList->lnext = StctList;
			StctList->lprev = StctList;
			StctList->value = value_type();
			_node = StctList;
			_size = dist;
			while (i < dist)
			{
				in_list(_node, *(a++));
				++i;
			}
		}

		explicit list (allocator_type const &al = allocator_type())
		{
			this->_node = NULL;
			this->_size = 0;
			this->_alloc = al;
			StctList *StctList;
			StctList = _salloc.allocate(1);
			StctList->lnext = StctList;
			StctList->lprev = StctList;
			StctList->value = value_type();
			_node = StctList;
		}

		list (list const &obj)
		{
			this->_node = NULL;
			this->_size = obj._size;
			this->_alloc = obj._alloc;
			size_type i = 0;
			StctList	*tmp_StctList = obj._node->lnext;
			StctList *StctList;
			StctList = _salloc.allocate(1);
			StctList->lnext = StctList;
			StctList->lprev = StctList;
			StctList->value = value_type();
			_node = StctList;
			while (obj._size > i)
			{
				in_list(_node, tmp_StctList->value);
				tmp_StctList = tmp_StctList->lnext;
				++i;
			}
		}

		list &operator=(list const &a)
		{
			if (this != &a)
			{
				size_type i = 0;
				this->~list();
				StctList *tmp_StctList = a._node;
				StctList *StctList;
				StctList = _salloc.allocate(1);
				StctList->lnext = StctList;
				StctList->lprev = StctList;
				StctList->value = value_type();
				_node = StctList;
				while (a._size > i)
				{
					in_list(_node, tmp_StctList->value);
					tmp_StctList = tmp_StctList->lnext;
					++i;
				}
				_size = a._size;
				_alloc = a._alloc;
			}
			return (*this);
		}

		~list()
		{
			StctList *tmp_StctList = _node->lprev;
			size_type i = 0;
			while (_size > i)
			{
				StctList	*lprev;
				lprev = tmp_StctList->lprev;
				_alloc.destroy(&tmp_StctList->value);
				tmp_StctList->lprev->lnext = tmp_StctList->lnext;
				tmp_StctList->lnext->lprev = tmp_StctList->lprev;
				_salloc.deallocate(tmp_StctList, 1);
				tmp_StctList = lprev;
				++i;
			}
			_node->lprev->lnext = _node->lnext;
			_node->lnext->lprev = _node->lprev;
			_salloc.deallocate(_node, 1);
		}

		iterator begin()	{ return (iterator(_node->lnext)); }
		iterator end()		{ return (iterator(_node)); }
		const_iterator begin() const	{ return (const_iterator(_node->lnext)); }
		const_iterator	end() const		{ return (const_iterator(_node)); }
		reverse_iterator rbegin()
		{
			if (_size != 0)
				return (reverse_iterator(--this->end()));
			return (reverse_iterator(this->end()));
		}

		reverse_iterator rend()
		{
			if (_size != 0)
				return (reverse_iterator(--this->begin()));
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rbegin() const
		{
			if (_size != 0)
				return (const_reverse_iterator(--this->end()));
			return (const_reverse_iterator(this->end()));
		}
		const_reverse_iterator rend() const
		{
			if (_size != 0)
				return (const_reverse_iterator(--this->begin()));
			return (const_reverse_iterator(this->begin()));
		}
		bool			empty()		const
		{
			bool tmp = false;
			if (_size == 0)
				tmp = true;
			return tmp;
		}
		size_type 		size() 		const 	{ return (_size); }
		size_type 		max_size()	const 	{ return (_salloc.max_size()); }
		reference 		front() 			{ return (_node->lnext->value); }
		const_reference	front()		const 	{ return (_node->lnext->value); }
		reference 		back() 				{ return (_node->lprev->value); }
		const_reference	back()		const 	{ return (_node->lprev->value); }

		void assign (size_type st, value_type const &vt)
		{ list tmp(st, vt); this->swap(tmp); }
		template <class Ip>
		void assign (Ip a, Ip b)
		{ list tmp(a, b); this->swap(tmp); }

		void push_front(value_type const &v)
		{
			StctList *elist = _node->lnext;
			StctList *new_StctList = const_list(v);
			new_StctList->lnext = elist;
			new_StctList->lprev = elist->lprev;
			elist->lprev->lnext = new_StctList;
			elist->lprev = new_StctList;
			_size++;
		}

		void push_back(value_type const &v)
		{
			StctList *elist = _node;
			StctList *new_StctList = const_list(v);
			new_StctList->lnext = elist;
			new_StctList->lprev = elist->lprev;
			elist->lprev->lnext = new_StctList;
			elist->lprev = new_StctList;
			_size++;
		}
		
		void pop_back()
		{
			StctList *sl = _node->lprev;
			_alloc.destroy(&sl->value);
			sl->lprev->lnext = sl->lnext;
			sl->lnext->lprev = sl->lprev;
			_salloc.deallocate(sl, 1);
			_size--;
		}

		void pop_front()
		{
			StctList *sl = _node->lnext;
			_alloc.destroy(&sl->value);
			sl->lprev->lnext = sl->lnext;
			sl->lnext->lprev = sl->lprev;
			_salloc.deallocate(sl, 1);
			_size--;
		}

		iterator insert (iterator loc, value_type const &v)
		{
			StctList *elist = loc.get_pointer();
			StctList *new_StctList = const_list(v);
			new_StctList->lnext = elist;
			new_StctList->lprev = elist->lprev;
			elist->lprev->lnext = new_StctList;
			elist->lprev = new_StctList;
			_size++;
			--loc;
			return loc;
		}

		void insert (iterator loc, size_type n, value_type const &v)
		{
			size_type i = 0;
			while (n > i)
			{
				StctList *elist = loc.get_pointer();
				StctList *new_StctList = const_list(v);
				new_StctList->lnext = elist;
				new_StctList->lprev = elist->lprev;
				elist->lprev->lnext = new_StctList;
				elist->lprev = new_StctList;
				++i;
			}
			_size = _size + n;
		}

		template <class Ip>
		void insert (iterator loc, Ip a, Ip b, typename enable_if < !std::numeric_limits<Ip>::is_specialized >::type* = 0) 
		{
			size_type d = std::distance(a, b);
			size_type i = 0;
			while (d > i)
			{
				StctList *elist = loc.get_pointer();
				StctList *new_StctList = const_list(*a);
				new_StctList->lnext = elist;
				new_StctList->lprev = elist->lprev;
				elist->lprev->lnext = new_StctList;
				elist->lprev = new_StctList;
				a++;
				++i;
			}
			_size = _size + d;
		}

		iterator erase (iterator a, iterator b)
		{
			size_type d = std::distance(a, b);
			if (d <= _size)
			{
				size_type i = 0;
				while (d > i)
				{
					erase(a++);	
					++i;
				}
				return (b);
			}
			else
				return (a);
		}

		iterator erase(iterator loc)
		{
			iterator res = iterator(loc.get_pointer()->lnext);
			StctList *sl = loc.get_pointer();
			_alloc.destroy(&sl->value);
			sl->lprev->lnext = sl->lnext;
			sl->lnext->lprev = sl->lprev;
			_salloc.deallocate(sl, 1);
			_size--;
			return res;
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (_size < n)
			{
				while (_size < n)
				{
					StctList *elist = _node;
					StctList *new_StctList = const_list(val);
					new_StctList->lnext = elist;
					new_StctList->lprev = elist->lprev;
					elist->lprev->lnext = new_StctList;
					elist->lprev = new_StctList;
					_size++;
				}
			}
			else if (_size > n)
			{
				while (_size > n)
				{
					StctList *sl = _node->lprev;
					_alloc.destroy(&sl->value);
					sl->lprev->lnext = sl->lnext;
					sl->lnext->lprev = sl->lprev;
					_salloc.deallocate(sl, 1);
					_size--;
				}
			}
		}

		void swap(list &a)
		{
			ft::swap(_size, a._size);
			ft::swap(_node, a._node);
			ft::swap(_salloc, a._salloc);
			ft::swap(_alloc, a._alloc);
		}

		void clear() { this->erase(this->begin(), this->end()); }

		void splice(iterator loc, list &a)
		{
			StctList *s1 = loc.get_pointer()->lprev;
			StctList *se = loc.get_pointer();
			StctList *trbe = a.begin().get_pointer();
			StctList *tren = a.end().get_pointer()->lprev;
			StctList *trold = a.end().get_pointer();
			s1->lnext = trbe;
			trbe->lprev = s1;
			se->lprev = tren;
			tren->lnext = se;
			trold->lnext = trold;
			trold->lprev = trold;
			_size = _size + a._size;
			a._size = 0;
		}

		void splice (iterator loc, list& a, iterator i)
		{
			StctList *be = loc.get_pointer()->lprev;
			StctList *en = loc.get_pointer();
			StctList *pos = i.get_pointer();
			pos->lprev->lnext = pos->lnext;
			pos->lnext->lprev = pos->lprev;
			be->lnext = pos;
			pos->lprev = be;
			en->lprev = pos;
			pos->lnext = en;
			_size++;
			a._size--;
		}

		void splice (iterator loc, list& a, iterator first, iterator last)
		{
			size_type dist = std::distance(first, last);
			if (dist != 0)
			{
				StctList *be = loc.get_pointer()->lprev;
				StctList *en = loc.get_pointer();
				StctList *tbe = first.get_pointer();
				StctList *ten = last.get_pointer()->lprev;
				StctList *tpos = last.get_pointer();
				tpos->lprev = tbe->lprev;
				tbe->lprev->lnext = tpos;
				be->lnext = tbe;
				tbe->lprev = be;
				en->lprev = ten;
				ten->lnext = en;
				_size = _size + dist;
				a._size -= dist;
			}
		}

		void remove (value_type const &v)
		{
			StctList *be1 = _node->lnext;
			StctList *loc;
			size_type j = 0;
			size_type i = 0;

			while (_size > i)
			{
				loc = be1->lnext;
				if (be1->value == v)
				{
					StctList *sl = be1;
					_alloc.destroy(&sl->value);
					sl->lprev->lnext = sl->lnext;
					sl->lnext->lprev = sl->lprev;
					_salloc.deallocate(sl, 1);
					j++;
				}
				be1 = loc;
				++i;
			}
			_size = _size - j;
		}

		template <class P>
		void remove_if (P p)
		{
			iterator pos;
			iterator be = this->begin();
			
			for (;be != this->end();)
			{
				pos = be;
				pos++;
				if (p(*be))
				{
					StctList *sl = be.get_pointer();
					_alloc.destroy(&sl->value);
					sl->lprev->lnext = sl->lnext;
					sl->lnext->lprev = sl->lprev;
					_salloc.deallocate(sl, 1);
					_size--;
				}
				be = pos;
			}
		}

		void unique()
		{
			iterator be1 = this->begin();
			iterator be2 = this->begin();
			iterator pos;

			++be1;
			for (;be1 != this->end();)
			{
				pos = be1;
				pos++;
				if (*be1 != *be2)
					be2 = be1;
				else
				{
					StctList *sl = be1.get_pointer();
					_alloc.destroy(&sl->value);
					sl->lprev->lnext = sl->lnext;
					sl->lnext->lprev = sl->lprev;
					_salloc.deallocate(sl, 1);
					_size--;
				}
				be1 = pos;
			}
		}

		template <class B>
		void unique (B b)
		{
			iterator be1 = this->begin();
			iterator be2 = this->begin();
			iterator pos;

			++be1;
			while (be1 != this->end())
			{
				pos = be1;
				pos++;
				if (b(*be1, *be2))
				{
					StctList *sl = be1.get_pointer();
					_alloc.destroy(&sl->value);
					sl->lprev->lnext = sl->lnext;
					sl->lnext->lprev = sl->lprev;
					_salloc.deallocate(sl, 1);
					--_size;
				}
				else
					be2 = be1;
				be1 = pos;
			}
		}

		void merge(list &a)
		{
			if (&a != this)
			{
				iterator be1 = this->begin();
				iterator bex = a.begin();
				for (; be1 != this->end();)
				{
					iterator enx = bex;
					for (; enx != a.end(); ++enx)
					{
						if (*enx >= *be1)
							break ;
					}
					if (enx != bex)
					{
						splice(be1, a, bex, enx);
						bex = enx;
					}
					else
						be1++;
				}
				if (a._size != 0)
					splice(be1, a);
			}
		}

		template <class C>
		void merge (list &a, C comp)
		{
			if (&a != this)
			{
				iterator be1 = this->begin();
				iterator bea = a.begin();
				for (;be1 != this->end();)
				{
					iterator ena = bea;
					for (;ena != a.end(); ++ena)
					{
						if (!(comp(*ena, *be1)))
							break ;
					}
					if (ena != bea)
					{
						splice(be1, a, bea, ena);
						bea = ena;
					}
					else
						++be1;
				}
				if (a._size == 0)
					return ;
				else
					splice(be1, a);
			}
		}

		void sort()
		{
			iterator be1 = this->begin();
			iterator en1 = this->end();
			--en1;
			while (be1 != en1)
			{
				iterator pos = be1;
				++pos;
				while (pos != this->end())
				{
					if (*pos < *be1)
						ft::swap(*pos, *be1);
					++pos;
				}
				++be1;
			}
		}
	
		template <class C>
		void sort (C comp)
		{
			iterator be1 = this->begin();
			iterator en1 = this->end();
			--en1;
			while (be1 != en1)
			{
				iterator pos = be1;
				++pos;
				while (pos != this->end())
				{
					if (comp(*pos, *be1))
						ft::swap(*pos, *be1);
					++pos;
				}
				++be1;
			}
		}

		void reverse()
		{
			StctList *be1 = _node->lnext;
			StctList *end = _node->lprev;
			size_type flag = 0;
			size_type i = 0;
			while (_size / 2 > i)
			{
				StctList *bes = be1->lnext;
				StctList *ens = end->lprev;
				StctList *ost[4];
				ost[0] = be1->lprev;
				ost[1] = end->lprev;
				ost[2] = be1->lnext;
				ost[3] = end->lnext;
				flag = 0;
				if (be1->lnext == end && end->lprev == be1)
					flag++;
				if (be1->lprev == end && be1->lnext == end)
					flag++;
				if (flag == 0)
				{
					be1->lnext = ost[3];
					end->lnext = ost[2];
					be1->lprev = ost[1];
					end->lprev = ost[0];
				}
				else
				{
					be1->lnext = ost[3];
					be1->lprev = ost[2];
					end->lnext = ost[1];
					end->lprev = ost[0];
				}
				be1->lprev->lnext = be1;
				be1->lnext->lprev = be1;
				end->lprev->lnext = end;
				end->lnext->lprev = end;
				be1 = bes;
				end = ens;
				++i;
			}
		}
	
		allocator_type	get_alloc() const { return (_alloc); }
	};

	template <class T, class Alloc>
	bool operator<(list<T, Alloc> const &a, list<T, Alloc> const &b) 
	{
		bool tmp = false;
		typename ft::list<T, Alloc>::const_iterator	be1 = a.begin();
		typename ft::list<T, Alloc>::const_iterator	be2 = b.begin();
		for (;be1 != a.end() && be2 != b.end(); ++be1, ++be2)
		{
			if (*be1 <= *be2)
			{
				tmp = true;
				break ;
			}
		}			
		return (tmp);
	}

	template <class T, class Alloc>
	bool operator<=(list<T, Alloc> const &a, list<T, Alloc> const &b)
	{
		bool tmp = false;
		if (a == b)
			tmp = true;
		if (a < b)
			tmp = true;
		return tmp;
	}

	template <class T, class Alloc>
	bool operator>(list<T,Alloc> const &a, list<T,Alloc> const &b)
	{
		bool tmp = false;
		if (b < a)
			tmp = true;
		return tmp;
	}

	template <class T, class Alloc>
	bool operator>=(list<T,Alloc> const &a, list<T,Alloc> const &b)
	{
		bool tmp = false;
		if (a > b || a == b)
			tmp = true;
		return tmp;
	}

	template <class T, class Alloc>
	bool operator!=(list<T, Alloc> const &a, list<T, Alloc> const &b)
	{
		bool tmp = true;
		if (a == b)
			tmp = false;
		return tmp;
	}
	
	template <class T, class Alloc>
	bool operator==(list<T, Alloc> const &a, list<T, Alloc> const &b)
	{
		bool tmp = false;
		if (b.size() == a.size())
		{
			typename ft::list<T, Alloc>::const_iterator	be1 = a.begin();
			typename ft::list<T, Alloc>::const_iterator	be2 = b.begin();
			for (;be1 != a.end(); ++be1, ++be2)
			{
				if (*be1 != *be2)
					return (tmp);
			}
			tmp = true;
		}
		return tmp;
	}

	template <class T, class Alloc>
	void swap(list<T,Alloc>& x, list<T,Alloc>& y) { x.swap(y); }
}

#endif