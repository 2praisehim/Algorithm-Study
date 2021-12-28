#include <iostream>
using namespace std;

char number[10000][11];

struct TRIE {
	bool finish; //������ ���� üũ
	TRIE* node[10];

	//������. '��带 �Ҵ��Ѵ�.'
	TRIE() {
		finish = false;
		for (int i = 0; i < 10; i++) node[i] = NULL;
	}

	//���� �Լ�
	void insert(char* number) {
		if (*number == NULL) {
			finish = true;
			return;
		}
		int cur = *number - '0';
		if (node[cur] == NULL) node[cur] = new TRIE();
		node[cur]->insert(number + 1);
	}

	//ã�� �Լ�
	bool find(char* number) {
		if (*number == NULL) {
			return false;
		}
		if (finish) return true;

		int cur = *number - '0';
		if (node[cur] == NULL) return false;
		return node[cur]->find(number + 1);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCase, numberCnt; cin >> testCase;

	while (testCase--) {
		cin >> numberCnt;
		TRIE* trie = new TRIE();

		for (int i = 0; i < numberCnt; i++) {
			cin >> number[i];
			trie->insert(number[i]);
		}
		bool flag = true;
		for (int i = 0; i < numberCnt; i++) {
			if (trie->find(number[i])) {
				cout << "NO" << '\n';
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES" << '\n';
	}
}