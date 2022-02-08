// ������ �����ֱ�
// ���� ���� N, �迭 Ai, ��Ģ���� ���� �迭 Bi
// �ִ밪�� �ּҰ� ���
// 2022-02-08

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000001;
int N;
int operands[12], operators[4];
int maxData = -MAX;
int minData = MAX;

int dfs(int plus, int minus, int multiple, int divide, int index, int result)
{
	if (index == N)
	{
		minData = min(minData, result);
		maxData = max(maxData, result);
	}

	if (plus > 0)
	{
		dfs(plus - 1, minus, multiple, divide, index + 1, result + operands[index]);
	}

	if (minus > 0)
	{
		dfs(plus, minus - 1, multiple, divide, index + 1, result - operands[index]);
	}

	if (multiple > 0)
	{
		dfs(plus, minus, multiple - 1, divide, index + 1, result * operands[index]);
	}

	if (divide > 0)
	{
		dfs(plus, minus, multiple, divide - 1, index + 1, result / operands[index]);
	}

	return 0;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> operands[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}

	dfs(operators[0], operators[1], operators[2], operators[3], 1, operands[0]);

	cout << maxData << endl;
	cout << minData << endl;
}