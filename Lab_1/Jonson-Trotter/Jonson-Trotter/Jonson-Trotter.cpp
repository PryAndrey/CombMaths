#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v1(n+2);
	vector<int> pos(n+1);
	vector<int> direction(n+1);
	

	boost::timer t;
	t.restart();

	for (int i = 1; i <= n + 1; i++)//создание вектора
	{
		v1[i] = i;
		if (i != n+1) {
			pos[i] = i;
			direction[i] = -1;
		}
	}

	direction[0] = direction[1] = 0;
	pos[0] = 0;
	int m;
	v1[0] = v1[n+1] = m = n+1;
	int k =1;
	while (m != 1)
	{//вывод итерации
		copy(v1.begin() + 1, v1.end() - 1, ostream_iterator<int>(cout, " "));
		cout << " ";
		cout << k;
		cout << endl;
		k++;

		m = n;
		while (v1[pos[m] + direction[m]] > m) {
			direction[m] = -direction[m];
			m--;
		}

		swap(v1[pos[m]], v1[pos[m] + direction[m]]);
		swap(pos[v1[pos[m]]], pos[m]);

	}
	double duration = t.elapsed();

	cout << duration << endl;
}
//Для 10 элементов время перестановок равно: 0.747 секунд
//Для 15 элементов время перестановок равно: 269188 секунд
//Для 20 элементов время перестановок равно: 5*10^11 секунд
//Для 50 элементов время перестановок равно: 6,3*10^57 секунд
//Для 100 элементов время перестановок равно: 1,92*10^151 секунд
