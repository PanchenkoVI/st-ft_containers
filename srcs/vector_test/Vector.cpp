/*
* Created: 2021/06/27
*/

#include "../../header/vector/Vector.hpp"

#include <vector>
static void ft_hd(int i, int j)
{
	if (i == 1)
	{
		if (j == 1)
			std::cout << "STD: INT   : ";
		else if (j == 2)
			std::cout << "STD: FLOAT : ";
		else if (j == 3)
			std::cout << "STD: DOUBLE: ";
		else if (j == 4)
			std::cout << "STD: STRING: ";
	}
	else if (i == 2)
	{
		if (j == 1)
			std::cout << FIO << "FT:  INT   : ";
		else if (j == 2)
			std::cout << "FT:  FLOAT : ";
		else if (j == 3)
			std::cout << "FT:  DOUBLE: ";
		else if (j == 4)
			std::cout << "FT:  STRING: ";
	}
}

static void	testv_constructor(void)
{
	std::cout << "#------------->" << REDC << " CONSTRUCTOR" << END  << std::endl;
	std::vector<char> t1;
	std::vector<float> t2;
	std::vector<double> t3;
	std::vector<std::string> t4;
	std::vector<int> first;
	std::vector<int> second(4, 100);
	std::vector<int> third (second.begin(), second.end());
	std::vector<int> fourth (third);
	int myints[] = {16, 2, 77, 29};
	float myints1[] = {16, 2, 77, 29};
	double myints2[] = {16, 2, 77, 29};
	std::string myints3[] = {"16", "2", "77", "29"};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "STD: INT   : The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<float> v1 (myints1, myints1 + sizeof(myints1) / sizeof(float) );
	std::cout << "STD: FLOAT : The contents of fifth are:";
	for (std::vector<float>::iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
		std::vector<double> v2 (myints2, myints2 + sizeof(myints2) / sizeof(double) );
	std::cout << "STD: DOUBLE: The contents of fifth are:";
	for (std::vector<double>::iterator it = v2.begin(); it != v2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<std::string> v3 (myints3, myints3 + sizeof(myints3) / sizeof(std::string) );
	std::cout << "STD: STRING: The contents of fifth are:";
	for (std::vector<std::string>::iterator it = v3.begin(); it != v3.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try 
	{
		ft::vector<char> t1ft;
		ft::vector<float> t2ft;
		ft::vector<double> t3ft;
		ft::vector<std::string> t4ft;
		ft::vector<int> firstft;
		ft::vector<int> secondft(4, 100);
		ft::vector<int> thirdft (secondft.begin(), secondft.end());
		ft::vector<int> fourthft (thirdft);
		int myintsft[] = {16, 2, 77, 29};
		float myints1ft[] = {16, 2, 77, 29};
		double myints2ft[] = {16, 2, 77, 29};
		std::string myints3ft[] = {"16", "2", "77", "29"};
		ft::vector<int> fifthft (myintsft, myintsft + sizeof(myintsft) / sizeof(int) );
		std::cout << FIO << "FT:  INT   : The contents of fifth are:";
		for (ft::vector<int>::iterator it = fifthft.begin(); it != fifthft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::vector<float> v1ft (myints1ft, myints1ft + sizeof(myints1ft) / sizeof(float) );
		std::cout << "FT:  FLOAT : The contents of fifth are:";
		for (ft::vector<float>::iterator it = v1ft.begin(); it != v1ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::vector<double> v2ft (myints2ft, myints2ft + sizeof(myints2ft) / sizeof(double));
		std::cout << "FT:  DOUBLE: The contents of fifth are:";
		for (ft::vector<double>::iterator it = v2ft.begin(); it != v2ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::vector<std::string> v3ft (myints3ft, myints3ft + sizeof(myints3ft) / sizeof(std::string));
		std::cout << "FT:  STRING: The contents of fifth are:";
		for (ft::vector<std::string>::iterator it = v3ft.begin(); it != v3ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testv_operator(void)
{
	std::cout << "#------------->" << REDC << " OPERATOR" << END  << std::endl;
	std::vector<int> foo (3, 0);
	std::vector<int> bar (5, 0);
	bar = foo;
	foo = std::vector<int>();
	std::cout << "STD: INT   : Size of foo = " << int(foo.size()) << " | Size of bar = " << int(bar.size()) << std::endl;
	std::vector<float> foo1 (3, 0);
	std::vector<float> bar1 (5, 0);
	bar1 = foo1;
	foo1 = std::vector<float>();
	std::cout << "STD: FLOAT : Size of foo = " << float(foo1.size()) << " | Size of bar = " << float(bar1.size()) << std::endl;
	std::vector<double> foo2 (3, 0);
	std::vector<double> bar2 (5, 0);
	bar2 = foo2;
	foo2 = std::vector<double>();
	std::cout << "STD: DOUBLE: Size of foo = " << double(foo2.size()) << " | Size of bar = " << double(bar2.size()) << std::endl;
	std::vector<std::string> foo3 (3);
	std::vector<std::string> bar3 (5);
	bar3 = foo3;
	foo3 = std::vector<std::string>();
	std::cout << "STD: STRING: Size of foo = " << foo3.size() << " | Size of bar = " << bar3.size() << std::endl;
	try 
	{
		ft::vector<int> fooft (3, 0);
		ft::vector<int> barft (5, 0);
		barft = fooft;
		fooft = ft::vector<int>();
		std::cout << FIO << "FT:  INT   : Size of foo = " << int(fooft.size()) << " | Size of bar = " << int(barft.size()) << std::endl;
		ft::vector<float> foo1ft (3, 0);
		ft::vector<float> bar1ft (5, 0);
		bar1ft = foo1ft;
		foo1ft = ft::vector<float>();
		std::cout << "FT:  FLOAT : Size of foo = " << float(foo1ft.size()) << " | Size of bar = " << float(bar1ft.size()) << std::endl;
		ft::vector<double> foo2ft (3, 0);
		ft::vector<double> bar2ft (5, 0);
		bar2ft = foo2ft;
		foo2ft = ft::vector<double>();
		std::cout << "FT:  DOUBLE: Size of foo = " << double(foo2ft.size()) << " | Size of bar = " << double(bar2ft.size()) << std::endl;
		ft::vector<std::string> foo3ft (3);
		ft::vector<std::string> bar3ft (5);
		bar3ft = foo3ft;
		foo3ft = ft::vector<std::string>();
		std::cout << "FT:  STRING: Size of foo = " << foo3ft.size() << " | Size of bar = " << bar3ft.size() << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_begin_end(void)
{
	std::cout << "#------------->" << REDC << " BEGIN and END" << END  << std::endl;
	std::vector<int> myvector;
	for (int i = 1; i <= 5; i++)
		myvector.push_back(i);
	std::cout << "STD: INT   : myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<float> myvector1;
	for (int i = 1; i <= 5; i++)
		myvector1.push_back(i);
	std::cout << "STD: FLOAT : myvector contains:";
	for (std::vector<float>::iterator it = myvector1.begin() ; it != myvector1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<double> myvector2;
	for (int i = 1; i <= 5; i++)
		myvector2.push_back(i);
	std::cout << "STD: DOUBLE: myvector contains:";
	for (std::vector<double>::iterator it = myvector2.begin() ; it != myvector2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<std::string> myvector3;
	for (int i = 1; i <= 5; i++)
		myvector3.push_back(std::to_string(i));
	std::cout << "STD: STRING: myvector contains:";
	for (std::vector<std::string>::iterator it = myvector3.begin() ; it != myvector3.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try 
	{
		ft::vector<int> myvectorft;
		for (int i = 1; i <= 5; i++)
			myvectorft.push_back(i);
		std::cout << FIO << "FT:  INT   : myvector contains:";
		for (ft::vector<int>::iterator it = myvectorft.begin() ; it != myvectorft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::vector<float> myvector1ft;
		for (int i = 1; i <= 5; i++)
			myvector1ft.push_back(i);
		std::cout << "FT:  FLOAT : myvector contains:";
		for (ft::vector<float>::iterator it = myvector1ft.begin() ; it != myvector1ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::vector<double> myvector2ft;
		for (int i = 1; i <= 5; i++)
			myvector2ft.push_back(i);
		std::cout << "FT:  DOUBLE: myvector contains:";
		for (ft::vector<double>::iterator it = myvector2ft.begin() ; it != myvector2ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		ft::vector<std::string> myvector3ft;
		for (int i = 1; i <= 5; i++)
			myvector3ft.push_back(std::to_string(i));
		std::cout << "FT:  STRING: myvector contains:";
		for (ft::vector<std::string>::iterator it = myvector3ft.begin() ; it != myvector3ft.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_rbegin_rend(void)
{
	std::cout << "#------------->" << REDC << " RBEGIN and REND" << END  << std::endl;
	std::vector<int> myvector(5);
	int i = 0;
	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;
	std::cout << "STD: INT   : myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<float> myvector1(5);
	float i1 = 0;
	std::vector<float>::reverse_iterator rit1 = myvector1.rbegin();
	for (; rit1!= myvector1.rend(); ++rit1)
		*rit1 = ++i1;
	std::cout << "STD: FLOAT : myvector contains:";
	for (std::vector<float>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<double> myvector2(5);
	double i2 = 0;
	std::vector<double>::reverse_iterator rit2 = myvector2.rbegin();
	for (; rit2!= myvector2.rend(); ++rit2)
		*rit2 = ++i2;
	std::cout << "STD: DOUBLE: myvector contains:";
	for (std::vector<double>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<std::string> myvectors(5);
	int is = 0;
	std::vector<std::string>::reverse_iterator rits = myvectors.rbegin();
	for (; rits!= myvectors.rend(); ++rits)
	{
		*rits = std::to_string(++is);		
	}
	std::cout << "STD: STRING: myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try 
	{
		ft::vector<int> myvectorft(5);
		int ift = 0;
		ft::vector<int>::reverse_iterator ritft = myvectorft.rbegin();
		for (; ritft!= myvectorft.rend(); ++ritft)
			*ritft = ++ift;
		std::cout << FIO << "FT:  INT   : myvector contains:";
		for (ft::vector<int>::iterator itft = myvectorft.begin(); itft != myvectorft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << std::endl;
		ft::vector<float> myvector1ft(5);
		float i1ft = 0;
		ft::vector<float>::reverse_iterator rit1ft = myvector1ft.rbegin();
		for (; rit1ft!= myvector1ft.rend(); ++rit1ft)
			*rit1ft = ++i1ft;
		std::cout << "FT:  FLOAT : myvector contains:";
		for (ft::vector<float>::iterator itft = myvector1ft.begin(); itft != myvector1ft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << std::endl;
		ft::vector<double> myvector2ft(5);
		double i2ft = 0;
		ft::vector<double>::reverse_iterator rit2ft = myvector2ft.rbegin();
		for (; rit2ft!= myvector2ft.rend(); ++rit2ft)
			*rit2ft = ++i2ft;
		std::cout << "FT:  DOUBLE: myvector contains:";
		for (ft::vector<double>::iterator itft = myvector2ft.begin(); itft != myvector2ft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << std::endl;
		ft::vector<std::string> myvectorsft(5);
		int isft = 0;
		ft::vector<std::string>::reverse_iterator ritsft = myvectorsft.rbegin();
		for (; ritsft!= myvectorsft.rend(); ++ritsft)
			*ritsft = std::to_string(++isft);		
		std::cout << "FT:  STRING: myvector contains:";
		for (ft::vector<int>::iterator itft = myvectorft.begin(); itft != myvectorft.end(); ++itft)
			std::cout << ' ' << *itft;
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}	
}

static void	testv_size(void)
{
	std::cout << "#------------->" << REDC << " SIZE" << END  << std::endl;
	std::vector<int> myints;
	std::cout << "STD: INT   : | 0. size = " << myints.size();
	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	std::cout << "| 1. size = " << myints.size();
	myints.insert(myints.end(), 10, 100);
	std::cout << " | 2. size = " << myints.size();
	myints.pop_back();
	std::cout << " | 3. size = " << myints.size() << " | " << std::endl;
	std::vector<float> myints1;
	std::cout << "STD: FLOAT : | 0. size = " << myints1.size();
	for (int i = 0; i < 10; i++)
		myints1.push_back(i);
	std::cout << "| 1. size = " << myints1.size();
	myints1.insert(myints1.end(), 10, 100);
	std::cout << " | 2. size = " << myints1.size();
	myints1.pop_back();
	std::cout << " | 3. size = " << myints1.size() << " |" << std::endl;
	std::vector<double> myints2;
	std::cout << "STD: DOUBLE: | 0. size = " << myints2.size();
	for (int i = 0; i < 10; i++)
		myints2.push_back(i);
	std::cout << "| 1. size = " << myints2.size();
	myints2.insert(myints2.end(), 10, 100);
	std::cout << " | 2. size = " << myints2.size();
	myints2.pop_back();
	std::cout << " | 3. size = " << myints2.size() << " |" << std::endl;
	std::vector<std::string> myints3;
	std::cout << "STD: STRING: | 0. size = " << myints3.size();
	for (int i = 0; i < 10; i++)
		myints3.push_back(std::to_string(i));
	std::cout << "| 1. size = " << myints3.size();
	myints3.insert(myints3.begin(), myints3.begin(), myints3.end());
	std::cout << " | 2. size = " << myints3.size();
	myints3.pop_back();
	std::cout << " | 3. size = " << myints3.size() << " |" << std::endl;
	try
	{
		ft::vector<int> myintsft;
		std::cout << FIO << "FT:  INT   : | 0. size = " << myintsft.size();
		for (int i = 0; i < 10; i++)
			myintsft.push_back(i);
		std::cout << "| 1. size = " << myintsft.size();
		myintsft.insert(myintsft.end(), 10, 100);
		std::cout << " | 2. size = " << myintsft.size();
		myintsft.pop_back();
		std::cout << " | 3. size = " << myintsft.size() << " | " << std::endl;
		ft::vector<float> myints1ft;
		std::cout << "FT:  FLOAT : | 0. size = " << myints1ft.size();
		for (int i = 0; i < 10; i++)
			myints1ft.push_back(i);
		std::cout << "| 1. size = " << myints1ft.size();
		myints1ft.insert(myints1ft.end(), 10, 100);
		std::cout << " | 2. size = " << myints1ft.size();
		myints1ft.pop_back();
		std::cout << " | 3. size = " << myints1ft.size() << " |" << std::endl;
		ft::vector<double> myints2ft;
		std::cout << "FT:  DOUBLE: | 0. size = " << myints2ft.size();
		for (int i = 0; i < 10; i++)
			myints2ft.push_back(i);
		std::cout << "| 1. size = " << myints2ft.size();
		myints2ft.insert(myints2ft.end(), 10, 100);
		std::cout << " | 2. size = " << myints2ft.size();
		myints2ft.pop_back();
		std::cout << " | 3. size = " << myints2ft.size() << " |" << std::endl;


		ft::vector<std::string> myints3ft;
		std::cout << "FT:  STRING: | 0. size = " << myints3ft.size();
		for (int i = 0; i < 10; i++)
			myints3ft.push_back(std::to_string(i));
		std::cout << "| 1. size = " << myints3ft.size();
		myints3ft.insert(myints3ft.begin(), myints3ft.begin(), myints3ft.end());
		std::cout << " | 2. size = " << myints3ft.size();
		myints3ft.pop_back();
		std::cout << " | 3. size = " << myints3ft.size() << " |" << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
	
}

static void	testv_max_size(void)
{
	std::cout << "#------------->" << REDC << " MAX SIZE" << END  << std::endl;
	std::vector<int> myvector;
	for (int i = 0; i < 100; i++)
		myvector.push_back(i);
	std::cout << "STD: INT   : size = " << myvector.size();
	std::cout << " | capacity = " << myvector.capacity();
	std::cout << " | max_size: " << myvector.max_size() << " |" << std::endl;
	std::vector<float> myvector1;
	for (int i = 0; i < 100; i++)
		myvector1.push_back(i);
	std::cout << "STD: FLOAT : size = " << myvector1.size();
	std::cout << " | capacity = " << myvector1.capacity();
	std::cout << " | max_size: " << myvector1.max_size() << " |" << std::endl;
	std::vector<double> myvector2;
	for (int i = 0; i < 100; i++)
		myvector2.push_back(i);
	std::cout << "STD: DOUBLE: size = " << myvector2.size();
	std::cout << " | capacity = " << myvector2.capacity();
	std::cout << " | max_size: " << myvector2.max_size() << " |" << std::endl;
	std::vector<std::string> myvector3;
	for (int i = 0; i < 100; i++)
		myvector3.push_back(std::to_string(i));
	std::cout << "STD: STRING: size = " << myvector3.size();
	std::cout << " | capacity = " << myvector3.capacity();
	std::cout << " | max_size: " << myvector3.max_size() << "  |" << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		for (int i = 0; i < 100; i++)
			myvectorft.push_back(i);
		std::cout << FIO << "FT:  INT   : size = " << myvectorft.size();
		std::cout << " | capacity = " << myvectorft.capacity();
		std::cout << " | max_size: " << myvectorft.max_size() << " |" << std::endl;
		ft::vector<float> myvector1ft;
		for (int i = 0; i < 100; i++)
			myvector1ft.push_back(i);
		std::cout << "FT:  FLOAT : size = " << myvector1ft.size();
		std::cout << " | capacity = " << myvector1ft.capacity();
		std::cout << " | max_size: " << myvector1ft.max_size() << " |" << std::endl;
		ft::vector<double> myvector2ft;
		for (int i = 0; i < 100; i++)
			myvector2ft.push_back(i);
		std::cout << "FT:  DOUBLE: size = " << myvector2ft.size();
		std::cout << " | capacity = " << myvector2ft.capacity();
		std::cout << " | max_size: " << myvector2ft.max_size() << " |" << std::endl;
		ft::vector<std::string> myvector3ft;
		for (int i = 0; i < 100; i++)
			myvector3ft.push_back(std::to_string(i));
		std::cout << "FT:  STRING: size = " << myvector3ft.size();
		std::cout << " | capacity = " << myvector3ft.capacity();
		std::cout << " | max_size: " << myvector3ft.max_size() << "  |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_resize(void)
{
	std::cout << "#------------->" << REDC << " RESIZE" << END  << std::endl;
	std::vector<int> myvector;
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);
	std::cout << "STD: INT   : myvector contains:";
	for (size_t i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl;
	std::vector<float> myvector1;
	for (int i = 1; i < 10; i++)
		myvector1.push_back(i);
	myvector1.resize(5);
	myvector1.resize(8,100);
	myvector1.resize(12);
	std::cout << "STD: FLOAT : myvector contains:";
	for (size_t i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1[i];
	std::cout << std::endl;
	std::vector<double> myvector2;
	for (int i = 1; i < 10; i++)
	myvector2.push_back(i);
	myvector2.resize(5);
	myvector2.resize(8,100);
	myvector2.resize(12);
	std::cout << "STD: DOUBLE: myvector contains:";
	for (size_t i = 0; i < myvector2.size(); i++)
		std::cout << ' ' << myvector2[i];
	std::cout << std::endl;
	std::vector<std::string> myvector3;
	for (int i = 1; i < 10; i++)
	myvector3.push_back(std::to_string(i));
	myvector3.resize(5);
	myvector3.resize(8, "100");
	myvector3.resize(12);
	std::cout << "STD: STRING: myvector contains:";
	for (size_t i = 0; i < myvector3.size(); i++)
		std::cout << ' ' << myvector3[i];
	std::cout << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		for (int i = 1; i < 10; i++)
			myvectorft.push_back(i);
		myvectorft.resize(5);
		myvectorft.resize(8,100);
		myvectorft.resize(12);
		std::cout << FIO << "FT:  INT   : myvector contains:";
		for (size_t i = 0; i < myvectorft.size(); i++)
			std::cout << ' ' << myvectorft[i];
		std::cout << std::endl;
		ft::vector<float> myvector1ft;
		for (int i = 1; i < 10; i++)
			myvector1ft.push_back(i);
		myvector1ft.resize(5);
		myvector1ft.resize(8,100);
		myvector1ft.resize(12);
		std::cout << "FT:  FLOAT : myvector contains:";
		for (size_t i = 0; i < myvector1ft.size(); i++)
			std::cout << ' ' << myvector1ft[i];
		std::cout << std::endl;
		ft::vector<double> myvector2ft;
		for (int i = 1; i < 10; i++)
		myvector2ft.push_back(i);
		myvector2ft.resize(5);
		myvector2ft.resize(8,100);
		myvector2ft.resize(12);
		std::cout << "FT:  DOUBLE: myvector contains:";
		for (size_t i = 0; i < myvector2ft.size(); i++)
			std::cout << ' ' << myvector2ft[i];
		std::cout << std::endl;
		ft::vector<std::string> myvector3ft;
		for (int i = 1; i < 10; i++)
		myvector3ft.push_back(std::to_string(i));
		myvector3ft.resize(5);
		myvector3ft.resize(8, "100");
		myvector3ft.resize(12);
		std::cout << "FT:  STRING: myvector contains:";
		for (size_t i = 0; i < myvector3ft.size(); i++)
			std::cout << ' ' << myvector3ft[i];
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_capacity(void)
{
	std::cout << "#------------->" << REDC << " CAPACITY" << END  << std::endl;
	std::vector<int> myvector;
	for (int i = 0; i < 100; i++)
		myvector.push_back(i);
	std::cout << "STD: INT   : | size = " << (int) myvector.size();
	std::cout << " | capacity = " << (int) myvector.capacity();
	std::cout << " | max_size = " << (int) myvector.max_size() << " |" << std::endl;
	std::vector<float> myvector1;
	for (int i = 0; i < 100; i++)
		myvector1.push_back(i);
	std::cout << "STD: FLOAT : | size = " << (float) myvector1.size();
	std::cout << " | capacity = " << (float) myvector1.capacity();
	std::cout << " | max_size = " << (float) myvector1.max_size() << " |" << std::endl;
	std::vector<double> myvector2;
	for (int i = 0; i < 100; i++)
		myvector2.push_back(i);
	std::cout << "STD: DOUBLE: | size = " << (double) myvector2.size();
	std::cout << " | capacity = " << (double) myvector2.capacity();
	std::cout << " | max_size = " << (double) myvector2.max_size() << " |" << std::endl;
	std::vector<std::string> myvector3;
	for (int i = 0; i < 100; i++)
		myvector3.push_back(std::to_string(i));
	std::cout << "STD: STRING: | size = " << myvector3.size();
	std::cout << " | capacity = " << myvector3.capacity();
	std::cout << " | max_size = " << myvector3.max_size() << " |" << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		for (int i = 0; i < 100; i++)
			myvectorft.push_back(i);
		std::cout << FIO << "FT:  INT   : | size = " << (int) myvectorft.size();
		std::cout << " | capacity = " << (int) myvectorft.capacity();
		std::cout << " | max_size = " << (int) myvectorft.max_size() << " |" << std::endl;
		ft::vector<float> myvector1ft;
		for (int i = 0; i < 100; i++)
			myvector1ft.push_back(i);
		std::cout << "FT:  FLOAT : | size = " << (float) myvector1ft.size();
		std::cout << " | capacity = " << (float) myvector1ft.capacity();
		std::cout << " | max_size = " << (float) myvector1ft.max_size() << " |" << std::endl;
		ft::vector<double> myvector2ft;
		for (int i = 0; i < 100; i++)
			myvector2ft.push_back(i);
		std::cout << "FT:  DOUBLE: | size = " << (double) myvector2ft.size();
		std::cout << " | capacity = " << (double) myvector2ft.capacity();
		std::cout << " | max_size = " << (double) myvector2ft.max_size() << " |" << std::endl;
		ft::vector<std::string> myvector3ft;
		for (int i = 0; i < 100; i++)
			myvector3ft.push_back(std::to_string(i));
		std::cout << "FT:  STRING: | size = " << myvector3ft.size();
		std::cout << " | capacity = " << myvector3ft.capacity();
		std::cout << " | max_size = " << myvector3ft.max_size() << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_empty(void)
{
	std::cout << "#------------->" << REDC << " EMPTY" << END  << std::endl;
	std::vector<int> myvector;
	int sum (0);
	for (int i = 1; i <= 10;i++)
		myvector.push_back(i);
	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "STD: INT   : total: " << sum << std::endl;
	std::vector<float> myvector1;
	float sum1 (0);
	for (int i = 1; i <= 10; i++)
		myvector1.push_back(i);
	while (!myvector1.empty())
	{
		sum1 += myvector1.back();
		myvector1.pop_back();
	}
	std::cout << "STD: FLOAT : total: " << sum1 << std::endl;
	std::vector<double> myvector2;
	float sum2 (0);
	for (int i = 1; i <= 10; i++)
		myvector2.push_back(i);
	while (!myvector2.empty())
	{
		sum2 += myvector2.back();
		myvector2.pop_back();
	}
	std::cout << "STD: DOUBLE: total: " << sum2 << std::endl;
	std::vector<std::string> myvector3;
	std::string sum3;
	for (int i = 1; i <= 10; i++)
		myvector3.push_back(std::to_string(i));
	while (!myvector3.empty())
	{
		sum3 += myvector3.back();
		myvector3.pop_back();
	}
	std::cout << "STD: STRING: total: " << sum3 << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		int sumft (0);
		for (int i = 1; i <= 10;i++)
			myvectorft.push_back(i);
		while (!myvectorft.empty())
		{
			sumft += myvectorft.back();
			myvectorft.pop_back();
		}
		std::cout << FIO << "FT:  INT   : total: " << sumft << std::endl;
		ft::vector<float> myvector1ft;
		float sum1ft (0);
		for (int i = 1; i <= 10; i++)
			myvector1ft.push_back(i);
		while (!myvector1ft.empty())
		{
			sum1ft += myvector1ft.back();
			myvector1ft.pop_back();
		}
		std::cout << "FT:  FLOAT : total: " << sum1ft << std::endl;
		ft::vector<double> myvector2ft;
		float sum2ft (0);
		for (int i = 1; i <= 10; i++)
			myvector2ft.push_back(i);
		while (!myvector2ft.empty())
		{
			sum2ft += myvector2ft.back();
			myvector2ft.pop_back();
		}
		std::cout << "FT:  DOUBLE: total: " << sum2ft << std::endl;
		ft::vector<std::string> myvector3ft;
		std::string sum3ft;
		for (int i = 1; i <= 10; i++)
			myvector3ft.push_back(std::to_string(i));
		while (!myvector3ft.empty())
		{
			sum3ft += myvector3ft.back();
			myvector3ft.pop_back();
		}
		std::cout << "FT:  STRING: total: " << sum3ft << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_reserve(void)
{
	std::cout << "#------------->" << REDC << " RESERVE" << END  << std::endl;
	std::vector<int>::size_type sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "STD: INT   : foo: ";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << sz;
		}
	}
	std::cout << " | ";
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "bar: ";
	for (int i = 0; i < 100; ++i) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << sz;
		}
	}
	std::cout << " |" << std::endl;
	std::vector<float>::size_type szf;
	std::vector<float> foof;
	szf = foof.capacity();
	std::cout << "STD: FLOAT : foo: ";
	for (int i = 0; i < 100; ++i) {
		foof.push_back(i);
		if (szf != foof.capacity()) {
			szf = foof.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << szf;
		}
	}
	std::cout << " | ";
	std::vector<float> barf;
	szf = barf.capacity();
	barf.reserve(100);
	std::cout << "bar: ";
	for (int i = 0; i < 100; ++i) {
		barf.push_back(i);
		if (szf != barf.capacity()) {
			szf = barf.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << szf;
		}
	}
	std::cout << " |" << std::endl;
	std::vector<double>::size_type szfd;
	std::vector<double> food;
	szfd = food.capacity();
	std::cout << "STD: DOUBLE: foo: ";
	for (int i = 0; i < 100; ++i) {
		food.push_back(i);
		if (szfd != food.capacity()) {
			szfd = food.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << szfd;
		}
	}
	std::cout << " | ";
	std::vector<double> barfd;
	szfd = barfd.capacity();
	barfd.reserve(100);
	std::cout << "bar: ";
	for (int i = 0; i < 100; ++i) {
		barfd.push_back(i);
		if (szfd != barfd.capacity()) {
			szfd = barfd.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << szfd;
		}
	}
	std::cout << " |" << std::endl;
	std::vector<std::string>::size_type szfd1;
	std::vector<std::string> food1;
	szfd1 = food1.capacity();
	std::cout << "STD: STRING: foo: ";
	for (int i = 0; i < 100; ++i) {
		food1.push_back(std::to_string(i));
		if (szfd1 != food1.capacity()) {
			szfd1 = food1.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << szfd1;
		}
	}
	std::cout << " | ";
	std::vector<std::string> barfd1;
	szfd1 = barfd1.capacity();
	barfd1.reserve(100);
	std::cout << "bar: ";
	for (int i = 0; i < 100; ++i) {
		barfd1.push_back(std::to_string(i));
		if (szfd1 != barfd1.capacity()) {
			szfd1 = barfd1.capacity();
			if (i != 0)
				std::cout << " | ";
			std::cout << szfd1;
		}
	}
	std::cout << " |" << std::endl;
	try
	{
		ft::vector<int>::size_type szft;
		ft::vector<int> fooft;
		szft = fooft.capacity();
		std::cout << FIO << "FT:  INT   : foo: ";
		for (int i = 0; i < 100; ++i) {
			fooft.push_back(i);
			if (szft != fooft.capacity()) {
				szft = fooft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szft;
			}
		}
		std::cout << " | ";
		ft::vector<int> barft;
		szft = barft.capacity();
		barft.reserve(100);
		std::cout << "bar: ";
		for (int i = 0; i < 100; ++i) {
			barft.push_back(i);
			if (szft != barft.capacity()) {
				szft = barft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szft;
			}
		}
		std::cout << " |" << std::endl;
		ft::vector<float>::size_type szfft;
		ft::vector<float> foofft;
		szfft = foofft.capacity();
		std::cout << "FT:  FLOAT : foo: ";
		for (int i = 0; i < 100; ++i) {
			foofft.push_back(i);
			if (szfft != foofft.capacity()) {
				szfft = foofft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szfft;
			}
		}
		std::cout << " | ";
		ft::vector<float> barfft;
		szfft = barfft.capacity();
		barfft.reserve(100);
		std::cout << "bar: ";
		for (int i = 0; i < 100; ++i) {
			barfft.push_back(i);
			if (szfft != barfft.capacity()) {
				szfft = barfft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szfft;
			}
		}
		std::cout << " |" << std::endl;
		ft::vector<double>::size_type szfdft;
		ft::vector<double> foodft;
		szfdft = foodft.capacity();
		std::cout << "FT:  DOUBLE: foo: ";
		for (int i = 0; i < 100; ++i) {
			foodft.push_back(i);
			if (szfdft != foodft.capacity()) {
				szfdft = foodft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szfdft;
			}
		}
		std::cout << " | ";
		ft::vector<double> barfdft;
		szfdft = barfdft.capacity();
		barfdft.reserve(100);
		std::cout << "bar: ";
		for (int i = 0; i < 100; ++i) {
			barfdft.push_back(i);
			if (szfdft != barfdft.capacity()) {
				szfdft = barfdft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szfdft;
			}
		}
		std::cout << " |" << std::endl;
		ft::vector<std::string>::size_type szfd1ft;
		ft::vector<std::string> food1ft;
		szfd1ft = food1ft.capacity();
		std::cout << "FT:  STRING: foo: ";
		for (int i = 0; i < 100; ++i) {
			food1ft.push_back(std::to_string(i));
			if (szfd1ft != food1ft.capacity()) {
				szfd1ft = food1ft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szfd1ft;
			}
		}
		std::cout << " | ";
		ft::vector<std::string> barfd1ft;
		szfd1ft = barfd1ft.capacity();
		barfd1ft.reserve(100);
		std::cout << "bar: ";
		for (int i = 0; i < 100; ++i) {
			barfd1ft.push_back(std::to_string(i));
			if (szfd1ft != barfd1ft.capacity()) {
				szfd1ft = barfd1ft.capacity();
				if (i != 0)
					std::cout << " | ";
				std::cout << szfd1ft;
			}
		}
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_operator2(void)
{
	std::cout << "#------------->" << REDC << " OPERATOR[]" << END  << std::endl;
	std::vector<int> myvector (10);
	std::vector<int>::size_type sz = myvector.size();
	for (unsigned i = 0; i < sz; i++) 
		myvector[i] = i;
	for (unsigned i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = myvector[sz - 1 - i];
		myvector[sz - 1 - i] = myvector[i];
		myvector[i] = temp;
	}
	ft_hd(1, 1);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl;
	std::vector<float> myvector1 (10);
	std::vector<float>::size_type sz1 = myvector1.size();
	for (unsigned i = 0; i < sz1; i++) 
		myvector1[i] = i;
	for (unsigned i = 0; i < sz1 / 2; i++)
	{
		float temp1;
		temp1 = myvector1[sz1 - 1 - i];
		myvector1[sz1 - 1 - i] = myvector1[i];
		myvector1[i] = temp1;
	}
	ft_hd(1, 2);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < sz; i++)
		std::cout << ' ' << myvector1[i];
	std::cout << std::endl;
	std::vector<double> myvector1d (10);
	std::vector<double>::size_type sz1d = myvector1d.size();
	for (unsigned i = 0; i < sz1d; i++) 
		myvector1d[i] = i;
	for (unsigned i = 0; i < sz1d / 2; i++)
	{
		double temp1d;
		temp1d = myvector1d[sz1d - 1 - i];
		myvector1d[sz1d - 1 - i] = myvector1d[i];
		myvector1d[i] = temp1d;
	}
	ft_hd(1, 3);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < sz1d; i++)
		std::cout << ' ' << myvector1d[i];
	std::cout << std::endl;

	std::vector<std::string> myvector1ds (10);
	std::vector<std::string>::size_type sz1ds = myvector1ds.size();
	for (unsigned i = 0; i < sz1ds; i++) 
		myvector1ds[i] = std::to_string(i);
	for (unsigned i = 0; i < sz1ds / 2; i++)
	{
		std::string temp1dss;
		temp1dss = myvector1ds[sz1ds - 1 - i];
		myvector1ds[sz1ds - 1 - i] = myvector1ds[i];
		myvector1ds[i] = temp1dss;
	}
	ft_hd(1, 4);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < sz1ds; i++)
		std::cout << ' ' << myvector1ds[i];
	std::cout << std::endl;
	try
	{
		ft::vector<int> myvectorft(10);
		ft::vector<int>::size_type szft = myvectorft.size();
		for (unsigned i = 0; i < szft; i++) 
			myvectorft[i] = i;
		for (unsigned i = 0; i < szft / 2; i++)
		{
			int tempft;
			tempft = myvectorft[szft - 1 - i];
			myvectorft[sz - 1 - i] = myvectorft[i];
			myvectorft[i] = tempft;
		}
		ft_hd(2, 1);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < szft; i++)
			std::cout << ' ' << myvectorft[i];
		std::cout << std::endl;
		ft::vector<float> myvector1ft (10);
		ft::vector<float>::size_type sz1ft = myvector1ft.size();
		for (unsigned i = 0; i < sz1ft; i++) 
			myvector1ft[i] = i;
		for (unsigned i = 0; i < sz1ft / 2; i++)
		{
			float temp1ft;
			temp1ft = myvector1ft[sz1ft - 1 - i];
			myvector1ft[sz1ft - 1 - i] = myvector1ft[i];
			myvector1ft[i] = temp1ft;
		}
		ft_hd(2, 2);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < sz; i++)
			std::cout << ' ' << myvector1ft[i];
		std::cout << std::endl;
		ft::vector<double> myvector1dft(10);
		ft::vector<double>::size_type sz1dft = myvector1dft.size();
		for (unsigned i = 0; i < sz1dft; i++) 
			myvector1dft[i] = i;
		for (unsigned i = 0; i < sz1dft / 2; i++)
		{
			double temp1dft;
			temp1dft = myvector1dft[sz1dft - 1 - i];
			myvector1dft[sz1dft - 1 - i] = myvector1dft[i];
			myvector1dft[i] = temp1dft;
		}
		ft_hd(2, 3);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < sz1dft; i++)
			std::cout << ' ' << myvector1dft[i];
		std::cout << std::endl;
		ft::vector<std::string> myvector1dsft (10);
		ft::vector<std::string>::size_type sz1dsft = myvector1dsft.size();
		for (unsigned i = 0; i < sz1dsft; i++) 
			myvector1dsft[i] = std::to_string(i);
		for (unsigned i = 0; i < sz1dsft / 2; i++)
		{
			std::string temp1dssft;
			temp1dssft = myvector1dsft[sz1dsft - 1 - i];
			myvector1dsft[sz1dsft - 1 - i] = myvector1dsft[i];
			myvector1dsft[i] = temp1dssft;
		}
		ft_hd(2, 4);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < sz1dsft; i++)
			std::cout << ' ' << myvector1dsft[i];
		std::cout << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_at(void)
{
	std::cout << "#------------->" << REDC << " AT" << END  << std::endl;
	std::vector<int> myvector (10);
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;
	ft_hd(1, 1);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << std::endl;
	std::vector<float> myvector1 (10);
	for (unsigned i = 0; i < myvector1.size(); i++)
		myvector1.at(i)=i;
	ft_hd(1, 2);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1.size(); i++)
		std::cout << ' ' << myvector1.at(i);
	std::cout << std::endl;
	std::vector<double> myvector1f (10);
	for (unsigned i = 0; i < myvector1f.size(); i++)
		myvector1f.at(i) = i;
	ft_hd(1, 3);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1f.size(); i++)
		std::cout << ' ' << myvector1f.at(i);
	std::cout << std::endl;	
	std::vector<std::string> myvector1s (10);
	for (unsigned i = 0; i < myvector1s.size(); i++)
		myvector1s.at(i) = std::to_string(i);
	ft_hd(1, 4);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1s.size(); i++)
		std::cout << ' ' << myvector1s.at(i);
	std::cout << std::endl;
	try
	{
		ft::vector<int> myvectorft (10);
		for (unsigned i = 0; i < myvectorft.size(); i++)
			myvectorft.at(i) = i;
		ft_hd(2, 1);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvectorft.size(); i++)
			std::cout << ' ' << myvectorft.at(i);
		std::cout << std::endl;
		ft::vector<float> myvector1ft (10);
		for (unsigned i = 0; i < myvector1ft.size(); i++)
			myvector1ft.at(i) = i;
		ft_hd(2, 2);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1ft.size(); i++)
			std::cout << ' ' << myvector1ft.at(i);
		std::cout << std::endl;
		ft::vector<double> myvector1fft (10);
		for (unsigned i = 0; i < myvector1fft.size(); i++)
			myvector1fft.at(i) = i;
		ft_hd(2, 3);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1fft.size(); i++)
			std::cout << ' ' << myvector1fft.at(i);
		std::cout << std::endl;	
		ft::vector<std::string> myvector1sft (10);
		for (unsigned i = 0; i < myvector1sft.size(); i++)
			myvector1sft.at(i) = std::to_string(i);
		ft_hd(2, 4);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1sft.size(); i++)
			std::cout << ' ' << myvector1sft.at(i);
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
	
}

static void	testv_front(void)
{
	std::cout << "#------------->" << REDC << " FRONT" << END  << std::endl;
	std::vector<int> myvector;
	myvector.push_back(78);
	myvector.push_back(16);
	myvector.front() -= myvector.back();
	ft_hd(1, 1);
	std::cout << "myvector.front() is now " << myvector.front() << std::endl;
	std::vector<float> myvectorf;
	myvectorf.push_back(78);
	myvectorf.push_back(16);
	myvectorf.front() -= myvectorf.back();
	ft_hd(1, 2);
	std::cout << "myvector.front() is now " << myvectorf.front() << std::endl;
	std::vector<double> myvectorfd;
	myvectorfd.push_back(78);
	myvectorfd.push_back(16);
	myvectorfd.front() -= myvectorfd.back();
	ft_hd(1, 3);
	std::cout << "myvector.front() is now " << myvectorfd.front() << std::endl;
	std::vector<std::string> myvectorfd1;
	myvectorfd1.push_back("78");
	myvectorfd1.push_back("16");
	myvectorfd1.front();
	ft_hd(1, 4);
	std::cout << "myvector.front() is now " << myvectorfd1.front() << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		myvectorft.push_back(78);
		myvectorft.push_back(16);
		myvectorft.front() -= myvectorft.back();
		ft_hd(2, 1);
		std::cout << "myvector.front() is now " << myvectorft.front() << std::endl;
		ft::vector<float> myvectorfft;
		myvectorfft.push_back(78);
		myvectorfft.push_back(16);
		myvectorfft.front() -= myvectorfft.back();
		ft_hd(2, 2);
		std::cout << "myvector.front() is now " << myvectorfft.front() << std::endl;
		ft::vector<double> myvectorfdft;
		myvectorfdft.push_back(78);
		myvectorfdft.push_back(16);
		myvectorfdft.front() -= myvectorfdft.back();
		ft_hd(2, 3);
		std::cout << "myvector.front() is now " << myvectorfdft.front() << std::endl;
		ft::vector<std::string> myvectorfd1ft;
		myvectorfd1ft.push_back("78");
		myvectorfd1ft.push_back("16");
		myvectorfd1ft.front();
		ft_hd(2, 4);
		std::cout << "myvector.front() is now " << myvectorfd1ft.front() << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_back(void)
{
	std::cout << "#------------->" << REDC << " BACK" << END  << std::endl;
	std::vector<int> myvector;
	myvector.push_back(10);
	while (myvector.back() != 0)
		myvector.push_back (myvector.back() -1);
	ft_hd(1, 1);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl;
	std::vector<float> myvector1;
	myvector1.push_back(10);
	while (myvector1.back() != 0)
		myvector1.push_back (myvector1.back() -1);
	ft_hd(1, 2);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1.size() ; i++)
		std::cout << ' ' << myvector1[i];
	std::cout << std::endl;
	std::vector<double> myvector1d;
	myvector1d.push_back(10);
	while (myvector1d.back() != 0)
		myvector1d.push_back (myvector1d.back() -1);
	ft_hd(1, 3);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1d.size() ; i++)
		std::cout << ' ' << myvector1d[i];
	std::cout << std::endl;
	std::vector<std::string> myvector1dd;
	myvector1dd.push_back("10");
	for (int i = 9; i >= 0 ; i--){
		myvector1dd.push_back(std::to_string(i));
	}
	ft_hd(1, 4);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1dd.size() ; i++)
		std::cout << ' ' << myvector1dd[i];
	std::cout << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		myvectorft.push_back(10);
		while (myvectorft.back() != 0)
			myvectorft.push_back (myvectorft.back() -1);
		ft_hd(2, 1);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvectorft.size() ; i++)
			std::cout << ' ' << myvectorft[i];
		std::cout << std::endl;
		ft::vector<float> myvector1ft;
		myvector1ft.push_back(10);
		while (myvector1ft.back() != 0)
			myvector1ft.push_back (myvector1ft.back() -1);
		ft_hd(2, 2);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1ft.size() ; i++)
			std::cout << ' ' << myvector1ft[i];
		std::cout << std::endl;
		ft::vector<double> myvector1dft;
		myvector1dft.push_back(10);
		while (myvector1dft.back() != 0)
			myvector1dft.push_back (myvector1dft.back() -1);
		ft_hd(2, 3);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1dft.size() ; i++)
			std::cout << ' ' << myvector1dft[i];
		std::cout << std::endl;
		ft::vector<std::string> myvector1ddft;
		myvector1ddft.push_back("10");
		for (int i = 9; i >= 0 ; i--){
			myvector1ddft.push_back(std::to_string(i));
		}
		ft_hd(2, 4);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1ddft.size() ; i++)
			std::cout << ' ' << myvector1ddft[i];
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_assign(void)
{
	std::cout << "#------------->" << REDC << " ASSIGN" << END  << std::endl;
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;
	first.assign (7, 100);
	std::vector<int>::iterator it;
	it = first.begin() + 1;
	second.assign (it, first.end() - 1);
	int myints[] = {1776, 7, 4};
	third.assign (myints,myints + 3);
	ft_hd(1, 1);
	std::cout << "Size_1 = " << int (first.size());
	std::cout << " | Size_2 = " << int (second.size());
	std::cout << " | Size_3 = " << int (third.size()) << " |" << std::endl;
	std::vector<float> firstf;
	std::vector<float> secondf;
	std::vector<float> thirdf;
	firstf.assign (7, 100);
	std::vector<float>::iterator itf;
	itf = firstf.begin() + 1;
	secondf.assign (itf, firstf.end() - 1);
	float myintsf[] = {1776, 7, 4};
	thirdf.assign (myintsf, myintsf + 3);
	ft_hd(1, 2);
	std::cout << "Size_1 = " << float (firstf.size());
	std::cout << " | Size_2 = " << float (secondf.size());
	std::cout << " | Size_3 = " << float (thirdf.size()) << " |" << std::endl;
	std::vector<double> firstff;
	std::vector<double> secondff;
	std::vector<double> thirdff;
	firstff.assign (7, 100);
	std::vector<double>::iterator itff;
	itff = firstff.begin() + 1;
	secondff.assign (itf, firstf.end() - 1);
	double myintsff[] = {1776, 7, 4};
	thirdff.assign (myintsff, myintsff + 3);
	ft_hd(1, 3);
	std::cout << "Size_1 = " << double (firstff.size());
	std::cout << " | Size_2 = " << double (secondff.size());
	std::cout << " | Size_3 = " << double (thirdff.size()) << " |" << std::endl;
	std::vector<std::string> firstffs;
	std::vector<std::string> secondffs;
	std::vector<std::string> thirdffs;
	firstffs.assign (7, "100");
	std::vector<std::string>::iterator itffs;
	itffs = firstffs.begin() + 1;
	secondffs.assign (itffs, firstffs.end() - 1);
	std::string myintsffs[] = {"1776", "7", "4"};
	thirdffs.assign (myintsffs, myintsffs + 3);
	ft_hd(1, 4);
	std::cout << "Size_1 = " << firstffs.size();
	std::cout << " | Size_2 = " << secondffs.size();
	std::cout << " | Size_3 = " << thirdffs.size() << " |" << std::endl;
	try
	{
		ft::vector<int> firstft;
		ft::vector<int> secondft;
		ft::vector<int> thirdft;
		firstft.assign (7, 100);
		ft::vector<int>::iterator itft;
		itft = firstft.begin() + 1;
		secondft.assign (itft, firstft.end() - 1);
		int myintsft[] = {1776, 7, 4};
		thirdft.assign (myintsft, myintsft + 3);
		ft_hd(2, 1);
		std::cout << "Size_1 = " << int (firstft.size());
		std::cout << " | Size_2 = " << int (secondft.size());
		std::cout << " | Size_3 = " << int (thirdft.size()) << " |" << std::endl;
		ft::vector<float> firstfft;
		ft::vector<float> secondfft;
		ft::vector<float> thirdfft;
		firstfft.assign (7, 100);
		ft::vector<float>::iterator itfft;
		itfft = firstfft.begin() + 1;
		secondfft.assign (itfft, firstfft.end() - 1);
		float myintsfft[] = {1776, 7, 4};
		thirdfft.assign (myintsfft, myintsfft + 3);
		ft_hd(2, 2);
		std::cout << "Size_1 = " << float (firstfft.size());
		std::cout << " | Size_2 = " << float (secondfft.size());
		std::cout << " | Size_3 = " << float (thirdfft.size()) << " |" << std::endl;
		ft::vector<double> firstffft;
		ft::vector<double> secondffft;
		ft::vector<double> thirdffft;
		firstffft.assign (7, 100);
		ft::vector<double>::iterator itffft;
		itffft = firstffft.begin() + 1;
		secondffft.assign (itffft, firstffft.end() - 1);
		double myintsffft[] = {1776, 7, 4};
		thirdffft.assign (myintsffft, myintsffft + 3);
		ft_hd(2, 3);
		std::cout << "Size_1 = " << double (firstffft.size());
		std::cout << " | Size_2 = " << double (secondffft.size());
		std::cout << " | Size_3 = " << double (thirdffft.size()) << " |" << std::endl;
		ft::vector<std::string> firstffsft;
		ft::vector<std::string> secondffsft;
		ft::vector<std::string> thirdffsft;
		firstffsft.assign (7, "100");
		ft::vector<std::string>::iterator itffsft;
		itffsft = firstffsft.begin() + 1;
		secondffsft.assign (itffsft, firstffsft.end() - 1);
		std::string myintsffsft[] = {"1776", "7", "4"};
		thirdffsft.assign (myintsffsft, myintsffsft + 3);
		ft_hd(2, 4);
		std::cout << "Size_1 = " << firstffsft.size();
		std::cout << " | Size_2 = " << secondffsft.size();
		std::cout << " | Size_3 = " << thirdffsft.size() << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_push_back(void)
{
	std::cout << "#------------->" << REDC << " PUSH BACK" << END  << std::endl;
	std::vector<int> myvector;
	for (int i = 0; i < 5; i++)
		myvector.push_back(i);
	ft_hd(1, 1);
	std::cout << "myvector contains: " << int(myvector.size()) << " numbers: ";
	for (int i = 0; i < 5; i++)
		std::cout << myvector[i] << " ";
	std::cout << std::endl;
	std::vector<float> myvectorf;
	for (int i = 0; i < 5; i++)
		myvectorf.push_back(i);
	ft_hd(1, 2);
	std::cout << "myvector contains: " << float(myvectorf.size()) << " numbers: ";
	for (int i = 0; i < 5; i++)
		std::cout << myvectorf[i] << " ";
	std::cout << std::endl;
	std::vector<double> myvectorfd;
	for (int i = 0; i < 5; i++)
		myvectorfd.push_back(i);
	ft_hd(1, 3);
	std::cout << "myvector contains: " << double(myvectorfd.size()) << " numbers: ";
	for (int i = 0; i < 5; i++)
		std::cout << myvectorf[i] << " ";
	std::cout << std::endl;
	std::vector<std::string> myvectorfds;
	for (int i = 0; i < 5; i++)
		myvectorfds.push_back(std::to_string(i));
	ft_hd(1, 3);
	std::cout << "myvector contains: " << myvectorfd.size() << " numbers: ";
	for (int i = 0; i < 5; i++)
		std::cout << myvectorf[i] << " ";
	std::cout << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		for (int i = 0; i < 5; i++)
			myvectorft.push_back(i);
		ft_hd(2, 1);
		std::cout << "myvector contains: " << int(myvectorft.size()) << " numbers: ";
		for (int i = 0; i < 5; i++)
			std::cout << myvectorft[i] << " ";
		std::cout << std::endl;
		ft::vector<float> myvectorfft;
		for (int i = 0; i < 5; i++)
			myvectorfft.push_back(i);
		ft_hd(2, 2);
		std::cout << "myvector contains: " << float(myvectorfft.size()) << " numbers: ";
		for (int i = 0; i < 5; i++)
			std::cout << myvectorfft[i] << " ";
		std::cout << std::endl;
		ft::vector<double> myvectorfdft;
		for (int i = 0; i < 5; i++)
			myvectorfdft.push_back(i);
		ft_hd(2, 3);
		std::cout << "myvector contains: " << double(myvectorfdft.size()) << " numbers: ";
		for (int i = 0; i < 5; i++)
			std::cout << myvectorfft[i] << " ";
		std::cout << std::endl;
		ft::vector<std::string> myvectorfdsft;
		for (int i = 0; i < 5; i++)
			myvectorfdsft.push_back(std::to_string(i));
		ft_hd(2, 3);
		std::cout << "myvector contains: " << myvectorfdft.size() << " numbers: ";
		for (int i = 0; i < 5; i++)
			std::cout << myvectorfft[i] << " ";
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_pop_back(void)
{
	std::cout << "#------------->" << REDC << " POP BACK" << END  << std::endl;
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	ft_hd(1, 1);
	std::cout << "The elements of myvector add up to " << sum << std::endl;
	std::vector<float> myvectorf;
	int sumf (0);
	myvectorf.push_back (100);
	myvectorf.push_back (200);
	myvectorf.push_back (300);
	while (!myvectorf.empty())
	{
		sumf += myvectorf.back();
		myvectorf.pop_back();
	}
	ft_hd(1, 2);
	std::cout << "The elements of myvector add up to " << sumf << std::endl;
	std::vector<double> myvectorfd;
	int sumfd (0);
	myvectorfd.push_back (100);
	myvectorfd.push_back (200);
	myvectorfd.push_back (300);
	while (!myvectorfd.empty())
	{
		sumfd += myvectorfd.back();
		myvectorfd.pop_back();
	}
	ft_hd(1, 3);
	std::cout << "The elements of myvector add up to " << sumfd << std::endl;
	std::vector<std::string> myvectorfd1;
	std::string sumfd1;
	myvectorfd1.push_back ("0");
	myvectorfd1.push_back ("0");
	myvectorfd1.push_back ("6");
	while (!myvectorfd1.empty())
	{
		sumfd1 += myvectorfd1.back();
		myvectorfd1.pop_back();
	}
	ft_hd(1, 4);
	std::cout << "The elements of myvector add up to " << sumfd1 << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		int sumft (0);
		myvectorft.push_back (100);
		myvectorft.push_back (200);
		myvectorft.push_back (300);
		while (!myvectorft.empty())
		{
			sumft += myvectorft.back();
			myvectorft.pop_back();
		}
		ft_hd(2, 1);
		std::cout << "The elements of myvector add up to " << sumft << std::endl;
		ft::vector<float> myvectorfft;
		int sumfft (0);
		myvectorfft.push_back (100);
		myvectorfft.push_back (200);
		myvectorfft.push_back (300);
		while (!myvectorfft.empty())
		{
			sumfft += myvectorfft.back();
			myvectorfft.pop_back();
		}
		ft_hd(1, 2);
		std::cout << "The elements of myvector add up to " << sumfft << std::endl;
		ft::vector<double> myvectorfdft;
		int sumfdft (0);
		myvectorfdft.push_back (100);
		myvectorfdft.push_back (200);
		myvectorfdft.push_back (300);
		while (!myvectorfdft.empty())
		{
			sumfdft += myvectorfdft.back();
			myvectorfdft.pop_back();
		}
		ft_hd(1, 3);
		std::cout << "The elements of myvector add up to " << sumfdft << std::endl;
		ft::vector<std::string> myvectorfd1ft;
		std::string sumfd1ft;
		myvectorfd1ft.push_back ("0");
		myvectorfd1ft.push_back ("0");
		myvectorfd1ft.push_back ("6");
		while (!myvectorfd1ft.empty())
		{
			sumfd1ft += myvectorfd1ft.back();
			myvectorfd1ft.pop_back();
		}
		ft_hd(1, 4);
		std::cout << "The elements of myvector add up to " << sumfd1ft << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_insert(void)
{
	std::cout << "#------------->" << REDC << " INSERT" << END  << std::endl;
	std::vector<int> myvector (3, 100);
	std::vector<int>::iterator it;
	it = myvector.begin();
	it = myvector.insert (it, 200);
	myvector.insert (it, 2, 300);
	it = myvector.begin();
	std::vector<int> anothervector (2, 400);
	myvector.insert (it + 2, anothervector.begin(), anothervector.end());
	int myarray [] = { 501,502,503 };
	ft_hd(1, 1);
	myvector.insert (myvector.begin(), myarray, myarray + 3);
	std::cout << "myvector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::vector<float> myvectorf (3, 100);
	std::vector<float>::iterator itf;
	itf = myvectorf.begin();
	itf = myvectorf.insert (itf, 200);
	myvectorf.insert (itf, 2, 300);
	itf = myvectorf.begin();
	std::vector<float> anothervectorf (2, 400);
	myvectorf.insert (itf + 2, anothervectorf.begin(), anothervectorf.end());
	int myarrayf [] = { 501,502,503 };
	ft_hd(1, 2);
	myvectorf.insert (myvectorf.begin(), myarrayf, myarrayf + 3);
	std::cout << "myvector contains:";
	for (itf = myvectorf.begin(); itf < myvectorf.end(); itf++)
		std::cout << ' ' << *itf;
	std::cout << std::endl;
	std::vector<double> myvectorfd (3, 100);
	std::vector<double>::iterator itfd;
	itfd = myvectorfd.begin();
	itfd = myvectorfd.insert (itfd, 200);
	myvectorfd.insert (itfd, 2, 300);
	itfd = myvectorfd.begin();
	std::vector<double> anothervectorfd (2, 400);
	myvectorfd.insert (itfd + 2, anothervectorfd.begin(), anothervectorfd.end());
	int myarrayfd [] = { 501,502,503 };
	ft_hd(1, 3);
	myvectorfd.insert (myvectorfd.begin(), myarrayfd, myarrayfd + 3);
	std::cout << "myvector contains:";
	for (itfd = myvectorfd.begin(); itfd < myvectorfd.end(); itfd++)
		std::cout << ' ' << *itfd;
	std::cout << std::endl;
	std::vector<std::string> myvectorfda1 (1, "100");
	std::vector<std::string>::iterator itfda1;
	itfda1 = myvectorfda1.begin();
	itfda1 = myvectorfda1.insert (itfda1, "200");
	myvectorfda1.insert (itfda1, 2, "300");
	itfda1 = myvectorfda1.begin();
	std::vector<std::string> anothervectorfda1 (1, "400");
	myvectorfda1.insert (itfda1, myvectorfda1.begin(), myvectorfda1.end());
	std::string myarrayfda1 [] = { "501", "502", "503" };
	ft_hd(1, 4);
	myvectorfda1.insert (myvectorfda1.begin(), myarrayfda1, myarrayfda1);
	std::cout << "myvector contains:";
	for (itfda1 = myvectorfda1.begin(); itfda1 < myvectorfda1.end(); itfda1++)
		std::cout << ' ' << *itfda1;
	std::cout << std::endl;
	try
	{
		ft::vector<int> myvectorft (3, 100);
		ft::vector<int>::iterator itft;
		itft = myvectorft.begin();
		itft = myvectorft.insert (itft, 200);
		myvectorft.insert (itft, 2, 300);
		itft = myvectorft.begin();
		ft::vector<int> anothervectorft (2, 400);
		myvectorft.insert (itft + 2, anothervectorft.begin(), anothervectorft.end());
		int myarrayft [] = { 501,502,503 };
		ft_hd(2, 1);
		myvectorft.insert (myvectorft.begin(), myarrayft, myarrayft + 3);
		std::cout << "myvector contains:";
		for (itft = myvectorft.begin(); itft < myvectorft.end(); itft++)
			std::cout << ' ' << *itft;
		std::cout << std::endl;
		ft::vector<float> myvectorfft (3, 100);
		ft::vector<float>::iterator itfft;
		itfft = myvectorfft.begin();
		itfft = myvectorfft.insert (itfft, 200);
		myvectorfft.insert (itfft, 2, 300);
		itfft = myvectorfft.begin();
		ft::vector<float> anothervectorfft (2, 400);
		myvectorfft.insert (itfft + 2, anothervectorfft.begin(), anothervectorfft.end());
		int myarrayfft [] = { 501,502,503 };
		ft_hd(2, 2);
		myvectorfft.insert (myvectorfft.begin(), myarrayfft, myarrayfft + 3);
		std::cout << "myvector contains:";
		for (itfft = myvectorfft.begin(); itfft < myvectorfft.end(); itfft++)
			std::cout << ' ' << *itfft;
		std::cout << std::endl;
		ft::vector<double> myvectorfdft (3, 100);
		ft::vector<double>::iterator itfdft;
		itfdft = myvectorfdft.begin();
		itfdft = myvectorfdft.insert (itfdft, 200);
		myvectorfdft.insert (itfdft, 2, 300);
		itfdft = myvectorfdft.begin();
		ft::vector<double> anothervectorfdft (2, 400);
		myvectorfdft.insert (itfdft + 2, anothervectorfdft.begin(), anothervectorfdft.end());
		int myarrayfdft [] = { 501,502,503 };
		ft_hd(2, 3);
		myvectorfdft.insert (myvectorfdft.begin(), myarrayfdft, myarrayfdft + 3);
		std::cout << "myvector contains:";
		for (itfdft = myvectorfdft.begin(); itfdft < myvectorfdft.end(); itfdft++)
			std::cout << ' ' << *itfdft;
		std::cout << std::endl;

		ft::vector<std::string> myvectorfda1ft (1, "100");
		ft::vector<std::string>::iterator itfda1ft;
		itfda1ft = myvectorfda1ft.begin();
		itfda1ft = myvectorfda1ft.insert (itfda1ft, "200");
		myvectorfda1ft.insert (itfda1ft, 2, "300");
		itfda1ft = myvectorfda1ft.begin();
		ft::vector<std::string> anothervectorfda1ft (1, "400");
		myvectorfda1ft.insert (itfda1ft, myvectorfda1ft.begin(), myvectorfda1ft.end());
		std::string myarrayfda1ft [] = { "501", "502", "503" };
		ft_hd(2, 4);
		myvectorfda1ft.insert (myvectorfda1ft.begin(), myarrayfda1ft, myarrayfda1ft);
		std::cout << "myvector contains:";
		for (itfda1ft = myvectorfda1ft.begin(); itfda1ft < myvectorfda1ft.end(); itfda1ft++)
			std::cout << ' ' << *itfda1ft;
		std::cout << std::endl;
			std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_erase(void)
{
	std::cout << "#------------->" << REDC << " ERESE" << END  << std::endl;
	std::vector<int> myvector;
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);
	myvector.erase (myvector.begin() + 5);
	myvector.erase (myvector.begin(), myvector.begin() + 3);
	ft_hd(1, 1);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl;
	std::vector<float> myvector1;
	for (int i = 1; i <= 10; i++)
		myvector1.push_back(i);
	myvector1.erase (myvector1.begin() + 5);
	myvector1.erase (myvector1.begin(), myvector1.begin() + 3);
	ft_hd(1, 2);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1.size(); ++i)
		std::cout << ' ' << myvector1[i];
	std::cout << std::endl;
	std::vector<double> myvector1d;
	for (int i = 1; i <= 10; i++)
		myvector1d.push_back(i);
	myvector1d.erase (myvector1d.begin() + 5);
	myvector1d.erase (myvector1d.begin(), myvector1d.begin() + 3);
	ft_hd(1, 3);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1d.size(); ++i)
		std::cout << ' ' << myvector1d[i];
	std::cout << std::endl;
	std::vector<std::string> myvector1s;
	for (int i = 1; i <= 10; i++)
		myvector1s.push_back(std::to_string(i));
	myvector1s.erase (myvector1s.begin() + 5);
	myvector1s.erase (myvector1s.begin(), myvector1s.begin() + 3);
	ft_hd(1, 4);
	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector1s.size(); ++i)
		std::cout << ' ' << myvector1s[i];
	std::cout << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		for (int i = 1; i <= 10; i++)
			myvectorft.push_back(i);
		myvectorft.erase (myvectorft.begin() + 5);
		myvectorft.erase (myvectorft.begin(), myvectorft.begin() + 3);
		ft_hd(2, 1);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvectorft.size(); ++i)
			std::cout << ' ' << myvectorft[i];
		std::cout << std::endl;
		ft::vector<float> myvector1ft;
		for (int i = 1; i <= 10; i++)
			myvector1ft.push_back(i);
		myvector1ft.erase (myvector1ft.begin() + 5);
		myvector1ft.erase (myvector1ft.begin(), myvector1ft.begin() + 3);
		ft_hd(2, 2);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1ft.size(); ++i)
			std::cout << ' ' << myvector1ft[i];
		std::cout << std::endl;
		ft::vector<double> myvector1dft;
		for (int i = 1; i <= 10; i++)
			myvector1dft.push_back(i);
		myvector1dft.erase (myvector1dft.begin() + 5);
		myvector1dft.erase (myvector1dft.begin(), myvector1dft.begin() + 3);
		ft_hd(2, 3);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1dft.size(); ++i)
			std::cout << ' ' << myvector1dft[i];
		std::cout << std::endl;
		ft::vector<std::string> myvector1sft;
		for (int i = 1; i <= 10; i++)
			myvector1sft.push_back(std::to_string(i));
		myvector1sft.erase (myvector1sft.begin() + 5);
		myvector1sft.erase (myvector1sft.begin(), myvector1sft.begin() + 3);
		ft_hd(2, 4);
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector1sft.size(); ++i)
			std::cout << ' ' << myvector1sft[i];
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_swap(void)
{
	std::cout << "#------------->" << REDC << " SWAP" << END  << std::endl;
	std::vector<int> foo (3, 100);
	std::vector<int> bar (5, 200);
	foo.swap(bar);
	ft_hd(1, 1);
	std::cout << "foo:";
	for (unsigned i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << " | bar:";
	for (unsigned i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << std::endl;
	std::vector<float> foof (3, 100);
	std::vector<float> barf (5, 200);
	foof.swap(barf);
	ft_hd(1, 2);
	std::cout << "foo:";
	for (unsigned i = 0; i < foof.size(); i++)
		std::cout << ' ' << foof[i];
	std::cout << " | bar:";
	for (unsigned i = 0; i < barf.size(); i++)
		std::cout << ' ' << barf[i];
	std::cout << std::endl;
	std::vector<double> foofd (3, 100);
	std::vector<double> barfd (5, 200);
	foofd.swap(barfd);
	ft_hd(1, 3);
	std::cout << "foo:";
	for (unsigned i = 0; i < foofd.size(); i++)
		std::cout << ' ' << foofd[i];
	std::cout << " | bar:";
	for (unsigned i = 0; i < barfd.size(); i++)
		std::cout << ' ' << barfd[i];
	std::cout << std::endl;
	std::vector<std::string> foofds (3, "100");
	std::vector<std::string> barfds (5, "200");
	foofds.swap(barfds);
	ft_hd(1, 4);
	std::cout << "foo:";
	for (unsigned i = 0; i < foofds.size(); i++)
		std::cout << ' ' << foofds[i];
	std::cout << " | bar:";
	for (unsigned i = 0; i < barfds.size(); i++)
		std::cout << ' ' << barfds[i];
	std::cout << std::endl;
	try
	{
		ft::vector<int> fooft (3, 100);
		ft::vector<int> barft (5, 200);
		fooft.swap(barft);
		ft_hd(2, 1);
		std::cout << "foo:";
		for (unsigned i = 0; i < fooft.size(); i++)
			std::cout << ' ' << fooft[i];
		std::cout << " | bar:";
		for (unsigned i = 0; i < barft.size(); i++)
			std::cout << ' ' << barft[i];
		std::cout << std::endl;
		ft::vector<float> foofft (3, 100);
		ft::vector<float> barfft (5, 200);
		foofft.swap(barfft);
		ft_hd(2, 2);
		std::cout << "foo:";
		for (unsigned i = 0; i < foofft.size(); i++)
			std::cout << ' ' << foofft[i];
		std::cout << " | bar:";
		for (unsigned i = 0; i < barfft.size(); i++)
			std::cout << ' ' << barfft[i];
		std::cout << std::endl;
		ft::vector<double> foofdft (3, 100);
		ft::vector<double> barfdft (5, 200);
		foofdft.swap(barfdft);
		ft_hd(2, 3);
		std::cout << "foo:";
		for (unsigned i = 0; i < foofdft.size(); i++)
			std::cout << ' ' << foofdft[i];
		std::cout << " | bar:";
		for (unsigned i = 0; i < barfdft.size(); i++)
			std::cout << ' ' << barfdft[i];
		std::cout << std::endl;
		ft::vector<std::string> foofdsft (3, "100");
		ft::vector<std::string> barfdsft (5, "200");
		foofdsft.swap(barfdsft);
		ft_hd(2, 4);
		std::cout << "foo:";
		for (unsigned i = 0; i < foofdsft.size(); i++)
			std::cout << ' ' << foofdsft[i];
		std::cout << " | bar:";
		for (unsigned i = 0; i < barfdsft.size(); i++)
			std::cout << ' ' << barfdsft[i];
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_clear(void)
{
	std::cout << "#------------->" << REDC << " CLEAR" << END  << std::endl;
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	ft_hd(1, 1);
	std::cout << "before:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);
	std::cout << " | after:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << " |" << std::endl;
	std::vector<float> myvectorft;
	myvectorft.push_back (100);
	myvectorft.push_back (200);
	myvectorft.push_back (300);
	ft_hd(1, 2);
	std::cout << "before:";
	for (unsigned i = 0; i < myvectorft.size(); i++)
		std::cout << ' ' << myvectorft[i];
	myvectorft.clear();
	myvectorft.push_back (1101);
	myvectorft.push_back (2202);
	std::cout << " | after:";
	for (unsigned i = 0; i < myvectorft.size(); i++)
		std::cout << ' ' << myvectorft[i];
	std::cout << " |" << std::endl;
	std::vector<double> myvectorftd;
	myvectorftd.push_back (100);
	myvectorftd.push_back (200);
	myvectorftd.push_back (300);
	ft_hd(1, 3);
	std::cout << "before:";
	for (unsigned i = 0; i < myvectorftd.size(); i++)
		std::cout << ' ' << myvectorftd[i];
	myvectorftd.clear();
	myvectorftd.push_back (1101);
	myvectorftd.push_back (2202);
	std::cout << " | after:";
	for (unsigned i = 0; i < myvectorftd.size(); i++)
		std::cout << ' ' << myvectorftd[i];
	std::cout << " |" << std::endl;
	std::vector<std::string> myvectorfts;
	myvectorfts.push_back ("100");
	myvectorfts.push_back ("200");
	myvectorfts.push_back ("300");
	ft_hd(1, 4);
	std::cout << "before:";
	for (unsigned i = 0; i < myvectorfts.size(); i++)
		std::cout << ' ' << myvectorfts[i];
	myvectorfts.clear();
	myvectorfts.push_back ("1101");
	myvectorfts.push_back ("2202");
	std::cout << " | after:";
	for (unsigned i = 0; i < myvectorfts.size(); i++)
		std::cout << ' ' << myvectorfts[i];
	std::cout << " |" << std::endl;
	try
	{
		ft::vector<int> myvectorft;
		myvectorft.push_back (100);
		myvectorft.push_back (200);
		myvectorft.push_back (300);
		ft_hd(2, 1);
		std::cout << "before:";
		for (unsigned i = 0; i < myvectorft.size(); i++)
			std::cout << ' ' << myvectorft[i];
		myvectorft.clear();
		myvectorft.push_back (1101);
		myvectorft.push_back (2202);
		std::cout << " | after:";
		for (unsigned i = 0; i < myvectorft.size(); i++)
			std::cout << ' ' << myvectorft[i];
		std::cout << " |" << std::endl;
		ft::vector<float> myvectorftft;
		myvectorftft.push_back (100);
		myvectorftft.push_back (200);
		myvectorftft.push_back (300);
		ft_hd(2, 2);
		std::cout << "before:";
		for (unsigned i = 0; i < myvectorftft.size(); i++)
			std::cout << ' ' << myvectorftft[i];
		myvectorftft.clear();
		myvectorftft.push_back (1101);
		myvectorftft.push_back (2202);
		std::cout << " | after:";
		for (unsigned i = 0; i < myvectorftft.size(); i++)
			std::cout << ' ' << myvectorftft[i];
		std::cout << " |" << std::endl;
		ft::vector<double> myvectorftdft;
		myvectorftdft.push_back (100);
		myvectorftdft.push_back (200);
		myvectorftdft.push_back (300);
		ft_hd(2, 3);
		std::cout << "before:";
		for (unsigned i = 0; i < myvectorftdft.size(); i++)
			std::cout << ' ' << myvectorftdft[i];
		myvectorftdft.clear();
		myvectorftdft.push_back (1101);
		myvectorftdft.push_back (2202);
		std::cout << " | after:";
		for (unsigned i = 0; i < myvectorftdft.size(); i++)
			std::cout << ' ' << myvectorftdft[i];
		std::cout << " |" << std::endl;
		ft::vector<std::string> myvectorftsft;
		myvectorftsft.push_back ("100");
		myvectorftsft.push_back ("200");
		myvectorftsft.push_back ("300");
		ft_hd(2, 4);
		std::cout << "before:";
		for (unsigned i = 0; i < myvectorftsft.size(); i++)
			std::cout << ' ' << myvectorftsft[i];
		myvectorftsft.clear();
		myvectorftsft.push_back ("1101");
		myvectorftsft.push_back ("2202");
		std::cout << " | after:";
		for (unsigned i = 0; i < myvectorftsft.size(); i++)
			std::cout << ' ' << myvectorftsft[i];
		std::cout << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_comparisons(void)
{
	std::cout << "#------------->" << REDC << " COMPARISONS" << END  << std::endl;
	std::vector<int> foo (3, 100);
	std::vector<int> bar (2, 200);
	if (foo == bar)
		std::cout << "STD: foo and bar are equal\n";
	if (foo != bar)
		std::cout << "STD: foo and bar are not equal\n";
	if (foo < bar)
		std::cout << "STD: foo is less than bar\n";
	if (foo > bar)
		std::cout << "STD: foo is greater than bar\n";
	if (foo <= bar)
		std::cout << "STD: foo is less than or equal to bar\n";
	if (foo >= bar)
		std::cout << "STD: foo is greater than or equal to bar\n";
	try
	{
		ft::vector<int> foo1 (3, 100);
		ft::vector<int> bar1 (2, 200);
		std::cout << FIO;
		if (foo1 == bar1)
			std::cout << "FT:  foo and bar are equal\n";
		if (foo1 != bar1)
			std::cout << "FT:  foo and bar are not equal\n";
		if (foo1 < bar1)
			std::cout << "FT:  foo is less than bar\n";
		if (foo1 > bar1)
			std::cout << "FT:  foo is greater than bar\n";
		if (foo1 <= bar1)
			std::cout << "FT:  foo is less than or equal to bar\n";
		if (foo1 >= bar1)
			std::cout << "FT:  foo is greater than or equal to bar\n";
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void	testv_swap_vector_overload(void)
{
	std::cout << "#------------->" << REDC << " SWAP VECTORE OVERLOAD" << END  << std::endl;
	std::vector<int> foo (3, 100);
	std::vector<int> bar (5, 200);
	foo.swap(bar);
	std::cout << "STD: foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "STD: bar contains:";
	for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	try
	{
		ft::vector<int> foo1 (3, 100);
		ft::vector<int> bar1 (5, 200);
		foo1.swap(bar1);
		std::cout << FIO << "FT:  foo contains:";
		for (ft::vector<int>::iterator it1 = foo1.begin(); it1 != foo1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << std::endl;
		std::cout << "FT:  bar contains:";
		for (ft::vector<int>::iterator it1 = bar1.begin(); it1 != bar1.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "RESULT: ERROR" << END << std::endl;
	}
}

static void testv_for_vector()
{
	std::cout << "#------------->" << REDC << " OPERATOR" << END  << std::endl;
	{
		std::string str1 = "Ab";
		std::string str2 = "AB";
		std::string str3 = "ab";
		std::string str4 = "aB";
		std::vector<std::string > stack1(1, str1);
		std::vector<std::string > stack2(2, str2);
		std::vector<std::string > stack3(3, str3);
		std::vector<std::string > stack4(4, str4);
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
			ft::vector<std::string > stack1(1, str1);
			ft::vector<std::string > stack2(2, str2);
			ft::vector<std::string > stack3(3, str3);
			ft::vector<std::string > stack4(4, str4);
			std::cout << FIO << "FT:  ";
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
			std::cout << GREEN << "RESULT: OK" << END << std::endl;
		}
		catch (...)
		{
			std::cout << REDC << "ERROR" << END << std::endl;
		}
	}
}

void ft_test_vector(void)
{
	std::cout << "\t\t\t<=====|" << REDC << "__VECTOR__" << END << "|=====>" << std::endl << std::endl;
	testv_constructor();
	testv_operator();
	testv_begin_end();
	testv_rbegin_rend();
	testv_size();
	testv_max_size();
	testv_resize();
	testv_capacity();
	testv_empty();
	testv_reserve();
	testv_operator2();
	testv_at();
	testv_front();
	testv_back();
	testv_assign();
	testv_push_back();
	testv_pop_back();
	testv_insert();
	testv_erase();
	testv_swap();
	testv_clear();
	testv_comparisons();
	testv_swap_vector_overload();
	testv_for_vector();
}