//C는 절차지향, C++는 객체지향

//객체지향 프로그래밍은 현실에 존재하는 사물과 대상, 그리고 그에 따른 행동을 있는 그대로 실체화시키는 형태의 프로그래밍
//객체는 하나 이상의 상태 정보(데이터)와 하나 이상의 행동(기능)으로 구성되어 있다.

//객체생성방식
//정적 : Classname objname;
//동적 : Classname*ptrObj=new Classname;

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
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
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
	void BuyApples(FruitSeller& seller, int money)	//	이런 식으로 다른 객체와의 상호작용이 가능하다.
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuy()
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.Init(1000, 20, 0);
	FruitBuyer buyer;
	buyer.Init(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSale();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuy();
	return 0;
}