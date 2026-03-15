#include<iostream>
#include<new>

using namespace std;

char** createCourt(const int n) {
	char** court = new char* [n];
	for (int i = 0; i < n; i++) {
		court[i] = new char[n];
		for (int j = 0; j < n; j++) {
			court[i][j] = '+';
		}
	}
	return court;
}

int** createSecondDown(const int n) {
	int** court = new int* [n];
	for (int i = 0; i < n; i++) {
		court[i] = new int[n];
		for (int j = 0; j < n; j++) {
			court[i][j] = 0;
		}
	}
	return court;
}

void releaseCourt(char** court, const int n) {
	for (int i = 0; i < n; i++) {
		delete[]court[i];
	}
	delete[]court;
	return;
}

void releaseSecond(int** second, const int n) {
	for (int i = 0; i < n; i++) {
		delete[]second[i];
	}
	delete[]second;
	return;
}

void showCourt(char** court, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << court[i][j] << ' ';
		}
		cout << i + 1 << endl;
	}
	for (int k = 1; k <= n; k++) {
		cout << k << ' ';
	}
	cout << endl;
}

int check0Win(char** court, const int n, int x, int y,int victoryNum) {
	int contiPos = 1;
	int condition = 2;
	while (condition) {
		if (condition == 2) {
			for (int i_x = x-1; i_x >= 1 && court[i_x-1][y-1] == 'O'; i_x--)contiPos++;
		}
		else {
			for (int i_x = x+1; i_x <= n && court[i_x - 1][y - 1] == 'O'; i_x++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 0;
	}
	else {
		contiPos = 1;
		condition = 2;
	}
	while (condition) {
		if (condition == 2) {
			for (int i_y = y-1; i_y >= 1 && court[x - 1][i_y - 1] == 'O'; i_y--)contiPos++;
		}
		else {
			for (int i_y = y+1; i_y <= n && court[x - 1][i_y - 1] == 'O'; i_y++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 0;
	}
	else {
		contiPos = 1;
		condition = 2;
	}


	while (condition) {
		if (condition == 2) {
			for (int i_x = x - 1, i_y=y-1; i_x >= 1 &&i_y>=1 && court[i_x - 1][i_y - 1] == 'O'; i_x--,i_y--)contiPos++;
		}
		else {
			for (int i_x = x + 1, i_y = y + 1; i_x <= n && i_y <= n && court[i_x - 1][i_y - 1] == 'O'; i_x++, i_y++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 0;
	}
	else {
		contiPos = 1;
		condition = 2;
	}

	while (condition) {
		if (condition == 2) {
			for (int i_x = x + 1, i_y = y - 1; i_x <= n && i_y >= 1 && court[i_x - 1][i_y - 1] == 'O'; i_x++, i_y--)contiPos++;
		}
		else {
			for (int i_x = x - 1, i_y = y + 1; i_x >= 1 && i_y <= n && court[i_x - 1][i_y - 1] == 'O'; i_x--, i_y++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 0;
	}
	else {
		contiPos = 1;
		condition = 2;
		return 3;
	}

}

int check1Win(char** court, const int n, int x, int y, int victoryNum) {
	int contiPos = 1;
	int condition = 2;

	while (condition) {
		if (condition == 2) {
			for (int i_x = x - 1; i_x >= 1 && court[i_x - 1][y - 1] == 'X'; i_x--)contiPos++;
		}
		else {
			for (int i_x = x + 1; i_x <= n && court[i_x - 1][y - 1] == 'X'; i_x++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 1;
	}
	else {
		contiPos = 1;
		condition = 2;
	}

	while (condition) {
		if (condition == 2) {
			for (int i_y = y - 1; i_y >= 1 && court[x - 1][i_y - 1] == 'X'; i_y--)contiPos++;
		}
		else {
			for (int i_y = y + 1; i_y <= n && court[x - 1][i_y - 1] == 'X'; i_y++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 1;
	}
	else {
		contiPos = 1;
		condition = 2;
	}


	while (condition) {
		if (condition == 2) {
			for (int i_x = x - 1, i_y = y - 1; i_x >= 1 && i_y >= 1 && court[i_x - 1][i_y - 1] == 'X'; i_x--, i_y--)contiPos++;
		}
		else {
			for (int i_x = x + 1, i_y = y + 1; i_x <= n && i_y <= n && court[i_x - 1][i_y - 1] == 'X'; i_x++, i_y++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 1;
	}
	else {
		contiPos = 1;
		condition = 2;
	}

	while (condition) {
		if (condition == 2) {
			for (int i_x = x + 1, i_y = y - 1; i_x <= n && i_y >= 1 && court[i_x - 1][i_y - 1] == 'X'; i_x++, i_y--)contiPos++;
		}
		else {
			for (int i_x = x - 1, i_y = y + 1; i_x >= 1 && i_y <= n && court[i_x - 1][i_y - 1] == 'X'; i_x--, i_y++)contiPos++;
		}
		--condition;
	}
	if (contiPos == victoryNum) {
		return 1;
	}
	else {
		contiPos = 1;
		condition = 2;
		return 3;
	}

}