#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<string>


using namespace std;

static bool bidStart = false;
static int itemCount = 0;

struct Items
{

	string name;
	int number;
	int resPrice;
	int highestPrice = 0;
	int buyerNo;

};

void displayItems(Items items[])
{
	for (int i = 0; i < itemCount; i++)
	{
		cout << "Item Number: " << items[i].number << endl;
		cout << "Item Name: " << items[i].name << endl;
		cout << "Item's Highest Bid Yet: " << items[i].highestPrice << endl << endl;
	}

}

void itemEntry(Items items[])
{



	items[0].number = 1;
	items[0].name = "OIL FOSSIL";
	items[0].resPrice = 12000;
	items[0].highestPrice = 0;

	items[1].number = 2;
	items[1].name = "ANTIQUE VASE";
	items[1].resPrice = 8000;
	items[1].highestPrice = 0;

	items[2].number = 3;
	items[2].name = "VINTAGE WATCH";
	items[2].resPrice = 6000;
	items[2].highestPrice = 0;

	items[3].number = 4;
	items[3].name = "RARE COIN COLLECTION";
	items[3].resPrice = 10000;
	items[3].highestPrice = 0;

	items[4].number = 5;
	items[4].name = "SCULPTURE";                      
	items[4].resPrice = 7000;
	items[4].highestPrice = 0;

	items[5].number = 6;
	items[5].name = "DIAMOND NECKLACE";
	items[5].resPrice = 12000;
	items[5].highestPrice = 0;

	items[6].number = 7;
	items[6].name = "CLASSIC CAR";
	items[6].resPrice = 150000;
	items[6].highestPrice = 0;

	items[7].number = 8;
	items[7].name = "RARE BOOKS";
	items[7].resPrice = 4000;
	items[7].highestPrice = 0;

	items[8].number = 9;
	items[8].name = "VINTAGE WINE";
	items[8].resPrice = 3000;
	items[8].highestPrice = 0;

	items[9].number = 10;
	items[9].name = "ART DECO LAMP";
	items[9].resPrice = 2000;
	items[9].highestPrice = 0;

	itemCount += 10;


	

}


void bidding(Items items[])
{


	int itemNo, buyerNum, iter = -1, currBid;
	displayItems(items);

	cout << "Enter Buyer Number" << endl;
	cin >> buyerNum; cout << endl;
	cout << "Enter The Item Number" << endl;
	cin >> itemNo; cout << endl;

	for (int i = 0; i < itemCount; i++)
	{
		if (itemNo == items[i].number)
		{
			iter = i;
			break;
		}
		else continue;
	}

	if (iter != -1)
	{
		cout << "Enter Your Bid For Item No. " << items[iter].number << " With Current Highest Bid: " << items[iter].highestPrice << endl;
		cin >> currBid;
		if (currBid > items[iter].highestPrice)
		{
			items[iter].highestPrice = currBid;
			items[iter].buyerNo = buyerNum;
			cout << "The Bid By Buyer No. " << buyerNum << " Against The Item No. " << items[iter].number << " Has Been Successfully Placed For $" << currBid << endl << endl;
		}
		else
		{
			cout << "Your Bid Is Not Higher Than Current Bid, Returning to Main Menu..." << endl << endl;
		}

	}
	else
	{
		cout << "Item Number Does Not Exist" << endl << endl;
	}

}

void endOfAuction(Items items[])
{

	int sold = 0, unsold = 0, noBid = 0, totalFees = 0;

	for (int i = 0; i < itemCount; i++)
	{
		if (items[i].highestPrice > items[i].resPrice)
		{
			sold++;
		}
		else if (items[i].highestPrice < items[i].resPrice && items[i].highestPrice != 0)
		{
			unsold++;
		}
		else
		{
			noBid++;
		}
	}

	cout << "No. Of Sold Items: " << sold << endl << endl;
	cout << "No. of Unsold Items: " << unsold << endl << endl;
	cout << "No. of Items With No Bids: " << noBid++ << endl << endl << endl;

	cout << "Details Of Sold Items: " << endl << endl;
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i].highestPrice > items[i].resPrice)
		{
			totalFees += (items[i].highestPrice * 0.1);
			cout << "Item Number: " << items[i].number << endl;
			cout << "Item Name: " << items[i].name << endl;
			cout << "Item's Price Sold For: $" << items[i].highestPrice << endl;
			cout << "Item's Fee: $" << items[i].highestPrice * 0.1 << endl;
			cout << "Item's Reserve Price: $" << items[i].resPrice << endl;
			cout << "Item's Buyer's No: " << items[i].buyerNo << endl << endl;
		}
		else continue;
	}
	cout << "Details Of Unsold Items That Did Not Reach Reserve Price: " << endl << endl;
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i].highestPrice < items[i].resPrice && items[i].highestPrice != 0)
		{

			cout << "Item Number: " << items[i].number << endl;
			cout << "Item Name: " << items[i].name << endl;
			cout << "Item's Highest Bid: $" << items[i].highestPrice << endl;
			cout << "Item's Reserve Price: $" << items[i].resPrice << endl << endl;
		}
		else continue;
	}

	cout << "Details Of Unsold Items That Did Not Have Any Bidders: " << endl << endl;
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i].highestPrice == 0)
		{
			cout << "Item Number: " << items[i].number << endl;
			cout << "Item Name: " << items[i].name << endl;
			cout << "Item's Highest Bid: $" << items[i].highestPrice << endl;
			cout << "Item's Reserve Price: $" << items[i].resPrice << endl << endl;

		}
		else continue;
	}

	cout << "Total Fee's For Auction: $" << totalFees << endl << endl;




}



int main()
{
	Items items[10];

	int choice = 0;


	do
	{
		cout << "        Welcome to The Annual Auction" << endl << endl << endl;
		cout << "view Items (1)" << endl << endl;
		cout << "Buyer Bidding (2)" << endl << endl;
		cout << "End Auction (3)" << endl << endl << endl << endl;
		cin >> choice;

		if (choice == 1)
		{

			if (!bidStart)
			{
				itemEntry(items);
				displayItems(items);

			}
			
		}
		else if (choice == 2)
		{
			if (!(itemCount < 10))
			{
				bidStart = true;
				bidding(items);
			}
			else
			{
				cout << "Bidding Cannot be Started as Their Are Less than 10 Items" << endl << endl;
			}

		}
		else if (choice == 3)
		{
			endOfAuction(items);
		}




	} while (choice != 3);




	return 0;
}