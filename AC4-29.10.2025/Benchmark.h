#include <iostream>
#include <chrono>
template <typename D = std::chrono::microseconds>
class Banchmark {
public:
	Banchmark() {
		start = std::chrono::high_resolution_clock::now();
	}
	typename D::rep elepsed() {
		auto end = std::chrono::high_resolution_clock::now();
		auto result = std::chrono::duration_cast<D>(end - start);
		return result.count();
	}
	std::chrono::high_resolution_clock::time_point start;
};