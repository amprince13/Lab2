#pragma once
#include "stdafx.h"
#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Deck.h"

class Hand {
	friend ostream &operator<<(ostream &out, Hand &h);
	friend Hand &operator<<(Hand &h, Deck &d);
public:
	Hand();
	Hand(const Hand &);
	Hand & operator=(const Hand &n);
	 int size() const;
	bool operator==( const Hand &n) const ;
	bool operator<(const Hand &n) const;
	string toString();
	Card getCardAtPosition(unsigned int n) const;
	int getRank() const;
private:
	vector<Card> h;
};
enum handRank { HC, OP, TP, TOK, S, F, FH, FOK, SF };
bool poker_rank(Hand h1, Hand h2);
Card organizeOnePair(const Hand &h);	// returns a new card representing the highest member of the pair
vector<int> twoPairLocation(const Hand &h); // returns vector containing location of important cards, see method
Card getThreePairRank(const Hand &h);