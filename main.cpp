#include <iostream>
#include "StackFuncs.h"
#include "Stackl.h"
#include "Stackm.h"
#include "Stackmm.h"
#include <stack>



int main(int argc, char* argv[]) {
	/*std::vector<int> vec;
	const int n = atoi(argv[1]);
	const int m = atoi(argv[2]);
	const double p = atof(argv[3]);
	Stackm<int> stackm(n*m);
	std::cout << "Stackm: " << get_time(test<Stackm<int>>,stackm,n,m)<< std::endl;
	Stackl<int> stackl;
	std::cout << "Stackl: " << get_time(test<Stackl<int>>, stackl, n, m) << std::endl;
	Stackmm<int> stackmm;
	std::cout << "Stackmm: " << get_time(test<Stackmm<int>>, stackmm, n, m) << std::endl;
	std::stack<int> stack;
	std::cout << "std::stack: " << get_time(test<std::stack<int>>, stack, n, m) << std::endl;*/
	
	/*std::vector<size_t> vec({3,3,2,1,2,2,3,2,1,4,4,3,1,3,2,1,2,3,1});
	std::cout << get_square<std::stack<size_t>>(vec);*/

	/*
	 std::cout << get_max_substring<Stackmm<char>>("aaadczabcaad", 4) << std::endl;
	 */
	
	/*Stackmm<int> stack;
	stack.push(5);
	stack.push(10);
	stack.push(2);
	sort_stack(stack);
	while(!stack.empty()) {
		std::cout << stack.top() << std::endl;
		stack.pop();
	}*/
	
	/*auto graph = create_eulerian_graph(10);
	for(size_t i = 0; i < graph.size(); ++i) {
		for(size_t j = 0; j < graph.size(); ++j)
			std::cout << graph[i][j] << ' ';
		std::cout << std::endl;
	}*/
	return 0;
}