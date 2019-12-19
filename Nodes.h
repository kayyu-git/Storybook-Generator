#include <vector>
#include <fstream>
#include <string>
#include "Story.h"
#include "Player.h"
using namespace std;

vector<Node> nodes;

int getNext(int element, int val) {
	if (nodes[element].options[val].stat != "") {
		cout << rollStat(nodes[element].options[val].stat);
		cout << "You have " + to_string(player.health) + " HP. \n";
	}
	if (player.health <= 0) {
		return 1;
	}
	else {
		return nodes[element].options[val].nextNode;
	}
}

vector<Node> writeStory(ifstream& storyFile) {
	string line = "";
	string storyText = "";
	int next = 0;
	string optionText = "";
	string stat = "";
	vector<Option> options;

	while (getline(storyFile, line)) {
		if (line == "[Node Text]") {
			getline(storyFile, line);
			storyText = line + "\n";
		}
		if (line == "[Node Option Text]") {
			getline(storyFile, line);
			optionText = line + "\n";
		}
		if (line == "[Node Option Next]") {
			getline(storyFile, line);
			next = stoi(line);
		}
		if (line == "[Node Option Stat]") {
			getline(storyFile, line);
			stat = line;
		}
		if (line == "[Node Option End]") {
			options.push_back(Option(next, optionText, stat));
			next = 0;
			optionText = "";
			stat = "";
		}
		if (line == "[Node End]") {
			if (storyText == "outputStats()\n") {
				storyText = outputStats() + "\n";
			}
			nodes.push_back(Node(storyText, options));
			options.clear();
			storyText = "";
		}
	}
	return nodes;
}