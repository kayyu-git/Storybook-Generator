#pragma once

using namespace std;

struct Option {
	int nextNode;
	string text;
	string stat;

	Option(int n, string t, string s) : nextNode(n), text(t), stat(s) {};
};

struct Node {
	const string text;
	vector<Option> options;

	Node(string t, vector<Option> o) : text(t), options(o) {};
};

struct Player {
	int strength, perception, endurance, charisma, intelligence, agility, luck;
	int health;

	Player(int s, int p, int e, int c, int i, int a, int l, int h) : strength(s), perception(p), endurance(e), charisma(c), intelligence(i), agility(a), luck(l), health(h) {};
};