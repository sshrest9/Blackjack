#include <iostream>
#include <string>

using namespace std;

int myRandom(int nummax, int nummin);
int checkBet(int money, int bet);
int card(int card);
int main()
{
	srand((unsigned int)time_t(0));
	int bet;
	char again; int money(10000);
	do
	{
		cout << "Money:" << money << endl; //starting money
		cout << "Place your bet: "; cin >> bet;
		bet = checkBet(money, bet);//calls the function to check if the bet is valid
		money -= bet; cout << "Money: " << money << endl;//subtracts the bet from the total money that the player has

		int ptotal, dtotal;
		int pcard1 = myRandom(13, 1);//generates a random number from 1 and 13 for player card 1 by using the function
		int pcard2 = myRandom(13, 1);//generates a random number from 1 and 13 for player card 2 
		int dcard1 = myRandom(13, 1);//generates a random number from 1 and 13 for dealer card 1
		int dcard2 = myRandom(13, 1);//generates a random number from 1 and 13 for dealer card 2
		cout << "You have ";
		pcard1 = card(pcard1);
		pcard2 = card(pcard2);
		cout << endl << "The dealer has: ";
		dcard1 = card(dcard1);
		dcard2 = card(dcard2);

		cout << endl;
		ptotal = pcard1 + pcard2; //adds the two card values together for player
		dtotal = dcard1 + dcard2; //adds the two card values together for dealer



		if ((pcard1 == 1 && pcard2 == 11 || pcard2 == 12 || pcard2 == 13) || (pcard2 == 1 && pcard2 == 11 || pcard2 == 12 || pcard2 == 13))//checks if player has blackjack
		{
			cout << "Blackjack you win!!";
			bet *= 1.5;
			money += bet;

		}
		else if ((dcard1 == 1 && (dcard2 == 11 || dcard2 == 12 || dcard2 == 13)) || (dcard2 == 1 && (dcard2 == 11 || dcard2 == 12 || dcard2 == 13)))//checks if dealer has blackjack
		{
			cout << "Better luck next time";
			money = money - bet;
		}
		else
		{
			if (ptotal > dtotal) //if player has higher than dealer than the player wins
			{
				cout << "You win!";
				money += bet;
			}
			else //if player has less than dealer than the player loses
			{
				cout << "You lose :(";
				money -= bet;
				if (money < 0)
				{
					money = 0;
				}
			}
		}
		cout << endl << "Money: " << money << endl; //displays money left
		if (money <= 0)
		{
			cout << "Game Over!" << endl;
			break; //ends the loop
		}
		cout << "Would you like to play again? y/n: "; cin >> again;

		again = tolower(again);
	} while (again == 'y');//loops the program if the entered letter is 'y'


	return 0;
}

int card(int card)
{
	switch (card)//checks the number and displays it
	{
	case 1: cout << "Ace and ";
		break;
	case 11: cout << "Jack and ";
		card = 10;
		break;
	case 12: cout << "Queen and ";
		card = 10;
		break;
	case 13: cout << "King and ";
		card = 10;
		break;
	default: cout << card << " and ";
		break;
	}
	return card;
}
int myRandom(int nummax, int nummin)
{

	int randomnum;
	randomnum = nummin + rand() % (nummax - nummin + 1);
	return randomnum;
}
int checkBet(int money, int bet)
{
	while (bet > money)
	{
		cout << "Invalid bet \n Please enter bet "; cin >> bet;

	}
	return bet;
}

