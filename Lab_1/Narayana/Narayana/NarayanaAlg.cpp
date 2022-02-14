#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>

int main()
{
	std::vector<size_t> v = { 1,2,3,4,5,6,7,8,9,10 };
	boost::timer t;
	t.restart();
	std::sort(v.begin(), v.end());
	do
	{
		//copy(v.begin(), v.end(), std::ostream_iterator<size_t>(std::cout, " "));
		//std::cout << std::endl;
	} while (std::next_permutation(v.begin(), v.end()));
	double duration = t.elapsed();

	std::cout << duration << std::endl;
}
//Для 10 элементов время перестановок равно: 0,013
//Для 15 элементов время перестановок равно: 4685
//Для 20 элементов время перестановок равно: 8715753450
//Для 50 элементов время перестановок равно: 1,1*10^56
//Для 100 элементов время перестановок равно: 3,34*10^149
