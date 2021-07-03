/*
* Created: 2021/06/27
*/

#include "header/list/List.hpp"
#include "srcs/list_test/List.cpp"

#include "header/vector/Vector.hpp"
#include "srcs/vector_test/Vector.cpp"

#include "header/queue/Queue.hpp"
#include "srcs/queue_test/Queue.cpp"

#include "header/stack/Stack.hpp"
#include "srcs/stack_test/Stack.cpp"

#include "header/map/Map.hpp"
#include "srcs/map_test/Map.cpp"

int main(void)
{
	std::cout << "\t\t<=====|=======|" << REDC << "CONTAINERS" << END << "|=======|=====>" << std::endl;
	std::cout << "\t\t\t <=====|========|=====>" << std::endl << std::endl;
	ft_test_list();
	ft_test_vector();
	ft_test_queue();
	ft_test_stack();
	ft_test_map();
	std::cout << "\t\t\t\t<======>\n" << std::endl;
	return (0);
}