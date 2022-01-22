// ��ġ
// ��ü ��� �� N, ������ x, Ű y
// �־��� �����Կ� Ű ������ ��ġ ���� ���
// 2022-01-22

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<pair<int, int>> v;
	int rank[50];
	fill_n(rank, 50, 1);
	int N;
	int height, weight;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height >> weight;
		v.push_back(make_pair(height, weight));
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				rank[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << rank[i] << " ";
	}

	return 0;
}