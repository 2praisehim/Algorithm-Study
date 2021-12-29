// YonseiTOTO
// ��ü ���� ��N, ���ϸ���m, ��û�� ��� �� Pi, �����ο� Li
// �־��� ���ϸ����� �ִ�� ���� �� �ִ� ���� �� ���
// 2021-12-27

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
	int N, m;
	int answer = 0;
	cin >> N >> m; // ��ü ���� ��, ���ϸ��� �Է�

	for (int i = 0; i < N; i++) {
		vector<int> v;

		int p, l;
		cin >> p >> l; // ��û ��, �����ο�

		for (int j = 0; j < p; j++) {
			int x;
			cin >> x;

			v.push_back(x);
		}
		sort(v.begin(), v.end(), greater<>()); // �ٸ� ����� ���ϸ��� ��������
		if (p > l) {
			while (v.size() > l) {
				v.pop_back();
			}
			arr.push_back(v.back());
		}
		else if (p == l) {
			arr.push_back(v.back());
		}
		else
			arr.push_back(1);
	}

	sort(arr.begin(), arr.end(), less<>()); // ��� ���ϸ��� ��������

	for (int i = 0; i < arr.size(); i++) {
		if (m >= arr[i]) {
			m -= arr[i];
			answer++;
		}
	}
	cout << answer;

	return 0;
}