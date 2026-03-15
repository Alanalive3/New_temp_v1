#include<iostream>
#include<new>
#include"game.hpp"
using namespace std;
int main() {
	int gameState = 0;
	while (gameState == 0) {
		int edge,victoryNum;
		cout << "Set the edge:";
		cin >> edge;
		cout << "Set the victory number:";
		cin >> victoryNum;
		if (edge < victoryNum) {
			cout << "Error Invalid Enter.Enter again.\n";
		}
		else {
			gameState = 1;
			char** pos= createCourt(edge);
			int** seconddown = createSecondDown(edge);
			showCourt(pos, edge);
			int x, y;
			int player = 2;
			const char player0 = 'O';
			const char player1 = 'X';
			cout << "Player0, Please Enter position of the court, "<<endl
				<<"from 1 to " 
				<< edge <<':';
				cin >> x;
				cin >> y;
			while (gameState == 1) {
				if (x > edge || x<0 || y>edge || y < 0) {
					cout << "Error Invalid Enter." << endl
						<< "Try again:";
					cin >> x;
					cin >> y;
				}
				else {
					break;
				}
			}
			while (gameState == 1) {
				while(player == 2) {
					if (x>edge||x<=0||y>edge||y<=0||seconddown[x - 1][y - 1] == 1) {
						cout << "Error Invalid Enter." << endl
							<< "Try again:";
						cin >> x;
						cin >> y;
					}
					else {
						pos[x - 1][y - 1] = player0;
						seconddown[x - 1][y - 1] = 1;
						if (check0Win(pos, edge, x, y, victoryNum) == 0) {
							showCourt(pos, edge);
							cout << "Player0 victory!";
							player = 0;
							gameState = 2;
							break;
						}
						player=1;
						cout << "Now the court is:" << endl;
						showCourt(pos, edge);
						cout << endl;
						cout << "Player0 entered " << '(' << x << ',' << y << ')' << endl;
						cout << "Player1, Please Enter position of the court, "<<endl
							<<"from 1 to "
							<< edge << ':';
						cin >> x;
						cin >> y;
					}
				}
				while(player == 1) {
					if (x > edge || x<=0 || y>edge || y <= 0 || seconddown[x - 1][y - 1] == 1) {
						cout << "Error Invalid Enter." << endl
							<< "Try again:";
						cin >> x;
						cin >> y;
					}
					else {
						pos[x - 1][y - 1] = player1;
						seconddown[x - 1][y - 1] = 1;
						if (check1Win(pos, edge, x, y, victoryNum) == 1) {
							showCourt(pos, edge);
							cout << "Player1 victory!";
							player = 0;
							gameState = 2;
							break;
						}
						player=2;
						cout << "Now the court is:" << endl;
						showCourt(pos, edge);
						cout << endl;
						cout << "Player1 entered " << '(' << x << ',' << y << ')' << endl;
						cout << "Player0, Please Enter position of the court, from 1 to "
							<< edge << ':';
						cin >> x;
						cin >> y;
					}
				}
			}
			releaseCourt(pos, edge);
			releaseSecond(seconddown,edge);
			cout << "\nDo you want to play again? Enter Y/N";
			char again;
			cin >> again;
			if (again == 'Y' || again == 'y') {
				gameState = 0;
			}
			else {
				cout << "Thanks for playing!";
				return 0;
			}
		}
	}
}
