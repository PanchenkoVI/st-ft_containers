/*
* Created: 2021/06/27
*/

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../MainIncludes.hpp"

namespace ft
{
	template <bool C, typename T = void> 	struct enable_ifv {};
	template <> 							struct enable_ifv<true>	{ typedef bool type; };
	template <typename T>	struct is_integralv						{ static const bool value = false; };
	template <>				struct is_integralv	<int>				{ static const bool value = true; };

	template <typename T>
	class VIterator
	{
		private:
			T *ptr;

		public:
			typedef size_t size_type;
			typedef std::ptrdiff_t difference_type;

			VIterator() { this->ptr = 0; }
			VIterator(VIterator const &a) { this->ptr = a.ptr; }
			VIterator &operator=(VIterator const &a) { this->ptr = a.ptr; return (*this); }
			~VIterator() {}
			explicit VIterator(T *p) { this->ptr = p; }
			T *getPtr() const { return (ptr); }
			T *operator->() const { return (ptr); }
			T &operator*() const { return (*ptr); }
			T &operator[](size_type n) const { return (ptr[n]); }

			template<typename D> 
			VIterator(VIterator<D> const &a) { this->ptr = a.getPtr(); }
			template<typename D>
			bool operator!=(VIterator<D> const &a) const
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) != ptr)
					tmp = true;
				return tmp;
			}

			bool operator!=(VIterator const &a) const
			{
				bool tmp = false;
				if (a.ptr != ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator==(VIterator<D> const &a) const 
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) == ptr)
					tmp = true;
				return tmp;
			}

			bool operator==(VIterator const &a) const 
			{
				bool tmp = false;
				if (a.ptr == ptr)
					tmp = true;
				return tmp;
			}

			VIterator operator++(int) 	{ VIterator<T> tmp = *this; ++ptr; return tmp; }
			VIterator &operator++() 	{ ++ptr; return (*this); }
			VIterator operator--(int) 	{ VIterator<T> tmp = *this; --ptr; return tmp; }
			VIterator &operator--() 	{ --ptr; return (*this); }
			VIterator operator+(difference_type dt) const	{ VIterator<T> tmp(ptr + dt); return tmp; }
			VIterator operator-(difference_type dt) const	{ VIterator<T> tmp(ptr - dt); return tmp; }
			difference_type operator-(VIterator &a) const	{ return (ptr - a.ptr); }
			template<typename D>
			difference_type operator-(VIterator<D> const &a) const 	{ return (ptr - const_cast<T*>(a.getPtr())); }
			VIterator		&operator+=(difference_type dt) 		{ ptr = ptr + dt; return (*this); }
			VIterator 		&operator-=(difference_type dt) 		{ ptr = ptr - dt; return (*this); }
		
			bool operator<(const VIterator &a) const
			{
				bool tmp = false;
				if (a.ptr > ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator<(VIterator<D> const &a) const
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) > ptr)
					tmp = true;
				return tmp;
			}

			bool operator>(VIterator const &a) const
			{
				bool tmp = false;
				if (ptr > a.ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator>(VIterator<D> const &a) const
			{
				bool tmp = false;
				if (ptr > const_cast<T*>(a.getPtr()))
					tmp = true;
				return tmp;
			}

			bool operator<=(VIterator const &a) const
			{
				bool tmp = false;
				if (ptr <= a.ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator<=(VIterator<D> const &a) const
			{
				bool tmp = false;
				if (ptr <= const_cast<T*>(a.getPtr()))
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator>=(VIterator<D> const &a) const
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) <= ptr)
					tmp = true;
				return tmp;
			}

			bool operator>=(VIterator const &a) const
			{
				bool tmp = false;
				if (ptr >= a.ptr)
					tmp = true;
				return tmp;
			}
	};

	template <typename T>
	VIterator<T> operator+(int a, VIterator<T> const &b) { return (b + a); }

	template <typename T>
	class VRIterator
	{
		private:
			T *ptr;

		public:
			typedef size_t size_type;
			typedef std::ptrdiff_t difference_type;

			VRIterator() 									{ this->ptr = 0; }
			VRIterator &operator=(const VRIterator &a) 		{ this->ptr = a.ptr; return (*this); }
			VRIterator(VRIterator const &a) 				{ this->ptr = a.ptr; }
			~VRIterator() 									{}
			template<typename D> VRIterator(VRIterator<D> const &a) { this->ptr = a.getPtr(); }
			explicit VRIterator(T *p) 						{ this->ptr = p; }
			explicit VRIterator(VIterator<T> a) 			{ this->ptr = a.getPtr(); --ptr; }
			VIterator<T> base()								{ return (VIterator<T>(ptr + 1)); }
			T			*getPtr()		const				{ return ptr; }; 
			T			&operator*()	const				{ return (*ptr); }
			T			*operator->()	const				{ return (ptr); }
			T 			&operator[](size_type dt) const		{ return (*(ptr - dt)); }
			VRIterator	&operator--()						{ ++ptr; return (*this); }
			VRIterator	&operator++()						{ --ptr; return (*this); }
			VRIterator	&operator+=(difference_type dt)		{ ptr = ptr - dt; return (*this); }
			VRIterator	&operator-=(difference_type dt)		{ ptr = ptr + dt; return (*this); }
			VRIterator	operator+(difference_type n) const	{ VRIterator<T> tmp(ptr - n); return tmp; }
			VRIterator	operator-(difference_type n) const	{ VRIterator<T> tmp(ptr + n); return tmp; }
			VRIterator	operator--(int)						{ VRIterator<T> tmp = *this; ++ptr; return tmp; }
			VRIterator	operator++(int)						{ VRIterator<T> tmp = *this; --ptr; return tmp; }
			difference_type operator-(VRIterator const &a) const { return (a.ptr - ptr); }
			template<typename D> 
			difference_type operator-(VRIterator<D> const &a) const { return (const_cast<T*>(a.getPtr()) - ptr); }
			bool operator==(VRIterator const &a) const
			{
				bool tmp = false;
				if (ptr == a.ptr)
					tmp = true;
				return tmp;
			}

			bool operator!=(VRIterator const &a) const
			{
				bool tmp = false;
				if (ptr != a.ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator==(VRIterator<D> const &a) const
			{
				bool tmp = false;
				if (ptr == const_cast<T*>(a.getPtr()))
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator!=(VRIterator<D> const &a) const
			{
				bool tmp = false;
				if (ptr != const_cast<T*>(a.getPtr()))
					tmp = true;
				return tmp;
			}

			bool operator<(VRIterator const &a) const
			{
				bool tmp = false;
				if (a.ptr < ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator<(VRIterator<D> const &a) const
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) < ptr)
					tmp = true;
				return tmp;
			}

			bool operator>(VRIterator const &a) const
			{
				bool tmp = false;
				if (a.ptr > ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator>(VRIterator<D> const &a) const
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) > ptr)
					tmp = true;
				return tmp;
			}
			
			bool operator<=(VRIterator const &a) const
			{
				bool tmp = false;
				if (a.ptr <= ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator<=(VRIterator<D> const &a) const
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) <= ptr)
					tmp = true;
				return tmp;
			}

			template<typename D>
			bool operator>=(VRIterator<D> const &a) const
			{
				bool tmp = false;
				if (const_cast<T*>(a.getPtr()) >= ptr)
					tmp = true;
				return tmp;
			}		

			bool operator>=(VRIterator const &a) const
			{
				bool tmp = false;
				if (a.ptr >= ptr)
					tmp = true;
				return tmp;
			}
	};

	template <typename T>
	VRIterator<T> operator+(int a, const VRIterator<T> &b){ return (b + a); }

	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef size_t size_type;

		private:
			T *_vptr;
			size_type _len;
			size_type _volume;

		public:
			typedef T *pointer;
			typedef	T value_type;
			typedef T &reference;
			typedef VIterator<T> iterator;
			typedef const T *const_pointer;
			typedef const T &const_reference;
			typedef std::ptrdiff_t difference_type;
			typedef VRIterator<T> reverse_iterator;
			typedef	std::allocator<T> allocator_type;
			typedef VIterator<const T> const_iterator;
			typedef	VRIterator<const T> const_reverse_iterator;

			class ErrorVectorException : public std::exception
			{
				public:
					virtual const char *what() const throw()
					{
						return ("ERROR: VECTOR");
					}
			};
	
			explicit vector(allocator_type const &a = allocator_type()) : _len(0), _volume(0)
			{
				(void)a;
				this->_vptr = 0;
			}

			explicit vector(size_type n, value_type const &v = value_type(), allocator_type const &a = allocator_type())
			{
				allocator_type _alloc = a;
				size_type i = 0;

				this->_len = n;
				this->_volume = n;
				_vptr = _alloc.allocate(_volume);
				while (i < _len)
				{
					_alloc.construct(_vptr + i, v);
					i++;
				}
			}

			template <typename II>
			vector(II a, II b, const allocator_type &al = allocator_type(), typename ft::enable_ifv<!ft::is_integralv<II>::value>::type type = 0)
			{
				allocator_type _alloc = al;
				II ii = a;
				size_type i = 0;
				(void)type;
				this->_len = 0;
				while (ii != b)
				{
					++ii;
					_len++;
				}
				this->_volume = _len;
				_vptr = _alloc.allocate(_volume);
				while (i < _len)
				{
					_alloc.construct(_vptr + i, *a++);
					i++;
				}
			}

			vector(vector const &a)
			{
				if (a._volume != 0)
				{
					size_type i = 0;
					allocator_type alloc;
					_vptr = alloc.allocate(a._volume);
					while (i < a._len)
					{
						alloc.construct(_vptr + i, a._vptr[i]);
						i++;
					}
				}
				else
					_vptr = 0;
				_len = a._len;
				_volume = a._volume;
			}

			~vector()
			{
				allocator_type alloc;
				size_type i = 0;
				while (_len > i)
				{
					alloc.destroy(_vptr + i);
					i++;
				}
				alloc.deallocate(_vptr, _volume);
			}
			
			T 		&operator[](size_type n) { return (_vptr[n]); }
			T const &operator[](size_type n) const { return (_vptr[n]); }
	
			vector 	&operator=(vector const &x)
			{
				allocator_type alloc;
				size_type i = 0;

				if (_volume < x._len)
				{
					if (_volume != 0)
					{
						i = 0;
						while (_len > i)
						{
							alloc.destroy(_vptr + i);
							i++;
						}
						alloc.deallocate(_vptr, _volume);
					}
					_vptr = alloc.allocate(x._len);
					i = 0;
					while (i < x._len)
					{
						alloc.construct(_vptr + i, x._vptr[i]);
						i++;
					}
					_volume = x._len;
				}
				else
				{
					if (_volume != 0)
					{
						i = 0;
						while (_len > i)
						{
							alloc.destroy(_vptr + i);
							i++;
						}
					}
					i = 0;
					while (i < x._len)
					{
						alloc.construct(_vptr + i, x._vptr[i]);
						i++;
					}
				}
				_len = x._len;
				return (*this);
			}
			
			iterator				begin()			{ return (iterator(_vptr)); 							}
			iterator				end() 			{ return (iterator(&_vptr[_len])); 						}
			const_iterator 			begin()	const	{ return (const_iterator(_vptr)); 						}
			const_iterator 			end()	const	{ return (const_iterator(&_vptr[_len])); 				}
			reverse_iterator		rbegin()		{ return (reverse_iterator(&_vptr[_len - 1])); 			}
			reverse_iterator		rend()			{ return (reverse_iterator(_vptr - 1)); 			 	}
			const_reverse_iterator	rbegin()const	{ return (const_reverse_iterator(&_vptr[_len - 1])); 	}
			const_reverse_iterator	rend()	const	{ return (const_reverse_iterator(_vptr - 1)); 			}
			size_type 				size() const 	{ return (_len); 										}
			size_type 				capacity() const{ return _volume; 										}
			reference 				front() 		{ return (_vptr[0]); 									}
			reference 				back () 		{ return (_vptr[_len - 1]);								}
			const_reference 		front()	const 	{ return (_vptr[0]);									}
			const_reference 		back ()	const 	{ return (_vptr[_len - 1]); 							}
			void 					pop_back()		{ allocator_type al; --_len; al.destroy(_vptr + _len);	}
			
			size_type max_size() const
			{
				size_type a = (size_type)std::numeric_limits<difference_type>::max();
				size_type b = std::numeric_limits<size_type>::max();
				b = b / sizeof(value_type);
				a = std::min(a, b);
				return a;
			}

			void resize(size_type a, value_type v = value_type())
			{
				if (a <= _volume)
				{
					size_type i = _len;
					while (i < a)
					{
						_vptr[i] = v;
						i++;
					}
					_len = a;
					return ;
				}
				else
				{
					if (_volume * 2 < a)
						reserve(a);
					else
						reserve(_volume * 2);
				}
				size_type i = _len;
				while (i < a)
				{
					_vptr[i] = v;
					i++;
				}
				_len = a;
			}
			
			reference  at(size_type n)
			{
				if (n < _len)
					return (_vptr[n]);
				else
					throw ErrorVectorException();
			}

			const_reference at(size_type n) const
			{
				if (n < _len)
					return (_vptr[n]);
				else
					throw ErrorVectorException();
			}

			bool empty() const
			{
				bool tmp = false;
				if (_len == 0)
					tmp = true;
				return tmp;
			}

			void reserve(size_type a)
			{
				if (a > _volume && a <= max_size())
				{
					size_type i = 0;
					allocator_type alloc;
					T *tmp = alloc.allocate(a);
					while (_len > i)
					{
						alloc.construct(tmp + i, _vptr[i]);
						i++;
					}
					i = 0;
					while (i < _len)
					{
						alloc.destroy(_vptr + i);
						i++;
					}
					alloc.deallocate(_vptr, _volume);
					_volume = a;
					_vptr = tmp;
				}
				if (a > max_size())
					throw ErrorVectorException();
			}	

			template <typename II>
			void assign(II be, II en, typename ft::enable_ifv<!ft::is_integralv<II>::value>::type t = 0)
			{	
				(void)t;
				II it = be;	
				allocator_type al; 
				size_type n = 0;
				size_type i = 0;
				for (;it != en; it++)
					n++;
				if (_volume < n)
					reserve(n);
				else
				{
					i = n;
					while (i < _len)
					{
						al.destroy(_vptr + i);
						i++;
					}
				}
				i = 0;
				while (i < n)
				{
					al.construct(_vptr + i, *be++);
					i++;
				}
				_len = n;
			}

			void push_back(value_type const &v)
			{
				allocator_type al;
				size_type c = 0;
				size_type i = 0;

				if (_volume <= _len && _volume != 0)
				{
					c = _volume * 2;
					T *temp = al.allocate(c);
					while (_volume > i)
					{
						al.construct(temp + i, _vptr[i]);
						i++;
					}
					al.construct(temp + _len, v);
					i = 0;
					while (_len > i)
					{
						al.destroy(_vptr + i);
						i++;
					}
					al.deallocate(_vptr, _volume);
					this->_vptr = temp;
					this->_len++;
					this->_volume = c;
				}
				else if (_volume == 0)
				{
					this->_vptr = al.allocate(1);
					al.construct(_vptr + _len, v);
					this->_len++;
					this->_volume = 1;
				}
				else
					this->_vptr[_len++] = v;
			}

			void assign(size_type n, value_type const &v)
			{
				allocator_type	alloc;
				size_type i = 0;
				if (_volume < n)
					reserve(n);
				else
				{
					i = n;
					while (i < _len)
					{
						alloc.destroy(_vptr + i);
						i++;
					}
				}
				i = 0;
				while (i < n)
				{
					alloc.construct(_vptr + i, v);
					i++;
				}
				_len = n;
			}

			void insert(iterator p, size_type n, value_type const &val)
			{
				allocator_type al;
				iterator i = begin();
				size_type j = 0;
				size_type len = 0;
				size_type tmp1 = 0;
				size_type tmp2 = 0;
				T *temp = 0;
				size_type c = _volume;

				if (n != 0)
				{
					for (;i != p; i++, j++)
						if (j > _len)
							break ;
					tmp1 = _len + n;
					if (_volume < tmp1)
					{
						tmp2 = _volume * 2;
						_volume = (tmp2 >= tmp1) ? tmp2 : tmp1;
						temp = al.allocate(_volume);
						i = begin();
						while (i != p)
						{
							al.construct(temp + len, *i);
							len++;
							i++;
						}
						for (size_type p = 0; p < n; p++)
						{
							al.construct(temp + len, val);
							len++;
						}
						i = p;
						while (i != end())
						{
							al.construct(temp + len, *i);
							len++;
							i++;
						}
						for (size_type i = 0; i < _len; i++)
							al.destroy(_vptr + i);
						al.deallocate(_vptr, c);
						_vptr = temp;
					}
					else if (_volume >= tmp1)
					{
						len = tmp1 - 1;
						tmp2 = _len - j;
						c = 0;
						while (c < tmp2)
						{
							al.construct(_vptr + len, _vptr[len - n]);
							len--;
							c++;
						}
						c = n;
						while (c)
						{
							al.construct(_vptr + len, val);
							len--;
							c--;
						}
					}
					_len = _len + n;
				}
			}

			void swap(vector &x)
			{
				T *temp = _vptr;
				size_type s = _len;
				size_type c = _volume;
				_vptr = x._vptr;
				_volume = x._volume;
				_len = x._len;
				x._vptr = temp;
				x._len = s;
				x._volume = c;
			}

			void clear()
			{
				allocator_type	al;
				size_type i = 0; 

				while (_len > i)
				{
					al.destroy(_vptr + i);
					i++;
				}
				_len = 0;
			}

			iterator insert(iterator p, value_type const &v)
			{
				allocator_type al;
				iterator  i = begin();
				size_type j = 0;
				size_type c = _volume;
				size_type be = 0;
				size_type len = 0;
				T *temp = 0;

				for (;i != p; i++, j++)
					if (j > _len)
						break ;
				if (_volume < _len + 1)
				{
					_volume *= 2;
					(_volume == 0) ? _volume = 1 : _volume;
					temp = al.allocate(_volume);
					while (i != p)
					{
						al.construct(temp + len, *i);
						len++;
						i++;
					}
					al.construct(temp + len, v);
					len++;
					i = p;
					while (i != end())
					{
						al.construct(temp + len, *i);
						len++;
						i++;
					}
					while (be < _len)
					{
						al.destroy(_vptr + be);
						be++;
					}
					al.deallocate(_vptr, c);
					_vptr = temp;
				}
				else if (_volume >= _len + 1)
				{
					len = _len;
					c = 0;
					while (c < _len - j)
					{
						al.construct(_vptr + len, _vptr[len - 1]);
						len--;
						c++;
					}
					al.construct(_vptr + len, v);
				}
				_len++;
				return (iterator(&_vptr[j]));
			}

			template<typename II>
			void insert(iterator p, II be, II en, typename ft::enable_ifv<!ft::is_integralv<II>::value>::type t = 0)
			{
				(void)t;
				allocator_type al;
				iterator i = begin();
				size_type j = 0;
				size_type len = 0;
				size_type c = _volume;
				size_type n = 0;
				size_type tmp1 = 0;
				size_type tmp2 = 0;
				T *temp = 0;

				for (II it = be; it != en; it++)
					n++;
				if (n != 0)
				{
					for (;i != p; i++, j++)
						if (j > _len)
							break ;
					tmp1 = _len + n;
					if (_volume < tmp1)
					{
						tmp2 = _volume * 2;
						_volume = (tmp2 >= tmp1) ? tmp2 : tmp1;
						temp = al.allocate(_volume);
						i = begin();
						while (i != p)
						{
							al.construct(temp + len, *i);
							len++;
							i++;
						}
						while (be != en)
						{
							al.construct(temp + len, *be);
							len++;
							be++;
						}
						i = p;
						while (i != end())
						{
							al.construct(temp + len, *i);
							len++;
							i++;
						}
						size_type i1 = 0;
						while (i1 < _len)
						{
							al.destroy(_vptr + i1);
							i1++;
						}
						al.deallocate(_vptr, c);
						_vptr = temp;
					}
					else if (_volume >= tmp1)
					{
						len = tmp1 - 1;
						c = 0;
						size_t aaa = 0;
						while (c < _len - j)
						{
							aaa = len - n;
							al.construct(_vptr + len, _vptr[aaa]);
							len--;
							c++;
						}
						while (' ')
						{
							en--;
							al.construct(_vptr + len, *en);
							len--;
							if (en == be)
								break ;
						}
					}
					_len = _len + n;
				}
			}

			iterator erase(iterator be, iterator en)
			{
				allocator_type al;
				iterator be1 = be;
				iterator en1;
				size_type n = 0;
				size_type m = 0;

				for(;be1 != en;)
				{
					be1++;
					n++;
				}
				be1 = be;
				en1 = be + n;
				for(;en1 != end(); be1++, en1++)
					*be1 = *en1;
				m = n;
				while (n)
				{
					al.destroy(_vptr + _len - n);
					n--;
				}
				_len = _len - m;
				return be;
			}

			iterator erase(iterator p)
			{
				allocator_type al;
				iterator be;
				iterator en;
				be = p;
				en = be;
				en++;
				for (;en != end(); be++, en++)
					*be = *en;
				--_len;
				al.destroy(_vptr + _len);
				return p;
			}
	};

	template <typename T, typename Alloc>
	bool operator!=(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{
		bool tmp = false;
		if (!(a == b))
			tmp = true;
		return tmp;
	}

	template <typename T, typename Alloc>
	bool operator==(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{
		bool tmp = true;
		size_t n = a.size();
		size_t i = 0;

		if (b.size() != a.size())
			tmp = false;
		else
		{
			while (i < n)
			{
				if (a[i] != b[i])
				{
					tmp = false;
					break ;
				}
				i++;
			}
		}
		return tmp;
	}

	template <typename T, typename Alloc>
	bool operator<(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{
		bool tmp = false;
		size_t i = 0;
		size_t n;
		int flag = 0;
		n = std::min(a.size(), b.size());
		while (i < n)
		{
			if (a[i] > b[i])
			{
				flag = 1;
				break ;
			}
			else if (a[i] < b[i])
			{
				tmp = true;
				break ;
			}
			i++;
		}
		if (b.size() > n && flag == 0)
			tmp = true;
		return tmp;
	}

	template <typename T, typename Alloc>
	bool operator>(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{
		bool tmp = false;
		if  (b < a)
			tmp = true;
		return tmp;
	}

	template <typename T, typename Alloc>
	bool operator<=(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{
		bool tmp = false;
		if (!(b < a))
			tmp = true;
		return tmp;
	}

	template <typename T, typename Alloc>
	bool operator>=(vector<T, Alloc> const &a, vector<T, Alloc> const &b)
	{
		bool tmp = false;
		if (!(a < b))
			tmp = true;
		return tmp;
	}	

	template <typename T, typename Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }
}


#endif