// �ְ��� ����
// ���� ������ �� N, ������ ���� A, ������ ���� B, ������ ���� C, ������ ���� Di�� �� �ٿ� �ϳ��� �־�����.
// 1���� ������ ���� ���� �ְ��� ������ 1���� ������ ����Ѵ�. �Ҽ��� ���ϴ� ������ ���� ������ ����Ѵ�.
//2021-12-28

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	int N;
	int price_sum, price_topping;
	int cal_sum;
	int no_topping;
	int answer = 0;

	cin >> N;
	cin >> price_sum >> price_topping;
	cin >> cal_sum;

	no_topping = cal_sum * 1.0 / price_sum * 1.0;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < N; i++) {
		cal_sum = cal_sum + v[i];
		price_sum = price_sum + price_topping;
		v[i] = cal_sum * 1.0 / price_sum * 1.0; // 1���� ����

		answer = max(v[i], answer); // �ִ밪
	}
	answer = max(answer, no_topping); // ���� ���°� �ִ��� ���

	cout << answer;

	return 0;
}