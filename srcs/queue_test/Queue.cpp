/*
* Created: 2021/06/27
*/

#include "../../header/queue/Queue.hpp"

#include <list>
#include <queue>

static void ft_hdq(int i, int j)
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

static void	testq_constructor(void)
{
	std::cout << "#------------->" << REDC << " CONSTRUCTOR" << END  << std::endl;
	std::list<int> mylist (2, 200);
	std::queue<int> first;
	std::queue<int, std::list<int> > third;
	std::queue<int, std::list<int> > fourth (mylist);
	ft_hdq(1, 1);
	std::cout << "0.size = " << first.size() << " | 1.size = " << third.size();
	std::cout << "| 2.size = " << fourth.size() << std::endl;
	std::list<float> mylistf (2, 200);
	std::queue<float> firstf;
	std::queue<float, std::list<float> > thirdf;
	std::queue<float, std::list<float> > fourthf (mylistf);
	ft_hdq(1, 2);
	std::cout << "0.size = " << firstf.size() << " | 1.size = " << thirdf.size();
	std::cout << "| 2.size = " << fourthf.size() << std::endl;
	std::list<double> mylistd (2, 200);
	std::queue<double> firstd;
	std::queue<double, std::list<double> > thirdd;
	std::queue<double, std::list<double> > fourthd (mylistd);
	ft_hdq(1, 3);
	std::cout << "0.size = " << firstd.size() << " | 1.size = " << thirdd.size();
	std::cout << "| 2.size = " << fourthd.size() << std::endl;
	std::list<std::string> mylists (2, "200");
	std::queue<std::string> firsts;
	std::queue<std::string, std::list<std::string> > thirds;
	std::queue<std::string, std::list<std::string> > fourths (mylists);
	ft_hdq(1, 4);
	std::cout << "0.size = " << firsts.size() << " | 1.size = " << thirds.size();
	std::cout << "| 2.size = " << fourths.size() << std::endl;
	try
	{
		std::list<int> mylistft (2, 200);
		ft::queue<int> firstft;
		ft::queue<int, std::list<int> > thirdft;
		ft::queue<int, std::list<int> > fourthft (mylistft);
		ft_hdq(2, 1);
		std::cout << "0.size = " << firstft.size() << " | 1.size = " << thirdft.size();
		std::cout << "| 2.size = " << fourthft.size() << std::endl;
		std::list<float> mylistfft (2, 200);
		ft::queue<float> firstfft;
		ft::queue<float, std::list<float> > thirdfft;
		ft::queue<float, std::list<float> > fourthfft (mylistfft);
		ft_hdq(2, 2);
		std::cout << "0.size = " << firstfft.size() << " | 1.size = " << thirdfft.size();
		std::cout << "| 2.size = " << fourthfft.size() << std::endl;
		std::list<double> mylistdft (2, 200);
		ft::queue<double> firstdft;
		ft::queue<double, std::list<double> > thirddft;
		ft::queue<double, std::list<double> > fourthdft (mylistdft);
		ft_hdq(2, 3);
		std::cout << "0.size = " << firstdft.size() << " | 1.size = " << thirddft.size();
		std::cout << "| 2.size = " << fourthdft.size() << std::endl;
		std::list<std::string> mylistsft (2, "200");
		ft::queue<std::string> firstsft;
		ft::queue<std::string, std::list<std::string> > thirdsft;
		ft::queue<std::string, std::list<std::string> > fourthsft (mylistsft);
		ft_hdq(2, 4);
		std::cout << "0.size = " << firstsft.size() << " | 1.size = " << thirdsft.size();
		std::cout << "| 2.size = " << fourthsft.size() << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testq_empty(void)
{
	std::cout << "#------------->" << REDC << " EMPTY" << END  << std::endl;
	std::queue<int> myqueue;
	int sum (0);
	for (int i = 1; i <= 10; i++)
		myqueue.push(i);
	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}
	ft_hdq(1, 1);
	std::cout << "total: " << sum << std::endl;
	std::queue<float> myqueuef;
	int sumf (0);
	for (int i = 1; i <= 10; i++)
		myqueuef.push(i);
	while (!myqueuef.empty())
	{
		sumf += myqueuef.front();
		myqueuef.pop();
	}
	ft_hdq(1, 2);
	std::cout << "total: " << sumf << std::endl;
	std::queue<double> myqueued;
	int sumd (0);
	for (int i = 1; i <= 10; i++)
		myqueued.push(i);
	while (!myqueued.empty())
	{
		sumd += myqueued.front();
		myqueued.pop();
	}
	ft_hdq(1, 3);
	std::cout << "total: " << sumd << std::endl;
	std::queue<std::string> myqueues;
	std::string sums;
	for (int i = 1; i <= 10; i++)
		myqueues.push(std::to_string(i));
	while (!myqueues.empty())
	{
		sums += myqueues.front();
		sums += " ";
		myqueues.pop();
	}
	ft_hdq(1, 4);
	std::cout << "total: " << sums << std::endl;
	try
	{
		ft::queue<int> myqueueft;
		int sumft (0);
		for (int i = 1; i <= 10; i++)
			myqueueft.push(i);
		while (!myqueueft.empty())
		{
			sumft += myqueueft.front();
			myqueueft.pop();
		}
		ft_hdq(2, 1);
		std::cout << "total: " << sumft << std::endl;
		ft::queue<float> myqueuefft;
		int sumfft (0);
		for (int i = 1; i <= 10; i++)
			myqueuefft.push(i);
		while (!myqueuefft.empty())
		{
			sumfft += myqueuefft.front();
			myqueuefft.pop();
		}
		ft_hdq(2, 2);
		std::cout << "total: " << sumfft << std::endl;
		ft::queue<double> myqueuedft;
		int sumdft (0);
		for (int i = 1; i <= 10; i++)
			myqueuedft.push(i);
		while (!myqueuedft.empty())
		{
			sumdft += myqueuedft.front();
			myqueuedft.pop();
		}
		ft_hdq(2, 3);
		std::cout << "total: " << sumdft << std::endl;
		ft::queue<std::string> myqueues1;
		std::string sums1;
		for (int i = 1; i <= 10; i++)
			myqueues1.push(std::to_string(i));
		while (!myqueues1.empty())
		{
			sums1 += myqueues1.front();
			sums1 += " ";
			myqueues1.pop();
		}
		ft_hdq(2, 4);
		std::cout << "total: " << sums1 << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testq_size(void)
{
	std::cout << "#------------->" << REDC << " SIZE" << END  << std::endl;
	std::queue<int> myints;
	ft_hdq(1, 1);
	std::cout << "0.size = " << myints.size(); 
	for (int i = 0; i < 5; i++)
		myints.push(i);
	std::cout << " | 1.size = " << myints.size();
	myints.pop();
	std::cout << " | 2.size = " << myints.size() << " |" << std::endl;
	std::queue<float> myintsf;
	ft_hdq(1, 2);
	std::cout << "0.size = " << myintsf.size(); 
	for (int i = 0; i < 5; i++)
		myintsf.push(i);
	std::cout << " | 1.size = " << myintsf.size();
	myintsf.pop();
	std::cout << " | 2.size = " << myintsf.size() << " |" << std::endl;
	std::queue<double> myintsd;
	ft_hdq(1, 3);
	std::cout << "0.size = " << myintsd.size(); 
	for (int i = 0; i < 5; i++)
		myintsd.push(i);
	std::cout << " | 1.size = " << myintsd.size();
	myintsd.pop();
	std::cout << " | 2.size = " << myintsd.size() << " |" << std::endl;
	std::queue<std::string> myintss;
	ft_hdq(1, 4);
	std::cout << "0.size = " << myintss.size(); 
	for (int i = 0; i < 5; i++)
		myintss.push(std::to_string(i));
	std::cout << " | 1.size = " << myintss.size();
	myintss.pop();
	std::cout << " | 2.size = " << myintss.size() << " |" << std::endl;
	try
	{
		ft::queue<int> myintsft;
		ft_hdq(2, 1);
		std::cout << "0.size = " << myintsft.size(); 
		for (int i = 0; i < 5; i++)
			myintsft.push(i);
		std::cout << " | 1.size = " << myintsft.size();
		myintsft.pop();
		std::cout << " | 2.size = " << myintsft.size() << " |" << std::endl;
		ft::queue<float> myintsfft;
		ft_hdq(2, 2);
		std::cout << "0.size = " << myintsfft.size(); 
		for (int i = 0; i < 5; i++)
			myintsfft.push(i);
		std::cout << " | 1.size = " << myintsfft.size();
		myintsfft.pop();
		std::cout << " | 2.size = " << myintsfft.size() << " |" << std::endl;
		ft::queue<double> myintsdft;
		ft_hdq(2, 3);
		std::cout << "0.size = " << myintsdft.size(); 
		for (int i = 0; i < 5; i++)
			myintsdft.push(i);
		std::cout << " | 1.size = " << myintsdft.size();
		myintsdft.pop();
		std::cout << " | 2.size = " << myintsdft.size() << " |" << std::endl;
		ft::queue<std::string> myintssft;
		ft_hdq(2, 4);
		std::cout << "0.size = " << myintssft.size(); 
		for (int i = 0; i < 5; i++)
			myintssft.push(std::to_string(i));
		std::cout << " | 1.size = " << myintssft.size();
		myintssft.pop();
		std::cout << " | 2.size = " << myintssft.size() << " |" << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testq_front(void)
{
	std::cout << "#------------->" << REDC << " FRONT" << END << std::endl;
	std::queue<int> myqueue;
	myqueue.push(77);
	myqueue.push(16);
	myqueue.front() -= myqueue.back();
	ft_hdq(1, 1);
	std::cout << "myqueue.front() is now " << myqueue.front() << std::endl;
	std::queue<float> myqueuef;
	myqueuef.push(77);
	myqueuef.push(16);
	myqueuef.front() -= myqueuef.back();
	ft_hdq(1, 2);
	std::cout << "myqueue.front() is now " << myqueuef.front() << std::endl;
	std::queue<double> myqueued;
	myqueued.push(77);
	myqueued.push(16);
	myqueued.front() -= myqueued.back();
	ft_hdq(1, 3);
	std::cout << "myqueue.front() is now " << myqueued.front() << std::endl;
	std::queue<std::string> myqueues;
	myqueues.push("61");
	myqueues.push("16");
	ft_hdq(1, 4);
	std::cout << "myqueue.front() is now " << myqueues.front() << std::endl;
	try
	{
		ft::queue<int> myqueueft;
		myqueueft.push(77);
		myqueueft.push(16);
		myqueueft.front() -= myqueueft.back();
		ft_hdq(2, 1);
		std::cout << "myqueue.front() is now " << myqueueft.front() << std::endl;
		ft::queue<float> myqueuefft;
		myqueuefft.push(77);
		myqueuefft.push(16);
		myqueuefft.front() -= myqueuefft.back();
		ft_hdq(2, 2);
		std::cout << "myqueue.front() is now " << myqueuefft.front() << std::endl;
		ft::queue<double> myqueuedft;
		myqueuedft.push(77);
		myqueuedft.push(16);
		myqueuedft.front() -= myqueuedft.back();
		ft_hdq(2, 3);
		std::cout << "myqueue.front() is now " << myqueuedft.front() << std::endl;
		ft::queue<std::string> myqueuesft;
		myqueuesft.push("61");
		myqueuesft.push("16");
		ft_hdq(2, 4);
		std::cout << "myqueue.front() is now " << myqueuesft.front() << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testq_back(void)
{
	std::cout << "#------------->" << REDC << " BACK" << END  << std::endl;
	std::queue<int> myqueue;
	myqueue.push(12);
	myqueue.push(75);
	myqueue.back() -= myqueue.front();
	ft_hdq(1, 1);
	std::cout << "myqueue.back() is now " << myqueue.back() << std::endl;
	std::queue<float> myqueuef;
	myqueuef.push(12);
	myqueuef.push(75);
	myqueuef.back() -= myqueuef.front();
	ft_hdq(1, 2);
	std::cout << "myqueue.back() is now " << myqueuef.back() << std::endl;
	std::queue<double> myqueued;
	myqueued.push(12);
	myqueued.push(75);
	myqueued.back() -= myqueued.front();
	ft_hdq(1, 3);
	std::cout << "myqueue.back() is now " << myqueued.back() << std::endl;
	std::queue<std::string> myqueues;
	myqueues.push("75");
	myqueues.push("63");
	ft_hdq(1, 4);
	std::cout << "myqueue.back() is now " << myqueues.back() << std::endl;
	try
	{
		ft::queue<int> myqueueft;
		myqueueft.push(12);
		myqueueft.push(75);
		myqueueft.back() -= myqueueft.front();
		ft_hdq(2, 1);
		std::cout << "myqueue.back() is now " << myqueueft.back() << std::endl;
		ft::queue<float> myqueuefft;
		myqueuefft.push(12);
		myqueuefft.push(75);
		myqueuefft.back() -= myqueuefft.front();
		ft_hdq(2, 2);
		std::cout << "myqueue.back() is now " << myqueuefft.back() << std::endl;
		ft::queue<double> myqueuedft;
		myqueuedft.push(12);
		myqueuedft.push(75);
		myqueuedft.back() -= myqueuedft.front();
		ft_hdq(2, 3);
		std::cout << "myqueue.back() is now " << myqueuedft.back() << std::endl;
		ft::queue<std::string> myqueuesft;
		myqueuesft.push("75");
		myqueuesft.push("63");
		ft_hdq(2, 4);
		std::cout << "myqueue.back() is now " << myqueuesft.back() << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	testq_push_pop(void)
{
	std::cout << "#------------->" << REDC << " PUSH and POP" << END  << std::endl;
	std::queue<int> myqueue;
	for (int i = 10; i < 17; i++)
		myqueue.push (i);
	ft_hdq(1, 1);
	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << std::endl;
	std::queue<float> myqueuef;
	for (int i = 10; i < 17; i++)
		myqueuef.push (i);
	ft_hdq(1, 2);
	std::cout << "myqueue contains: ";
	while (!myqueuef.empty())
	{
		std::cout << ' ' << myqueuef.front();
		myqueuef.pop();
	}
	std::cout << std::endl;
	std::queue<double> myqueued;
	for (int i = 10; i < 17; i++)
		myqueued.push (i);
	ft_hdq(1, 3);
	std::cout << "myqueue contains: ";
	while (!myqueued.empty())
	{
		std::cout << ' ' << myqueued.front();
		myqueued.pop();
	}
	std::cout << std::endl;
	std::queue<std::string> myqueues;
	for (int i = 10; i < 17; i++)
		myqueues.push (std::to_string(i));
	ft_hdq(1, 4);
	std::cout << "myqueue contains: ";
	while (!myqueues.empty())
	{
		std::cout << ' ' << myqueues.front();
		myqueues.pop();
	}
	std::cout << std::endl;
	try
	{
		ft::queue<int> myqueueft;
		for (int i = 10; i < 17; i++)
			myqueueft.push (i);
		ft_hdq(2, 1);
		std::cout << "myqueue contains: ";
		while (!myqueueft.empty())
		{
			std::cout << ' ' << myqueueft.front();
			myqueueft.pop();
		}
		std::cout << std::endl;
		ft::queue<float> myqueuefft;
		for (int i = 10; i < 17; i++)
			myqueuefft.push (i);
		ft_hdq(2, 2);
		std::cout << "myqueue contains: ";
		while (!myqueuefft.empty())
		{
			std::cout << ' ' << myqueuefft.front();
			myqueuefft.pop();
		}
		std::cout << std::endl;
		ft::queue<double> myqueuedft;
		for (int i = 10; i < 17; i++)
			myqueuedft.push (i);
		ft_hdq(2, 3);
		std::cout << "myqueue contains: ";
		while (!myqueuedft.empty())
		{
			std::cout << ' ' << myqueuedft.front();
			myqueuedft.pop();
		}
		std::cout << std::endl;
		ft::queue<std::string> myqueuesft;
		for (int i = 10; i < 17; i++)
			myqueuesft.push (std::to_string(i));
		ft_hdq(2, 4);
		std::cout << "myqueue contains: ";
		while (!myqueuesft.empty())
		{
			std::cout << ' ' << myqueuesft.front();
			myqueuesft.pop();
		}
		std::cout << std::endl;
		std::cout << GREEN << "RESULT: OK" << END << std::endl;
	}
	catch (...)
	{
		std::cout << REDC << "ERROR" << END << std::endl;
	}
}

static void	tests_for_queue(void)
{
	std::cout << "#------------->" << REDC << " CONSTRUCTOR" << END  << std::endl;
	{
		std::deque<int> mydeque (3,100);
		std::vector<int> myvector (2,200);
		std::queue<int> first;
		std::queue<int> second (mydeque);
		std::queue<int,std::vector<int> > third;
		std::queue<int,std::vector<int> > fourth (myvector);
		ft_hdq(1, 1);
		std::cout << "size of first:  " << first.size() << std::endl;
		ft_hdq(1, 1);
  		std::cout << "size of second: " << second.size() << std::endl;
		ft_hdq(1, 1);
  		std::cout << "size of third:  " << third.size() << std::endl;
		ft_hdq(1, 1);
  		std::cout << "size of fourth: " << fourth.size() << std::endl;
	}
	{
		try
		{
			std::deque<int> mydeque (3,100);
			std::vector<int> myvector (2,200);
			ft::queue<int> first;
			ft::queue<int> second (mydeque);
			ft::queue<int,std::vector<int> > third;
			ft::queue<int,std::vector<int> > fourth (myvector);
			ft_hdq(2, 1);
			std::cout << "size of first:  " << first.size() << std::endl;
			ft_hdq(2, 1);
			std::cout << "size of second: " << second.size() << std::endl;
			ft_hdq(2, 1);
			std::cout << "size of third:  " << third.size() << std::endl;
			ft_hdq(2, 1);
			std::cout << "size of fourth: " << fourth.size() << std::endl;
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
		std::queue<char, std::string > stack1(str1);
		std::queue<char, std::string > stack2(str2);
		std::queue<char, std::string > stack3(str3);
		std::queue<char, std::string > stack4(str4);
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
			ft::queue<char, std::string > stack1(str1);
			ft::queue<char, std::string > stack2(str2);
			ft::queue<char, std::string > stack3(str3);
			ft::queue<char, std::string > stack4(str4);
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

void ft_test_queue(void)
{
	std::cout << "\t\t\t<=====|" << REDC << "__QUEUE__" << END << "|=====>" << std::endl << std::endl;
	testq_constructor();
	testq_empty();
	testq_size();
	testq_front();
	testq_back();
	testq_push_pop();
	tests_for_queue();
}