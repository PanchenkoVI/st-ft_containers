/*
* Created: 2021/06/27
*/

#include "../../header/map/Map.hpp"

#include <map>

static void ft_hdm(int i, int j)
{
	if (i == 1)
	{
		if (j == 1)
			std::cout << "STD: NUMBER: ";
		else if (j == 2)
			std::cout << "STD: STRING: ";
	}
	else if (i == 2)
	{
		std::cout << FIO;
		if (j == 1)
			std::cout << "FT:  NUMBER: ";
		else if (j == 2)
			std::cout << "FT:  STRING: ";
	}
}

static bool fncomp (char lhs, char rhs) {
	return lhs < rhs;
}

struct classcomp { bool operator() (const char& lhs, const char& rhs) const {
	return lhs < rhs;
	} 
};

static void	test_constructor(void)
{
	std::cout << "#------------->" << REDC << " CONSTRUCTOR" << END  << std::endl;
	std::map<char,int> first;
	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;
	std::map<char, int> second (first.begin(),first.end());
	std::map<char, int> third (second);
	std::map<char, int, classcomp> fourth;
	bool(*fn_pt)(char, char) = fncomp;
	std::map<char, int, bool(*)(char, char) > fifth (fn_pt);
	try
	{
		ft::map <char, int> first1;
		first1['a'] = 10;
		first1['b'] = 30;
		first1['c'] = 50;
		first1['d'] = 70;
		ft::map<char, int> second1 (first1.begin(), first1.end());
		ft::map<char, int> third1 (second1);
		ft::map<char, int, classcomp> fourth1;
		bool(*fn_pt1)(char, char) = fncomp;
		ft::map<char, int, bool(*)(char, char) > fifth1 (fn_pt1);
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_operator(void)
{
	std::cout << "#------------->" << REDC << " OPERATOR" << END  << std::endl;
	std::map<char, int> first;
	std::map<char, int> second;
	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;
	second = first;
	first = std::map<char,int>();
	ft_hdm(1, 1);
	std::cout << "Size of  first =  " << first.size();
	std::cout << " | Size of second = " << second.size() << " |" << std::endl;
	std::map<char, std::string> firsta;
	std::map<char, std::string> seconda;
	firsta['x'] = "a";
	firsta['y'] = "bb";
	firsta['z'] = "ccc";
	seconda = firsta;
	firsta = std::map<char, std::string>();
	ft_hdm(1, 2);
	std::cout << "Size of  first =  " << firsta.size();
	std::cout << " | Size of second = " << seconda.size() << " |" << std::endl;
	try
	{
		ft::map<char, int> firstft;
		ft::map<char, int> secondft;
		firstft['x'] = 8;
		firstft['y'] = 16;
		firstft['z'] = 32;
		secondft = firstft;
		firstft = ft::map<char, int>();
		ft_hdm(2, 1);
		std::cout << "Size of  first =  " << firstft.size();
		std::cout << " | Size of second = " << secondft.size() << " |" << std::endl;
		ft::map<char, std::string> firstaft;
		ft::map<char, std::string> secondaft;
		firstaft['x'] = "a";
		firstaft['y'] = "bb";
		firstaft['z'] = "ccc";
		secondaft = firstaft;
		firstaft = ft::map<char, std::string>();
		ft_hdm(2, 2);
		std::cout << "Size of  first =  " << firstaft.size();
		std::cout << " | Size of second = " << secondaft.size() << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_begin_end(void)
{
	std::cout << "#------------->" << REDC << " BEGIN and END" << END  << std::endl;
	std::map<char, int> mymap;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	ft_hdm(1, 1);
	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	mymap1['b'] = "100";
	mymap1['a'] = "200";
	mymap1['c'] = "300";
	ft_hdm(1, 2);
	for (std::map<char, std::string>::iterator it = mymap1.begin(); it != mymap1.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft['b'] = 100;
		mymapft['a'] = 200;
		mymapft['c'] = 300;
		ft_hdm(2, 1);
		for (ft::map<char, int>::iterator it = mymapft.begin(); it != mymapft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		mymap1ft['b'] = "100";
		mymap1ft['a'] = "200";
		mymap1ft['c'] = "300";
		ft_hdm(2, 2);
		for (ft::map<char, std::string>::iterator it = mymap1ft.begin(); it != mymap1ft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_rbegin_rend(void)
{
	std::cout << "#------------->" << REDC << " RBEGIN and REND" << END  << std::endl;
	std::map<char, int> mymap;
	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;
	std::map<char, int>::reverse_iterator rit;
	ft_hdm(1, 1);
	for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
		std::cout << " | " << rit->first << " => " << rit->second;
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	mymap1['x'] = "100";
	mymap1['y'] = "200";
	mymap1['z'] = "300";
	std::map<char, std::string>::reverse_iterator rit1;
	ft_hdm(1, 2);
	for (rit1 = mymap1.rbegin(); rit1 != mymap1.rend(); ++rit1)
		std::cout << " | " << rit1->first << " => " << rit1->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft['x'] = 100;
		mymapft['y'] = 200;
		mymapft['z'] = 300;
		ft::map<char, int>::reverse_iterator ritft;
		ft_hdm(2, 1);
		for (ritft = mymapft.rbegin(); ritft != mymapft.rend(); ++ritft)
			std::cout << " | " << ritft->first << " => " << ritft->second;
		std::cout << " |" << std::endl;
		std::map<char, std::string> mymap1ft;
		mymap1ft['x'] = "100";
		mymap1ft['y'] = "200";
		mymap1ft['z'] = "300";
		std::map<char, std::string>::reverse_iterator rit1ft;
		ft_hdm(2, 2);
		for (rit1ft = mymap1ft.rbegin(); rit1ft != mymap1ft.rend(); ++rit1ft)
			std::cout << " | " << rit1ft->first << " => " << rit1ft->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_empty(void)
{
	std::cout << "#------------->" << REDC << " EMPTY" << END  << std::endl;
	std::map<char, int> mymap;
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	ft_hdm(1, 1);
	while (!mymap.empty())
	{
		std::cout << " | " << mymap.begin()->first << " => " << mymap.begin()->second;
		mymap.erase(mymap.begin());
	}
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	mymap1['a'] = "10";
	mymap1['b'] = "20";
	mymap1['c'] = "30";
	ft_hdm(1, 2);
	while (!mymap1.empty())
	{
		std::cout << " | " << mymap1.begin()->first << " => " << mymap1.begin()->second;
		mymap1.erase(mymap1.begin());
	}
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft['a'] = 10;
		mymapft['b'] = 20;
		mymapft['c'] = 30;
		ft_hdm(2, 1);
		while (!mymapft.empty())
		{
			std::cout << " | " << mymapft.begin()->first << " => " << mymapft.begin()->second;
			mymapft.erase(mymapft.begin());
		}
		std::cout << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		mymap1ft['a'] = "10";
		mymap1ft['b'] = "20";
		mymap1ft['c'] = "30";
		ft_hdm(2, 2);
		while (!mymap1ft.empty())
		{
			std::cout << " | " << mymap1ft.begin()->first << " => " << mymap1ft.begin()->second;
			mymap1ft.erase(mymap1ft.begin());
		}
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_size(void)
{
	std::cout << "#------------->" << REDC << " SIZE" << END  << std::endl;
	std::map<char, int> mymap;
	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 302;
	ft_hdm(1, 1);
	std::cout << "mymap.size()      is " << mymap.size() << std::endl;
	ft::map<char, std::string> mymapft;
	mymapft['a'] = "101";
	mymapft['b'] = "202";
	mymapft['c'] = "302";
	ft_hdm(1, 2);
	std::cout << "mymap['a'].size() is " << mymapft['a'].size() <<  std::endl;
	ft_hdm(1, 2);
	std::cout <<  "mymap['d'].size() is " << mymapft['d'].size() <<  std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft['a'] = 101;
		mymapft['b'] = 202;
		mymapft['c'] = 302;
		ft_hdm(2, 1);
		std::cout << "mymap.size()      is " << mymapft.size() << std::endl;
		ft::map<char, std::string> mymapftft;
		mymapftft['a'] = "101";
		mymapftft['b'] = "202";
		mymapftft['c'] = "302";
		ft_hdm(2, 2);
		std::cout << "mymap['a'].size() is " << mymapftft['a'].size() <<  std::endl;
		ft_hdm(2, 2);
		std::cout <<  "mymap['d'].size() is " << mymapftft['d'].size() <<  std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_max_size(void)
{
	std::cout << "#------------->" << REDC << " MAX SIZE" << END  << std::endl;
	int i;
	std::map<int, int> mymap;
	if (mymap.max_size() > 1000)
	{
		for (int i = 0; i < 1000; i++)
			mymap[i] = 0;
		ft_hdm(1, 1);
		std::cout << "The map contains 1000 elements." << std::endl;
	}
	else
	{
		ft_hdm(1, 1);
		std::cout << "The map could not hold 1000 elements." << std::endl;
	}
	i = 0;
	std::map<int, std::string> mymap1;
	if (mymap1.max_size() > 1000)
	{
		for (int i = 0; i < 1000; i++)
			mymap1[i] = "0";
		ft_hdm(1, 2);
		std::cout << "The map contains 1000 elements." << std::endl;
	}
	else
	{
		ft_hdm(1, 2);
		std::cout << "The map could not hold 1000 elements." << std::endl;
	}	
	try
	{
		ft::map<int, int> mymapft;
		if (mymapft.max_size() > 1000)
		{
			for (int i = 0; i < 1000; i++)
				mymapft[i] = 0;
			ft_hdm(2, 1);
			std::cout << "The map contains 1000 elements." << std::endl;
		}
		else
		{
			ft_hdm(2, 1);
			std::cout << "The map could not hold 1000 elements." << std::endl;
		}
		i = 0;
		ft::map<int, std::string> mymap12;
		if (mymap12.max_size() > 1000)
		{
			for (int i = 0; i < 1000; i++)
				mymap12[i] = "0";
			ft_hdm(2, 2);
			std::cout << "The map contains 1000 elements." << std::endl;
		}
		else
		{
			ft_hdm(2, 2);
			std::cout << "The map could not hold 1000 elements." << std::endl;
		}
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_operator2(void)
{
	std::cout << "#------------->" << REDC << " OPERATOR2" << END  << std::endl;
	std::map<char, std::string> mymap;
	mymap['a'] = "ok";
	mymap['b'] = "ko";
	mymap['c'] = mymap['b'];
	ft_hdm(1, 2);
	std::cout << "mymap['a'] = " << mymap['a'];
	std::cout << " | mymap['b'] = " << mymap['b'] << std::endl;
	ft_hdm(1, 2);
	std::cout << "mymap['c'] = " << mymap['c'];
	std::cout << " | mymap['d'] = " << mymap['d'] << std::endl;
	ft_hdm(1, 2);
	std::cout << "mymap now contains " << mymap.size() << " elements." << std::endl;
	try
	{
		ft::map<char, std::string> mymapft;
		mymapft['a'] = "ok";
		mymapft['b'] = "ko";
		mymapft['c'] = mymapft['b'];
		ft_hdm(2, 2);
		std::cout << "mymap['a'] = " << mymapft['a'];
		std::cout << " | mymap['b'] = " << mymapft['b'] << std::endl;
		ft_hdm(2, 2);
		std::cout << "mymap['c'] = " << mymapft['c'];
		std::cout << " | mymap['d'] = " << mymapft['d'] << std::endl;
		ft_hdm(2, 2);
		std::cout << "mymap now contains " << mymapft.size() << " elements." << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_insert(void)
{
	std::cout << "#------------->" << REDC << " INSERT" << END  << std::endl;
	std::map<char, int> mymap;
	mymap.insert (std::pair<char, int> ('a',100));
	mymap.insert (std::pair<char, int> ('z',200));
	std::pair<std::map<char, int>::iterator, bool> ret;
	ret = mymap.insert (std::pair<char, int>('z',500));
	if (ret.second == false) {
		ft_hdm(1, 1);
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << std::endl;
	}
	std::map<char, int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char, int>('b',300));
	mymap.insert (it, std::pair<char, int>('c',400));
	std::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));
	ft_hdm(1, 1);
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	std::cout << "STD: anothermap contains:\n";
	ft_hdm(1, 1);
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft.insert (std::pair<char, int> ('a',100));
		mymapft.insert (std::pair<char, int> ('z',200));
		std::pair<ft::map<char, int>::iterator, bool> retft;
		retft = mymapft.insert (std::pair<char, int>('z',500));
		if (retft.second == false) {
			ft_hdm(2, 1);
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << retft.first->second << std::endl;
		}
		ft::map<char, int>::iterator itft = mymapft.begin();
		mymapft.insert (itft, std::pair<char, int>('b',300));
		mymapft.insert (itft, std::pair<char, int>('c',400));
		ft::map<char, int> anothermapft;
		anothermapft.insert(mymapft.begin(), mymapft.find('c'));
		ft_hdm(2, 1);
		for (itft = mymapft.begin(); itft != mymapft.end(); ++itft)
			std::cout << " | " << itft->first << " => " << itft->second;
		std::cout << " |" << std::endl;
		std::cout << "FT:  anothermap contains:\n";
		ft_hdm(2, 1);
		for (itft = anothermapft.begin(); itft != anothermapft.end(); ++itft)
			std::cout << " | " << itft->first << " => " << itft->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_erase(void)
{
	std::cout << "#------------->" << REDC << " ERASE" << END  << std::endl;
	std::map<char, int> mymap;
	std::map<char, int>::iterator it;
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;
	it = mymap.find('b');
	mymap.erase (it);
	mymap.erase ('c');
	it = mymap.find ('e');
	mymap.erase (it, mymap.end());
	ft_hdm(1, 1);
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |"<< std::endl;
	std::map<char, std::string> mymap1;
	std::map<char, std::string>::iterator it1s;
	mymap1['a'] = "10";
	mymap1['b'] = "20";
	mymap1['c'] = "30";
	mymap1['d'] = "40";
	mymap1['e'] = "50";
	mymap1['f'] = "60";
	it1s = mymap1.find('b');
	mymap1.erase (it1s);
	mymap1.erase ('c');
	it1s = mymap1.find ('e');
	mymap1.erase (it1s, mymap1.end());
	ft_hdm(1, 2);
	for (it1s = mymap1.begin(); it1s != mymap1.end(); ++it1s)
		std::cout << " | " << it1s->first << " => " << it1s->second;
	std::cout << " |"<< std::endl;
	try
	{
		ft::map<char, int> mymap1;
		ft::map<char, int>::iterator it1;
		mymap1['a'] = 10;
		mymap1['b'] = 20;
		mymap1['c'] = 30;
		mymap1['d'] = 40;
		mymap1['e'] = 50;
		mymap1['f'] = 60;
		it1 = mymap1.find('b');
		mymap1.erase (it1);
		mymap1.erase ('c');
		it1 = mymap1.find ('e');
		mymap1.erase (it1, mymap1.end());
		ft_hdm(2, 1);
		for (it1 = mymap1.begin(); it1 != mymap1.end(); ++it1)
			std::cout << " | " << it1->first << " => " << it1->second;
		std::cout << " |"<< std::endl;
		ft::map<char, std::string> mymap1ft;
		ft::map<char, std::string>::iterator it1sft;
		mymap1ft['a'] = "10";
		mymap1ft['b'] = "20";
		mymap1ft['c'] = "30";
		mymap1ft['d'] = "40";
		mymap1ft['e'] = "50";
		mymap1ft['f'] = "60";
		it1sft = mymap1ft.find('b');
		mymap1ft.erase (it1sft);
		mymap1ft.erase ('c');
		it1sft = mymap1ft.find ('e');
		mymap1ft.erase (it1sft, mymap1ft.end());
		ft_hdm(2, 2);
		for (it1sft = mymap1ft.begin(); it1sft != mymap1ft.end(); ++it1sft)
			std::cout << " | " << it1sft->first << " => " << it1sft->second;
		std::cout << " |"<< std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_swap(void)
{
	std::cout << "#------------->" << REDC << " SWAP" << END  << std::endl;
	std::map<char, int> foo, bar;
	foo['x'] = 100;
	foo['y'] = 200;
	bar['a'] = 111;
	bar['b'] = 222;
	bar['c'] = 333;
	foo.swap(bar);
	ft_hdm(1, 1);
	std::cout << "foo contains:";
	for (std::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	ft_hdm(1, 1);
	std::cout << "bar contains:";
	for (std::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	std::map<char, std::string> foo1, bar1;
	foo1['x'] = "100";
	foo1['y'] = "200";
	bar1['a'] = "111";
	bar1['b'] = "222";
	bar1['c'] = "333";
	foo1.swap(bar1);
	ft_hdm(1, 2);
	std::cout << "foo contains:";
	for (std::map<char, std::string>::iterator it = foo1.begin(); it != foo1.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	ft_hdm(1, 2);
	std::cout << "bar contains:";
	for (std::map<char, std::string>::iterator it = bar1.begin(); it != bar1.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> fooft, barft;
		fooft['x'] = 100;
		fooft['y'] = 200;
		barft['a'] = 111;
		barft['b'] = 222;
		barft['c'] = 333;
		fooft.swap(barft);
		ft_hdm(2, 1);
		std::cout << "foo contains:";
		for (ft::map<char, int>::iterator itft = fooft.begin(); itft != fooft.end(); ++itft)
			std::cout << " | " << itft->first << " => " << itft->second;
		std::cout << " |" << std::endl;
		ft_hdm(2, 1);
		std::cout << "bar contains:";
		for (ft::map<char, int>::iterator it = barft.begin(); it != barft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		ft::map<char, std::string> foo1ft, bar1ft;
		foo1ft['x'] = "100";
		foo1ft['y'] = "200";
		bar1ft['a'] = "111";
		bar1ft['b'] = "222";
		bar1ft['c'] = "333";
		foo1ft.swap(bar1ft);
		ft_hdm(2, 2);
		std::cout << "foo contains:";
		for (ft::map<char, std::string>::iterator it = foo1ft.begin(); it != foo1ft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		ft_hdm(2, 2);
		std::cout << "bar contains:";
		for (ft::map<char, std::string>::iterator it = bar1ft.begin(); it != bar1ft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_clear(void)
{
	std::cout << "#------------->" << REDC << " CLEAR" << END  << std::endl;
	std::map<char, int> mymap;
	mymap['x'] = 1000;
	mymap['y'] = 2000;
	mymap['z'] = 3000;
	ft_hdm(1, 1);
	std::cout << "mymap contains:";
	for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	mymap.clear();
	mymap['a'] = 1111;
	mymap['b'] = 2222;
	ft_hdm(1, 1);
	std::cout << "mymap contains:";
	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	mymap1['x'] = "1000";
	mymap1['y'] = "2000";
	mymap1['z'] = "3000";
	ft_hdm(1, 2);
	std::cout << "mymap contains:";
	for (std::map<char, std::string>::iterator it = mymap1.begin(); it != mymap1.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	mymap1.clear();
	mymap1['a'] = "1111";
	mymap1['b'] = "2222";
	ft_hdm(1, 2);
	std::cout << "mymap contains:";
	for (std::map<char, std::string>::iterator it = mymap1.begin(); it != mymap1.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft['x'] = 1000;
		mymapft['y'] = 2000;
		mymapft['z'] = 3000;
		ft_hdm(2, 1);
		std::cout << "mymap contains:";
		for (ft::map<char,int>::iterator it = mymapft.begin(); it != mymapft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		mymapft.clear();
		mymapft['a'] = 1111;
		mymapft['b'] = 2222;
		ft_hdm(2, 1);
		std::cout << "mymap contains:";
		for (ft::map<char, int>::iterator it = mymapft.begin(); it != mymapft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		mymap1ft['x'] = "1000";
		mymap1ft['y'] = "2000";
		mymap1ft['z'] = "3000";
		ft_hdm(2, 2);
		std::cout << "mymap contains:";
		for (ft::map<char, std::string>::iterator it = mymap1ft.begin(); it != mymap1ft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		mymap1ft.clear();
		mymap1ft['a'] = "1111";
		mymap1ft['b'] = "2222";
		ft_hdm(2, 2);
		std::cout << "mymap contains:";
		for (ft::map<char, std::string>::iterator it = mymap1ft.begin(); it != mymap1ft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_key_comp(void)
{
	std::cout << "#------------->" << REDC << " KEY_COM" << END  << std::endl;
	std::map<char, int> mymap;
	std::map<char, int>::key_compare mycomp = mymap.key_comp();
	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;
	ft_hdm(1, 1);
	std::cout << "contains:";
	char highest = mymap.rbegin()->first;
	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << " | " << it->first << " => " << it->second;
	} while (mycomp((*it++).first, highest));
	std::cout << " |"<< std::endl;
	std::map<char, std::string> mymap1;
	std::map<char, std::string>::key_compare mycomp1 = mymap1.key_comp();
	mymap1['a'] = "100";
	mymap1['b'] = "200";
	mymap1['c'] = "300";
	ft_hdm(1, 2);
	std::cout << "contains:";
	char highest1 = mymap1.rbegin()->first;
	std::map<char,std::string>::iterator it1 = mymap1.begin();
	do {
		std::cout << " | " << it1->first << " => " << it1->second;
	} while (mycomp1((*it1++).first, highest1));
	std::cout << " |"<< std::endl;
	try
	{
		ft::map<char, int> mymapft;
		ft::map<char, int>::key_compare mycompft = mymapft.key_comp();
		mymapft['a'] = 100;
		mymapft['b'] = 200;
		mymapft['c'] = 300;
		ft_hdm(2, 1);
		std::cout << "contains:";
		char highestft = mymapft.rbegin()->first;
		ft::map<char,int>::iterator itft = mymapft.begin();
		do { std::cout << " | " << itft->first << " => " << itft->second;
		} while (mycompft((*itft++).first, highestft));
		std::cout << " |"<< std::endl;
		ft::map<char, std::string> mymap1ft;
		ft::map<char, std::string>::key_compare mycomp1ft = mymap1ft.key_comp();
		mymap1ft['a'] = "100";
		mymap1ft['b'] = "200";
		mymap1ft['c'] = "300";
		ft_hdm(2, 2);
		std::cout << "contains:";
		char highest1ft = mymap1ft.rbegin()->first;
		ft::map<char,std::string>::iterator it1ft = mymap1ft.begin();
		do { std::cout << " | " << it1ft->first << " => " << it1ft->second;
		} while (mycomp1ft((*it1ft++).first, highest1ft));
		std::cout << " |"<< std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_value_comp(void)
{
	std::cout << "#------------->" << REDC << " VALUE_COMP" << END  << std::endl;
	std::map<char, int> mymap;
	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;
	ft_hdm(1, 1);
	std::cout << "contains:";
	std::pair<char, int> highest = *mymap.rbegin();
	std::map<char, int>::iterator it = mymap.begin();
	do { std::cout << " | " << it->first << " => " << it->second;
	} while (mymap.value_comp()(*it++, highest));
	std::cout << " | " << std::endl;
	std::map<char, std::string> mymap2;
	mymap2['x'] = "1001";
	mymap2['y'] = "2002";
	mymap2['z'] = "3003";
	ft_hdm(1, 2);
	std::cout << "contains:";
	std::pair<char, std::string> highest2 = *mymap2.rbegin();
	std::map<char, std::string>::iterator it2 = mymap2.begin();
	do { std::cout << " | " << it2->first << " => " << it2->second;
	} while (mymap2.value_comp()(*it2++, highest2));
	std::cout << " | " << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft['x'] = 1001;
		mymapft['y'] = 2002;
		mymapft['z'] = 3003;
		ft_hdm(2, 1);
		std::cout << "contains:";
		std::pair<char, int> highestft = *mymapft.rbegin();
		ft::map<char, int>::iterator itft = mymapft.begin();
		do { std::cout << " | " << itft->first << " => " << itft->second;
		} while (mymapft.value_comp()(*itft++, highestft));
		std::cout << " | " << std::endl;
		ft::map<char, std::string> mymap2ft;
		mymap2ft['x'] = "1001";
		mymap2ft['y'] = "2002";
		mymap2ft['z'] = "3003";
		ft_hdm(2, 2);
		std::cout << "contains:";
		std::pair<char, std::string> highest2ft = *mymap2ft.rbegin();
		ft::map<char, std::string>::iterator it2ft = mymap2ft.begin();
		do { std::cout << " | " << it2ft->first << " => " << it2ft->second;
		} while (mymap2ft.value_comp()(*it2ft++, highest2ft));
		std::cout << " | " << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_find(void)
{
	std::cout << "#------------->" << REDC << " FIND" << END  << std::endl;
	std::map<char, int> mymap;
	std::map<char, int>::iterator it;
	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;
	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);
	ft_hdm(1, 1);
	std::cout << "mymap:";
	std::cout << " | a => " << mymap.find('a')->second;
	std::cout << " | c => " << mymap.find('c')->second;
	std::cout << " | d => " << mymap.find('d')->second << " |" << std::endl;
	std::map<char, std::string> mymap1;
	std::map<char, std::string>::iterator it1;
	mymap1['a'] = "50";
	mymap1['b'] = "100";
	mymap1['c'] = "150";
	mymap1['d'] = "200";
	it1 = mymap1.find('b');
	if (it1 != mymap1.end())
		mymap1.erase (it1);
	ft_hdm(1, 2);
	std::cout << "mymap:";
	std::cout << " | a => " << mymap1.find('a')->second;
	std::cout << " | c => " << mymap1.find('c')->second;
	std::cout << " | d => " << mymap1.find('d')->second << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		ft::map<char, int>::iterator itft;
		mymapft['a'] = 50;
		mymapft['b'] = 100;
		mymapft['c'] = 150;
		mymapft['d'] = 200;
		itft = mymapft.find('b');
		if (itft != mymapft.end())
			mymapft.erase (itft);
		ft_hdm(2, 1);
		std::cout << "mymap:";
		std::cout << " | a => " << mymapft.find('a')->second;
		std::cout << " | c => " << mymapft.find('c')->second;
		std::cout << " | d => " << mymapft.find('d')->second << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		ft::map<char, std::string>::iterator it1ft;
		mymap1ft['a'] = "50";
		mymap1ft['b'] = "100";
		mymap1ft['c'] = "150";
		mymap1ft['d'] = "200";
		it1ft = mymap1ft.find('b');
		if (it1ft != mymap1ft.end())
			mymap1ft.erase (it1ft);
		ft_hdm(2, 2);
		std::cout << "mymap:";
		std::cout << " | a => " << mymap1ft.find('a')->second;
		std::cout << " | c => " << mymap1ft.find('c')->second;
		std::cout << " | d => " << mymap1ft.find('d')->second << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void test_add_max_sizem()
{
	std::cout << "#------------->" << REDC << " ADD_MAX_SIZE" << END  << std::endl;
	ft::map<std::string, std::string> f1;
	ft::map<int, int> f2;
	ft::map<float, float> f3;
	ft::map<char, char> f4;
	std::map<std::string, std::string> s1;
	std::map<int, int> s2;
	std::map<float, float> s3;
	ft::map<char, char> s4;
	std::cout << "STD: MAX_SIZE = " << s1.max_size() << std::endl;
	std::cout << "STD: MAX_SIZE = " << s2.max_size() << std::endl;
	std::cout << "STD: MAX_SIZE = " << s3.max_size() << std::endl;
	std::cout << "STD: MAX_SIZE = " << s4.max_size() << std::endl;
	std::cout << FIO << "FT : MAX_SIZE = " << f1.max_size() << std::endl;
	std::cout << "FT : MAX_SIZE = " << f2.max_size() << std::endl;
	std::cout << "FT : MAX_SIZE = " << f3.max_size() << std::endl;
	std::cout << "FT : MAX_SIZE = " << f4.max_size() << std::endl;
	std::cout << GREEN << "RESULT: OK" << END << std::endl;
}

static void	test_count(void)
{
	std::cout << "#------------->" << REDC << " COUNT" << END  << std::endl;
	std::map<char, int> mymap;
	char c;
	mymap['a'] = 101;
	mymap['c'] = 202;
	mymap['f'] = 303;
	ft_hdm(1, 1);
	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << " | " << c;
		if (mymap.count(c) > 0)
			std::cout << GREEN << " = OK" << END;
		else 
			std::cout << REDC << " = KO" << END;
	}
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	mymap1['a'] = "101";
	mymap1['c'] = "202";
	mymap1['f'] = "303";
	ft_hdm(1, 2);
	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << " | " << c;
		if (mymap1.count(c) > 0)
			std::cout << GREEN << " = OK" << END;
		else 
			std::cout << REDC << " = KO" << END;
	}
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		char cft;
		mymapft['a'] = 101;
		mymapft['c'] = 202;
		mymapft['f'] = 303;
		ft_hdm(2, 1);
		for (cft = 'a'; cft < 'h'; cft++)
		{
			std::cout << END << " | " << cft;
			if (mymapft.count(cft) > 0)
				std::cout << GREEN << " = OK" << END;
			else 
				std::cout << REDC << " = KO" << END;
		}
		std::cout << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		mymap1ft['a'] = "101";
		mymap1ft['c'] = "202";
		mymap1ft['f'] = "303";
		ft_hdm(2, 2);
		for (cft = 'a'; cft < 'h'; cft++)
		{
			std::cout << END << " | " << cft;
			if (mymap1ft.count(cft) > 0)
				std::cout << GREEN << " = OK" << END;
			else 
				std::cout << REDC << " = KO" << END;
		}
		std::cout << " |" << std::endl;

		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_lower_bound(void)
{
	std::cout << "#------------->" << REDC << " LOWER_BOUND" << END  << std::endl;
	std::map<char, int> mymap;
	std::map<char, int>::iterator itlow, itup;
	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;
	itlow = mymap.lower_bound ('b');
	itup = mymap.upper_bound ('d');
	mymap.erase(itlow, itup);
	ft_hdm(1, 1);
	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	std::map<char, std::string>::iterator itlow1, itup1;
	mymap1['a'] = "20";
	mymap1['b'] = "40";
	mymap1['c'] = "60";
	mymap1['d'] = "80";
	mymap1['e'] = "100";
	itlow1 = mymap1.lower_bound ('b');
	itup1 = mymap1.upper_bound ('d');
	mymap1.erase(itlow1, itup1);
	ft_hdm(1, 2);
	for (std::map<char, std::string>::iterator it = mymap1.begin(); it != mymap1.end(); ++it)
		std::cout << " | " << it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		ft::map<char, int>::iterator itlowft, itupft;
		mymapft['a'] = 20;
		mymapft['b'] = 40;
		mymapft['c'] = 60;
		mymapft['d'] = 80;
		mymapft['e'] = 100;
		itlowft = mymapft.lower_bound ('b');
		itupft = mymapft.upper_bound ('d');
		mymapft.erase(itlowft, itupft);
		ft_hdm(2, 1);
		for (ft::map<char, int>::iterator it = mymapft.begin(); it != mymapft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		ft::map<char, std::string>::iterator itlow1ft, itup1ft;
		mymap1ft['a'] = "20";
		mymap1ft['b'] = "40";
		mymap1ft['c'] = "60";
		mymap1ft['d'] = "80";
		mymap1ft['e'] = "100";
		itlow1ft = mymap1ft.lower_bound ('b');
		itup1ft = mymap1ft.upper_bound ('d');
		mymap1ft.erase(itlow1ft, itup1ft);
		ft_hdm(2, 2);
		for (ft::map<char, std::string>::iterator it = mymap1ft.begin(); it != mymap1ft.end(); ++it)
			std::cout << " | " << it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_upper_bound(void)
{
	std::cout << "#------------->" << REDC << " UPPER_BOUND" << END  << std::endl;
	std::map<char, int> mymap;
	std::map<char, int>::iterator itlow, itup;
	mymap['a'] = 100;
	mymap['b'] = 30;
	mymap['c'] = 20;
	mymap['d'] = 40;
	mymap['e'] = 50;
	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');
	mymap.erase(itlow, itup);
	ft_hdm(1, 1);
	for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " | "<< it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	std::map<char, std::string>::iterator itlow1, itup1;
	mymap1['a'] = "100";
	mymap1['b'] = "30";
	mymap1['c'] = "20";
	mymap1['d'] = "40";
	mymap1['e'] = "50";
	itlow1 = mymap1.lower_bound('b');
	itup1 = mymap1.upper_bound('d');
	mymap1.erase(itlow1, itup1);
	ft_hdm(1, 2);
	for (std::map<char, std::string>::iterator it = mymap1.begin(); it != mymap1.end(); ++it)
		std::cout << " | "<< it->first << " => " << it->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		ft::map<char, int>::iterator itlowft, itupft;
		mymapft['a'] = 100;
		mymapft['b'] = 30;
		mymapft['c'] = 20;
		mymapft['d'] = 40;
		mymapft['e'] = 50;
		itlowft = mymapft.lower_bound('b');
		itupft = mymapft.upper_bound('d');
		mymapft.erase(itlowft, itupft);
		ft_hdm(2, 1);
		for (ft::map<char,int>::iterator it = mymapft.begin(); it != mymapft.end(); ++it)
			std::cout << " | "<< it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		ft::map<char, std::string>::iterator itlow1ft, itup1ft;
		mymap1ft['a'] = "100";
		mymap1ft['b'] = "30";
		mymap1ft['c'] = "20";
		mymap1ft['d'] = "40";
		mymap1ft['e'] = "50";
		itlow1ft = mymap1ft.lower_bound('b');
		itup1ft = mymap1ft.upper_bound('d');
		mymap1ft.erase(itlow1ft, itup1ft);
		ft_hdm(2, 2);
		for (ft::map<char, std::string>::iterator it = mymap1ft.begin(); it != mymap1ft.end(); ++it)
			std::cout << " | "<< it->first << " => " << it->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	test_equal_range(void)
{
	std::cout << "#------------->" << REDC << " EQUAL_RANGE" << END  << std::endl;
	std::map<char, int> mymap;
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
	ret = mymap.equal_range('b');
	ft_hdm(1, 1);
	std::cout << " | lower: " << ret.first->first << " => " << ret.first->second;
	std::cout << " | upper: " << ret.second->first << " => " << ret.second->second;
	std::cout << " |" << std::endl;
	std::map<char, std::string> mymap1;
	mymap1['a'] = "10";
	mymap1['b'] = "20";
	mymap1['c'] = "30";
	std::pair<std::map<char, std::string>::iterator, std::map<char, std::string>::iterator> ret1;
	ret1 = mymap1.equal_range('b');
	ft_hdm(1, 2);
	std::cout << " | lower: " << ret1.first->first << " => " << ret1.first->second;
	std::cout << " | upper: " << ret1.second->first << " => " << ret1.second->second;
	std::cout << " |" << std::endl;
	try
	{
		ft::map<char, int> mymapft;
		mymapft['a'] = 10;
		mymapft['b'] = 20;
		mymapft['c'] = 30;
		std::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> retft;
		retft = mymapft.equal_range('b');
		ft_hdm(2, 1);
		std::cout << " | lower: " << retft.first->first << " => " << retft.first->second;
		std::cout << " | upper: " << retft.second->first << " => " << retft.second->second;
		std::cout << " |" << std::endl;
		ft::map<char, std::string> mymap1ft;
		mymap1ft['a'] = "10";
		mymap1ft['b'] = "20";
		mymap1ft['c'] = "30";
		std::pair<ft::map<char, std::string>::iterator, ft::map<char, std::string>::iterator> ret1ft;
		ret1ft = mymap1ft.equal_range('b');
		ft_hdm(2, 2);
		std::cout << " | lower: " << ret1ft.first->first << " => " << ret1ft.first->second;
		std::cout << " | upper: " << ret1ft.second->first << " => " << ret1ft.second->second;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void test_const()
{
	std::cout << "#------------->" << REDC << " CONST" << END  << std::endl;
	std::pair<std::string, std::string> _ins[] = {std::make_pair("21", "School"), std::make_pair("42", "Ecole"), std::make_pair("84", "Univercity")};
	std::map<std::string, std::string> sMtr(_ins, _ins + 1);
	std::map<std::string, std::string> sMtr1(sMtr);
	sMtr1["42&"] = "21&";
	std::cout << "STD: Constructors " << sMtr1["42&"] << std::endl;
	try
	{
		std::pair<std::string, std::string> _insft[] = {std::make_pair("21", "School"), std::make_pair("42", "Ecole"), std::make_pair("84", "Univercity")};
		ft::map<std::string, std::string> sMtrft(_insft, _insft + 1);
		ft::map<std::string, std::string> sMtr1ft(sMtrft);
		sMtr1ft["42&"] = "21&";
		std::cout << FIO << "FT:  Constructors " << sMtr1ft["42&"] << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

template <class T>
static void put_map(T & map) {
	typename T::iterator mit = map.begin();
	typename T::iterator emit = map.end();
	std::cout << "iterator : Begin,  End,  Size(" << map.size() << ") ";
	std::cout << "[";
	while (mit != emit)
	{
		std::cout << "\"" << mit->first << "\" : \"" << mit->second << "\"";
		++mit;
		if (mit != emit) { std::cout << ", "; }
	}
	std::cout << "]" << std::endl;
};

template <class T>
static void put_rmap(T & map) {
	typename T::reverse_iterator rmit = map.rbegin();
	typename T::reverse_iterator remit = map.rend();
	std::cout << "riterator: Rbegin, Rend, Size(" << map.size() << ") ";
	std::cout << "[";
	while (rmit != remit)
	{
		std::cout << "\"" << rmit->first << "\" : \"" << rmit->second << "\"";
		++rmit;
		if (rmit != remit) { std::cout << ", "; }
	}
	std::cout << "]" << std::endl;
};

static void test_add_map()
{
	{
		std::cout << "#------------->" << REDC << " EQUAL_RANGE" << END  << std::endl;
		std::pair<std::string, std::string> _ins[] = {std::make_pair("21", "School"), std::make_pair("42", "Ecole"), std::make_pair("84", "Univercity")};
		std::map<std::string, std::string> sMtr3(_ins, _ins + 3);
		std::cout << "STD: oper[21]| " << sMtr3["21"] << std::endl;
		put_map(sMtr3);
		put_rmap(sMtr3);
		sMtr3.clear();
		std::cout << "STD: Clear\t| " << sMtr3.size() << std::endl;
		std::cout << "STD: Empty\t| " << sMtr3.empty() << std::endl;
		std::map<std::string, std::string> sMtr4(_ins, _ins + 1);
		sMtr4.insert(++sMtr4.begin(), std::make_pair("ft_server", "21School"));
		std::cout << "STD: Insert\t| "  << sMtr4.size() << std::endl;
		std::cout << "STD: Count\t| " << sMtr4.count("21") << std::endl;
		std::pair<std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator> _s21 = sMtr4.equal_range("a");
		std::cout << "STD: Equal_r\t| " << _s21.second->second << std::endl;
		std::cout << "STD: Find\t| " << sMtr4.find("21")->second << std::endl;
		std::cout << "STD: Lower_b\t| " << sMtr4.lower_bound("21")->first << std::endl;
		std::cout << "STD: Upper_b\t| " << sMtr4.upper_bound("42")->first << std::endl;
		std::map<std::string, std::string> sMtr5;
		sMtr5.swap(sMtr4);
		std::cout << "STD: Swap\t| " << sMtr5.size() << std::endl;
		sMtr4 = sMtr5;
		std::cout << "STD: operat==\t| " << (sMtr4 == sMtr5) << std::endl;
		sMtr4.insert(++sMtr4.begin(), std::make_pair("ft_server", "21School"));
		std::cout << "STD: operat!=\t| " << (sMtr4 != sMtr5) << std::endl;
		std::cout << "STD: operat> \t| " << (sMtr4 > sMtr5) << std::endl;
		std::cout << "STD: operat< \t| " << (sMtr5 < sMtr4) << std::endl;
		std::cout << "STD: operat>=\t| " << (sMtr4 >= sMtr5) << std::endl;
		std::cout << "STD: operat<=\t| " << (sMtr4 <= sMtr5) << std::endl;
	}
	{
		try
		{
			std::pair<std::string, std::string> _ins[] = {std::make_pair("21", "School"), std::make_pair("42", "Ecole"), std::make_pair("84", "Univercity")};
			ft::map<std::string, std::string> sMtr3(_ins, _ins + 3);
			std::cout << FIO << "FT:  oper[21]| " << sMtr3["21"] << std::endl;
			put_map(sMtr3);
			put_rmap(sMtr3);
			sMtr3.clear();
			std::cout << "FT:  Clear\t| " << sMtr3.size() << std::endl;
			std::cout << "FT:  Empty\t| " << sMtr3.empty() << std::endl;
			ft::map<std::string, std::string> sMtr4(_ins, _ins + 1);
			sMtr4.insert(++sMtr4.begin(), std::make_pair("ft_server", "21School"));
			std::cout << "FT:  Insert\t| "  << sMtr4.size() << std::endl;
			std::cout << "FT:  Count\t| " << sMtr4.count("21") << std::endl;
			std::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> _s21 = sMtr4.equal_range("a");
			std::cout << "FT:  Equal_r\t| " << _s21.second->second << std::endl;
			std::cout << "FT:  Find\t| " << sMtr4.find("21")->second << std::endl;
			std::cout << "FT:  Lower_b\t| " << sMtr4.lower_bound("21")->first << std::endl;
			std::cout << "FT:  Upper_b\t| " << sMtr4.upper_bound("42")->first << std::endl;
			ft::map<std::string, std::string> sMtr5;
			sMtr5.swap(sMtr4);
			std::cout << "FT:  Swap\t| " << sMtr5.size() << std::endl;
			sMtr4 = sMtr5;
			std::cout << "FT:  operat==\t| " << (sMtr4 == sMtr5) << std::endl;
			sMtr4.insert(++sMtr4.begin(), std::make_pair("ft_server", "21School"));
			std::cout << "FT:  operat!=\t| " << (sMtr4 != sMtr5) << std::endl;
			std::cout << "FT:  operat> \t| " << (sMtr4 > sMtr5) << std::endl;
			std::cout << "FT:  operat< \t| " << (sMtr5 < sMtr4) << std::endl;
			std::cout << "FT:  operat>=\t| " << (sMtr4 >= sMtr5) << std::endl;
			std::cout << "FT:  operat<=\t| " << (sMtr4 <= sMtr5) << std::endl;
			std::cout << GREEN << "RESULT: OK" << END << std::endl;
		}
		catch (...)
		{
			std::cout << REDC << "ERROR" << END << std::endl;
		}
	}	
}

void	ft_test_map(void)
{
	std::cout << "\t\t\t<=====|" << REDC << "___MAP___" << END << "|=====>" << std::endl << std::endl;
	test_constructor();
	test_operator();
	test_begin_end();
	test_rbegin_rend();
	test_empty();
	test_size();
	test_max_size();
	test_add_max_sizem();
	test_operator2();
	test_insert();
	test_erase();
	test_swap();
	test_clear();
	test_key_comp();
	test_value_comp();
	test_find();
	test_count();
	test_lower_bound();
	test_upper_bound();
	test_equal_range();
	test_const();
	test_add_map();
}
