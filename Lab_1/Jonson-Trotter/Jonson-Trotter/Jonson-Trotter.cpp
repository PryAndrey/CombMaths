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

	for (int i = 1; i <= n + 1; i++)//�������� �������
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
	{//����� ��������
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
//��� 10 ��������� ����� ������������ �����: 0.747 ������
//��� 15 ��������� ����� ������������ �����: 269188 ������
//��� 20 ��������� ����� ������������ �����: 5*10^11 ������
//��� 50 ��������� ����� ������������ �����: 6,3*10^57 ������
//��� 100 ��������� ����� ������������ �����: 1,92*10^151 ������
