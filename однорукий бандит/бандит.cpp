#include "бандит.h"

slotMachiime::slotMachiime(int money, int bet)
{
	srand(time(0));
	this->bet = bet;
	this->balance = money;
	//36,209,65,66,67,252,64,61,251
	for (size_t i = 0; i < 3; i++) {
		bar[i].push(36);
		bar[i].push(209);
		bar[i].push(65);
		bar[i].push(66);
		bar[i].push(67);
		bar[i].push(252);
		bar[i].push(64);
		bar[i].push(61);
		bar[i].push(251);
		
	}

}

bool slotMachiime::game()
{
	if (this->balance<this->bet) {
		return false;
	}
	this->balance -= this->bet;
	rollbars();
	balance +=bet* getCoeff();
	return true;
}

void slotMachiime::setBet(int bet)
{
	this->bet = bet;
}

void slotMachiime::addmoney(int money)
{
	this->balance += money;
}



void slotMachiime::rollbars()
{
	
	int r=27 + rand() % 28;
	for (size_t i = 0; i < r; i++)
	{
		bar[0].pop(false);
	}
	///
     r = 27 + rand() % 28;
	for (size_t i = 0; i < r; i++)
	{
		bar[1].pop(false);
	}
	///
    r = 27 + rand() % 28;
	for (size_t i = 0; i < r; i++)
	{
		bar[2].pop(false);
	}
}

int slotMachiime::getCoeff()
{
	int coef = 0;
	if (bar[0].front() == bar[1].front() || bar[1].front() == bar[2].front())
		coef = 2;
	if (bar[0].front() == bar[1].front() && bar[1].front() == bar[2].front())
		coef = 10;
	if (bar[0].front() == bar[1].front() && bar[1].front() == bar[2].front() && bar[0].front() == '$')
		coef = 50;
	bar[0].front();
	bar[1].front();
	bar[2].front();
	return coef;
}
