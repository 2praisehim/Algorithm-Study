// ȸ�ǽ� ����
// ȸ���� �� N, ���� �ð��� ������ �ð��� �� ȸ���� ������ �־�����.
// �ִ� ����� �� �ִ� ȸ���� ������ ����Ѵ�.
// 2021-12-27

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) // �ι�° ������ �������� ����
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

int main()
{
	int N;
	int now = 0;
	int cnt = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) { // ���� �ð����� ���� �ð��� ũ�� ī��Ʈ
		if (now <= v[i].first) {
			cnt++;
			now = v[i].second;
		}
	}

	cout << cnt << endl;

	return 0;
}