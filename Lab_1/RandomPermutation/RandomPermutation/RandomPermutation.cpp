#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int deck = 36;

	int n;
	cin >> n;

	vector<int> v1(deck);
	for (int j = 1; j <= n; j++)
	{

		for (int i = 0; i < deck; i++) {//создание колоды
			v1[i] = i + 1;
		}

		for (int i = 0; i <= deck - 1; i++) {
			swap(v1[i], v1[rand() % (deck - 1)]);
		}
		copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

	}
}
