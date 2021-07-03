/*
* Created: 2021/06/27
*/

#include "../../header/stack/Stack.hpp"

#include <stack>
#include <vector>

static void ft_hds(int i, int j)
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

static void	tests_constructor(void)
{
	std::cout << "#------------->" << REDC << " CONSTRUCTOR" << END  << std::endl;
	std::vector<int> myvector (2, 200);
	std::stack<int> first;
	std::stack<int,std::vector<int> > third;
	std::stack<int,std::vector<int> > fourth (myvector);
	ft_hds(1, 1);
	std::cout << "1.size = " << first.size() << " | 2.size = " << third.size();
	std::cout << " | 3.size = " << fourth.size() << " |" << std::endl;
	std::vector<float> myvectorf (2, 200);
	std::stack<float> firstf;
	std::stack<float,std::vector<float> > thirdf;
	std::stack<float,std::vector<float> > fourthf (myvectorf);
	ft_hds(1, 2);
	std::cout << "1.size = " << firstf.size() << " | 2.size = " << thirdf.size();
	std::cout << " | 3.size = " << fourthf.size() << " |" << std::endl;
	std::vector<double> myvectord (2, 200);
	std::stack<double> firstd;
	std::stack<double,std::vector<double> > thirdd;
	std::stack<double,std::vector<double> > fourthd (myvectord);
	ft_hds(1, 3);
	std::cout << "1.size = " << firstd.size() << " | 2.size = " << thirdd.size();
	std::cout << " | 3.size = " << fourthd.size() << " |" << std::endl;
	std::vector<std::string> myvectors (2, "200");
	std::stack<std::string> firsts;
	std::stack<std::string,std::vector<std::string> > thirds;
	std::stack<std::string,std::vector<std::string> > fourths (myvectors);
	ft_hds(1, 4);
	std::cout << "1.size = " << firsts.size() << " | 2.size = " << thirds.size();
	std::cout << " | 3.size = " << fourths.size() << " |" << std::endl;
	try
	{
		std::vector<int> myvectorft (2, 200);
		ft::stack<int> firstft;
		ft::stack<int, std::vector<int> > thirdft;
		ft::stack<int, std::vector<int> > fourthft (myvectorft);
		ft_hds(2, 1);
		std::cout << "1.size = " << firstft.size() << " | 2.size = " << thirdft.size();
		std::cout << " | 3.size = " << fourthf.size() << " |" << std::endl;
		std::vector<float> myvectorfft (2, 200);
		ft::stack<float> firstfft;
		ft::stack<float, std::vector<float> > thirdfft;
		ft::stack<float, std::vector<float> > fourthfft (myvectorfft);
		ft_hds(2, 2);
		std::cout << "1.size = " << firstfft.size() << " | 2.size = " << thirdfft.size();
		std::cout << " | 3.size = " << fourthfft.size() << " |" << std::endl;
		std::vector<double> myvectordft (2, 200);
		ft::stack<double> firstdft;
		ft::stack<double,std::vector<double> > thirddft;
		ft::stack<double,std::vector<double> > fourthdft (myvectordft);
		ft_hds(2, 3);
		std::cout << "1.size = " << firstdft.size() << " | 2.size = " << thirddft.size();
		std::cout << " | 3.size = " << fourthdft.size() << " |" << std::endl;
		std::vector<std::string> myvectorsft (2, "200");
		ft::stack<std::string> firstsft;
		ft::stack<std::string,std::vector<std::string> > thirdsft;
		ft::stack<std::string,std::vector<std::string> > fourthsft (myvectorsft);
		ft_hds(2, 4);
		std::cout << "1.size = " << firstsft.size() << " | 2.size = " << thirdsft.size();
		std::cout << " | 3.size = " << fourthsft.size() << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	tests_empty(void)
{
	std::cout << "#------------->" << REDC << " EMPTY" << END  << std::endl;
	std::stack<int> mystack;
	int sum (0);
	for (int i = 1; i <= 10; i++)
		mystack.push(i);
	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	ft_hds(1, 1);
	std::cout << "total: " << sum << std::endl;
	std::stack<float> mystackf;
	int sumf (0);
	for (int i = 1; i <= 10; i++)
		mystackf.push(i);
	while (!mystackf.empty())
	{
		sumf += mystackf.top();
		mystackf.pop();
	}
	ft_hds(1, 2);
	std::cout << "total: " << sumf << std::endl;
	std::stack<double> mystackd;
	int sumd (0);
	for (int i = 1; i <= 10; i++)
		mystackd.push(i);
	while (!mystackd.empty())
	{
		sumd += mystackd.top();
		mystackd.pop();
	}
	ft_hds(1, 3);
	std::cout << "total: " << sumd << std::endl;
	std::stack<std::string> mystacks;
	std::string sums;
	for (int i = 1; i <= 10; i++)
		mystacks.push(std::to_string(i));
	while (!mystacks.empty())
	{
		sums += mystacks.top();
		sums += " ";
		mystacks.pop();
	}
	ft_hds(1, 4);
	std::cout << "total: " << sums << std::endl;
	try
	{
		ft::stack<int> mystackft;
		int sumft (0);
		for (int i = 1; i <= 10; i++)
			mystackft.push(i);
		while (!mystackft.empty())
		{
			sumft += mystackft.top();
			mystackft.pop();
		}
		ft_hds(2, 1);
		std::cout << "total: " << sumft << std::endl;
		std::stack<float> mystackfft;
		int sumfft (0);
		for (int i = 1; i <= 10; i++)
			mystackfft.push(i);
		while (!mystackfft.empty())
		{
			sumfft += mystackfft.top();
			mystackfft.pop();
		}
		ft_hds(2, 2);
		std::cout << "total: " << sumfft << std::endl;
		ft::stack<double> mystackdft;
		int sumdft (0);
		for (int i = 1; i <= 10; i++)
			mystackdft.push(i);
		while (!mystackdft.empty())
		{
			sumdft += mystackdft.top();
			mystackdft.pop();
		}
		ft_hds(2, 3);
		std::cout << "total: " << sumdft << std::endl;
		std::stack<std::string> mystacksft;
		std::string sumsft;
		for (int i = 1; i <= 10; i++)
			mystacksft.push(std::to_string(i));
		while (!mystacksft.empty())
		{
			sumsft += mystacksft.top();
			sumsft += " ";
			mystacksft.pop();
		}
		ft_hds(2, 4);
		std::cout << "total: " << sumsft << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	tests_size(void)
{
	std::cout << "#------------->" << REDC << " SIZE" << END  << std::endl;
	std::stack<int> myints;
	ft_hds(1, 1);
	std::cout << "0.size = " << myints.size();
	for (int i = 0; i < 5; i++)
		myints.push(i);
	std::cout << " | 1.size = " << myints.size();
	myints.pop();
	std::cout << " | 2.size = " << myints.size() << std::endl;
	std::stack<float> myintsf;
	ft_hds(1, 2);
	std::cout << "0.size = " << myintsf.size();
	for (int i = 0; i < 5; i++)
		myintsf.push(i);
	std::cout << " | 1.size = " << myintsf.size();
	myintsf.pop();
	std::cout << " | 2.size = " << myintsf.size() << std::endl;
	std::stack<double> myintsd;
	ft_hds(1, 3);
	std::cout << "0.size = " << myintsd.size();
	for (int i = 0; i < 5; i++)
		myintsd.push(i);
	std::cout << " | 1.size = " << myintsd.size();
	myintsd.pop();
	std::cout << " | 2.size = " << myintsd.size() << std::endl;
	std::stack<std::string> myintss;
	ft_hds(1, 4);
	std::cout << "0.size = " << myintss.size();
	for (int i = 0; i < 5; i++)
		myintss.push(std::to_string(i));
	std::cout << " | 1.size = " << myintss.size();
	myintss.pop();
	std::cout << " | 2.size = " << myintss.size() << std::endl;
	try
	{
		ft::stack<int> myintsft;
		ft_hds(2, 1);
		std::cout << "0.size = " << myintsft.size();
		for (int i = 0; i < 5; i++)
			myintsft.push(i);
		std::cout << " | 1.size = " << myintsft.size();
		myintsft.pop();
		std::cout << " | 2.size = " << myintsft.size() << std::endl;
		ft::stack<float> myintsfft;
		ft_hds(2, 2);
		std::cout << "0.size = " << myintsfft.size();
		for (int i = 0; i < 5; i++)
			myintsfft.push(i);
		std::cout << " | 1.size = " << myintsfft.size();
		myintsfft.pop();
		std::cout << " | 2.size = " << myintsfft.size() << std::endl;
		ft::stack<double> myintsdft;
		ft_hds(2, 3);
		std::cout << "0.size = " << myintsdft.size();
		for (int i = 0; i < 5; i++)
			myintsdft.push(i);
		std::cout << " | 1.size = " << myintsdft.size();
		myintsdft.pop();
		std::cout << " | 2.size = " << myintsdft.size() << std::endl;
		ft::stack<std::string> myintssft;
		ft_hds(2, 4);
		std::cout << "0.size = " << myintssft.size();
		for (int i = 0; i < 5; i++)
			myintssft.push(std::to_string(i));
		std::cout << " | 1.size = " << myintssft.size();
		myintssft.pop();
		std::cout << " | 2.size = " << myintssft.size() << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	tests_top(void)
{
	std::cout << "#------------->" << REDC << " TOP" << END  << std::endl;
	std::stack<int> mystack;
	mystack.push(10);
	mystack.push(20);
	mystack.top() -= 5;
	ft_hds(1, 1);
	std::cout << "mystack.top() is now " << mystack.top() << std::endl;
	std::stack<float> mystackf;
	mystackf.push(10);
	mystackf.push(20);
	mystackf.top() -= 5;
	ft_hds(1, 2);
	std::cout << "mystack.top() is now " << mystackf.top() << std::endl;
	std::stack<double> mystackd;
	mystackd.push(10);
	mystackd.push(20);
	mystackd.top() -= 5;
	ft_hds(1, 3);
	std::cout << "mystack.top() is now " << mystackd.top() << std::endl;
	std::stack<std::string> mystacks;
	mystacks.push("10");
	mystacks.push("15");
	ft_hds(1, 4);
	std::cout << "mystack.top() is now " << mystacks.top() << std::endl;
	try
	{
		ft::stack<int> mystackft;
		mystackft.push(10);
		mystackft.push(20);
		mystackft.top() -= 5;
		ft_hds(2, 1);
		std::cout << "mystack.top() is now " << mystackft.top() << std::endl;
		ft::stack<float> mystackfft;
		mystackfft.push(10);
		mystackfft.push(20);
		mystackfft.top() -= 5;
		ft_hds(2, 2);
		std::cout << "mystack.top() is now " << mystackf.top() << std::endl;
		ft::stack<double> mystackdft;
		mystackdft.push(10);
		mystackdft.push(20);
		mystackdft.top() -= 5;
		ft_hds(2, 3);
		std::cout << "mystack.top() is now " << mystackdft.top() << std::endl;
		ft::stack<std::string> mystacksft;
		mystacksft.push("10");
		mystacksft.push("15");
		ft_hds(2, 4);
		std::cout << "mystack.top() is now " << mystacksft.top() << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	tests_push_pop(void)
{
	std::cout << "#------------->" << REDC << " PUSH and POP" << END  << std::endl;
	std::stack<int> mystack;
	for (int i = 0; i < 5; ++i)
		mystack.push(i);
	ft_hds(1, 1);
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << std::endl;
	std::stack<float> mystackf;
	for (int i = 0; i < 5; ++i)
		mystackf.push(i);
	ft_hds(1, 2);
	std::cout << "Popping out elements...";
	while (!mystackf.empty())
	{
		std::cout << ' ' << mystackf.top();
		mystackf.pop();
	}
	std::cout << std::endl;
	std::stack<double> mystackd;
	for (int i = 0; i < 5; ++i)
		mystackd.push(i);
	ft_hds(1, 3);
	std::cout << "Popping out elements...";
	while (!mystackd.empty())
	{
		std::cout << ' ' << mystackd.top();
		mystackd.pop();
	}
	std::cout << std::endl;
	std::stack<std::string> mystacks;
	for (int i = 0; i < 5; ++i)
		mystacks.push(std::to_string(i));
	ft_hds(1, 4);
	std::cout << "Popping out elements...";
	while (!mystacks.empty())
	{
		std::cout << ' ' << mystacks.top();
		mystacks.pop();
	}
	std::cout << std::endl;
	try
	{
		ft::stack<int> mystackft;
		for (int i = 0; i < 5; ++i)
			mystackft.push(i);
		ft_hds(2, 1);
		std::cout << "Popping out elements...";
		while (!mystackft.empty())
		{
			std::cout << ' ' << mystackft.top();
			mystackft.pop();
		}
		std::cout << std::endl;
		ft::stack<float> mystackfft;
		for (int i = 0; i < 5; ++i)
			mystackfft.push(i);
		ft_hds(2, 2);
		std::cout << "Popping out elements...";
		while (!mystackfft.empty())
		{
			std::cout << ' ' << mystackfft.top();
			mystackfft.pop();
		}
		std::cout << std::endl;
		ft::stack<double> mystackdft;
		for (int i = 0; i < 5; ++i)
			mystackdft.push(i);
		ft_hds(2, 3);
		std::cout << "Popping out elements...";
		while (!mystackdft.empty())
		{
			std::cout << ' ' << mystackdft.top();
			mystackdft.pop();
		}
		std::cout << std::endl;
		ft::stack<std::string> mystacksft;
		for (int i = 0; i < 5; ++i)
			mystacksft.push(std::to_string(i));
		ft_hds(2, 4);
		std::cout << "Popping out elements...";
		while (!mystacksft.empty())
		{
			std::cout << ' ' << mystacksft.top();
			mystacksft.pop();
		}
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	tests_for_stack(void)
{
	std::cout << "#------------->" << REDC << " CONSTRUCTOR" << END  << std::endl;
	{
		std::deque<int> mydeque (3,100);
		std::vector<int> myvector (2,200);
		std::stack<int> first;
		std::stack<int> second (mydeque);
		std::stack<int,std::vector<int> > third;
		std::stack<int,std::vector<int> > fourth (myvector);
		ft_hds(1, 1);
		std::cout << "size of first:  " << first.size() << std::endl;
		ft_hds(1, 1);
  		std::cout << "size of second: " << second.size() << std::endl;
		ft_hds(1, 1);
  		std::cout << "size of third:  " << third.size() << std::endl;
		ft_hds(1, 1);
  		std::cout << "size of fourth: " << fourth.size() << std::endl;
	}
	{
		try
		{
			std::deque<int> mydeque (3,100);
			std::vector<int> myvector (2,200);
			ft::stack<int> first;
			ft::stack<int> second (mydeque);
			ft::stack<int,std::vector<int> > third;
			ft::stack<int,std::vector<int> > fourth (myvector);
			ft_hds(2, 1);
			std::cout << "size of first:  " << first.size() << std::endl;
			ft_hds(2, 1);
			std::cout << "size of second: " << second.size() << std::endl;
			ft_hds(2, 1);
			std::cout << "size of third:  " << third.size() << std::endl;
			ft_hds(2, 1);
			std::cout << "size of fourth: " << fourth.size() << std::endl;
			std::cout << GREEN << "RESULT: OK" << END << std::endl;
		}
		catch (...)
		{
			std::cout << REDC << "ERROR" << END << std::endl;
		}
	}
	std::cout << "#------------->" << REDC << " EMPTY, PUSH, TOP, POP, SIZE" << END  << std::endl;
	{
		std::stack<int> mystack;
  		int sum (0);
		for (int i = 1;i <= 10;i++)
			mystack.push(i);
		ft_hds(1, 1);
		std::cout << "size : " << mystack.size() << std::endl;
		while (!mystack.empty())
  		{
     		sum += mystack.top();
     		mystack.pop();
  		}
		ft_hds(1, 1);
		std::cout << "total: " << sum << std::endl;
	}
	{
		try
		{
			ft::stack<int> mystack;
			int sum (0);
			for (int i = 1;i <= 10;i++)
				mystack.push(i);
			ft_hds(2, 1);
			std::cout << "size : " << mystack.size() << std::endl;
			while (!mystack.empty())
			{
				sum += mystack.top();
				mystack.pop();
			}
			ft_hds(2, 1);
			std::cout << "total: " << sum << std::endl;
			std::cout << GREEN << "RESULT: OK" << END << std::endl;
		}
		catch (...)
		{
			std::cout << REDC << "ERROR" << END << std::endl;
		}
	}
	std::cout << "#------------->" << REDC << " OPERATOR" << END  << std::endl;
	{
		std::string str1 = "Ab";
		std::string str2 = "AB";
		std::string str3 = "ab";
		std::string str4 = "aB";
		std::stack<char, std::string > stack1(str1);
		std::stack<char, std::string > stack2(str2);
		std::stack<char, std::string > stack3(str3);
		std::stack<char, std::string > stack4(str4);
		std::cout << "STD: ";
		if (stack1 > stack2)
			std::cout << "| " << str1 << ">" << str2;
		else
			std::cout << "| " << str1 <<  "<=" << str2;
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
			ft::stack<char, std::string > stack1(str1);
			ft::stack<char, std::string > stack2(str2);
			ft::stack<char, std::string > stack3(str3);
			ft::stack<char, std::string > stack4(str4);
			std::cout << FIO << "FT:  ";
			if (stack1 > stack2)
				std::cout << "| " << str1 << ">" << str2;
			else
				std::cout << "| " << str1 <<  "<=" << str2;
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

void	ft_test_stack(void)
{
	std::cout << "\t\t\t<=====|" << REDC << "__STACK__" << END << "|=====>" << std::endl << std::endl;
	tests_constructor();
	tests_empty();
	tests_size();
	tests_top();
	tests_push_pop();
	tests_for_stack();
}