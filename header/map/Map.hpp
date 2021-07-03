/*
* Created: 2021/06/27
*/

#ifndef MAP_HPP
# define MAP_HPP

#include "../MainIncludes.hpp"

namespace ft
{
	template <typename T> 					struct coonst 							{ typedef T type; };
	template <typename T> 					struct coonst		<const T> 			{ typedef T type; };
	template <bool B, typename T = void> 	struct enable_ifm 						{};
	template <typename T> 					struct enable_ifm	<true, T> 			{ typedef T type; };
	template <typename N>					struct is_integralm						{ static const bool value = false;};
	template <class T1, class T2, class T3>
	struct binfun{ typedef T1 t1; typedef T2 t2; typedef T3 t3; };
	template <class T> struct less : binfun <T, T, bool>
	{
		bool operator() (T const &x, T const &y) const
		{
			bool tmp = false;
			if (y > x)
				tmp = true;
			return tmp;
		}
	};

	template <class Itm>
	class reverse_iterator
	{
		private:
			Itm loc;

		public:
			typedef Itm iterator_type;
			typedef typename Itm::iterator_category iterator_category;
			typedef typename Itm::value_type value_type;
			typedef typename Itm::reference reference;
			typedef typename Itm::pointer pointer;
			typedef typename Itm::difference_type difference_type;

			reverse_iterator(){}
			explicit reverse_iterator(iterator_type x)  { --x; this->loc= x; }
			template <class Iterator> reverse_iterator(reverse_iterator<Iterator> const &p) {this->loc = p; }

			iterator_type		base() const { iterator_type it = loc; ++it; return it; }
			reverse_iterator	operator+(difference_type dt) const { reverse_iterator a = base() - dt; return a; }
			reverse_iterator	operator-(difference_type dt) const { reverse_iterator a = base() + dt; return a; }
			reverse_iterator	&operator++() { --loc; return *this; }
			reverse_iterator	&operator--() { ++loc; return *this; }
			reverse_iterator	operator++(int) { reverse_iterator a = *this; ++(*this); return a; }
			reverse_iterator 	operator--(int) { reverse_iterator a = *this; --(*this); return a; }
			reverse_iterator	&operator+=(difference_type dt) { loc= loc- dt; return *this; }
			reverse_iterator	&operator-=(difference_type dt) { loc= loc+ dt; return *this; }
			reference			operator*() const { return *loc; }
			pointer 			operator->() const { return &(*loc); }
			reference 			operator[] (difference_type n) const { return loc[n]; }

			template <class Im>
			friend bool operator>(reverse_iterator const &a, reverse_iterator<Im> const &b)
			{
				bool tmp = false;
				if (b.loc < a.loc)
					tmp = true;
				return tmp;
			}

			template <class Im>
			friend bool operator<(reverse_iterator const &a, reverse_iterator<Im> const &b)
			{
				bool tmp = false;
				if (b.loc > a.loc)
					tmp = true;
				return tmp;
			}

			template <class Im>
			friend bool operator>=(reverse_iterator const &a, reverse_iterator<Im> const &b)
			{
				bool tmp = false;
				if (a.loc >= b.loc)
					tmp = true;
				return tmp;
			}

			template <class Im>
			friend bool operator<=(reverse_iterator const &a, reverse_iterator<Im> const &b)
			{
				bool tmp = false;
				if (a.loc<= b.loc)
					tmp = true;
				return tmp;
			}

			template <class Im>
			friend bool operator!=(reverse_iterator const &a, reverse_iterator<Im> const &b)
			{
				bool tmp = false;
				if (b.loc != a.loc)
					tmp = true;
				return tmp;
			}

			template <class Im>
			friend bool operator==(reverse_iterator const &a, reverse_iterator<Im> const &b)
			{
				bool tmp = false;
				if (b.loc == a.loc)
					tmp = true;
				return tmp;
			}
	};

	template	<typename Tp>
	class MapNTree
	{
		private:
			MapNTree* _mum;
			MapNTree* _lsun;
			MapNTree* _rsun;
			Tp MNTr;

		public:
			MapNTree(MapNTree const &a) { *this = a; }
			MapNTree() : MNTr(Tp()) { this->_mum = NULL; this->_lsun = NULL; this->_rsun = NULL; }
			MapNTree(Tp const &a) : MNTr(a){ this->_mum = NULL; this->_lsun = NULL; this->_rsun = NULL; }
			MapNTree &operator=(MapNTree const &a)
			{
				this->MNTr = a.MNTr;
				this->_mum = a._mum;
				this->_rsun = a._rsun;
				this->_lsun = a._lsun;
				return (*this);
			}
			virtual ~MapNTree() {}

			Tp 			&getMNTr() const { return MNTr; }
			Tp			&getMNTr()	{ return MNTr;	}
			MapNTree	*&getMum()	{ return _mum;	}
			MapNTree	*&getLsun() { return _lsun; }
			MapNTree	*&getRsun() { return _rsun; }
			
			template<class P>
			MapNTree* getMum_if(P p)
			{		
				if (_mum)
				{
					MapNTree* ma = _mum;
					for (;ma && p(ma) == false;)
						ma = ma->_mum;
					return ma;
				}
				else
					return NULL;
			}

			int getMumRelation() const
			{
				if (_mum->getRsun() == this && _mum)
					return 1;
				else if (_mum->getLsun() == this && _mum)
					return 0;
				return 2;
			}

			static bool lMum(MapNTree* a)
			{
				bool tmp = false;
				if (a->getMumRelation() == 1)
					tmp = true;
				return tmp;
			}			

			static bool rMum(MapNTree* a)
			{
				bool tmp = false;
				if (a->getMumRelation() == 0)
					tmp = true;
				return tmp;
			}

			void unmLink()
			{
				if (getMumRelation() == 1)
					_mum->_rsun = NULL;
				else if (getMumRelation() == 0)
					_mum->_lsun = NULL;
			}

			void mLink(MapNTree* ma, int lr)
			{
				if (lr == 1)
					ma->rLink(this);
				else if (lr == 0)
					ma->lLink(this); 
				else
					_mum = NULL;
			}

			void lLink(MapNTree* a)
			{
				_lsun = a;
				if (a)
					a->_mum = this;
			}

			void rLink(MapNTree* a)
			{
				_rsun = a;
				if (a)
					a->_mum = this;
			}

			MapNTree* getNewParent()
			{
				if (!_lsun)
					return _rsun->getMinNode();
				else
					return _lsun->getMaxNode();
			}

			MapNTree* getMaxNode()
			{
				MapNTree *a = this;
				for (;a->_rsun;)
					a = a->_rsun;
				return a;
			}

			MapNTree* getMinNode()
			{
				MapNTree* a = this;
				for (;a->_lsun;)
					a = a->_lsun;
				return a;
			}

	};

	template <typename Tp>
	class MIterator
	{
	private:
		template <class, class, class, class>
		friend class map;
		friend class MIterator<const Tp>;
		typedef typename coonst<Tp>::type nct;
		typedef MIterator<nct> nci;
		typedef MapNTree<nct> node;
		node* ndMap;

	public:
		typedef Tp value_type;
		typedef ptrdiff_t difference_type;
		typedef Tp *pointer;
		typedef Tp &reference;
		typedef std::bidirectional_iterator_tag iterator_category;

		MIterator() { this->ndMap = NULL; }
		MIterator(nci const &a) { ndMap = a.ndMap; }
		MIterator(node *ndMap) { this->ndMap = ndMap; }
		virtual ~MIterator() {}
		
		pointer		operator->() const { return &(ndMap->getMNTr()); }
		reference	operator*() const { return (ndMap->getMNTr()); }
		MIterator	operator--(int) { MIterator a = *this; --(*this); return a; }
		MIterator	operator++(int) { MIterator a = *this; ++(*this); return a; }
		MIterator	&operator=(MIterator const &a) { ndMap = a.ndMap; return *this; }
		MIterator	&operator--()
		{
			if (!(ndMap->getLsun()) && ndMap->getMumRelation() != 1)
				ndMap = ndMap->getMum_if(node::lMum)->getMum();
			else if (ndMap->getMumRelation() == 1 && !(ndMap->getLsun()))
				ndMap = ndMap->getMum();			
			else if (ndMap->getLsun())
				ndMap = ndMap->getLsun()->getMaxNode();
			return *this;
		}

		MIterator	&operator++()
		{
			if (!(ndMap->getRsun()) && (ndMap->getMumRelation() != 0))
				ndMap = ndMap->getMum_if(node::rMum)->getMum();
			else if (ndMap->getMumRelation() == 0 && !(ndMap->getRsun()))
				ndMap = ndMap->getMum();
			else if (ndMap->getRsun())
				ndMap = ndMap->getRsun()->getMinNode();
			return *this;
		}
	
		bool operator!=(MIterator const &b) const
		{
			bool tmp = false;
			if (ndMap != b.ndMap)
				tmp = true;
			return tmp;
		}
		
		bool operator==(MIterator const &b) const
		{
			bool tmp = false;
			if (ndMap == b.ndMap)
				tmp = true;
			return tmp;
		}
	};
	
	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef std::size_t size_type;

	private:
		typedef MapNTree<value_type> node;
		node *_MapnMin;
		node *_MapnMax;
		size_type _len;
		key_compare _kcomp;
		allocator_type _alloc;

	public:
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef MIterator<value_type> iterator;
		typedef MIterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;

	private:
		node*& getRoot() const { return (_MapnMax->getLsun()); }
		
	public:
		class value_compare : public binfun<value_type, value_type, bool>
		{
			public:
				typedef bool t3;
				typedef value_type t1;
				typedef value_type t2;
				bool operator()(value_type const &a, value_type const &b) const
				{
					bool tmp = false;
					if (comp(a.first, b.first))
						tmp = true;
					return tmp;
				}
				private:
					friend class map;

				protected:
					Compare comp;
					value_compare(Compare c) { this->comp = c; }
		};

		explicit map(key_compare const &k = key_compare(), allocator_type const &a = allocator_type())
		{
			this->_MapnMin = NULL;
			this->_MapnMax = NULL;
			this->_len = 0;
			this->_kcomp = k;
			this->_alloc = a;
			_MapnMin = new node(value_type(key_type(), mapped_type()));
			_MapnMax = new node(value_type(key_type(), mapped_type()));
			_MapnMin->rLink(_MapnMax);
		}

		template <class II>
		map(II a, II b, const key_compare &k = key_compare(), const allocator_type &al = allocator_type())
		{
			this->_MapnMin = NULL;
			this->_MapnMax = NULL;
			this->_len = 0;
			this->_kcomp = k;
			this->_alloc = al;
			_MapnMin = new node(value_type(key_type(), mapped_type()));
			_MapnMax = new node(value_type(key_type(), mapped_type()));
			_MapnMin->rLink(_MapnMax);
			while (a != b)
			{
				insert(*a);
				++a;
			}
		}

		map(map const &a)
		{
			_MapnMin = new node(value_type(key_type(), mapped_type()));
			_MapnMax = new node(value_type(key_type(), mapped_type()));
			_MapnMin->rLink(_MapnMax);
			*this = a;
		}

		~map()
		{
			clear();
			delete _MapnMax;
			delete _MapnMin;
		}

		map &operator=(map const &a)
		{
			this->_len = 0;
			this->_kcomp = a._kcomp;
			this->_alloc = a._alloc;
			insert(a.begin(), a.end());
			return *this;
		}

		iterator		end()			{ iterator a = _MapnMax; 		return a; }
		const_iterator	end() const		{ const_iterator a = _MapnMax;	return a; }
		iterator		begin() 		{ if (_len != 0) return iterator(getRoot()->getMinNode());			return end(); }
		const_iterator	begin() const	{ if (_len != 0) return const_iterator(getRoot()->getMinNode());	return end(); }
		reverse_iterator rend()			{ return reverse_iterator(begin()); }
		reverse_iterator rbegin()		{ return reverse_iterator(end());	}
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
		mapped_type &operator[](key_type const &a)
		{
			iterator beg = find(a);
			if (beg == end())
				return insert(value_type(a, mapped_type())).first->second;
			return beg->second;
		}

		bool empty() const
		{
			bool tmp = false;
			if (_len == 0)
				tmp = true;
			return tmp;
		}

		std::pair<iterator, bool> insert(value_type const &vt)
		{
			if (getRoot())
			{
				node *tmp = getRoot();
				while (' ')
				{
					if (tmp->getMNTr().first > vt.first)
					{
						if (!(tmp->getLsun()))
						{
							tmp->lLink(new node(vt));
							_len++;
							return std::pair<iterator, bool>(iterator(tmp->getLsun()), true);
						}
						else
							tmp = tmp->getLsun();
					}					
					else if (tmp->getMNTr().first < vt.first)
					{
						if (!(tmp->getRsun()))
						{
							tmp->rLink(new node(vt));
							_len++;
							return std::pair<iterator, bool>(iterator(tmp->getRsun()), true);
						}
						else
							tmp = tmp->getRsun();
					}
					else
						return std::pair<iterator, bool>(iterator(tmp), false);
					}
			}
			else
			{
				getRoot() = new node(vt);
				_MapnMax->lLink(getRoot());
				++_len;
				return std::pair<iterator, bool>(iterator(getRoot()), true);
			}
		}

		iterator insert(iterator loc, value_type const &vt) { (void)loc; return (insert(vt).first); }
		template <class II> void insert(II a, II b) { while (a != b) { insert(*a); ++a; } }
		void erase(iterator loc)
		{
			--_len;
			if (loc.ndMap->getLsun() || loc.ndMap->getRsun())
			{
				node *newParent = loc.ndMap->getNewParent();
				node *left = loc.ndMap->getLsun();
				node *right = loc.ndMap->getRsun();
				if (newParent == right)
					right = newParent->getRsun();
				else if (newParent == left)
					left = newParent->getLsun();
				if (!_kcomp(newParent->getMNTr().first, loc.ndMap->getMNTr().first))
					newParent->getMum()->lLink(newParent->getRsun());
				else
					newParent->getMum()->rLink(newParent->getLsun());
				newParent->mLink(loc.ndMap->getMum(), loc.ndMap->getMumRelation());
				newParent->rLink(right);
				newParent->lLink(left);
				delete loc.ndMap;
			}
			else
			{
				loc.ndMap->unmLink();
				delete loc.ndMap;
			}
		}

		size_type erase(key_type const &a)
		{
			iterator be = find(a);
			if (be == end())
				return 0;
			erase(be);
			return 1;
		}

		void erase(iterator a, iterator b)
		{
			if (a != b)
			{
				for (;a != b;)
				{
					iterator next = a;
					++next;
					erase(a);
					a = next;
				}
			}
		}		
		
		void swap(map &x)
		{
			ft::swap(x._len, _len);
			ft::swap(x._kcomp, _kcomp);
			ft::swap(x._MapnMax, _MapnMax);
			ft::swap(x._MapnMin, _MapnMin);
		}

		size_type size() const { return _len; }
		void clear() { erase(begin(), end()); }
		key_compare key_comp() const { return _kcomp; }
		value_compare value_comp() const { value_compare a = _kcomp; return a; }
		size_type count(key_type const &a) const { return find(a) != end(); }
		std::pair<const_iterator, const_iterator> equal_range(key_type const &k) const
		{ return std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)); }
		std::pair<iterator, iterator> equal_range(key_type const &k)
		{ return std::pair<iterator, iterator>(lower_bound(k), upper_bound(k)); }
		allocator_type get_allocator() const { return (_alloc); }
		
		const_iterator find(key_type const &a) const
		{
			node *start = getRoot();
			for(;start && start->getMNTr().first != a;)
				start = (start->getMNTr().first >= a) ? start->getLsun() : start->getRsun();
			if (start)
				return const_iterator(start);
			return end();
		}

		iterator find(key_type const &a)
		{
			node *start = getRoot();
			for (;start && start->getMNTr().first != a;)
				start = (start->getMNTr().first >= a) ? start->getLsun() : start->getRsun();
			if (start)
				return iterator(start);
			return end();
		}

		size_type max_size() const
		{
			if ((sizeof(ft::MapNTree<mapped_type>)) == 40)
				return (std::numeric_limits<difference_type>::max() / 20);
			else
				return (std::numeric_limits<difference_type>::max() / 40);
		}

		iterator upper_bound(key_type const &a)
		{
			iterator be = lower_bound(a);
			if (be != end())
			{
				if (be->first == a)
					++be;
			}
			return be;
		}

		const_iterator upper_bound(key_type const &a) const
		{
			const_iterator be = lower_bound(a);
			if (be != end())
			{
				if (be->first == a)
					++be;
			}
			return be;
		}

		iterator lower_bound(key_type const &a)
		{
			node *ndMap = getRoot();
			while (ndMap)
			{
				if ((a != ndMap->getMNTr().first) && (!_kcomp(a, ndMap->getMNTr().first)))
				{
					if (ndMap->getRsun())
						ndMap = ndMap->getRsun();
					else
						return ++iterator(ndMap);
				}
				else if (_kcomp(a, ndMap->getMNTr().first) && a != ndMap->getMNTr().first)
				{
					if (ndMap->getLsun())
						ndMap = ndMap->getLsun();
					else
						return iterator(ndMap);
				}
				else
					return iterator(ndMap);
			}
			return end();
		}
		
		const_iterator lower_bound(key_type const &a) const
		{
			node *ndMap = getRoot();
			while (ndMap)
			{
				if ((a != ndMap->getMNTr().first) && (!_kcomp(a, ndMap->getMNTr().first)))
				{
					if (ndMap->getRsun())
						ndMap = ndMap->getRsun();
					else
						return ++const_iterator(ndMap);
				}
				else if (_kcomp(a, ndMap->getMNTr().first) && a != ndMap->getMNTr().first)
				{
					if (ndMap->getLsun())
						ndMap = ndMap->getLsun();
					else
						return const_iterator(ndMap);
				}
				else
					return const_iterator(ndMap);
			}
			return end();
		}

		template <class K, class Tt, class C, class A>
		friend bool operator<(const map<K, Tt, C, A> &a, const map<K, Tt, C, A> &b);
		template <class K, class Tt, class C, class A>
		friend bool operator>(const map<K, Tt, C, A> &a, const map<K, Tt, C, A> &b);
		template <class K, class Tt, class C, class A>
		friend bool operator<=(const map<K, Tt, C, A> &a, const map<K, Tt, C, A> &b);
		template <class K, class Tt, class C, class A>
		friend bool operator>=(const map<K, Tt, C, A> &a, const map<K, Tt, C, A> &b);
		template <class K, class Tt, class C, class A>
		friend bool operator!=(const map<K, Tt, C, A> &a,  const map<K, Tt, C, A> &b);
		template <class K, class Tt, class C, class A>
		friend bool operator==(const map<K, Tt, C, A> &a, const map<K, Tt, C, A> &b);
	};

	template <class K, class Tt, class C, class A>
	bool operator<(map<K, Tt, C, A> const &a, map<K, Tt, C, A> const &b)
	{
		typename map<K, Tt, C, A>::const_iterator lit, rit;
		lit = a.begin();
		rit = b.begin();
		for(;lit != a.end() && rit != b.end();)
		{
			if (lit->first != rit->first)
				return lit->first < rit->first;
			else if (lit->first == rit->first && lit->second != rit->second)
				return lit->second < rit->second;
			++lit;
			++rit;
		}
		return (lit==a.end()) && (rit != b.end());
	}

	template <class K, class Tt, class C, class A>
	bool operator>(map<K, Tt, C, A> const &a, map<K, Tt, C, A> const &b)
	{
		typename map<K, Tt, C, A>::const_iterator lit, rit;
		lit = a.begin();
		rit = b.begin();
		for(;lit != a.end() && rit != b.end();)
		{
			if (lit->first != rit->first)
				return lit->first > rit->first;
			else if (lit->first == rit->first && lit->second != rit->second)
				return lit->second > rit->second;
			++lit;
			++rit;
		}
		return (lit != a.end()) && (rit == b.end());
	}

	template <class K, class Tt, class C, class A>
	bool operator<=(map<K, Tt, C, A> const &a, map<K, Tt, C, A> const &b)
	{
		bool tmp = false;
		if (a == b)
			tmp = true;
		else if (a < b)
			tmp = true;
		return tmp;
	}

	template <class K, class Tt, class C, class A>
	bool operator>=(map<K, Tt, C, A> &a, map<K, Tt, C, A> &b)
	{
		bool tmp = false;
		if (a == b)
			tmp = true;
		else if(a > b)
			tmp = true;
		return tmp;
	}

	template <class K, class Tt, class C, class A>
	bool operator!=(map<K, Tt, C, A> const &a, map<K, Tt, C, A> const &b)
	{
		bool tmp = false;
		if (!(a == b))
			tmp = true;
		return tmp;
	}

	template <class K, class Tt, class C, class A>
	bool operator==(map<K, Tt, C, A> const &a, map<K, Tt, C, A> const &b)
	{
		bool tmp = false;
		int flag = 0;
		if (a.size() == b.size())
		{
			typename map<K, Tt, C, A>::const_iterator lit = a.begin(), rit = b.begin();
			for (; lit != a.end();)
			{
				if (lit->second != rit->second)
				{
					flag = 1;
					break ;
				}
				else if (lit->first != rit->first)
				{
					flag = 1;
					break ;
				}
				++lit;
				++rit;
			}
			if (flag == 0)
				tmp = true;	
		}
		return tmp;
	}

	template <class K, class Tt, class C, class A>
	void swap(map<K, Tt, C, A> &a, map<K, Tt, C, A> &b) { a.swap(b); }
}

#endif