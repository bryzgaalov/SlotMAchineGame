#include "slotMashineConcole.h"

sloMashineConsole::sloMashineConsole():model(0,0)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int r = 10 + rand() % 6;
	int x = 0;
	for (size_t i = 0; i < r; i++)
	{
		cout << "����� ���������� � ����\n";
		cout << "�a������";
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
				cout << "������������ �������\n" 
				<< "������� ������ ��� �������� ������\n";
			
			
			break;
		case 2:
			changeBetMEnu();
			break;
		case 3:
			addMoneyMenu();
			break;
		case 4:
			cout << "��� ������� ����������: " << model.getBalance() << "euro" << endl;
			cout << "����������! " << endl;
			break;
		default:
			cout << "������ 404 . ���������� ������" << endl;
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
	cout << "��� ����:" << model.getBalance() << " euro" << endl;
	cout << "���� ������:\t" << model.getBet() << " euro";
	cout << endl;
	cout << "1- ��������" << endl;
	cout << "2- �������� ������" << endl;
	cout << "3- �������� ������" << endl;
	cout << "4- ����� ��  ����" << endl;
}

void sloMashineConsole::addMoneyMenu()
{
	system("cls");
	cout << "��� ������ �����: " << model.getBalance() << " Euro" << endl;
	cout << "������� ������" << endl;
	int m;
	cin >> m;
	model.addmoney(m);
	cout << "���������� ��������� �������!" << endl;
}

void sloMashineConsole::changeBetMEnu()
{
	system("cls");
	cout << "��� ������ �����: " << model.getBalance() << " Euro" << endl;
	cout << "���� ������ :"<<model.getBalance() << endl;
	cout << "������� ������ :" << endl;
	int b;
	cin >> b;
	model.setBet(b);
	cout << "������ �����������" << endl;
}
