#include <string>
#include "../header/Card.h"

using namespace std;

Card::Card(int rank, const string &suit, const string &name, const string &suitSymbol)
{
    this->rank = rank;
    this->suit = suit;
    this->name = name;
    this->suitSymbol = suitSymbol;
}

int Card::getRank() const
{
    return this->rank;
}

string Card::getSuit() const
{
    return this->suit;
}

string Card::getSuitSymbol() const
{
    return this->suitSymbol;
}

string Card::getName() const
{
    return this->name;
}