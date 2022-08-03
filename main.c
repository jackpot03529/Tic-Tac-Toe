#include <stdio.h>
#include <windows.h>
#include <conio.h>

char gameBoard[10] = {'1','2','3','4','5','6','7','8','9'};

void printMainMenu();
void playerMove(int num, int playerTurn);
int checkWin();
void printBoard();
int changeTurn(int playerTurn);
void resetGame();

int main() {
	int num, playerTurn = 0, count = 0, win = 0;
	char playerInput[2] = { '0' };
	char playAgain[2] = { '0' };
	printMainMenu();
	do {
		if (playAgain[0] != 'y') {
			printf("Enter: ");
			playerInput[0] = _getch();
			printf("%c", playerInput[0]);
			Sleep(200);
			printf("\b");
		}
		system("cls");
		if (playerInput[0] == 's' || playAgain[0] == 'y') {
			playAgain[0] = 'n';
			while (count < 9) {
				puts("");
				printBoard();
				puts("");
				printf("Player %d choose a number(1-9): ", playerTurn + 1);
				while (1) {
					num = _getch() - 48;
					printf("%d", num);
					Sleep(200);
					printf("\b");
					if (gameBoard[num - 1] != 'O' && gameBoard[num - 1] != 'X') {
						break;
					}
					else {
						printf("Player %d choose a number again(1-9): ", playerTurn + 1);
					}
				}
				playerMove(num, playerTurn);
				system("cls");
				if (win = checkWin() == 1) {
					break;
				}
				playerTurn = changeTurn(playerTurn);
				count++;
			}
			if (win == 1) {
				puts("");
				printBoard();
				puts("");
				printf("Player %d Won!!\n", playerTurn + 1);
			}
			else {
				puts("");
				printBoard();
				puts("");
				printf("Draw!\n");
			}

			puts("");
			printf("Play Again (y/n)?\nEnter: ");
			do {
				playAgain[0] = _getch();
				printf("%c", playAgain[0]);
				Sleep(200);
				printf("\b");
				if (playAgain[0] == 'n') {
					system("cls");
					resetGame();
					playerTurn = 0, count = 0, win = 0;
					printMainMenu();
					break;
				}
				else if (playAgain[0] == 'y') {
					resetGame();
					count = 0, win = 0;
					break;
				}
			} while (1);
		}
		else if (playerInput[0] == 'q') {
			break;
		}
		else {
			printMainMenu();
		}
	} while (1);
	
	return 0;
}

void printMainMenu() {
	puts("");

	printf("\tбсбсбсбсбс бс               бсбсбсбсбс                       бсбсбсбсбс     бсбсбс\n");
	printf("\t    бс                          бс                               бс         бс\n");
	printf("\t    бс     бс бсбсбс  бсбсбс    бс   бсбсбс    бсбсбс  бсбсбс    бс  бсбсбс бсбсбс\n");
	printf("\t    бс     бс бс                бс   бс  бсбс  бс                бс  бс  бс бс\n");
	printf("\t    бс     бс бсбсбс            бс   бсбсбс бс бсбсбс            бс  бсбсбс бсбсбс\n");

	puts("");
	printf("Start(s)\n");
	printf("Quit(q)\n");
	puts("");
}

void playerMove(int num, int playerTurn) {
	if (playerTurn == 0) {
		gameBoard[num - 1] = 'O';
	}
	else {
		gameBoard[num - 1] = 'X';
	}
}

int checkDiagonal() {
	char temp = gameBoard[0];
	if (gameBoard[4] == temp && gameBoard[8] == temp) {
		return 1;
	}
	temp = gameBoard[2];
	if (gameBoard[4] == temp && gameBoard[6] == temp) {
		return 1;
	}
	return 0;
}
int checkHorizontal() {
	int check = 0;
	for (int i = 0; i <= 6; i += 3) {
		if (gameBoard[i] == gameBoard[i + 1] && gameBoard[i] == gameBoard[i + 2]) {
			return 1;
		}
	}
	return check;
}
int checkVertical() {
	int check = 0;
	for (int i = 0; i <= 2; i++) {
		if (gameBoard[i] == gameBoard[i + 3] && gameBoard[i] == gameBoard[i + 6]) {
			return 1;
		}
	}
	return check;
}

int checkWin() {
	int check = 0;
	check = checkDiagonal();
	if (check == 1) {
		return check;
	}
	check = checkHorizontal();
	if (check == 1) {
		return check;
	}
	check = checkVertical();
	if (check == 1) {
		return check;
	}
	return check;
}

void printBoard() {
	printf(" %c | %c | %c \n", gameBoard[0], gameBoard[1], gameBoard[2]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", gameBoard[3], gameBoard[4], gameBoard[5]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", gameBoard[6], gameBoard[7], gameBoard[8]);
}

int changeTurn(int playerTurn) {
	if (playerTurn == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void resetGame() {
	for (int i = 0; i < 9; i++) {
		gameBoard[i] = i + 49;
	}
}