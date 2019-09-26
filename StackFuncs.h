#pragma once
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>

using Graph = std::vector<std::vector<size_t>>;

template<class StackT>
void test(StackT& stack, int n, int m) {
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i)
			stack.push(i);
		for (int i = 0; i < n; ++i)
			stack.pop();
	}
}

template<class StackT>
void test2(StackT& stack, int n, int m, double p) {
	for (int j = 0; j < m; ++j) {
		if (rand() % 100 <= p * 100) {
			for (int i = 0; i < n; ++i)
				stack.push(i);
		}
		else {
			if (!stack.empty())
				for (int i = 0; i < n; ++i)
					stack.pop();
		}
	}
}

template<typename StackT>
bool check_parentheses(const std::string& str) {
	StackT stack;
	std::string open("<({[");
	std::string close(">)}]");
	for (size_t i = 0; i < str.size(); ++i) {
		if (open.find(str[i]) != std::string::npos)
			stack.push(str[i]);
		else if (open.find(stack.top()) == close.find(str[i]))
			stack.pop();
		else
			return false;
	}
	return true;
}

template<typename F, typename... Args>
double get_time(F func, Args&& ... args) {
	auto start = std::chrono::high_resolution_clock::now();
	func(std::forward<Args>(args)...);
	auto end = std::chrono::high_resolution_clock::now();
	return (end - start).count() * 1e-9;
}

template<typename StackT>
std::vector<size_t> find_path(Graph graph) {
	auto it = std::find_if(graph.begin(), graph.end(), [](const auto& list) {
		return list.size() % 2 == 1;
		});
	std::vector<size_t> path;
	StackT stack;
	stack.push(it == graph.end() ? 0 : it - graph.begin());
	while (!stack.empty()) {
		if (graph[stack.top()].empty()) {
			path.push_back(stack.top());
			stack.pop();
			continue;
		}
		auto u = graph[stack.top()].back();
		std::swap(*std::find(graph[u].begin(), graph[u].end(), stack.top()), graph[u].back());
		graph[u].pop_back();
		graph[stack.top()].pop_back();
		stack.push(u);
	}
	return path;
}

template<typename StackT>
std::string get_max_substring(const std::string& str, size_t k) {
	StackT stack;
	size_t max = 0;
	while (stack.size() != k) {
		stack.push(str[max++]);
		for (size_t i = max; i < str.size(); ++i) {
			if (i + k - stack.size() >= str.size())
				break;
			if (stack.top() < str[i]) {
				stack.pop();
				stack.push(str[i]);
				max = i + 1;
			}
		}
	}
	std::string res;
	while (!stack.empty()) {
		res.push_back(stack.top());
		stack.pop();
	}
	std::reverse(res.begin(), res.end());
	return res;
}

template<typename StackT>
size_t get_square(const std::vector<size_t>& plitki) {
	size_t res = 0;
	StackT s;
	size_t highest = plitki[0];
	for (auto plitka : plitki) {
		if (highest > plitka)
			s.push(plitka);
		else if (highest <= plitka) {
			while (!s.empty()) {
				res += highest - s.top();
				s.pop();
			}
			highest = plitka;
		}
	}
	highest = 0;
	while (!s.empty()) {
		if (highest < s.top())
			highest = s.top();
		else
			res += highest - s.top();
		s.pop();
	}
	return res;
}

template< template<typename> class StackT, typename T>
void sort_stack(StackT<T>& stack) {
	StackT<T> tmpStack;

	while (!stack.empty()) {
		T tmp = stack.top();
		stack.pop();
		while (!tmpStack.empty() && tmpStack.top() > tmp) {
			stack.push(tmpStack.top());
			tmpStack.pop();
		}
		tmpStack.push(tmp);
	}
	while (!tmpStack.empty()) {
		stack.push(tmpStack.top());
		tmpStack.pop();
	}
}

inline std::vector<size_t> get_odd_nodes(const Graph& graph) {
	std::vector<size_t> oddNodes;
	for (size_t i = 0; i < graph.size(); ++i) {
		if (std::count_if(graph[i].begin(), graph[i].end(), [](size_t a) {return a != 0; }) % 2 != 0)
			oddNodes.push_back(i);
	}
	return oddNodes;
}

inline Graph create_eulerian_graph(size_t nodes) {
	Graph graph(nodes);
	std::random_device rand;
	std::mt19937 mersenne(rand());
	for (size_t i = 0; i < graph.size(); ++i)
		graph[i] = std::vector<size_t>(nodes, 0);
	for (size_t i = 0; i < graph.size(); ++i) {
		for (size_t j = 0; j < graph.size(); ++j) {
			if (mersenne() % 100 > 70) {
				size_t node;
				do
					node = mersenne() % nodes;
				while (node == i);
				if (graph[i][node] != 0)
					continue;
				graph[i][node] = 1;
				graph[node][i] = 1;
			}
		}
	}
	auto oddNodes = get_odd_nodes(graph);
	while (!oddNodes.empty()) {
		size_t node1, node2;
		do {
			node1 = mersenne() % oddNodes.size();
			node2 = mersenne() % nodes;
		} while (oddNodes[node1] == node2);
		graph[oddNodes[node1]][node2] = graph[node2][oddNodes[node1]] = 1;
		oddNodes = get_odd_nodes(graph);
	}
	return graph;
}