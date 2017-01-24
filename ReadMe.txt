Name: Daniel Finn
ID #: 434967

Lab 2: Decks and Hands

Design Notes:

The app is designed as described in the lab write-up in most places. There are two key differences noted below:

1.) Compiler-supplied deconstructors are used for Hand and Deck objects. This is okay because each member variable in these objects is a standard c++ object that has its own memory management (i.e. vector, string, int, etc) and as such a custom deconstructor is not needed.

2.) in the deck.shuffle() method, I do not supply a random engine to the std::random_shuffle() method. This is because I could not get default_random_engine to work. Instead, I call srand(unsigned(time(NULL))) to seed the runtime environments random generator and then call random_shuffle(). This means that each time shuffle is called, a new seed is used.

Errors and Warnings:

No errors or warnings during build in Visual Studio

Exit Codes:
	1 : ERROR_OPENING_FILE
        2 : TOO_MANY_COMMANDS
	3 : NO_SHUFFLE_FLAG (when argc == 3)
	4 : NO_COMMANDS_GIVEN
	5 : NO_FILE_NAME
	6 : DECK_TOO_SMALL

Testing:

All testing done using fulldeck.txt, which is a full deck of playing cards (52)
--------
commands testing
--------
Lab2PlayingCards.exe                               ==> (help message) %errorlevel% = 4
Lab2PlayingCards.exe -shuffle                      ==> (help message) %errorlevel% = 5
Lab2PlayingCards.exe fulldeck.txt hello            ==> (help message) %errorlevel% = 3
Lab2PlayingCards.exe fulldeck.txt -shuffle hello   ==> (help message) %errorlevel% = 2
Lab2PlayingCards.exe (non existent file.txt)  	   ==> (Error message) %errorlevel% = 1

^^^ All the above are expected results

------
output testing
------
Lab2PlayingCards.exe fulldeck.txt		==> (proper visual output) **always outputs same hands
Lab2PlyaingCards.exe fulldeck.txt -shuffle	==> (proper visual output) **Shuffled hands, order is properly (ran it many times)
Lab2PlayingCards.exe -shuffle fulldeck.txt	==> ^ same as above


^^^ All the above are expected results

Additional Notes:

Hand i : X X X X X : n  -> n is the poker_hand ranking of the hand represented as a number

Enclosed:
Lab2PlayingCards.cpp (main)
Card.cpp, Card.h     (Card struct / supporting functions)
Deck.cpp, Deck.h     (Deck class / supporting functions)
Hand.cpp, Hand.h     (Hand class / supporting functions)
fulldeck.txt	     (txt file containing a full deck of cards)


