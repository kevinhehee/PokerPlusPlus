#ifndef ROUND_HANDLER_H
#define ROUND_HANDLER_H

#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Pot.h"
#include "Display.h"
#include "Settings.h"

class RoundHandler {
    private:
        Display* display;
        Settings* settings;
        unsigned int dealerIndex;
        unsigned int roundNumber;
        Pot* pot;
        Deck* deck;
        vector<Card*> communityCards;

        bool startBettingStage(istream&, ostream&, vector<Player*>*, int);

        void blindInput(Player*, int);
        void cardInsert(int);

        bool call(ostream&, Player*);
        bool raise(istream&, ostream&, Player*);
        bool check(ostream&, Player*);
        bool fold(Player*);

        void clearScreen();
    public:
        RoundHandler();
        ~RoundHandler();
        unsigned int getRound() const;
        Pot* getPot() const;
        vector<Player*> lookForWinner(vector<Player*>*);
        vector<Player*> startRound(istream&, ostream&, vector<Player*>*);
        void resetRound(vector<Player*>*);
        void setSettings(Settings*);
};

#endif