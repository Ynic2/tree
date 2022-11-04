#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct tree {
	string question ="";
	string animal = "";
	tree* yans=nullptr;
	tree* nans=nullptr;
};

void userans(string& ans) {
	int flag = 0;
	while (flag == 0) {
		getline(cin, ans);
		if (ans == "n" || ans == "y") {
			flag = 1;
		}
		else {
			cout << "You entered incorrectly\n" << "Enter again\n";
		}
	}
}

void NewInformation(string& que, string& animal, string& ans) {
	cout << "Come up with a new animal\n";
	getline(cin, animal);
	cout << "Come up with a new question\n";
	getline(cin, que);
	cout << "What will be the answer to this question to get your animal?\n";
	userans(ans);
}

void end(tree* game, string& ans) {
	string NewQuestion, NewAnimal, YN;
	cout << "It's a " << game->animal << "?\n";
	userans(ans);
	if (ans == "y") {
		cout << "GAME OVER!";
	}
	else {
		NewInformation(NewQuestion, NewAnimal, YN);
		tree* yans=new tree;
		tree* nans=new tree;
		if (YN == "y") {
			yans->animal = NewAnimal;
			nans->animal = game->animal;
		}
		else {
			yans->animal = game->animal;
			nans->animal = NewAnimal;
		}
		game->animal = "";
		game->question = NewQuestion;
		game->yans = yans;
		game->nans = nans;
	}
}

void play(tree* game) {
	string ans;
	if (game->question != "") {
		cout << game->question << endl;
		userans(ans);
		if (ans == "y") {
			play(game->yans);
		}
		else {
			play(game->nans);
		}
	}
	else {
		end(game, ans);
	}
}

bool again() {
	string ans;
	cout << "Do you wanna play again? (y/n)\n";
	userans(ans);
	if (ans == "n") {
		return false;
	}
	else {
		return true;
	}
}

void save(ofstream &text,tree* game) {
	text << game->question << endl;
	text << game->animal << endl;
	if (game->animal == "") {
		save(text, game->yans);
		save(text, game->nans);
	}
}

void upload(tree*& game, ifstream& text) {
	string buff;
	if (!text.eof()) {
		getline(text, buff);
		game->question = buff;
		getline(text, buff);
		game->animal = buff;
	}
	if (!text.eof() && game->animal=="") {
		tree* yans = new tree;
		game->yans = yans;
		upload(yans, text);
	}
	if (!text.eof() && game->animal == ""){
		tree* nans = new tree;
		game->nans = nans;
		upload(nans, text);
	}
}

int main() {
	tree* game=new tree;
	ifstream text1("file1.txt");
	fstream text2("file1.txt");
	if (text2.peek()==EOF) {
		game->animal = "Rat";
	}
	else {
		upload(game, text1);	
	}
	text2.close();
	text1.close();
	do{
		play(game);
	} while (again());
	ofstream text;
	int y=0, n=0;
	text.open("file1.txt");
	save(text,game);
	text.close();
}