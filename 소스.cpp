//C�� ��������, C++�� ��ü����

//��ü���� ���α׷����� ���ǿ� �����ϴ� �繰�� ���, �׸��� �׿� ���� �ൿ�� �ִ� �״�� ��üȭ��Ű�� ������ ���α׷���
//��ü�� �ϳ� �̻��� ���� ����(������)�� �ϳ� �̻��� �ൿ(���)���� �����Ǿ� �ִ�.

//��ü�������
//���� : Classname objname;
//���� : Classname*ptrObj=new Classname;

#include<iostream>
using namespace std;

class FruitSeller
{
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void Init(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSale()
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;
public:
	void Init(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& seller, int money)	//	�̷� ������ �ٸ� ��ü���� ��ȣ�ۿ��� �����ϴ�.
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuy()
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.Init(1000, 20, 0);
	FruitBuyer buyer;
	buyer.Init(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSale();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuy();
	return 0;
}