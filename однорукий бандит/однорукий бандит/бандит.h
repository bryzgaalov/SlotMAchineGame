#pragma once
#include"cycleQueue.h"
#include<ctime>
class slotMachiime {

	cycleQueue<char> bar[3];
	int balance;
	int bet;
public:
	slotMachiime(int money,int bet);
	bool game();

	//getters&setters
	void setBet(int bet);
	void addmoney(int money);
	int getBalance()const { return balance; };
	int getBet()const { return bet; };
	char operator[](int index)const { return bar[index].front(); };
private:
	void rollbars();
	int getCoeff();
};