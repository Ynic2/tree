#include <iostream>
#include <vector>
#include <string>

using namespace std;

void aga(string& again, int& index) {
	int flag = 0;
	while (flag == 0) {
		cout << "������ ������ ������?(y-��,n-���)\n";
		getline(cin, again);
		if (again == "y") {
			index = 0;
			flag = 1;
		}
		else if (again == "n") {
			flag = 1;
		}
		else {
			cout << "�� ����� ������������ �����!" << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	vector<string> tree(3);
	tree[0] = "� ����� ��������� ���� �����?";
	string its = "��� �������� - ";
	tree[1] = its + "���?";
	tree[2] = its + "�������?";
	int index = 0, stop = 0;
	string answer;
	while (stop == 0) {
		string again;
		cout << tree[index] << endl << "�������� y, ���� - ��.\n" << "�������� n, ���� - ���\n";
		getline(cin, answer);
		if ((answer == "y" || answer == "n") && tree[index].find("-") == 13) {
			if (answer == "y") {
				aga(again, index);
			}
			else {
				string memory = tree[index];
				cout << "����� �������� �� �������, ��� ������� ���������� ��������? (��.���.)\n";
				string animal;
				getline(cin, animal);
				cout << "���������� ������ , �� ������� ����� �� ����� " << animal << endl;
				string question;
				getline(cin, question);
				int lenght = size(tree);
				tree.resize((lenght * 2) + 1);
				tree[index] = question;
				tree[((index + 1) * 2) - 1] = its + animal;
				tree[(index + 1) * 2] = memory;
				aga(again, index);
			}
		}
		else {
			if (answer == "n") {
				index = ((index + 1) * 2);
			}
			else if (answer == "y") {
				index = ((index + 1) * 2) - 1;
			}
			else {
				cout << "������� ���������� ��������\n";
			}
		}
		if (again == "n") {
			break;
		}
	}
}
