#include "slotMashineConcole.h"

sloMashineConsole::sloMashineConsole():model(0,0)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int r = 10 + rand() % 6;
	int x = 0;
	for (size_t i = 0; i < r; i++)
	{
		cout << "Добро пожаловать в игру\n";
		cout << "Зaгрузка";
		for (size_t i = 0; i < x; i++)
		{
			cout << ".";
		}
		Sleep(300);
		x++;
		if (x == 4)x = 0;
		system("cls");
	}
}

void sloMashineConsole::start()
{
	system("cls");
	addMoneyMenu();
	pause();
	changeBetMEnu();
	pause();
	
	int choice=0;
	int win = 0;

	while (choice != 4) {
	mainMenu();
	cin >> choice;
		switch (choice)
		{
		case 1:
		
			if (!model.game())
				cout << "Недостаточно средств\n" 
				<< "Введите деньги или измените ставку\n";
			
			
			break;
		case 2:
			changeBetMEnu();
			break;
		case 3:
			addMoneyMenu();
			break;
		case 4:
			cout << "Ваш выйгрыш состовляет: " << model.getBalance() << "euro" << endl;
			cout << "Досвидания! " << endl;
			break;
		default:
			cout << "Ошибка 404 . Попробуйте заново" << endl;
			break;
		}
		pause();
	}
}

void sloMashineConsole::mainMenu( )
{
	system("cls");
	cout << "--------------------" << endl << endl;
	cout << "\t" << model[0] << " " << model[1] << " " << model[2] << endl;
	cout << "--------------------" << endl << endl;
	cout << "Ваш счет:" << model.getBalance() << " euro" << endl;
	cout << "Ваша ставка:\t" << model.getBet() << " euro";
	cout << endl;
	cout << "1- Сьиграть" << endl;
	cout << "2- Изменить ставку" << endl;
	cout << "3- Добавить деньги" << endl;
	cout << "4- Выйти из  игры" << endl;
}

void sloMashineConsole::addMoneyMenu()
{
	system("cls");
	cout << "Ваш баланс равен: " << model.getBalance() << " Euro" << endl;
	cout << "Вставте деньги" << endl;
	int m;
	cin >> m;
	model.addmoney(m);
	cout << "Транзакция проведена успешно!" << endl;
}

void sloMashineConsole::changeBetMEnu()
{
	system("cls");
	cout << "Ваш баланс равен: " << model.getBalance() << " Euro" << endl;
	cout << "Ваша ставка :"<<model.getBalance() << endl;
	cout << "Введите ставку :" << endl;
	int b;
	cin >> b;
	model.setBet(b);
	cout << "Ставка установлена" << endl;
}
