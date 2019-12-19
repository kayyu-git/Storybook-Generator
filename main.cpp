#include <iostream>
#include <vector>
#include <fstream>
#include "Story.h"
#include "Player.h"
#include "Nodes.h"
using namespace std;

int main() {
	ifstream storyFile("story.txt");
	vector<Node> nodes = writeStory(storyFile);
	int response;
	int counter = 3;
	bool gameEnd = false;
	while (gameEnd == false) {
		cout << nodes[counter].text;
		for (unsigned int x = 0; x < nodes[counter].options.size(); x++) {
			cout << nodes[counter].options[x].text;
		}
		cin >> response;
		counter = getNext(counter, response - 1);
		if (counter == 0 || counter == 1 || counter == 2) {
			cout << nodes[counter].text;
			gameEnd = true;
		}
	}
	cout << "The End. \n";
	storyFile.close();
	system("pause");
	return 0;
};