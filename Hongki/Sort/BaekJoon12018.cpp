#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//����, ���ϸ���
	int16_t answer = 0, subject, mileage; cin >> subject >> mileage;
	vector<uint16_t> results;

	while (subject--) {
		int16_t n, m; cin >> n >> m; // �����ο�, �����ο�
		vector<int16_t> mileageStore(n);

		for (int i = 0; i < n; i++) cin >> mileageStore[i];

		// �����ο� > �����ο�
		if (n > m) {
			sort(mileageStore.rbegin(), mileageStore.rend());
			results.push_back(mileageStore[m - 1]);
		}
		// �����ο� == �����ο�
		else if (n == m) {
			results.push_back(*min_element(mileageStore.begin(), mileageStore.end()));
		}
		// �����ο� < �����ο�
		else results.push_back(1);
	}
	//��� ����� ��������
	sort(results.begin(), results.end());

	//���ϸ����� �ּ������� ����, �ִ����� ���� ���
	for (int i = 0; i < results.size(); i++) {
		if (mileage - results[i] >= 0) {
			mileage -= results[i]; ++answer;
		}
		else break;
	}
	cout << answer;
}