#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <iso646.h>
#include <assert.h>
#include<stdbool.h>

struct team {
	char name[10];
	int points;
	int goal_difference;
};

struct match {
	char HomeTeamName[10];
	int HomeTeamGoals;
	int AwayTeamGoals;
	char AwayTeamName[10];
};

struct match matches[12];
struct team teams[4] = { 0 };

void preprocess() {
	for (int i = 1; i < 12; ++i) {
		int j = 0;
		bool flag = true;
		while (flag) {
			if (!strcmp(teams[j].name ,matches[i].HomeTeamName)) {
				flag = false;
			} else if (teams[j].name[0] == '\0') {
				strcpy(teams[j].name ,matches[i].HomeTeamName);
				flag = false;
			}
			j++;
			if (j == 4) return;
		}
	}
}

int get(char* name) {
	int i = 0;
	while (i < 4) {
		if (!strcmp(name ,teams[i].name)) {
			return i;
		}
		i++;
	}
}


void evaluate_score() {
	for (int i = 0; i < 12; ++i) {
		int goal_diff = matches[i].HomeTeamGoals - matches[i].AwayTeamGoals;
		if (!goal_diff) {
			teams[get(matches[i].HomeTeamName)].points++;
			teams[get(matches[i].AwayTeamName)].points++;
		} else if (goal_diff > 0) {
			teams[get(matches[i].HomeTeamName)].points += 3;
			teams[get(matches[i].HomeTeamName)].goal_difference += goal_diff;
			teams[get(matches[i].AwayTeamName)].goal_difference -= goal_diff;
		} else {
			teams[get(matches[i].AwayTeamName)].points += 3;
			teams[get(matches[i].AwayTeamName)].goal_difference += -goal_diff;
			teams[get(matches[i].HomeTeamName)].goal_difference += goal_diff;
		}
	}
}

void sort_teams() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j < (4 - i); ++j) {
			if (teams[j - 1].points < teams[j].points) {
				struct team temp = teams[j - 1];
				teams[j - 1] = teams[j];
				teams[j] = temp;
			} else if (teams[j - 1].points == teams[j].points) {
				if (teams[j - 1].goal_difference < teams[j].goal_difference) {
					struct team temp = teams[j - 1];
					teams[j - 1] = teams[j];
					teams[j] = temp;
				}
			}
		}
	}
}

void clear() {
	for (int i = 0; i < 4; ++i) {
		teams[i].points = teams[i].goal_difference = 0;
		teams[i].name[0] = '\0';
	}
}
			

void solution() {
	for (int i = 0; i < 12; ++i) {
		scanf("%s %d vs. %d %s" ,
			matches[i].HomeTeamName ,&matches[i].HomeTeamGoals ,
			&matches[i].AwayTeamGoals ,matches[i].AwayTeamName);
	}
	strcpy(teams[0].name ,matches[0].HomeTeamName);
	preprocess();
	evaluate_score();
	sort_teams();
	printf("%s %s\n" ,teams[0].name ,teams[1].name);
	clear();
 }

int main(){
	int T;
	scanf("%d" ,&T);
	while (T--) {
		solution();
	}
	return 0;
}