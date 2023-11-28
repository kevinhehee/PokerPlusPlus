#include "../header/RoundHandler.h"


using namespace std;


RoundHandler::RoundHandler()
{
    this->dealerIndex = 0;
    this->deck = new Deck();
    this->pot = new Pot();
}

void RoundHandler::startRound(vector<Player*> playerList)
{

    // for (int i = 0; i < playerList.size(); i++)
    // {
    //     // playerList[i]->
    //     Player* currentPlayer;
    // }

    // Deals two cards to each player
    for (Player* currentPlayer: playerList)
    {
        Hand* currentHand = currentPlayer->getHand();

        for (int i = 0; i < 2; i++)
        {
            Card* nextCard = this->deck->nextCard();
            currentHand->addCard(nextCard);
        }
    }

    // Deals the first three cards to the communityCards
}

void RoundHandler::call(ostream& out, Player* currPlayer) {

    // if player has no chips
    if (currPlayer->getBalance() <= 0)
    {
        return;
    }

    // If the current highest bet is too much for the player to afford
    if (pot->highestBet - currPlayer->getCurrentBet() > currPlayer->getBalance()) {
        out << "ALL IN." << endl;
        
        // add to pot
        pot->addToPot(currPlayer->getBalance());

        // subtract from player balance
        currPlayer->setCurrentBet(currPlayer->getBalance() + currPlayer->getCurrentBet());

        out << "Current balance: " << currPlayer->getBalance() << endl; // should be 0
    }
    else {  // typical bet
        
        // add to pot
        pot->addToPot(pot->highestBet - currPlayer->getCurrentBet());
        
        // subtract from player balance
        currPlayer->setCurrentBet(pot->highestBet);

        out << "Current balance: " << currPlayer->getBalance() << endl;
    }
}


bool RoundHandler::raise(istream& is, ostream& out, Player* p) {
    int raiseTo;
    out << "How much would you like to raise?" << endl;
    // is >> raiseTo;
    // raise has to be bigger than highestBet
    while(!(is >> raiseTo)) {
        is.clear();
        is.ignore(256, '\n');
        out << "Please enter a valid number." << endl;
    } 

    if(raiseTo > pot->getHighestBet()) {
        p->setCurrentBet(raiseTo);
        pot->addToPot(raiseTo - p->getCurrentBet());
    }
    else {
        out << "Can't raise. " << raiseTo << " isn't the highest bet." << endl;
        return false;
    }
    return true;
    
}