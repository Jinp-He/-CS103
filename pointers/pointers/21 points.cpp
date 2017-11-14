
#include <sstream>
#include "21 points.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int[]);
void printCard(int);
int cardValue(int);
void printHand(int[], int);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
    for (int i = 1; i < 52; i++)
    {
            int randd;
            randd = rand() % i;
            int c = cards[randd];
            cards[randd] = cards[i];
            cards[i] = c;
    }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
    int typ = id / 13;
    string type,suit;
    switch (typ)
    {
        case 0:
            suit = "H";
            break;
        case 1:
            suit = "D";
            break;
        case 2:
            suit = "C";
            break;
        case 3:
            suit = "S";
            break;
    }
    typ = id % 13;
    switch (typ)
    {
        case 0:
            type = "A";
            break;
        case 1:
            type = "2";
            break;
        case 2:
            type = "3";
            break;
        case 3:
            type = "4";
            break;
        case 4:
            type = "5";
            break;
        case 5:
            type = "6";
            break;
        case 6:
            type = "7";
            break;
        case 7:
            type = "8";
            break;
        case 8:
            type = "9";
            break;
        case 9:
            type = "10";
            break;
        case 10:
            type = "J";
            break;
        case 11:
            type = "Q";
            break;
        case 12:
            type = "K";
            break;
    }
    string types = suit + "-" + type;
    cout << types;
    
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
    int cardSuit = id % 13;
    switch (cardSuit)
    {
        case 0:
            return 11;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 10;
        case -1:
            return 0;
    }
    return 0;
    
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
    for (int i = 0; i < numCards; i++)
    {
        printCard(hand[i]);
        cout << ' ';
    }
    cout << endl;
}

/**
 * Should return the total score of the provided hand.
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
    bool Ace_exist = false;
    int sum_value = 0;
    for (int i = 0; i < numCards; i++)
    {
        sum_value += cardValue(hand[i]);
        if (cardValue(hand[i]) == 11)
            Ace_exist = true;
    }
    if (sum_value <= 21)
        return sum_value;
    else
        if (Ace_exist)
        {
            sum_value -= 10;
            return sum_value;
        }
        else
            return sum_value;
    
    
    return 0;
}
void compare(int phand[],int dhand[],int playerind,int dealind)
{
    int pvalue = getBestScore(phand, playerind), dvalue = getBestScore(dhand, dealind);
    if (pvalue > dvalue)
    {
        printHand(phand, playerind);
        printHand(dhand, dealind);
        cout << "win: " << pvalue << " " << dvalue << endl;
    }
    if (pvalue == dvalue)
    {
        printHand(phand, playerind);
        printHand(dhand, dealind);
        cout << "tie " << pvalue << " " << dvalue << endl;
    }
    if (pvalue < dvalue)
    {
        printHand(phand, playerind);
        printHand(dhand, dealind);
        cout << "lose: " << pvalue << " " << dvalue << endl;
    }
}
/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
    //---------------------------------------
    // Do not change this code -- Begin
    //---------------------------------------
    if(argc < 2){
        cout << "Error - Please provide the seed value." << endl;
        return 1;
    }
    int seed = atoi(argv[1]);
    srand(seed);
    char command;
    
    do
    {
        int cards[52];
        int dhand[9] = {0};
        int phand[9] = {0};
        int cardind = 0, dealind = 0, playerind = 0;
        // refill cards[]
        for (int i = 0; i <=51; i++)
        {
            cards[i] = i;
        }
        // initialize
        for (int i = 1; i <= 8; i++)
        {
            dhand[i] = -1;
        }
        for (int i = 1; i <= 8; i++)
        {
            phand[i] = -1;
        }
        shuffle(cards);
        dhand[dealind] = cards[cardind];
        cardind ++;
        dealind ++;
        phand[playerind] = cards[cardind];
        cardind ++;
        playerind ++;
        dhand[dealind] = cards[cardind];
        cardind ++;
        dealind ++;
        phand[playerind] = cards[cardind];
        cardind ++;
        playerind ++;
        //show the cards in the first place
        cout << "dealer: ? ";
        printCard(dhand[dealind-1]);
        cout << endl;
        cout << "player: ";
        printHand(phand, playerind);
        // if player has 21;
        while ((getBestScore(phand, playerind) <= 21) && (getBestScore(dhand, dealind) <= 21))
        {
            cout << " Type 'h' to hit and 's' to stay: " << endl;
            cin >> command;
            // if player hit
            if (command == 'h')
            {
                phand[playerind] = cards[cardind];
                cardind ++;
                playerind ++;
                if (getBestScore(phand, playerind) > 21)
                {
                    cout << "player: ";
                    printHand(phand, playerind);
                    cout << "Player Busted!" << endl;
                    cout << "lose: " << getBestScore(phand, playerind)<< " " << getBestScore(dhand, dealind) << endl;
                    break;
                }
                else if (getBestScore(phand, playerind) == 21)
                {
                    while (getBestScore(dhand, dealind) <= 17)
                    {
                        dhand[dealind] = cards[cardind];
                        cardind ++;
                        dealind ++;
                    }
                    if (getBestScore(dhand, dealind) <= 21)
                    {
                        printHand(phand, playerind);
                        compare(phand,dhand,playerind,dealind);
                        break;
                    }
                    else
                    {
                        cout << "dealer: ";
                        printHand(dhand, dealind);
                        cout << "Dealer Busted" << endl;
                        cout << "win: " << getBestScore(phand, playerind) << " " << getBestScore(dhand, dealind) << endl;
                        break;
                    }
                }
                else
                {
                    dhand[dealind] = cards[cardind];
                    cardind ++;
                    dealind ++;
                    if (getBestScore(dhand, dealind) > 21)
                    {
                        cout << "dealer: ";
                        printHand(dhand, dealind);
                        cout << "Dealer Busted" << endl;
                        cout << "win: " << getBestScore(phand, playerind) << " " << getBestScore(dhand, dealind) << endl;
                        break;
                    }
                }
            }
            // if player stay
            if (command == 's')
            {
                while (getBestScore(dhand, dealind) <= 17)
                {
                    dhand[dealind] = cards[cardind];
                    cardind ++;
                    dealind ++;
                }
                if (getBestScore(dhand, dealind) <= 21)
                {
                    compare(phand,dhand,playerind,dealind);
                    break;
                }
                else
                {
                    cout << "dealer: ";
                    printHand(dhand, dealind);
                    cout << "Dealer Busted" << endl;
                    cout << "win: " << getBestScore(phand, playerind) << " " << getBestScore(dhand, dealind) << endl;
                    break;
                }
            }
        }
        cout << "Wanna play again? Y/N" << endl;
        cin >> command;
    }
    while(command == 'y');
    return 0;
}


