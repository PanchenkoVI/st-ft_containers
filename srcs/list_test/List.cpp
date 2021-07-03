/*
* Created: 2021/06/27
*/

#include "../../header/list/List.hpp"

#include <list>
#include <vector>
#include <iterator> 

static bool	single_digit (const int &value) { return (value < 10); }

static bool	mycomparison (double first, double second) { 
	return (int(first) < int(second)); 
}

static bool	same_integral_part (double first, double second) { 
	return (int(first) == int(second)); 
}

static bool	compare_nocase (const std::string &first, const std::string &second)
{
	unsigned int i = 0;

	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i]))
			return (true);
		else if (tolower(first[i])>tolower(second[i]))
			return (false);
		++i;
	}
	return (first.length() < second.length());
}

struct is_odd { bool operator() (const int &value) { return (value % 2) == 1; }};

struct is_near { bool operator() (double first, double second) { 
	return (fabs(first - second) < 5.0); 
	}
};

static void	testl_constructor(void)
{
	std::cout << "#------------->" << REDC << " CONSTRUCTOR" << END  << std::endl;
	int myints[] = {12, 32, 27, 19};
	float myints1[] = {12, 32, 27, 19};
	double myints11[] = {12.0, 32.0, 27.0, 19.0};
	char myints112[] = {"12322719"};
	std::string myints111[] = {"12", "32", "27", "19"};
	std::list<char> t1;
	std::list<float> t2;
	std::list<double> t3;
	std::list<std::string> t4;
	std::list<int> first;
	std::list<int> second (4, 100);
	std::list<int> third (second.begin(), second.end());
	std::list<int> fourth (third);
	std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );	
	std::list<char> t11 (myints112, myints112 + sizeof(myints112) / sizeof(char));
	std::list<float> t21 (myints1, myints1 + sizeof(myints1) / sizeof(float));
	std::list<double> t31 (myints11, myints11 + sizeof(myints11) / sizeof(double));
	std::list<std::string> t41 (myints111, myints111 + sizeof(myints111) / sizeof(std::string));
	std::cout << "STD: CHAR   : The contents are: ";
	for (std::list<char>::iterator it = t11.begin(); it != t11.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "STD: FLOAT  : The contents are: ";
	for (std::list<float>::iterator it = t21.begin(); it != t21.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;	
	std::cout << "STD: DOUBLE : The contents are: ";
	for (std::list<double>::iterator it = t31.begin(); it != t31.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "STD: STRING : The contents are: ";
	for (std::list<std::string>::iterator it = t41.begin(); it != t41.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;	
	std::cout << "STD: INT    : The contents are: ";
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	try {
		ft::list<char> t1ft;
		ft::list<float> t2ft;
		ft::list<double> t3ft;
		ft::list<std::string> t4ft;
		ft::list<int> first;
		ft::list<int> secondft (4, 100);
		ft::list<int> thirdft (secondft.begin(), secondft.end());
		ft::list<int> fourthft (thirdft);
		ft::list<int> fifthft (myints, myints + sizeof(myints) / sizeof(int) );	
		ft::list<char> t11ft (myints112, myints112 + sizeof(myints112) / sizeof(char));
		ft::list<float> t21ft (myints1, myints1 + sizeof(myints1) / sizeof(float));
		ft::list<double> t31ft (myints11, myints11 + sizeof(myints11) / sizeof(double));
		ft::list<std::string> t41ft (myints111, myints111 + sizeof(myints111) / sizeof(std::string));
		std::cout << FIO << "FT:  CHAR   : The contents are: ";
		for (ft::list<char>::iterator it = t11ft.begin(); it != t11ft.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		std::cout << "FT:  FLOAT  : The contents are: ";
		for (ft::list<float>::iterator it = t21ft.begin(); it != t21ft.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;	
		std::cout << "FT:  DOUBLE : The contents are: ";
		for (ft::list<double>::iterator it = t31ft.begin(); it != t31ft.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		std::cout << "FT:  STRING : The contents are: ";
		for (ft::list<std::string>::iterator it = t41ft.begin(); it != t41ft.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;	
		std::cout << "FT:  INT    : The contents are: ";
		for (ft::list<int>::iterator it = fifthft.begin(); it != fifthft.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_operator(void)
{
	std::cout << "#------------->" << REDC << " OPERATOR" << END  << std::endl;
	std::list<int> first (3);
	std::list<int> second (5);
	std::list<float> f1(3);
	std::list<float> f2(5);
	std::list<double> d1(3);
	std::list<double> d2(5);
	std::list<char> ch1(90);
	std::list<char> ch2(87);
	std::list<std::string> st1(3);
	std::list<std::string> st2(5);
	second = first;
	f2 = f1;
	d2 = d1;
	ch2 = ch1;
	st2 = st1;
	first = std::list<int>();
	f1 = std::list<float>();
	d1 = std::list<double>();
	ch1 = std::list<char>();
	st1 = std::list<std::string>();
	std::cout << "STD: CHAR   : Size of  first: " << char (ch1.size()) << std::endl;
	std::cout << "STD: CHAR   : Size of second: " << char (ch2.size()) << std::endl;
	std::cout << "STD: INT    : Size of  first: " << int (first.size()) << std::endl;
	std::cout << "STD: INT    : Size of second: " << int (second.size()) << std::endl;
	std::cout << "STD: FLOAT  : Size of  first: " << float (f1.size()) << std::endl;
	std::cout << "STD: FLOAT  : Size of second: " << float (f2.size()) << std::endl;
	std::cout << "STD: DOUBLE : Size of  first: " << double (d1.size()) << std::endl;
	std::cout << "STD: DOUBLE : Size of second: " << double (d2.size()) << std::endl;
	std::cout << "STD: STRING : Size of  first: " << st1.size() << std::endl;
	std::cout << "STD: STRING : Size of second: " << st2.size()  << std::endl;
	try
	{
		ft::list<int> firstft (3);
		ft::list<int> secondft (5);
		ft::list<float> f1ft(3);
		ft::list<float> f2ft(5);
		ft::list<double> d1ft(3);
		ft::list<double> d2ft(5);
		ft::list<char> ch1ft(90);
		ft::list<char> ch2ft(87);
		ft::list<std::string> st1ft(3);
		ft::list<std::string> st2ft(5);
		secondft = firstft;
		f2ft = f1ft;
		d2ft = d1ft;
		ch2ft = ch1ft;
		st2ft = st1ft;
		firstft = ft::list<int>();
		f1ft = ft::list<float>();
		d1ft = ft::list<double>();
		ch1ft = ft::list<char>();
		st1ft = ft::list<std::string>();
		std::cout << FIO << "FT:  CHAR   : Size of  first: " << char (ch1ft.size()) << std::endl;
		std::cout << "FT:  CHAR   : Size of second: " << char (ch2ft.size()) << std::endl;
		std::cout << "FT:  INT    : Size of  first: " << int (firstft.size()) << std::endl;
		std::cout << "FT:  INT    : Size of second: " << int (secondft.size()) << std::endl;
		std::cout << "FT:  FLOAT  : Size of  first: " << float (f1ft.size()) << std::endl;
		std::cout << "FT:  FLOAT  : Size of second: " << float (f2ft.size()) << std::endl;
		std::cout << "FT:  DOUBLE : Size of  first: " << double (d1ft.size()) << std::endl;
		std::cout << "FT:  DOUBLE : Size of second: " << double (d2ft.size()) << std::endl;
		std::cout << "FT:  STRING : Size of  first: " << st1ft.size() << std::endl;
		std::cout << "FT:  STRING : Size of second: " << st2ft.size()  << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_begin_end(void)
{
	std::cout << "#------------->" << REDC << " BEGIN and END" << END  << std::endl;
	int myints[] = {75, 23, 65, 42, 13};
	float myints1[] = {75, 23, 65, 42, 13};
	double myints11[] = {75.0, 23.0, 65.0, 42.0, 13.0};
	char myints2[] = {"12322719"};
	std::string myints22[] = {"75", "23", "65", "42", "13"};
	std::list<int> mylist (myints, myints + 5);
	std::list<float> mylist1 (myints1, myints1 + 5);
	std::list<double> mylist11 (myints11, myints11 + 5);
	std::list<char> mylist2 (myints2, myints2 + 5);
	std::list<std::string> mylist22 (myints22, myints22 + 5);
	std::cout << "STD: CHAR   : contains:";
	for (std::list<char>::iterator it = mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << "  " << *it;
	std::cout << std::endl;	std::cout << "STD: INT    : contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: FLOAT  : contains:";
	for (std::list<float>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: DOUBLE : contains:";
	for (std::list<double>::iterator it = mylist11.begin(); it != mylist11.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: STRING : contains:";
	for (std::list<std::string>::iterator it = mylist22.begin(); it != mylist22.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::list<int> mylistft (myints, myints + 5);
		ft::list<float> mylist1ft (myints1, myints1 + 5);
		ft::list<double> mylist11ft (myints11, myints11 + 5);
		ft::list<char> mylist2ft (myints2, myints2 + 5);
		ft::list<std::string> mylist22ft (myints22, myints22 + 5);
		std::cout << FIO << "FT:  CHAR   : contains:";
		for (ft::list<char>::iterator it = mylist2ft.begin(); it != mylist2ft.end(); ++it)
			std::cout << "  " << *it;
		std::cout << std::endl;	std::cout << "FT:  INT    : contains:";
		for (ft::list<int>::iterator it = mylistft.begin(); it != mylistft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "FT:  FLOAT  : contains:";
		for (ft::list<float>::iterator it = mylist1ft.begin(); it != mylist1ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "FT:  DOUBLE : contains:";
		for (ft::list<double>::iterator it = mylist11ft.begin(); it != mylist11ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "FT:  STRING : contains:";
		for (ft::list<std::string>::iterator it = mylist22ft.begin(); it != mylist22ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_rbegin_rend(void)
{
	std::cout << "#------------->" << REDC << " RBEGIN and REND" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<char> mylist2;
	std::list<std::string> mylist22;
	for (int i = 1; i <= 5; ++i)
		mylist.push_back(i);
	std::cout << "STD: INT    : mylist backwards:";
	for (std::list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << std::endl;
	for (int i = 1; i <= 5; ++i)
		mylist1.push_back(i);
	std::cout << "STD: FLOAT  : mylist backwards:";
	for (std::list<float>::reverse_iterator rit = mylist1.rbegin(); rit != mylist1.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << std::endl;	
	for (int i = 1; i <= 5; ++i)
		mylist11.push_back(i);
	std::cout << "STD: DOUBLE : mylist backwards:";
	for (std::list<double>::reverse_iterator rit = mylist11.rbegin(); rit != mylist11.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << std::endl;
	for (int i = 1; i <= 5; ++i)
		mylist22.push_back("i");
	std::cout << "STD: STRING : mylist backwards:";
	for (std::list<std::string>::reverse_iterator rit = mylist22.rbegin(); rit != mylist22.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << std::endl;
	for (int i = 1; i <= 5; ++i)
		mylist2.push_back(i + 80);
	std::cout << "STD: CHAR   : mylist backwards:";
	for (std::list<char>::reverse_iterator rit = mylist2.rbegin(); rit != mylist2.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<char> mylist2ft;
		ft::list<std::string> mylist22ft;
		for (int i = 1; i <= 5; ++i)
			mylistft.push_back(i);
		std::cout << FIO << "FT:  INT    : mylist backwards:";
		for (ft::list<int>::reverse_iterator rit = mylistft.rbegin(); rit != mylistft.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << std::endl;
		for (int i = 1; i <= 5; ++i)
			mylist1ft.push_back(i);
		std::cout << "FT:  FLOAT  : mylist backwards:";
		for (ft::list<float>::reverse_iterator rit = mylist1ft.rbegin(); rit != mylist1ft.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << std::endl;	
		for (int i = 1; i <= 5; ++i)
			mylist11ft.push_back(i);
		std::cout << "FT:  DOUBLE : mylist backwards:";
		for (ft::list<double>::reverse_iterator rit = mylist11ft.rbegin(); rit != mylist11ft.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << std::endl;
		for (int i = 1; i <= 5; ++i)
			mylist22ft.push_back("i");
		std::cout << "FT:  STRING : mylist backwards:";
		for (ft::list<std::string>::reverse_iterator rit = mylist22ft.rbegin(); rit != mylist22ft.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << std::endl;
		for (int i = 1; i <= 5; ++i)
			mylist2ft.push_back(i + 80);
		std::cout << "FT:  CHAR   : mylist backwards:";
		for (ft::list<char>::reverse_iterator rit = mylist2ft.rbegin(); rit != mylist2ft.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_empty(void)
{
	std::cout << "#------------->" << REDC << " EMPTY" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<char> mylist2;
	std::list<std::string> mylist22;
	int sum (0);
	float sum1 (0);
	double sum11 (0);
	char sum2 (0);
	std::string sum22 ("5");
	for (int i = 1; i <= 10; ++i)
		mylist.push_back(i);
	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}
	std::cout << "STD: INT    : total: " << sum << std::endl;
	for (int i = 1; i <= 10; ++i)
		mylist1.push_back(i);
	while (!mylist1.empty())
	{
		sum1 += mylist1.front();
		mylist1.pop_front();
	}
	std::cout << "STD: FLOAT  : total: " << sum1 << std::endl;
	for (int i = 1; i <= 10; ++i)
		mylist11.push_back(i);
	while (!mylist11.empty())
	{
		sum11 += mylist11.front();
		mylist11.pop_front();
	}
	std::cout << "STD: DOUBLE : total: " << sum11 << std::endl;
	
	for (int i = 1; i <= 10; ++i)
		mylist2.push_back(i);
	while (!mylist2.empty())
	{
		sum2 += mylist2.front();
		mylist2.pop_front();
	}
	std::cout << "STD: CHAR   : total: " << sum2 << std::endl;
	for (int i = 1; i < 2; ++i)
		mylist22.push_back("5");
	while (!mylist22.empty())
	{
		sum22 += mylist22.front();
		mylist22.pop_front();
	}
	std::cout << "STD: STRING : total: " << sum22 << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<char> mylist2ft;
		ft::list<std::string> mylist22ft;
		int sumft (0);
		float sum1ft (0);
		double sum11ft (0);
		char sum2ft (0);
		std::string sum22ft ("5");
		for (int i = 1; i <= 10; ++i)
			mylistft.push_back(i);
		while (!mylistft.empty())
		{
			sumft += mylistft.front();
			mylistft.pop_front();
		}
		std::cout << FIO << "FT:  INT    : total: " << sumft << std::endl;
		for (int i = 1; i <= 10; ++i)
			mylist1ft.push_back(i);
		while (!mylist1ft.empty())
		{
			sum1ft += mylist1ft.front();
			mylist1ft.pop_front();
		}
		std::cout << "FT:  FLOAT  : total: " << sum1ft << std::endl;
		for (int i = 1; i <= 10; ++i)
			mylist11ft.push_back(i);
		while (!mylist11ft.empty())
		{
			sum11ft += mylist11ft.front();
			mylist11ft.pop_front();
		}
		std::cout << "FT:  DOUBLE : total: " << sum11ft << std::endl;
		for (int i = 1; i <= 10; ++i)
			mylist2ft.push_back(i);
		while (!mylist2ft.empty())
		{
			sum2ft += mylist2ft.front();
			mylist2ft.pop_front();
		}
		std::cout << "FT:  CHAR   : total: " << sum2ft << std::endl;
		for (int i = 1; i < 2; ++i)
			mylist22ft.push_back("5");
		while (!mylist22ft.empty())
		{
			sum22ft += mylist22ft.front();
			mylist22ft.pop_front();
		}
		std::cout << "FT:  STRING : total: " << sum22ft << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_size(void)
{
	std::cout << "#------------->" << REDC << " SIZE" << END  << std::endl;
	std::list<int> myints;
	std::list<float> myints1;
	std::list<double> mylist11;
	std::list<char> mylist2;
	std::list<std::string> mylist22;
	std::cout << "STD: INT    : |var1 = " << myints.size();
	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	std::cout << " |var2 = " << myints.size();
	myints.insert (myints.begin(), 10, 100);
	std::cout << " |var3 = " << myints.size();
	myints.pop_back();
	std::cout << " |var4 = " << myints.size() << " |" << std::endl;
	std::cout << "STD: FLOAT  : |var1 = " << myints1.size();
	for (int i = 0; i < 10; i++)
		myints1.push_back(i);
	std::cout << " |var2 = " << myints1.size();
	myints1.insert (myints1.begin(), 10, 100);
	std::cout << " |var3 = " << myints1.size();
	myints1.pop_back();
	std::cout << " |var4 = " << myints1.size() << " |" << std::endl;
	std::cout << "STD: DOUBLE : |var1 = " << mylist11.size();
	for (int i = 0; i < 10; i++)
		mylist11.push_back(i);
	std::cout << " |var2 = " << mylist11.size();
	mylist11.insert (mylist11.begin(), 10, 100);
	std::cout << " |var3 = " << mylist11.size();
	mylist11.pop_back();
	std::cout << " |var4 = " << mylist11.size() << " |" << std::endl;
	std::cout << "STD: CHAR   : |var1 = " << mylist2.size();
	for (int i = 0; i < 10; i++)
		mylist2.push_back(i);
	std::cout << " |var2 = " << mylist2.size();
	mylist2.insert (mylist2.begin(), 10, 100);
	std::cout << " |var3 = " << mylist2.size();
	mylist2.pop_back();
	std::cout << " |var4 = " << mylist2.size() << " |" << std::endl;
	std::cout << "STD: STRING : |var1 = " << mylist22.size();
	for (int i = 0; i < 10; i++)
		mylist22.push_back("i");
	std::cout << " |var2 = " << mylist22.size();
	mylist22.insert (mylist22.begin(), mylist22.begin(), mylist22.end());
	std::cout << " |var3 = " << mylist22.size();
	mylist22.pop_back();
	std::cout << " |var4 = " << mylist22.size() << " |" << std::endl;
	try
	{
		ft::list<int> myintsft;
		ft::list<float> myints1ft;
		ft::list<double> mylist11ft;
		ft::list<char> mylist2ft;
		ft::list<std::string> mylist22ft;
		std::cout << FIO << "FT:  INT    : |var1 = " << myintsft.size();
		for (int i = 0; i < 10; i++)
			myintsft.push_back(i);
		std::cout << " |var2 = " << myintsft.size();
		myintsft.insert (myintsft.begin(), 10, 100);
		std::cout << " |var3 = " << myintsft.size();
		myintsft.pop_back();
		std::cout << " |var4 = " << myintsft.size() << " |" << std::endl;
		std::cout << "FT:  FLOAT  : |var1 = " << myints1ft.size();
		for (int i = 0; i < 10; i++)
			myints1ft.push_back(i);
		std::cout << " |var2 = " << myints1ft.size();
		myints1ft.insert (myints1ft.begin(), 10, 100);
		std::cout << " |var3 = " << myints1ft.size();
		myints1ft.pop_back();
		std::cout << " |var4 = " << myints1ft.size() << " |" << std::endl;
		std::cout << "FT:  DOUBLE : |var1 = " << mylist11ft.size();
		for (int i = 0; i < 10; i++)
			mylist11ft.push_back(i);
		std::cout << " |var2 = " << mylist11ft.size();
		mylist11ft.insert (mylist11ft.begin(), 10, 100);
		std::cout << " |var3 = " << mylist11ft.size();
		mylist11ft.pop_back();
		std::cout << " |var4 = " << mylist11ft.size() << " |" << std::endl;
		std::cout << "FT:  CHAR   : |var1 = " << mylist2ft.size();
		for (int i = 0; i < 10; i++)
			mylist2ft.push_back(i);
		std::cout << " |var2 = " << mylist2ft.size();
		mylist2ft.insert (mylist2ft.begin(), 10, 100);
		std::cout << " |var3 = " << mylist2ft.size();
		mylist2ft.pop_back();
		std::cout << " |var4 = " << mylist2ft.size() << " |" << std::endl;
		std::cout << "FT:  STRING : |var1 = " << mylist22ft.size();
		for (int i = 0; i < 10; i++)
			mylist22ft.push_back("i");
		std::cout << " |var2 = " << mylist22ft.size();
		mylist22ft.insert (mylist22ft.begin(), mylist22ft.begin(), mylist22ft.end());
		std::cout << " |var3 = " << mylist22ft.size();
		mylist22ft.pop_back();
		std::cout << " |var4 = " << mylist22ft.size() << " |" << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}

}

static void	testl_max_size(void)
{
	std::cout << "#------------->" << REDC << " MAX SIZE" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> myints1;
	std::list<double> mylist11;
	std::list<std::string> mylist22;
	std::cout << "STD: INT    : max_size = " <<  mylist.max_size() << std::endl;
	std::cout << "STD: FLOAT  : max_size = " <<  myints1.max_size() << std::endl;
	std::cout << "STD: DOUBLE : max_size = " <<  mylist11.max_size() << std::endl;
	std::cout << "STD: STRING : max_size = " <<  mylist22.max_size() << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> myints1ft;
		ft::list<double> mylist11ft;
		ft::list<std::string> mylist22ft;
		std::cout << FIO << "FT:  INT    : max_size = " <<  mylistft.max_size() << std::endl;
		std::cout << "FT:  FLOAT  : max_size = " <<  myints1ft.max_size() << std::endl;
		std::cout << "FT:  DOUBLE : max_size = " <<  mylist11ft.max_size() << std::endl;
		std::cout << "FT:  STRING : max_size = " <<  mylist22ft.max_size() << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}	
}

static void	testl_front(void)
{
	std::cout << "#------------->" << REDC << " FRONT" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<std::string> mylist22;
	mylist.push_back(77);
	mylist.push_back(22);
	mylist.front() -= mylist.back();
	std::cout << "STD: INT    : mylist.front() is now " << mylist.front() << std::endl;
	mylist1.push_back(77);
	mylist1.push_back(22);
	mylist1.front() -= mylist1.back();
	std::cout << "STD: FLOAT  : mylist.front() is now " << mylist1.front() << std::endl;
	mylist11.push_back(77);
	mylist11.push_back(22);
	mylist11.front() -= mylist11.back();
	std::cout << "STD: DOUBLE : mylist.front() is now " << mylist11.front() << std::endl;
	mylist22.push_back("55");
	mylist22.push_back("22");
	std::cout << "STD: STRING : mylist.front() is now " << mylist22.front() << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<std::string> mylist22ft;
		mylistft.push_back(77);
		mylistft.push_back(22);
		mylistft.front() -= mylistft.back();
		std::cout << FIO << "FT:  INT    : mylist.front() is now " << mylistft.front() << std::endl;
		mylist1ft.push_back(77);
		mylist1ft.push_back(22);
		mylist1ft.front() -= mylist1ft.back();
		std::cout << "FT:  FLOAT  : mylist.front() is now " << mylist1ft.front() << std::endl;
		mylist11ft.push_back(77);
		mylist11ft.push_back(22);
		mylist11ft.front() -= mylist11ft.back();
		std::cout << "FT:  DOUBLE : mylist.front() is now " << mylist11ft.front() << std::endl;
		mylist22ft.push_back("55");
		mylist22ft.push_back("22");
		std::cout << "FT:  STRING : mylist.front() is now " << mylist22ft.front() << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_back(void)
{
	std::cout << "#------------->" << REDC << " BACK" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<std::string> mylist22;
	mylist.push_back(10);
	while (mylist.back() != 0)
		mylist.push_back(mylist.back() -1 );
	std::cout << "STD: INT    : mylist contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist1.push_back(9);
	while (mylist1.back() != 0)
		mylist1.push_back(mylist1.back() -1 );
	std::cout << "STD: FLOAT  : mylist contains:";
	for (std::list<float>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist11.push_back(8);
	while (mylist11.back() != 0)
		mylist11.push_back(mylist11.back() -1 );
	std::cout << "STD: DOUBLE : mylist contains:";
	for (std::list<double>::iterator it = mylist11.begin(); it != mylist11.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist22.push_back("7");
	for (int i = 6; i >= 0 ; i--){
		mylist22.push_back(std::to_string(i));
	}
	std::cout << "STD: STRING : mylist contains:";
	for (std::list<std::string>::iterator it = mylist22.begin(); it != mylist22.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<std::string> mylist22ft;
		mylistft.push_back(10);
		while (mylistft.back() != 0)
			mylistft.push_back(mylistft.back() -1 );
		std::cout << FIO << "FT:  INT    : mylist contains:";
		for (ft::list<int>::iterator it = mylistft.begin(); it != mylistft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylist1ft.push_back(9);
		while (mylist1ft.back() != 0)
			mylist1ft.push_back(mylist1ft.back() -1 );
		std::cout << "FT:  FLOAT  : mylist contains:";
		for (ft::list<float>::iterator it = mylist1ft.begin(); it != mylist1ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylist11ft.push_back(8);
		while (mylist11ft.back() != 0)
			mylist11ft.push_back(mylist11ft.back() -1 );
		std::cout << "FT:  DOUBLE : mylist contains:";
		for (ft::list<double>::iterator it = mylist11ft.begin(); it != mylist11ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylist22ft.push_back("7");
		for (int i = 6; i >= 0 ; i--){
			mylist22ft.push_back(std::to_string(i));
		}
		std::cout << "FT:  STRING : mylist contains:";
		for (ft::list<std::string>::iterator it = mylist22ft.begin(); it != mylist22ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_assign(void)
{
	std::cout << "#------------->" << REDC << " ASSIGN" << END  << std::endl;
	std::list<int> first;
	std::list<int> second;
	std::list<float> f1;
	std::list<float> f2;
	std::list<double> d1;
	std::list<double> d2;
	first.assign (7, 100);
	second.assign (first.begin(),first.end());
	int myints[] = {1776, 7, 4};
	first.assign (myints, myints + 3);
	std::cout << "STD: INT    : | Size of first: " << int (first.size());
	std::cout << " | Size of second: " << int (second.size()) << " |" << std::endl;
	f1.assign (7, 100);
	f2.assign (f1.begin(),f1.end());
	f1.assign (myints, myints + 3);
	std::cout << "STD: FLOAT  : | Size of first: " << float (f1.size());
	std::cout << " | Size of second: " << float (f2.size()) << " |" << std::endl;
	d1.assign (7, 100);
	d2.assign (d1.begin(), d1.end());
	d1.assign (myints, myints + 3);
	std::cout << "STD: DOUBLE : | Size of first: " << double (d1.size());
	std::cout << " | Size of second: " << double (d2.size()) << " |" << std::endl;
	try
	{
		ft::list<int> firstft;
		ft::list<int> secondft;
		ft::list<float> f1ft;
		ft::list<float> f2ft;
		ft::list<double> d1ft;
		ft::list<double> d2ft;
		firstft.assign (7, 100);
		secondft.assign (firstft.begin(), firstft.end());
		firstft.assign (myints, myints + 3);
		std::cout << FIO << "FT:  INT    : | Size of first: " << int (firstft.size());
		std::cout << " | Size of second: " << int (secondft.size()) << " |" << std::endl;
		f1ft.assign (7, 100);
		f2ft.assign (f1ft.begin(), f1ft.end());
		f1ft.assign (myints, myints + 3);
		std::cout << "FT:  FLOAT  : | Size of first: " << float (f1ft.size());
		std::cout << " | Size of second: " << float (f2ft.size()) << " |" << std::endl;
		d1ft.assign (7, 100);
		d2ft.assign (d1ft.begin(), d1ft.end());
		d1ft.assign (myints, myints + 3);
		std::cout << "FT:  DOUBLE : | Size of first: " << double (d1ft.size());
		std::cout << " | Size of second: " << double (d2ft.size()) << " |" << std::endl;	
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_push_front(void)
{
	std::cout << "#------------->" << REDC << " PUSH_FRONT" << END  << std::endl;
	std::list<int> mylist (3, 777);
	std::list<float> mylist1 (3, 777);
	std::list<double> mylist11 (3, 777);
	std::list<char> mylist2 (5, 90);
	std::list<std::string> mylist22 (5, "90");
	mylist.push_front (200);
	mylist.push_front (300);
	std::cout << "STD: INT    : mylist contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist1.push_front (200);
	mylist1.push_front (300);
	std::cout << "STD: FLOAT  : mylist contains:";
	for (std::list<float>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist11.push_front (200);
	mylist11.push_front (300);
	std::cout << "STD: DOUBLE : mylist contains:";
	for (std::list<double>::iterator it = mylist11.begin(); it != mylist11.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist11.push_front (90);
	mylist11.push_front (40);
	std::cout << "STD: CHAR   : mylist contains:";
	for (std::list<char>::iterator it = mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << "   " << *it;
	std::cout << std::endl;
	mylist11.push_front (90);
	mylist11.push_front (40);
	std::cout << "STD: STRING : mylist contains:";
	for (std::list<std::string>::iterator it = mylist22.begin(); it != mylist22.end(); ++it)
		std::cout << "  " << *it;
	std::cout << std::endl;
	try
	{
		ft::list<int> mylistft (3, 777);
		ft::list<float> mylist1ft (3, 777);
		ft::list<double> mylist11ft (3, 777);
		ft::list<char> mylist2ft (5, 90);
		ft::list<std::string> mylist22ft (5, "90");
		mylistft.push_front (200);
		mylistft.push_front (300);
		std::cout << FIO << "FT:  INT    : mylist contains:";
		for (ft::list<int>::iterator it = mylistft.begin(); it != mylistft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylist1ft.push_front (200);
		mylist1ft.push_front (300);
		std::cout << "FT:  FLOAT  : mylist contains:";
		for (ft::list<float>::iterator it = mylist1ft.begin(); it != mylist1ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylist11ft.push_front (200);
		mylist11ft.push_front (300);
		std::cout << "FT:  DOUBLE : mylist contains:";
		for (ft::list<double>::iterator it = mylist11ft.begin(); it != mylist11ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylist11ft.push_front (90);
		mylist11ft.push_front (40);
		std::cout << "FT:  CHAR   : mylist contains:";
		for (ft::list<char>::iterator it = mylist2ft.begin(); it != mylist2ft.end(); ++it)
			std::cout << "   " << *it;
		std::cout << std::endl;
		mylist11ft.push_front (90);
		mylist11ft.push_front (40);
		std::cout << "FT:  STRING : mylist contains:";
		for (ft::list<std::string>::iterator it = mylist22ft.begin(); it != mylist22ft.end(); ++it)
			std::cout << "  " << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_pop_front(void)
{
	std::cout << "#------------->" << REDC << " POP_FRONT" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<char> mylist2;
	std::list<std::string> mylist22;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	std::cout << "STD: INT    : | before = ";
	while (!mylist.empty())
	{
		std::cout << ' ' << mylist.front();
		mylist.pop_front();
	}
	std::cout << " | after = " << mylist.size() << " |" << std::endl;
	mylist1.push_back (100);
	mylist1.push_back (200);
	mylist1.push_back (300);
	std::cout << "STD: FLOAT  : | before = ";
	while (!mylist1.empty())
	{
		std::cout << ' ' << mylist1.front();
		mylist1.pop_front();
	}
	std::cout << " | after = " << mylist1.size() << " |" << std::endl;
	mylist11.push_back (100);
	mylist11.push_back (200);
	mylist11.push_back (300);
	std::cout << "STD: DOUBLE : | before = ";
	while (!mylist11.empty())
	{
		std::cout << ' ' << mylist11.front();
		mylist11.pop_front();
	}
	std::cout << " | after = " << mylist11.size() << " |" << std::endl;
	mylist2.push_back (88);
	mylist2.push_back (89);
	mylist2.push_back (90);
	std::cout << "STD: CHAR   : | before = ";
	while (!mylist2.empty())
	{
		std::cout << "   " << mylist2.front();
		mylist2.pop_front();
	}
	std::cout << " | after = " << mylist2.size() << " |" << std::endl;
	mylist22.push_back ("100");
	mylist22.push_back ("200");
	mylist22.push_back ("300");
	std::cout << "STD: STRING : | before = ";
	while (!mylist22.empty())
	{
		std::cout << ' ' << mylist22.front();
		mylist22.pop_front();
	}
	std::cout << " | after = " << mylist22.size() << " |" << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<char> mylist2ft;
		ft::list<std::string> mylist22ft;
		mylistft.push_back (100);
		mylistft.push_back (200);
		mylistft.push_back (300);
		std::cout << FIO << "FT:  INT    : | before = ";
		while (!mylistft.empty())
		{
			std::cout << ' ' << mylistft.front();
			mylistft.pop_front();
		}
		std::cout << " | after = " << mylistft.size() << " |" << std::endl;
		mylist1ft.push_back (100);
		mylist1ft.push_back (200);
		mylist1ft.push_back (300);
		std::cout << "FT:  FLOAT  : | before = ";
		while (!mylist1ft.empty())
		{
			std::cout << ' ' << mylist1ft.front();
			mylist1ft.pop_front();
		}
		std::cout << " | after = " << mylist1ft.size() << " |" << std::endl;
		mylist11ft.push_back (100);
		mylist11ft.push_back (200);
		mylist11ft.push_back (300);
		std::cout << "FT:  DOUBLE : | before = ";
		while (!mylist11ft.empty())
		{
			std::cout << ' ' << mylist11ft.front();
			mylist11ft.pop_front();
		}
		std::cout << " | after = " << mylist11ft.size() << " |" << std::endl;
		mylist2ft.push_back (88);
		mylist2ft.push_back (89);
		mylist2ft.push_back (90);
		std::cout << "FT:  CHAR   : | before = ";
		while (!mylist2ft.empty())
		{
			std::cout << "   " << mylist2ft.front();
			mylist2ft.pop_front();
		}
		std::cout << " | after = " << mylist2ft.size() << " |" << std::endl;
		mylist22ft.push_back ("100");
		mylist22ft.push_back ("200");
		mylist22ft.push_back ("300");
		std::cout << "FT:  STRING : | before = ";
		while (!mylist22ft.empty())
		{
			std::cout << ' ' << mylist22ft.front();
			mylist22ft.pop_front();
		}
		std::cout << " | after = " << mylist22ft.size() << " |" << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_push_back(void)
{
	std::cout << "#------------->" << REDC << " PUSH_BACK" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<char> mylist2;
	std::list<std::string> mylist22;
	std::cout << "STD: INT    : | mylist = ";
	for (int i = 0; i < 7; i++)
		mylist.push_back(i);
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " | numbers = " << mylist.size() << " |" << std::endl;
	std::cout << "STD: FLOAT  : | mylist = ";
	for (int i = 0; i < 7; i++)
		mylist1.push_back(i);
	for (std::list<float>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " | numbers = " << mylist1.size() << " |" << std::endl;
	std::cout << "STD: DOUBLE : | mylist = ";
	for (int i = 0; i < 7; i++)
		mylist11.push_back(i);
	for (std::list<double>::iterator it = mylist11.begin(); it != mylist11.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " | numbers = " << mylist11.size() << " |" << std::endl;
	std::cout << "STD: STRING : | mylist = ";
	for (int i = 0; i < 7; i++)
		mylist22.push_back(std::to_string(i));
	for (std::list<std::string>::iterator it = mylist22.begin(); it != mylist22.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " | numbers = " << mylist22.size() << " |" << std::endl;
	std::cout << "STD: CHAR   : | mylist = ";
	for (int i = 0; i < 7; i++)
		mylist2.push_back(83 + i);
	for (std::list<char>::iterator it = mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " | numbers = " << mylist2.size() << " |" << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<char> mylist2ft;
		ft::list<std::string> mylist22ft;
		std::cout << FIO << "FT:  INT    : | mylist = ";
		for (int i = 0; i < 7; i++)
			mylistft.push_back(i);
		for (ft::list<int>::iterator it = mylistft.begin(); it != mylistft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << " | numbers = " << mylistft.size() << " |" << std::endl;
		std::cout << "FT:  FLOAT  : | mylist = ";
		for (int i = 0; i < 7; i++)
			mylist1ft.push_back(i);
		for (ft::list<float>::iterator it = mylist1ft.begin(); it != mylist1ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << " | numbers = " << mylist1ft.size() << " |" << std::endl;
		std::cout << "FT:  DOUBLE : | mylist = ";
		for (int i = 0; i < 7; i++)
			mylist11ft.push_back(i);
		for (ft::list<double>::iterator it = mylist11ft.begin(); it != mylist11ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << " | numbers = " << mylist11ft.size() << " |" << std::endl;
		std::cout << "FT:  STRING : | mylist = ";
		for (int i = 0; i < 7; i++)
			mylist22ft.push_back(std::to_string(i));
		for (ft::list<std::string>::iterator it = mylist22ft.begin(); it != mylist22ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << " | numbers = " << mylist22ft.size() << " |" << std::endl;
		std::cout << "FT:  CHAR   : | mylist = ";
		for (int i = 0; i < 7; i++)
			mylist2ft.push_back(83 + i);
		for (ft::list<char>::iterator it = mylist2ft.begin(); it != mylist2ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << " | numbers = " << mylist2ft.size() << " |" << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_pop_back(void)
{
	std::cout << "#------------->" << REDC << " POP_BACK" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<char> mylist2;
	std::list<std::string> mylist22;
	int sum (0);
	float sum1 (0);
	double sum11 (0);
	std::string sum2;
	std::string sum22;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	while (!mylist.empty())
	{
		sum += mylist.back();
		mylist.pop_back();
	}
	std::cout << "STD: INT    : The elements of mylist summed " << sum << std::endl;
	mylist1.push_back (100);
	mylist1.push_back (200);
	mylist1.push_back (300);
	while (!mylist1.empty())
	{
		sum1 += mylist1.back();
		mylist1.pop_back();
	}
	std::cout << "STD: FLOAT  : The elements of mylist summed " << sum1 << std::endl;
	mylist11.push_back (100);
	mylist11.push_back (200);
	mylist11.push_back (300);
	while (!mylist11.empty())
	{
		sum11 += mylist11.back();
		mylist11.pop_back();
	}
	std::cout << "STD: DOUBLE : The elements of mylist summed " << sum11 << std::endl;
	mylist22.push_back ("0");
	mylist22.push_back ("0");
	mylist22.push_back ("6");
	while (!mylist22.empty())
	{
		sum22 += mylist22.back();
		mylist22.pop_back();
	}
	std::cout << "STD: STRING : The elements str: " << sum22 << std::endl;
	mylist2.push_back (87);
	mylist2.push_back (88);
	mylist2.push_back (89);
	while (!mylist2.empty())
	{
		sum2 += mylist2.back();
		mylist2.pop_back();
	}
	std::cout << "STD: CHAR   : The elements : " << sum2 << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<char> mylist2ft;
		ft::list<std::string> mylist22ft;
		int sumft (0);
		float sum1ft (0);
		double sum11ft (0);
		std::string sum2ft;
		std::string sum22ft;
		mylistft.push_back (100);
		mylistft.push_back (200);
		mylistft.push_back (300);
		while (!mylistft.empty())
		{
			sumft += mylistft.back();
			mylistft.pop_back();
		}
		std::cout << FIO << "FT:  INT    : The elements of mylist summed " << sumft << std::endl;
		mylist1ft.push_back (100);
		mylist1ft.push_back (200);
		mylist1ft.push_back (300);
		while (!mylist1ft.empty())
		{
			sum1ft += mylist1ft.back();
			mylist1ft.pop_back();
		}
		std::cout << "FT:  FLOAT  : The elements of mylist summed " << sum1ft << std::endl;
		mylist11ft.push_back (100);
		mylist11ft.push_back (200);
		mylist11ft.push_back (300);
		while (!mylist11ft.empty())
		{
			sum11ft += mylist11ft.back();
			mylist11ft.pop_back();
		}
		std::cout << "FT:  DOUBLE : The elements of mylist summed " << sum11ft << std::endl;
		mylist22ft.push_back ("0");
		mylist22ft.push_back ("0");
		mylist22ft.push_back ("6");
		while (!mylist22ft.empty())
		{
			sum22ft += mylist22ft.back();
			mylist22ft.pop_back();
		}
		std::cout << "FT:  STRING : The elements str: " << sum22ft << std::endl;
		mylist2ft.push_back (87);
		mylist2ft.push_back (88);
		mylist2ft.push_back (89);
		while (!mylist2ft.empty())
		{
			sum2ft += mylist2ft.back();
			mylist2ft.pop_back();
		}
		std::cout << "FT:  CHAR   : The elements : " << sum2ft << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_insert(void)
{
	std::cout << "#------------->" << REDC << " INSERT" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<std::string> mylist22;	
	std::list<int>::iterator it;
	for (int i = 1; i <= 5; ++i)
		mylist.push_back(i);
	it = mylist.begin();
	++it;
	mylist.insert(it, 10);
	mylist.insert(it, 2, 20);
	--it;
	std::vector<int> myvector (2, 30);
	mylist.insert (it, myvector.begin(), myvector.end());
	std::cout << "STD: INT    : mylist contains:";
	for (it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<float>::iterator itf;
	for (float i = 1; i <= 5; ++i)
		mylist1.push_back(i);
	itf = mylist1.begin();
	++itf;
	mylist1.insert(itf, 10);
	mylist1.insert(itf, 2, 20);
	--itf;
	std::vector<float> myvector1 (2, 30);
	mylist1.insert (itf, myvector1.begin(), myvector1.end());
	std::cout << "STD: FLOAT  : mylist contains:";
	for (itf = mylist1.begin(); itf != mylist1.end(); ++itf)
		std::cout << ' ' << *itf;
	std::cout << std::endl;
	std::list<double>::iterator itd;
	for (double i = 1; i <= 5; ++i)
		mylist11.push_back(i);
	itd = mylist11.begin();
	++itd;
	mylist11.insert(itd, 10);
	mylist11.insert(itd, 2, 20);
	--itd;
	std::vector<double> myvector11 (2, 30);
	mylist11.insert (itd, myvector11.begin(), myvector11.end());
	std::cout << "STD: DOUBLE : mylist contains:";
	for (itd = mylist11.begin(); itd != mylist11.end(); ++itd)
		std::cout << ' ' << *itd;
	std::cout << std::endl;
	std::list<std::string>::iterator itst;
	for (int i = 1; i <= 5; ++i)
		mylist22.push_back(std::to_string(i));
	itst = mylist22.begin();
	++itst;
	mylist22.insert(itst, "10");
	mylist22.insert(itst, 2, "20");
	--itst;
	std::vector<std::string> myvector22 (2, "30");
	mylist22.insert (itst, myvector22.begin(), myvector22.end());
	std::cout << "STD: STRING : mylist contains:";
	for (itst = mylist22.begin(); itst != mylist22.end(); ++itst)
		std::cout << ' ' << *itst;
	std::cout << std::endl;

	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<std::string> mylist22ft;
		ft::list<int>::iterator itft;
		for (int i = 1; i <= 5; ++i)
			mylistft.push_back(i);
		itft = mylistft.begin();
		++itft;
		mylistft.insert(itft, 10);
		mylistft.insert(itft, 2, 20);
		--itft;
		std::vector<int> myvectorft (2, 30);
		mylistft.insert (itft, myvectorft.begin(), myvectorft.end());
		std::cout << FIO << "FT:  INT    : mylist contains:";
		for (itft = mylistft.begin(); itft != mylistft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << std::endl;
		ft::list<float>::iterator itfft;
		for (float i = 1; i <= 5; ++i)
			mylist1ft.push_back(i);
		itfft = mylist1ft.begin();
		++itfft;
		mylist1ft.insert(itfft, 10);
		mylist1ft.insert(itfft, 2, 20);
		--itfft;
		std::vector<float> myvector1ft (2, 30);
		mylist1ft.insert (itfft, myvector1ft.begin(), myvector1ft.end());
		std::cout << "FT:  FLOAT  : mylist contains:";
		for (itfft = mylist1ft.begin(); itfft != mylist1ft.end(); ++itfft)
			std::cout << ' ' << *itfft;
		std::cout << std::endl;
		ft::list<double>::iterator itdft;
		for (double i = 1; i <= 5; ++i)
			mylist11ft.push_back(i);
		itdft = mylist11ft.begin();
		++itdft;
		mylist11ft.insert(itdft, 10);
		mylist11ft.insert(itdft, 2, 20);
		--itdft;
		std::vector<double> myvector11ft (2, 30);
		mylist11ft.insert (itdft, myvector11ft.begin(), myvector11ft.end());
		std::cout << "STD: DOUBLE : mylist contains:";
		for (itdft = mylist11ft.begin(); itdft != mylist11ft.end(); ++itdft)
			std::cout << ' ' << *itdft;
		std::cout << std::endl;
		ft::list<std::string>::iterator itstft;
		for (int i = 1; i <= 5; ++i)
			mylist22ft.push_back(std::to_string(i));
		itstft = mylist22ft.begin();
		++itstft;
		mylist22ft.insert(itstft, "10");
		mylist22ft.insert(itstft, 2, "20");
		--itstft;
		std::vector<std::string> myvector22ft (2, "30");
		mylist22ft.insert (itstft, myvector22ft.begin(), myvector22ft.end());
		std::cout << "STD: STRING : mylist contains:";
		for (itstft = mylist22ft.begin(); itstft != mylist22ft.end(); ++itstft)
			std::cout << ' ' << *itstft;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_erase(void)
{
	std::cout << "#------------->" << REDC << " ERASE" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<std::string> mylist22;
	std::list<int>::iterator it1, it2;
	for (int i = 1; i < 10; ++i)
		mylist.push_back(i * 10);
	it1 = it2 = mylist.begin();
	std::advance (it2, 6);
	++it1;
	it1 = mylist.erase (it1);
	it2 = mylist.erase (it2);
	++it1;
	--it2;
	mylist.erase (it1, it2);
	std::cout << "STD: INT    : mylist contains:";
	for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << std::endl;
	std::list<float>::iterator it11, it21;
	for (float i = 1; i < 10; ++i)
		mylist1.push_back(i * 10);
	it11 = it21 = mylist1.begin();
	std::advance (it21, 6);
	++it11;
	it11 = mylist1.erase (it11);
	it21 = mylist1.erase (it21);
	++it11;
	--it21;
	mylist1.erase (it11, it21);
	std::cout << "STD: FLOAT  : mylist contains:";
	for (it11 = mylist1.begin(); it11 != mylist1.end(); ++it11)
		std::cout << ' ' << *it11;
	std::cout << std::endl;
	std::list<double>::iterator it111, it211;
	for (double i = 1; i < 10; ++i)
		mylist11.push_back(i * 10);
	it111 = it211 = mylist11.begin();
	std::advance (it211, 6);
	++it111;
	it111 = mylist11.erase (it111);
	it211 = mylist11.erase (it211);
	++it111;
	--it211;
	mylist11.erase (it111, it211);
	std::cout << "STD: DOUBLE : mylist contains:";
	for (it111 = mylist11.begin(); it111 != mylist11.end(); ++it111)
		std::cout << ' ' << *it111;
	std::cout << std::endl;	
	std::list<std::string>::iterator it112, it212;
	for (int i = 1; i < 10; ++i)
		mylist22.push_back(std::to_string(i * 10));
	it112 = it212 = mylist22.begin();
	std::advance (it212, 6);
	++it112;
	it112 = mylist22.erase (it112);
	it212 = mylist22.erase (it212);
	++it112;
	--it212;
	mylist22.erase (it112, it212);
	std::cout << "STD: STRING : mylist contains:";
	for (it112 = mylist22.begin(); it112 != mylist22.end(); ++it112)
		std::cout << ' ' << *it112;
	std::cout << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<std::string> mylist22ft;
		ft::list<int>::iterator it1ft, it2ft;
		for (int i = 1; i < 10; ++i)
			mylistft.push_back(i * 10);
		it1ft = it2ft = mylistft.begin();
		std::advance (it2ft, 6);
		++it1ft;
		it1ft = mylistft.erase (it1ft);
		it2ft = mylistft.erase (it2ft);
		++it1ft;
		--it2ft;
		mylistft.erase (it1ft, it2ft);
		std::cout << FIO << "FT:  INT    : mylist contains:";
		for (it1ft = mylistft.begin(); it1ft != mylistft.end(); ++it1ft)
			std::cout << ' ' << *it1ft;
		std::cout << std::endl;
		ft::list<float>::iterator it11ft, it21ft;
		for (float i = 1; i < 10; ++i)
			mylist1ft.push_back(i * 10);
		it11ft = it21ft = mylist1ft.begin();
		std::advance (it21ft, 6);
		++it11ft;
		it11ft = mylist1ft.erase (it11ft);
		it21ft = mylist1ft.erase (it21ft);
		++it11ft;
		--it21ft;
		mylist1ft.erase (it11ft, it21ft);
		std::cout << "FT:  FLOAT  : mylist contains:";
		for (it11ft = mylist1ft.begin(); it11ft != mylist1ft.end(); ++it11ft)
			std::cout << ' ' << *it11ft;
		std::cout << std::endl;
		ft::list<double>::iterator it111ft, it211ft;
		for (double i = 1; i < 10; ++i)
			mylist11ft.push_back(i * 10);
		it111ft = it211ft = mylist11ft.begin();
		std::advance (it211ft, 6);
		++it111ft;
		it111ft = mylist11ft.erase (it111ft);
		it211ft = mylist11ft.erase (it211ft);
		++it111ft;
		--it211ft;
		mylist11ft.erase (it111ft, it211ft);
		std::cout << "FT:  DOUBLE : mylist contains:";
		for (it111ft = mylist11ft.begin(); it111ft != mylist11ft.end(); ++it111ft)
			std::cout << ' ' << *it111ft;
		std::cout << std::endl;	
		ft::list<std::string>::iterator it112ft, it212ft;
		for (int i = 1; i < 10; ++i)
			mylist22ft.push_back(std::to_string(i * 10));
		it112ft = it212ft = mylist22ft.begin();
		std::advance (it212ft, 6);
		++it112ft;
		it112ft = mylist22ft.erase (it112ft);
		it212ft = mylist22ft.erase (it212ft);
		++it112ft;
		--it212ft;
		mylist22ft.erase (it112ft, it212ft);
		std::cout << "FT:  STRING : mylist contains:";
		for (it112ft = mylist22ft.begin(); it112ft != mylist22ft.end(); ++it112ft)
			std::cout << ' ' << *it112ft;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_swap(void)
{
	std::cout << "#------------->" << REDC << " SWAP" << END  << std::endl;
	std::list<int> first (3, 100);
	std::list<int> second (5, 200);
	first.swap(second);
	std::cout << "STD: INT    : first  contains:";
	for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: INT    : second contains:";
	for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<float> firstf (3, 100);
	std::list<float> secondf (5, 200);
	firstf.swap(secondf);
	std::cout << "STD: FLOAT  : first  contains:";
	for (std::list<float>::iterator it = firstf.begin(); it != firstf.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: FLOAT  : second contains:";
	for (std::list<float>::iterator it = secondf.begin(); it != secondf.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<double> firstd (3, 100);
	std::list<double> secondd (5, 200);
	firstd.swap(secondd);
	std::cout << "STD: DOUBLE : first  contains:";
	for (std::list<double>::iterator it = firstd.begin(); it != firstd.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: DOUBLE : second contains:";
	for (std::list<double>::iterator it = secondd.begin(); it != secondd.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<std::string> firstts (3, "100");
	std::list<std::string> secondst (5, "200");
	firstts.swap(secondst);
	std::cout << "STD: STRING : first  contains:";
	for (std::list<std::string>::iterator it = firstts.begin(); it != firstts.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: STRING : second contains:";
	for (std::list<std::string>::iterator it = secondst.begin(); it != secondst.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::list<int> firstft (3, 100);
		ft::list<int> secondft (5, 200);
		firstft.swap(secondft);
		std::cout << FIO << "FT:  INT    : first  contains:";
		for (ft::list<int>::iterator it = firstft.begin(); it != firstft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "FT:  INT    : second contains:";
		for (ft::list<int>::iterator it = secondft.begin(); it != secondft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<float> firstfft(3, 100);
		ft::list<float> secondfft (5, 200);
		firstfft.swap(secondfft);
		std::cout << "FT:  FLOAT  : first  contains:";
		for (ft::list<float>::iterator it = firstfft.begin(); it != firstfft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "FT:  FLOAT  : second contains:";
		for (ft::list<float>::iterator it = secondfft.begin(); it != secondfft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<double> firstdft (3, 100);
		ft::list<double> seconddft (5, 200);
		firstdft.swap(seconddft);
		std::cout << "FT:  DOUBLE : first  contains:";
		for (ft::list<double>::iterator it = firstdft.begin(); it != firstdft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "FT:  DOUBLE : second contains:";
		for (ft::list<double>::iterator it = seconddft.begin(); it != seconddft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<std::string> firsttsft (3, "100");
		ft::list<std::string> secondstft (5, "200");
		firsttsft.swap(secondstft);
		std::cout << "FT:  STRING : first  contains:";
		for (ft::list<std::string>::iterator it = firsttsft.begin(); it != firsttsft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "FT:  STRING : second contains:";
		for (ft::list<std::string>::iterator it = secondstft.begin(); it != secondstft.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_resize(void)
{
	std::cout << "#------------->" << REDC << " RESIZE" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<std::string> mylist22;
	for (int i = 1; i < 10; ++i)
		mylist.push_back(i);
	mylist.resize(5);
	mylist.resize(8, 100);
	mylist.resize(12);
	std::cout << "STD: INT    :";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (int i = 1; i < 10; ++i)
		mylist1.push_back(i);
	mylist1.resize(5);
	mylist1.resize(8, 100);
	mylist1.resize(12);
	std::cout << "STD: FLOAT  :";
	for (std::list<float>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (int i = 1; i < 10; ++i)
		mylist11.push_back(i);
	mylist11.resize(5);
	mylist11.resize(8, 100);
	mylist11.resize(12);
	std::cout << "STD: DOUBLE :";
	for (std::list<double>::iterator it = mylist11.begin(); it != mylist11.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (int i = 1; i < 10; ++i)
		mylist22.push_back(std::to_string(i));
	mylist22.resize(5);
	mylist22.resize(8, "100");
	mylist22.resize(12);
	std::cout << "STD: STRING :";
	for (std::list<std::string>::iterator it = mylist22.begin(); it != mylist22.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<std::string> mylist22ft;
		for (int i = 1; i < 10; ++i)
			mylistft.push_back(i);
		mylistft.resize(5);
		mylistft.resize(8, 100);
		mylistft.resize(12);
		std::cout << FIO << "FT:  INT    :";
		for (ft::list<int>::iterator it = mylistft.begin(); it != mylistft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		for (int i = 1; i < 10; ++i)
			mylist1ft.push_back(i);
		mylist1ft.resize(5);
		mylist1ft.resize(8, 100);
		mylist1ft.resize(12);
		std::cout << "FT:  FLOAT  :";
		for (ft::list<float>::iterator it = mylist1ft.begin(); it != mylist1ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		for (int i = 1; i < 10; ++i)
			mylist11ft.push_back(i);
		mylist11ft.resize(5);
		mylist11ft.resize(8, 100);
		mylist11ft.resize(12);
		std::cout << "FT:  DOUBLE :";
		for (ft::list<double>::iterator it = mylist11ft.begin(); it != mylist11ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		for (int i = 1; i < 10; ++i)
			mylist22ft.push_back(std::to_string(i));
		mylist22ft.resize(5);
		mylist22ft.resize(8, "100");
		mylist22ft.resize(12);
		std::cout << "FT:  STRING :";
		for (ft::list<std::string>::iterator it = mylist22ft.begin(); it != mylist22ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_clear(void)
{
	std::cout << "#------------->" << REDC << " CLEAR" << END  << std::endl;
	std::list<int> mylist;
	std::list<float> mylist1;
	std::list<double> mylist11;
	std::list<std::string> mylist22;
	std::list<int>::iterator it;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	std::cout << "STD: INT    : | before = ";
	for (it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);
	std::cout << " | after = ";
	for (it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " |" << std::endl;	
	std::list<float>::iterator itf;
	mylist1.push_back (100);
	mylist1.push_back (200);
	mylist1.push_back (300);
	std::cout << "STD: FLOAT  : | before = ";
	for (itf = mylist1.begin(); itf != mylist1.end(); ++itf)
		std::cout << ' ' << *itf;
	mylist1.clear();
	mylist1.push_back (1101);
	mylist1.push_back (2202);
	std::cout << " | after = ";
	for (itf = mylist1.begin(); itf != mylist1.end(); ++itf)
		std::cout << ' ' << *itf;
	std::cout << " |" << std::endl;
	std::list<double>::iterator itf1;
	mylist11.push_back (100);
	mylist11.push_back (200);
	mylist11.push_back (300);
	std::cout << "STD: DOUBLE : | before = ";
	for (itf1 = mylist11.begin(); itf1 != mylist11.end(); ++itf1)
		std::cout << ' ' << *itf1;
	mylist11.clear();
	mylist11.push_back (1101);
	mylist11.push_back (2202);
	std::cout << " | after = ";
	for (itf1 = mylist11.begin(); itf1 != mylist11.end(); ++itf1)
		std::cout << ' ' << *itf1;
	std::cout << " |" << std::endl;
	std::list<std::string>::iterator itf1s;
	mylist22.push_back ("100");
	mylist22.push_back ("200");
	mylist22.push_back ("300");
	std::cout << "STD: STRING : | before = ";
	for (itf1s = mylist22.begin(); itf1s != mylist22.end(); ++itf1s)
		std::cout << ' ' << *itf1s;
	mylist22.clear();
	mylist22.push_back ("1101");
	mylist22.push_back ("2202");
	std::cout << " | after = ";
	for (itf1s = mylist22.begin(); itf1s != mylist22.end(); ++itf1s)
		std::cout << ' ' << *itf1s;
	std::cout << " |" << std::endl;
	try
	{
		ft::list<int> mylistft;
		ft::list<float> mylist1ft;
		ft::list<double> mylist11ft;
		ft::list<std::string> mylist22ft;
		ft::list<int>::iterator itft;
		mylistft.push_back (100);
		mylistft.push_back (200);
		mylistft.push_back (300);
		std::cout << FIO << "FT:  INT    : | before = ";
		for (itft = mylistft.begin(); itft != mylistft.end(); ++itft)
			std::cout << ' ' << *itft;
		mylistft.clear();
		mylistft.push_back (1101);
		mylistft.push_back (2202);
		std::cout << " | after = ";
		for (itft = mylistft.begin(); itft != mylistft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << " |" << std::endl;	
		ft::list<float>::iterator itfft;
		mylist1ft.push_back (100);
		mylist1ft.push_back (200);
		mylist1ft.push_back (300);
		std::cout << "FT:  FLOAT  : | before = ";
		for (itfft = mylist1ft.begin(); itfft != mylist1ft.end(); ++itfft)
			std::cout << ' ' << *itfft;
		mylist1ft.clear();
		mylist1ft.push_back (1101);
		mylist1ft.push_back (2202);
		std::cout << " | after = ";
		for (itfft = mylist1ft.begin(); itfft != mylist1ft.end(); ++itfft)
			std::cout << ' ' << *itfft;
		std::cout << " |" << std::endl;
		ft::list<double>::iterator itf1ft;
		mylist11ft.push_back (100);
		mylist11ft.push_back (200);
		mylist11ft.push_back (300);
		std::cout << "FT:  DOUBLE : | before = ";
		for (itf1ft = mylist11ft.begin(); itf1ft != mylist11ft.end(); ++itf1ft)
			std::cout << ' ' << *itf1ft;
		mylist11ft.clear();
		mylist11ft.push_back (1101);
		mylist11ft.push_back (2202);
		std::cout << " | after = ";
		for (itf1ft = mylist11ft.begin(); itf1ft != mylist11ft.end(); ++itf1ft)
			std::cout << ' ' << *itf1ft;
		std::cout << " |" << std::endl;
		ft::list<std::string>::iterator itf1sft;
		mylist22ft.push_back ("100");
		mylist22ft.push_back ("200");
		mylist22ft.push_back ("300");
		std::cout << "FT:  STRING : | before = ";
		for (itf1sft = mylist22ft.begin(); itf1sft != mylist22ft.end(); ++itf1sft)
			std::cout << ' ' << *itf1sft;
		mylist22ft.clear();
		mylist22ft.push_back ("1101");
		mylist22ft.push_back ("2202");
		std::cout << " | after = ";
		for (itf1sft = mylist22ft.begin(); itf1sft != mylist22ft.end(); ++itf1sft)
			std::cout << ' ' << *itf1sft;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_splice(void)
{
	std::cout << "#------------->" << REDC << " SPLICE" << END  << std::endl;
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);
	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);
	it = mylist1.begin();
	++it;
	mylist1.splice (it, mylist2);
	mylist2.splice (mylist2.begin(), mylist1, it);
	it = mylist1.begin();
	std::advance(it, 3);
	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
	std::cout << "STD: INT    : | mylist1: ";
	for (it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " | mylist2: ";
	for (it = mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " |" << std::endl;
	std::list<float> mylist1f, mylist2f;
	std::list<float>::iterator itf;
	for (int i = 1; i <= 4; ++i)
		mylist1f.push_back(i);
	for (int i = 1; i <= 3; ++i)
		mylist2f.push_back(i * 10);
	itf = mylist1f.begin();
	++itf;
	mylist1f.splice (itf, mylist2f);
	mylist2f.splice (mylist2f.begin(), mylist1f, itf);
	itf = mylist1f.begin();
	std::advance(itf, 3);
	mylist1f.splice(mylist1f.begin(), mylist1f, itf, mylist1f.end());
	std::cout << "STD: FLOAT  : | mylist1: ";
	for (itf = mylist1f.begin(); itf != mylist1f.end(); ++itf)
		std::cout << ' ' << *itf;
	std::cout << " | mylist2: ";
	for (itf = mylist2f.begin(); itf != mylist2f.end(); ++itf)
		std::cout << ' ' << *itf;
	std::cout << " |" << std::endl;
	std::list<double> mylist1fd, mylist2fd;
	std::list<double>::iterator itfd;
	for (int i = 1; i <= 4; ++i)
		mylist1fd.push_back(i);
	for (int i = 1; i <= 3; ++i)
		mylist2fd.push_back(i * 10);
	itfd = mylist1fd.begin();
	++itfd;
	mylist1fd.splice (itfd, mylist2fd);
	mylist2fd.splice (mylist2fd.begin(), mylist1fd, itfd);
	itfd = mylist1fd.begin();
	std::advance(itfd, 3);
	mylist1fd.splice(mylist1fd.begin(), mylist1fd, itfd, mylist1fd.end());
	std::cout << "STD: DOUBLE : | mylist1: ";
	for (itfd = mylist1fd.begin(); itfd != mylist1fd.end(); ++itfd)
		std::cout << ' ' << *itfd;
	std::cout << " | mylist2: ";
	for (itfd = mylist2fd.begin(); itfd != mylist2fd.end(); ++itfd)
		std::cout << ' ' << *itfd;
	std::cout << " |" << std::endl;
	std::list<std::string> mylist1st, mylist2st;
	std::list<std::string>::iterator itst;
	for (int i = 1; i <= 4; ++i)
		mylist1st.push_back(std::to_string(i));
	for (int i = 1; i <= 3; ++i)
		mylist2st.push_back(std::to_string(i * 10));
	itst = mylist1st.begin();
	++itst;
	mylist1st.splice (itst, mylist2st);
	mylist2st.splice (mylist2st.begin(), mylist1st, itst);
	itst = mylist1st.begin();
	std::advance(itst, 3);
	mylist1st.splice(mylist1st.begin(), mylist1st, itst, mylist1st.end());
	std::cout << "STD: STRING : | mylist1: ";
	for (itst = mylist1st.begin(); itst != mylist1st.end(); ++itst)
		std::cout << ' ' << *itst;
	std::cout << " | mylist2: ";
	for (itst = mylist2st.begin(); itst != mylist2st.end(); ++itst)
		std::cout << ' ' << *itst;
	std::cout << " |" << std::endl;
	try
	{
		ft::list<int> mylist1ft, mylist2ft;
		ft::list<int>::iterator itft;
		for (int i = 1; i <= 4; ++i)
			mylist1ft.push_back(i);
		for (int i = 1; i <= 3; ++i)
			mylist2ft.push_back(i * 10);
		itft = mylist1ft.begin();
		++itft;
		mylist1ft.splice (itft, mylist2ft);
		mylist2ft.splice (mylist2ft.begin(), mylist1ft, itft);
		itft = mylist1ft.begin();
		std::advance(itft, 3);
		mylist1ft.splice(mylist1ft.begin(), mylist1ft, itft, mylist1ft.end());
		std::cout << FIO << "FT:  INT    : | mylist1: ";
		for (itft = mylist1ft.begin(); itft != mylist1ft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << " | mylist2: ";
		for (itft = mylist2ft.begin(); itft != mylist2ft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << " |" << std::endl;
		ft::list<float> mylist1fft, mylist2fft;
		ft::list<float>::iterator itfft;
		for (int i = 1; i <= 4; ++i)
			mylist1fft.push_back(i);
		for (int i = 1; i <= 3; ++i)
			mylist2fft.push_back(i * 10);
		itfft = mylist1fft.begin();
		++itfft;
		mylist1fft.splice (itfft, mylist2fft);
		mylist2fft.splice (mylist2fft.begin(), mylist1fft, itfft);
		itfft = mylist1fft.begin();
		std::advance(itfft, 3);
		mylist1fft.splice(mylist1fft.begin(), mylist1fft, itfft, mylist1fft.end());
		std::cout << "FT:  FLOAT  : | mylist1: ";
		for (itfft = mylist1fft.begin(); itfft != mylist1fft.end(); ++itfft)
			std::cout << ' ' << *itfft;
		std::cout << " | mylist2: ";
		for (itfft = mylist2fft.begin(); itfft != mylist2fft.end(); ++itfft)
			std::cout << ' ' << *itfft;
		std::cout << " |" << std::endl;
		ft::list<double> mylist1fdft, mylist2fdft;
		ft::list<double>::iterator itfdft;
		for (int i = 1; i <= 4; ++i)
			mylist1fdft.push_back(i);
		for (int i = 1; i <= 3; ++i)
			mylist2fdft.push_back(i * 10);
		itfdft = mylist1fdft.begin();
		++itfdft;
		mylist1fdft.splice (itfdft, mylist2fdft);
		mylist2fdft.splice (mylist2fdft.begin(), mylist1fdft, itfdft);
		itfdft = mylist1fdft.begin();
		std::advance(itfdft, 3);
		mylist1fdft.splice(mylist1fdft.begin(), mylist1fdft, itfdft, mylist1fdft.end());
		std::cout << "FT:  DOUBLE : | mylist1: ";
		for (itfdft = mylist1fdft.begin(); itfdft != mylist1fdft.end(); ++itfdft)
			std::cout << ' ' << *itfdft;
		std::cout << " | mylist2: ";
		for (itfdft = mylist2fdft.begin(); itfdft != mylist2fdft.end(); ++itfdft)
			std::cout << ' ' << *itfdft;
		std::cout << " |" << std::endl;
		ft::list<std::string> mylist1stf, mylist2stf;
		ft::list<std::string>::iterator itstf;
		for (int i = 1; i <= 4; ++i)
			mylist1stf.push_back(std::to_string(i));
		for (int i = 1; i <= 3; ++i)
			mylist2stf.push_back(std::to_string(i * 10));
		itstf = mylist1stf.begin();
		++itstf;
		mylist1stf.splice (itstf, mylist2stf);
		mylist2stf.splice (mylist2stf.begin(), mylist1stf, itstf);
		itstf = mylist1stf.begin();
		std::advance(itstf, 3);
		mylist1stf.splice(mylist1stf.begin(), mylist1stf, itstf, mylist1stf.end());
		std::cout << "FT:  STRING : | mylist1: ";
		for (itstf = mylist1stf.begin(); itstf != mylist1stf.end(); ++itstf)
			std::cout << ' ' << *itstf;
		std::cout << " | mylist2: ";
		for (itstf = mylist2stf.begin(); itstf != mylist2stf.end(); ++itstf)
			std::cout << ' ' << *itstf;
		std::cout << " |" << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_remove(void)
{
	std::cout << "#------------->" << REDC << " REMOVE" << END  << std::endl;
	int myints[]= {17, 89, 7, 14};
	float myints1[]= {17, 89, 7, 14};
	double myintsd[]= {17, 89, 7, 14};
	std::string myintsds[]= {"17", "89", "7", "14"};
	std::list<int> mylist (myints, myints + 4);
	std::list<float> mylist1 (myints1, myints1 + 4);
	std::list<double> mylistd (myintsd, myintsd + 4);
	std::list<std::string> mylistds (myintsds, myintsds + 4);
	mylist.remove(89);
	std::cout << "STD: INT    : mylist contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist1.remove(89);
	std::cout << "STD: FLOAT  : mylist contains:";
	for (std::list<float>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylistd.remove(89);
	std::cout << "STD: DOUBLE : mylist contains:";
	for (std::list<double>::iterator it = mylistd.begin(); it != mylistd.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylistds.remove("89");
	std::cout << "STD: STRING : mylist contains:";
	for (std::list<std::string>::iterator it = mylistds.begin(); it != mylistds.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		int myintsa[]= {17, 89, 7, 14};
		float myints1a[]= {17, 89, 7, 14};
		double myintsda[]= {17, 89, 7, 14};
		std::string myintsdsa[]= {"17", "89", "7", "14"};
		ft::list<int> mylista (myintsa, myintsa + 4);
		ft::list<float> mylist1a (myints1a, myints1a + 4);
		ft::list<double> mylistda (myintsda, myintsda + 4);
		ft::list<std::string> mylistdsa (myintsdsa, myintsdsa + 4);
		mylista.remove(89);
		std::cout << FIO << "FT:  INT    : mylist contains:";
		for (ft::list<int>::iterator it = mylista.begin(); it != mylista.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylist1a.remove(89);
		std::cout << "FT:  FLOAT  : mylist contains:";
		for (ft::list<float>::iterator it = mylist1a.begin(); it != mylist1a.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylistda.remove(89);
		std::cout << "FT:  DOUBLE : mylist contains:";
		for (ft::list<double>::iterator it = mylistda.begin(); it != mylistda.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylistdsa.remove("89");
		std::cout << "FT:  STRING : mylist contains:";
		for (ft::list<std::string>::iterator it = mylistdsa.begin(); it != mylistdsa.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_remove_if(void)
{
	std::cout << "#------------->" << REDC << " REMOVE_IF" << END  << std::endl;
	int myints[]= {15, 36, 7, 17, 20, 39, 4, 1};
	std::list<int> mylist (myints, myints + 8); 
	mylist.remove_if (single_digit);
	mylist.remove_if (is_odd());
	std::cout << "STD: INT    : mylist contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;	
	float myints1[]= {15, 36, 7, 17, 20, 39, 4, 1};
	std::list<float> mylist1 (myints1, myints1 + 8); 
	mylist1.remove_if (single_digit);
	mylist1.remove_if (is_odd());
	std::cout << "STD: FLOAT  : mylist contains:";
	for (std::list<float>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	double myints2[]= {15, 36, 7, 17, 20, 39, 4, 1};
	std::list<double> mylist2 (myints2, myints2 + 8); 
	mylist2.remove_if (single_digit);
	mylist2.remove_if (is_odd());
	std::cout << "STD: DOUBLE : mylist contains:";
	for (std::list<double>::iterator it = mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::string myints3[]= {"15", "36", "7", "17", "20", "39", "4", "1"};
	try
	{
		int myintsa[]= {15, 36, 7, 17, 20, 39, 4, 1};
		ft::list<int> mylista (myintsa, myintsa + 8); 
		mylista.remove_if (single_digit);
		mylista.remove_if (is_odd());
		std::cout << FIO << "FT:  INT    : mylist contains:";
		for (ft::list<int>::iterator it = mylista.begin(); it != mylista.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;	
		float myints1a[]= {15, 36, 7, 17, 20, 39, 4, 1};
		ft::list<float> mylist1a (myints1a, myints1a + 8); 
		mylist1a.remove_if (single_digit);
		mylist1a.remove_if (is_odd());
		std::cout << "FT:  FLOAT  : mylist contains:";
		for (ft::list<float>::iterator it = mylist1a.begin(); it != mylist1a.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		double myints2a[]= {15, 36, 7, 17, 20, 39, 4, 1};
		ft::list<double> mylist2a (myints2a, myints2a + 8); 
		mylist2a.remove_if (single_digit);
		mylist2a.remove_if (is_odd());
		std::cout << "FT:  DOUBLE : mylist contains:";
		for (ft::list<double>::iterator it = mylist2a.begin(); it != mylist2a.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_unique(void)
{
	std::cout << "#------------->" << REDC << " UNIQUE" << END  << std::endl;
	double mydoubles[] = {12.15,  2.72, 73.11,  12.77,  3.14,
						12.77, 73.35, 72.25, 15.31,  72.25};
	std::list<double> mylist (mydoubles,mydoubles + 10);
	std::cout << "STD: start  :";
	for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist.sort();
	std::cout << "STD: sort   : ";
	for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist.unique();
	std::cout << "STD: unique : ";
	for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist.unique (same_integral_part);
	std::cout << "STD: unique2: ";
	for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist.unique (is_near());
	std::cout << "STD: unique : ";
	for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		double mydoublesa[] = {12.15,  2.72, 73.11,  12.77,  3.14,
							12.77, 73.35, 72.25, 15.31,  72.25};
		ft::list<double> mylista (mydoublesa, mydoublesa + 10);
		std::cout << FIO << "FT:  start  :";
		for (ft::list<double>::iterator it = mylista.begin(); it != mylista.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylista.sort();
		std::cout << "FT:  sort   : ";
		for (ft::list<double>::iterator it = mylista.begin(); it != mylista.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylista.unique();
		std::cout << "FT:  unique : ";
		for (ft::list<double>::iterator it = mylista.begin(); it != mylista.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylista.unique (same_integral_part);
		std::cout << "FT:  unique2: ";
		for (ft::list<double>::iterator it = mylista.begin(); it != mylista.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		mylista.unique (is_near());
		std::cout << "FT:  unique : ";
		for (ft::list<double>::iterator it = mylista.begin(); it != mylista.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << GREEN << "\nFINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_merge(void)
{
	std::cout << "#------------->" << REDC << " MERGE" << END  << std::endl;
	std::list<double> first, second;
	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);
	first.sort();
	second.sort();
	first.merge(second);
	second.push_back (2.1);
	first.merge(second, mycomparison);
	std::cout << "STD: DOUBLE : first contains:";
	for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<float> firstf, secondf;
	firstf.push_back (3.1);
	firstf.push_back (2.9);
	secondf.push_back (3.7);
	secondf.push_back (7.1);
	secondf.push_back (1.4);
	firstf.sort();
	secondf.sort();
	firstf.merge(secondf);
	secondf.push_back (2.1);
	firstf.merge(secondf, mycomparison);
	std::cout << "STD: FLOAT  : first contains:";
	for (std::list<float>::iterator it = firstf.begin(); it != firstf.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<int> a, b;
	a.push_back (3);
	a.push_back (2);
	b.push_back (3);
	b.push_back (7);
	b.push_back (1);
	a.sort();
	b.sort();
	a.merge(b);
	b.push_back (2);
	a.merge(b, mycomparison);
	std::cout << "STD: INT    : first contains:";
	for (std::list<int>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::list<double> firsta, seconda;
		firsta.push_back (3.1);
		firsta.push_back (2.2);
		firsta.push_back (2.9);
		seconda.push_back (3.7);
		seconda.push_back (7.1);
		seconda.push_back (1.4);
		firsta.sort();
		seconda.sort();
		firsta.merge(seconda);
		seconda.push_back (2.1);
		firsta.merge(seconda, mycomparison);
		std::cout << FIO << "FT:  DOUBLE : first contains:";
		for (ft::list<double>::iterator it = firsta.begin(); it != firsta.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<float> firstfa, secondfa;
		firstfa.push_back (3.1);
		firstfa.push_back (2.9);
		secondfa.push_back (3.7);
		secondfa.push_back (7.1);
		secondfa.push_back (1.4);
		firstfa.sort();
		secondfa.sort();
		firstfa.merge(secondfa);
		secondfa.push_back (2.1);
		firstfa.merge(secondfa, mycomparison);
		std::cout << "FT:  FLOAT  : first contains:";
		for (ft::list<float>::iterator it = firstfa.begin(); it != firstfa.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<int> as, bs;
		as.push_back (3);
		as.push_back (2);
		bs.push_back (3);
		bs.push_back (7);
		bs.push_back (1);
		as.sort();
		bs.sort();
		as.merge(bs);
		bs.push_back (2);
		as.merge(bs, mycomparison);
		std::cout << "FT:  INT    : first contains:";
		for (ft::list<int>::iterator it = as.begin(); it != as.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_sort(void)
{
	std::cout << "#------------->" << REDC << " SORT" << END  << std::endl;
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");
	mylist.sort();
	std::cout << "STD: mylist contains:";
	for (it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist.sort(compare_nocase);
	std::cout << "STD: mylist contains:";
	for (it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::list<std::string> mylist1;
		ft::list<std::string>::iterator it1;
		mylist1.push_back ("one");
		mylist1.push_back ("two");
		mylist1.push_back ("Three");
		mylist1.sort();
		std::cout << FIO << "FT:  mylist contains:";
		for (it1 = mylist1.begin(); it1 != mylist1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << std::endl;
		mylist1.sort(compare_nocase);
		std::cout << "FT:  mylist contains:";
		for (it1 = mylist1.begin(); it1 != mylist1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testl_reverse(void)
{
	std::cout << "#------------->" << REDC << " REVERSE" << END  << std::endl;
	std::list<int> mylist;
	for (int i = 1; i < 10; ++i)
		mylist.push_back(i);
	mylist.reverse();
	std::cout << "STD: INT    : mylist contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<float> mylistf;
	for (int i = 1; i < 10; ++i)
		mylistf.push_back(i);
	mylistf.reverse();
	std::cout << "STD: FLOAT  : mylist contains:";
	for (std::list<float>::iterator it = mylistf.begin(); it != mylistf.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<double> mylistd;
	for (int i = 1; i < 10; ++i)
		mylistd.push_back(i);
	mylistd.reverse();
	std::cout << "STD: DOUBLE : mylist contains:";
	for (std::list<double>::iterator it = mylistd.begin(); it != mylistd.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::list<std::string> mylistq;
	for (int i = 1; i < 10; ++i)
		mylistq.push_back(std::to_string(i));
	mylistq.reverse();
	std::cout << "STD: STRING : mylist contains:";
	for (std::list<std::string>::iterator it = mylistq.begin(); it != mylistq.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::list<int> mylistz;
		for (int i = 1; i < 10; ++i)
			mylistz.push_back(i);
		mylistz.reverse();
		std::cout << FIO << "FT:  INT    : mylist contains:";
		for (ft::list<int>::iterator it = mylistz.begin(); it != mylistz.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<float> mylistfz;
		for (int i = 1; i < 10; ++i)
			mylistfz.push_back(i);
		mylistfz.reverse();
		std::cout << "FT:  FLOAT  : mylist contains:";
		for (ft::list<float>::iterator it = mylistfz.begin(); it != mylistfz.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<double> mylistdz;
		for (int i = 1; i < 10; ++i)
			mylistdz.push_back(i);
		mylistdz.reverse();
		std::cout << "FT:  DOUBLE : mylist contains:";
		for (ft::list<double>::iterator it = mylistdz.begin(); it != mylistdz.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::list<std::string> mylistqz;
		for (int i = 1; i < 10; ++i)
			mylistqz.push_back(std::to_string(i));
		mylistqz.reverse();
		std::cout << "FT:  STRING : mylist contains:";
		for (ft::list<std::string>::iterator it = mylistqz.begin(); it != mylistqz.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "FINISH: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void testv_for_list()
{
	std::cout << "#------------->" << REDC << " OPERATOR" << END  << std::endl;
	{
		std::string str1 = "Ab";
		std::string str2 = "AB";
		std::string str3 = "ab";
		std::string str4 = "aB";
		std::list< std::string > stack1(1, str1);
		std::list< std::string > stack2(2, str2);
		std::list< std::string > stack3(3, str3);
		std::list< std::string > stack4(4, str4);
		std::cout << "STD: ";
		if (stack1 > stack2)
			std::cout << "| " << str1 << ">" << str2;
		else
			std::cout << " | " << str1 <<  "<=" << str2;
		if (stack1 == stack2)
			std::cout << " | " << str1 << "==" << str2;
		else
			std::cout << " | " << str1 <<  "!=" << str2;
		if (stack1 != stack2)
			std::cout << " | " << str1 << "!=" << str2;
		else
			std::cout << " | " << str1 <<  "==" << str2;
		if (stack1 < stack2)
			std::cout << " | " << str1 << "<" << str2;
		else
			std::cout << " | " << str1 <<  ">=" << str2;
		if (stack3 > stack4)
			std::cout << " |" << str3 << ">" << str4;
		else
			std::cout << " | " << str3 <<  "<=" << str4;
		if (stack3 == stack4)
			std::cout << " | " << str3 << "==" << str4;
		else
			std::cout << " | " << str3 <<  "!=" << str4;
		if (stack3 != stack4)
			std::cout << " | " << str3 << "!=" << str4;
		else
			std::cout << " | " << str3 <<  "==" << str4;
		
		if (stack3 < stack4)
			std::cout << " | " << str3 << "<" << str4;
		else
			std::cout << " | " << str3 <<  ">=" << str4;
		std::cout << " |" << std::endl;
	}
	{
		try
		{
			std::string str1 = "Ab";
			std::string str2 = "AB";
			std::string str3 = "ab";
			std::string str4 = "aB";
			ft::list< std::string > stack1(1, str1);
			ft::list< std::string > stack2(2, str2);
			ft::list< std::string > stack3(3, str3);
			ft::list< std::string > stack4(4, str4);
			std::cout << FIO << "FT:  ";
			if (stack1 >= stack2)
				std::cout << "| " << str1 << ">" << str2;
			else
				std::cout << " | " << str1 <<  "<=" << str2;
			if (stack1 == stack2)
				std::cout << " | " << str1 << "==" << str2;
			else
				std::cout << " | " << str1 <<  "!=" << str2;
			if (stack1 != stack2)
				std::cout << " | " << str1 << "!=" << str2;
			else
				std::cout << " | " << str1 <<  "==" << str2;
			if (stack1 < stack2)
				std::cout << " | " << str1 << "<" << str2;
			else
				std::cout << " | " << str1 <<  ">=" << str2;
			if (stack3 > stack4)
				std::cout << " |" << str3 << ">" << str4;
			else
				std::cout << " | " << str3 <<  "<=" << str4;
			if (stack3 == stack4)
				std::cout << " | " << str3 << "==" << str4;
			else
				std::cout << " | " << str3 <<  "!=" << str4;
			if (stack3 != stack4)
				std::cout << " | " << str3 << "!=" << str4;
			else
				std::cout << " | " << str3 <<  "==" << str4;
			
			if (stack3 < stack4)
				std::cout << " | " << str3 << "<" << str4;
			else
				std::cout << " | " << str3 <<  ">=" << str4;
			std::cout << " |" << std::endl;
			std::cout << GREEN << "RESULT: OK" << END << std::endl;
		}
		catch (...)
		{
			std::cout << REDC << "ERROR" << END << std::endl;
		}
	}
}

static void testl_operator2()
{
	std::cout << "#------------->" << REDC << " OPERATOR_2" << END  << std::endl;
	std::list<std::string> st1;
	std::list<std::string> st2;
	st1.push_back("42");
	st2.push_back("42");
	std::cout << "STD: operator== " << (st1 == st2) << std::endl;
	st1.push_back("webserv");
	std::cout << "STD: operator!= "  << (st1 != st2) << std::endl;
	std::cout << "STD: operator>  "  << (st1 > st2) << std::endl;
	std::cout << "STD: operator<  "  << (st2 < st1) << std::endl;
	std::cout << "STD: operator>= "  << (st1 >= st2) << std::endl;
	std::cout << "STD: operator<= "  << (st2 <= st1) << std::endl;
	try
	{
		ft::list<std::string> ft1;
		ft::list<std::string> ft2;
		ft1.push_back("21");
		ft2.push_back("21");
		std::cout << FIO << "FT:  operator== " << (ft1 == ft2) << std::endl;
		ft1.push_back("webserv");
		std::cout << "FT:  operator!= " << (ft1 != ft2) << std::endl;
		std::cout << "FT:  operator>  " << (ft1 > ft2) << std::endl;
		std::cout << "FT:  operator<  " << (ft2 < ft1) << std::endl;
		std::cout << "FT:  operator>= " << (ft1 >= ft2) << std::endl;
		std::cout << "FT:  operator<= " << (ft2 <= ft1) << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static bool rmword(const std::string & value) { return (value  == "cube3D"); }

static void testv_add()
{
	std::cout << "#------------->" << REDC << " ADDITION" << END  << std::endl;
	std::list<std::string> sVtr4;
	sVtr4.push_back("21");
	sVtr4.push_back("42");
	sVtr4.push_back("WWW");
	sVtr4.push_back("!!!");
	std::cout << "STD: BACK\t| " << sVtr4.back() << std::endl;
	std::cout << "STD: FRONT\t| " << sVtr4.front() << std::endl;
	sVtr4.pop_back();
	std::cout << "STD: POP_BACK\t| " << sVtr4.size() << std::endl;
	sVtr4.pop_front();
	std::cout << "STD: POP_FRONT\t| " << sVtr4.size() << std::endl;
	sVtr4.push_back("school");
	sVtr4.clear();
	std::cout << "STD: CLEAR\t| " << sVtr4.size() << std::endl;
	std::cout << "STD: EMPTY\t| " << sVtr4.empty() << std::endl;
	sVtr4.push_back("21");
	std::cout << "STD: PUSH_BACK\t| " << sVtr4.back() << std::endl;
	sVtr4.push_front("21school");
	std::cout << "STD: PUSH_FRONT\t| " << sVtr4.front() << std::endl;
	sVtr4.reverse();
	std::cout << "STD: REVERSE\t| " << sVtr4.size() << std::endl;
	std::string _ins1 = "???";
	std::list<std::string>::iterator _sb1 = sVtr4.begin();
	std::list<std::string>::iterator _se1 = sVtr4.end();
	sVtr4.insert(_sb1, 2, _ins1);
	sVtr4.insert(_sb1, _sb1, _se1);
	std::cout << "STD: INSERT\t| " << sVtr4.size() << std::endl;
	sVtr4.resize(4, _ins1);
	std::cout << "STD: RESIZE\t| " << sVtr4.size() << std::endl;
	std::list<std::string> sVtr5;
	sVtr4.swap(sVtr5);
	std::cout << "STD: SWAP\t| " << sVtr5.front() << std::endl;
	sVtr5.unique();
	std::cout << "STD: UNIQUE\t| " << sVtr5.size() << std::endl;
	sVtr4.push_back("42ecole");
	std::list<std::string>::iterator _sb2 = sVtr5.begin();
	sVtr5.splice(_sb2, sVtr4);
	std::cout << "STD: SPLICE\t| " << sVtr5.size() << std::endl;
	sVtr4.push_back("ft_server");
	sVtr5.merge(sVtr4);
	std::cout << "STD: MERGE\t| " << sVtr5.size() << std::endl;
	sVtr5.push_front("ecole21");
	sVtr5.sort();
	std::cout << "STD: SORT\t| " << sVtr5.size() << std::endl;
	sVtr5.remove("ft_server");
	std::cout << "STD: REMOVE\t| "  << sVtr5.size() << std::endl;
	sVtr5.remove_if(rmword);
	std::cout << "STD: REMOVE_IF\t| " << sVtr5.size() << std::endl;
	std::list<std::string>::iterator _sb3 = sVtr5.begin();
	std::list<std::string>::iterator _se3 = sVtr5.end();
	sVtr5.erase(_sb3, _se3);
	std::cout << "STD: ERASE\t| " << sVtr5.size() << std::endl;
	for (std::list<std::string>::iterator it = sVtr5.begin(); it != sVtr5.end(); it++) 
		std::cout << *it << " ";
	try
	{
		ft::list<std::string> ft11;
		ft11.push_back("21");
		ft11.push_back("42");
		ft11.push_back("WWW");
		ft11.push_back("!!!");
		std::cout << FIO << "FT:  BACK\t| " << ft11.back() << std::endl;
		std::cout << "FT:  FRONT\t| " << ft11.front() << std::endl;
		ft11.pop_back();
		std::cout << "FT:  POP_BACK\t| " << ft11.size() << std::endl;
		ft11.pop_front();
		std::cout << "FT:  POP_FRONT\t| " << ft11.size() << std::endl;
		ft11.push_back("school");
		ft11.clear();
		std::cout << "FT:  CLEAR\t| " << ft11.size() << std::endl;
		std::cout << "FT:  EMPTY\t| " << ft11.empty() << std::endl;
		ft11.push_back("21");
		std::cout << "FT:  PUSH_BACK\t| " << ft11.back() << std::endl;
		ft11.push_front("21school");
		std::cout << "FT:  PUSH_FRONT\t| " << ft11.front() << std::endl;
		ft11.reverse();
		std::cout << "FT:  REVERSE\t| " << ft11.size() << std::endl;
		std::string _ins1 = "???";
		ft::list<std::string>::iterator _sb1f = ft11.begin();
		ft::list<std::string>::iterator _se1f = ft11.end();
		ft11.insert(_sb1f, 2, _ins1);
		ft11.insert(_sb1f, _sb1f, _se1f);
		std::cout << "FT:  INSERT\t| " << ft11.size() << std::endl;
		ft11.resize(4, _ins1);
		std::cout << "FT:  RESIZE\t| " << ft11.size() << std::endl;
		ft::list<std::string> ft22;
		ft11.swap(ft22);
		std::cout << "FT:  SWAP\t| " << ft22.front() << std::endl;
		ft22.unique();
		std::cout << "FT:  UNIQUE\t| " << ft22.size() << std::endl;
		ft11.push_back("42ecole");
		ft::list<std::string>::iterator _sb2 = ft22.begin();
		ft22.splice(_sb2, ft11);
		std::cout << "FT:  SPLICE\t| " << ft22.size() << std::endl;
		ft11.push_back("ft_server");
		ft22.merge(ft11);
		std::cout << "FT:  MERGE\t| " << ft22.size() << std::endl;
		ft22.push_front("ecole21");
		ft22.sort();
		std::cout << "FT:  SORT\t| " << ft22.size() << std::endl;
		ft22.remove("ft_server");
		std::cout << "FT:  REMOVE\t| "  << ft22.size() << std::endl;
		ft22.remove_if(rmword);
		std::cout << "FT:  REMOVE_IF\t| " << ft22.size() << std::endl;
		ft::list<std::string>::iterator _sb3 = ft22.begin();
		ft::list<std::string>::iterator _se3 = ft22.end();
		ft22.erase(_sb3, _se3);
		std::cout << "FT:  ERASE\t| " << ft22.size() << std::endl;
		for (ft::list<std::string>::iterator it = ft22.begin(); it != ft22.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

void ft_test_list (void)
{
	std::cout << "\t\t\t<=====|" << REDC << "___LIST___" << END << "|=====>" << std::endl << std::endl;
	testl_constructor();
	testl_operator();
	testl_begin_end();
	testl_rbegin_rend();
	testl_empty();
	testl_size();
	testl_max_size();
	testl_front();
	testl_back();
	testl_assign();
	testl_push_front();
	testl_pop_front();
	testl_push_back();
	testl_pop_back();
	testl_insert();
	testl_erase();
	testl_swap();
	testl_resize();
	testl_clear();
	testl_splice();
	testl_remove();
	testl_remove_if();
	testl_unique();
	testl_merge();
	testl_sort();
	testl_reverse();
	testv_add();
	testv_for_list();
	testl_operator2();
}