// stockBrokerageSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class stock
{
public:
    string name;
    int quantity;
    stockOwner* owner;
    double marketPrice;

    //Default Constructors
    stock()
    {
        name = "Not_Initialized";
        int quantity = 1;
        owner = NULL;
        marketPrice = 1;

    }

    stock(string name, int inQuantity, stockOwner* inOwner, double inPrice)
    {
        quantity = inQuantity;
        owner = inOwner;
        marketPrice = inPrice;

    };

};

class stockOwner
{
public:
    int ownerId;
    double balance;
    vector<stock> ownedStock;

    //Default Constuctor
    stockOwner()
    {
        ownerId = -1;
        balance = 1000;
    }

    //Constructor
    stockOwner(int inID, double inBalance, vector<stock> inStock)
    {
        ownerId = inID;
        balance = inBalance;
        ownedStock = inStock;

    }

    //Use Case: Buy Stock
    int requestBuyStock(int listingID, stockExchange desiredLocation)
    {
        double total;
        total = desiredLocation.calculateTotal(listingID);

        if (balance >= total)
        {
            balance -= total;
            return confirmPurchase(listingID, desiredLocation, total);
        }
    }

    //Use Case: Buy Stock
    int confirmPurchase(int listingID, stockExchange desiredLocation, double total)
    {
        //Create Transaction
        return desiredLocation.createTransaction(listingID, this, total);
        
    }

    //Use Case: Sell Stock
    int requestSellStock(stock* reqStock, int quantity, stockExchange desiredLocation)
    {
        return desiredLocation.createNewListing(reqStock, quantity,this);
    }
};

class stockExchange
{ 
public:
    string name;
    vector<stockListing> exchangeListings;
    vector<transaction> pastTransactions;
    int listingIdGen = 0;

    stockExchange()
    {
        name = "Not_Initialized";
    }

    stockExchange(string inName)
    {
        name = inName;
    }

    double calculateTotal(int listingID)
    {
        double pricePerShare = exchangeListings[listingID].pricePerShare;
        int numShares = exchangeListings[listingID].numShares;
        return (pricePerShare * numShares);
    }

    int createTransaction(int listingID, stockOwner* buyer, double total)
    {
        //Get Transaction Info
        stockListing interestedListing= exchangeListings[listingID];
        stock* inStock = interestedListing.stockID;
        int inQuantity = interestedListing.numShares;
        stockOwner* inSeller = interestedListing.seller;

        //Create Transactions and add to past transactions
        transaction newTransaction(*inStock, inQuantity,  buyer, inSeller,  total);
        pastTransactions.push_back(newTransaction);

        //Transfer Ownership
        inStock->owner = buyer;
        return 1;
    }

    int createNewListing(stock* reqStock, int quantity, stockOwner* seller)
    {
        stockListing newListing(listingIdGen, reqStock, quantity, seller);
        listingIdGen++;
        return 1;

    }
};

class stockListing
{
public:
    int listingID;
    stock* stockID;
    int numShares;
    double pricePerShare;
    stockOwner* seller;

    stockListing(int inListing, stock* inID, int inNum, stockOwner* inSeller)
    {
        listingID = inListing;
        stockID = inID;
        numShares = inNum;
        seller = inSeller;
        pricePerShare = inID->marketPrice;
    }


};

class transaction
{
public:
    stock reqStock;
    int quantity;
    stockOwner* buyer;
    stockOwner* seller;
    double overallPrice;

    transaction(stock inStock, int inQuantity, stockOwner* inBuyer, stockOwner* inSeller, double inPrice)
    {
        reqStock = inStock;
        quantity = inQuantity;
        buyer = inBuyer;
        seller = inSeller;
        overallPrice = inPrice;

    }

};

int main()
{
    //Create Dummy Stocks
    //Create Dummy Owners
    //Create Dummy Stock Exchange
    //Create Dummy Transactions
}


*************************************************************************************************************


// stockBrokerageSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


class stockOwner;
class stock
{
public:
    string name;
    int quantity;
    stockOwner* owner = NULL;
    double marketPrice;

    //Default Constructors
    stock()
    {
        name = "Not_Initialized";
        int quantity = 1;
        owner = NULL;
        marketPrice = 1;

    }

    stock(string name, int inQuantity, stockOwner* inOwner, double inPrice)
    {
        quantity = inQuantity;
        owner = inOwner;
        marketPrice = inPrice;

    };

};


class stockExchange;
class stockOwner
{
public:
    int ownerId;
    double balance;
    vector<stock> ownedStock;

    //Default Constuctor
    stockOwner()
    {
        ownerId = -1;
        balance = 1000;
    }

    //Constructor
    stockOwner(int inID, double inBalance, vector<stock> inStock)
    {
        ownerId = inID;
        balance = inBalance;
        ownedStock = inStock;

    }

    //Use Case: Buy Stock
    int requestBuyStock(int listingID, stockExchange desiredLocation)
    {
        double total;
        total = desiredLocation.calculateTotal(listingID);

        if (balance >= total)
        {
            balance -= total;
            return confirmPurchase(listingID, desiredLocation, total);
        }
    }

    //Use Case: Buy Stock
    int confirmPurchase(int listingID, stockExchange desiredLocation, double total)
    {
        //Create Transaction
        return desiredLocation.createTransaction(listingID, this, total);
        
    }

    //Use Case: Sell Stock
    int requestSellStock(stock* reqStock, int quantity, stockExchange desiredLocation)
    {
        return desiredLocation.createNewListing(reqStock, quantity, this);
    }
};

class transaction;
class stockListing;
class stockExchange
{ 
public:
    string name;
    vector<stockListing> exchangeListings;
    vector<transaction> pastTransactions;
    int listingIdGen = 0;

    stockExchange()
    {
        name = "Not_Initialized";
    }

    stockExchange(string inName)
    {
        name = inName;
    }

    double calculateTotal(int listingID)
    {
        double pricePerShare = exchangeListings[listingID].pricePerShare;
        int numShares = exchangeListings[listingID].numShares;
        return (pricePerShare * numShares);
    }

    int createTransaction(int listingID, stockOwner* buyer, double total)
    {
        //Get Transaction Info
        stockListing interestedListing = exchangeListings[listingID];
        stock* inStock = interestedListing.stockID;
        int inQuantity = interestedListing.numShares;
        stockOwner* inSeller = interestedListing.seller;

        //Create Transactions and add to past transactions
        transaction newTransaction(*inStock, inQuantity,  buyer, inSeller,  total);
        pastTransactions.push_back(newTransaction);

        //Transfer Ownership
        inStock->owner = buyer;
        return 1;
    }

    int createNewListing(stock* reqStock, int quantity, stockOwner* seller)
    {

        stockListing newListing(int listingIdGen, stock* reqStock, int quantity, stockOwner* seller);
        listingIdGen++;
        return 1;

    }
};

class stockListing
{
public:
    int listingID;
    stock* stockID;
    int numShares;
    double pricePerShare;
    stockOwner* seller;

    stockListing(int inListing, stock* inID, int inNum, stockOwner* inSeller)
    {
        listingID = inListing;
        stockID = inID;
        numShares = inNum;
        seller = inSeller;
        pricePerShare = inID->marketPrice;
    }


};

class transaction
{
public:
    stock reqStock;
    int quantity;
    stockOwner* buyer;
    stockOwner* seller;
    double overallPrice;

    transaction(stock inStock, int inQuantity, stockOwner* inBuyer, stockOwner* inSeller, double inPrice)
    {
        reqStock = inStock;
        quantity = inQuantity;
        buyer = inBuyer;
        seller = inSeller;
        overallPrice = inPrice;

    }

};

int main()
{
    //Create Dummy Stocks
    //Create Dummy Owners
    //Create Dummy Stock Exchange
    //Create Dummy Transactions
}
