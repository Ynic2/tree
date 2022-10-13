#include <iostream>
#include <vector>
#include <string>

using namespace std;

void aga(string& again, int& index) {
	int flag = 0;
	while (flag == 0) {
		cout << "Хотите начать заново?(y-да,n-нет)\n";
		getline(cin, again);
		if (again == "y") {
			index = 0;
			flag = 1;
		}
		else if (again == "n") {
			flag = 1;
		}
		else {
			cout << "Вы ввели неправильный ответ!" << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	vector<string> tree(3);
	tree[0] = "У этого животного есть хвост?";
	string its = "Это животное - ";
	tree[1] = its + "кот?";
	tree[2] = its + "лягушка?";
	int index = 0, stop = 0;
	string answer;
	while (stop == 0) {
		string again;
		cout << tree[index] << endl << "Напишите y, если - да.\n" << "Напишите n, если - нет\n";
		getline(cin, answer);
		if ((answer == "y" || answer == "n") && tree[index].find("-") == 13) {
			if (answer == "y") {
				aga(again, index);
			}
			else {
				string memory = tree[index];
				cout << "Какое животное вы загадли, при условии предыдущих вопросов? (Им.пад.)\n";
				string animal;
				getline(cin, animal);
				cout << "Придумайте вопрос , на который ответ да будет " << animal << endl;
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
				cout << "Введите правильное значение\n";
			}
		}
		if (again == "n") {
			break;
		}
	}
}
