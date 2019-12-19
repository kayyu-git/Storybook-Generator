#pragma once

#include <random>
#include <string>
#include "Story.h"
using namespace std;

random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int> uni(1, 5);

Player player(uni(rng), uni(rng), uni(rng), uni(rng), uni(rng), uni(rng), uni(rng), 10);

int getHealth() {
	return player.health;
}

string rollResult(int num) {
	if (num <= 3) {
		player.health = player.health - 3;
		return "Ooo, that's not good. You failed and lost a good deal of health. Minus 3 HP. \n";
	}
	if (num > 3 && num <= 6) {
		player.health = player.health - 2;
		return "Unfortunately, you failed, but you managed to somewhat salvage the situation, so it wasn't as bad as it could've been. Still got injured though. Minus 2 HP. \n";
	}
	if (num > 6 && num <= 10) {
		player.health = player.health - 1;
		return "So close! Just a little bit more, and you would have made it! Minus 1 HP. \n";
	}
	if (num > 10 && num <= 19) {
		return "You did it! Yay! \n";
	}
	if (num >= 20) {
		player.health = player.health + 1;
		return "Amazing! You blew that right out of the water! You're so excited that you feel ready for anything! Plus 1 HP. \n";
	}

	return "";
}

string rollStat(string stat) {
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(1, 15);
	int result = uni(rng);

	if (stat == "Strength") {
		result = result + player.strength;
	}
	if (stat == "Perception") {
		result = result + player.perception;
	}
	if (stat == "Endurance") {
		result = result + player.endurance;
	}
	if (stat == "Charisma") {
		result = result + player.charisma;
	}
	if (stat == "Intelligence") {
		result = result + player.intelligence;
	}
	if (stat == "Agility") {
		result = result + player.agility;
	}
	if (stat == "Luck") {
		result = result + player.luck;
	}
	return rollResult(result);
}

string outputStats() {
	return "Stat Distribution: Strength - " + to_string(player.strength) + ", Perception - " + to_string(player.perception) + ", Endurance - " + to_string(player.endurance) + ", Charisma - " + to_string(player.charisma) + ", Intelligence - " + to_string(player.intelligence) + ", Agility - " + to_string(player.agility) + ", Luck - " + to_string(player.luck) + ", Health - " + to_string(player.health) + ". \n";
}