#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Card {
public:
    enum Suit { SPADES, HEARTS, DIAMONDS, CLUBS };
    enum Rank { FLAG, ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    Card() {}
    Card(Suit suit, Rank rank) : suit(suit), rank(rank) {this->suit = suit; this->rank = rank;}

    void print() const {
        switch (rank) {
            case ACE: cout << "A"; break;
            case TWO: cout << "2"; break;
            case THREE: cout << "3"; break;
            case FOUR: cout << "4"; break;
            case FIVE: cout << "5"; break;
            case SIX: cout << "6"; break;
            case SEVEN: cout << "7"; break;
            case EIGHT: cout << "8"; break;
            case NINE: cout << "9"; break;
            case TEN: cout << "10"; break;
            case JACK: cout << "J"; break;
            case QUEEN: cout << "Q"; break;
            case KING: cout << "K"; break;
        }
        switch (suit) {
            case SPADES: cout << "S"; break;
            case HEARTS: cout << "H"; break;
            case DIAMONDS: cout << "D"; break;
            case CLUBS: cout << "C"; break;
        }
    }
    void set(Suit suit, Rank rank){
        this->suit = suit;
        this->rank = rank;
    }
    bool operator>(const Card& other) const {
        // if(other.rank == FLAG){
        //     return 1;
        // }
        return rank > other.rank;
    }

    bool operator==(const Card& other) const {
        return suit == other.suit && rank == other.rank;
    }


private:
    Suit suit;
    Rank rank;
};

class Player {
public:
    void addCard(const Card& card) {
        hand.push_back(card);
    }

    void removeCard(const Card& card) {
        auto it = find(hand.begin(), hand.end(), card);
        if (it != hand.end()) {
            hand.erase(it);
        }
    }

    void printHand() const {
        for (const auto& card : hand) {
            card.print();
            cout << " ";
        }
        cout << endl;
    }

    const vector<Card>& getHand() const {
        return hand;
    }

private:
    vector<Card> hand;
};

class Game {
public:
    void start() {
        deck.clear();
        generateDeck();
        shuffleDeck();
        dealCards();

        int currentPlayer = 0;
        int firstrun = 1;
        Card previousCard(Card::CLUBS,Card::FLAG);
        while (!players[currentPlayer].getHand().empty()) {
            Player& currentPlayerObj = players[currentPlayer];
            cout << "Player " << currentPlayer + 1 << "'s turn." << endl;

            bool canPlay = false;
            Card selectedCard;

            if (firstrun) {
                canPlay = true;
            } else {
                cout << "Previous card: ";
                previousCard.print();
                cout << endl;
            }

            // Check if any of the player's cards are greater than the previous card and in their hand
            for (const auto& card : currentPlayerObj.getHand()) {
                if (card > previousCard ) {
                    canPlay = true;
                    selectedCard = card;
                    break;
                }
            }

            if (canPlay) {
                cout << "Available cards: ";
                currentPlayerObj.printHand();

                cout << "Select a card to play: ";
                selectedCard.print();
                cout << endl;

                // Remove the selected card from the player's hand
                currentPlayerObj.removeCard(selectedCard);

                // Update the previous card
                previousCard = selectedCard;
            } else {
                cout << "Player " << currentPlayer + 1 << " has no cards to play." << endl;
                noPlayableCount++; // Increase the count of no playable turns
            }
            int flag = 0;
            if(players[currentPlayer].getHand().empty())
                break;
            // Check if no player can continue playing
            if (noPlayableCount >= maxNoPlayableCount) {
                if (maxCardPlayer != -1) {
                    currentPlayer = (currentPlayer+4-maxNoPlayableCount)%4;
                    cout << "Player " << currentPlayer + 1 << " continues to play." << endl;
                    noPlayableCount = 0; // Reset the count of no playable turns
                    flag = 1;
                    firstrun = 1;
                } else {
                    cout << "No player can continue playing. The game is over." << endl;
                    break; // Terminate the loop
                }
            }

            // Print remaining cards in hand
            cout << "Player " << currentPlayer + 1 << "'s hand: ";
            currentPlayerObj.printHand();
            if(!flag){
                firstrun = 0;
                currentPlayer = (currentPlayer + 1) % players.size(); // Move to the next player
            }else{
                previousCard.set(previousCard.CLUBS,previousCard.FLAG);
            }
            flag = 0;
            
        }
        cout<< currentPlayer + 1 << " wins" << endl;
    }

private:
    vector<Card> deck;
    vector<Player> players;
    int noPlayableCount = 0;
    const int maxNoPlayableCount = 3;
    Card maxCard;
    int maxCardPlayer = 3;

    void generateDeck() {
        for (int suit = Card::SPADES; suit <= Card::CLUBS; ++suit) {
            for (int rank = Card::ACE; rank <= Card::KING; ++rank) {
                Card card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
                deck.push_back(card);
            }
        }
    }

    void shuffleDeck() {
        random_device rd;
        mt19937 gen(rd());
        shuffle(deck.begin(), deck.end(), gen);
    }

    void dealCards() {
        const int numPlayers = 4;
        const int numCardsPerPlayer = 13;

        players.clear();
        for (int i = 0; i < numPlayers; ++i) {
            Player player;
            for (int j = 0; j < numCardsPerPlayer; ++j) {
                player.addCard(deck.back());
                deck.pop_back();
            }
            players.push_back(player);
        }
    }

    bool isCardInHand(const Player& player, const Card& card) {
        const vector<Card>& hand = player.getHand();
        auto it = find(hand.begin(), hand.end(), card);
        return it != hand.end();
    }


    bool isCardGeneratedByGame(const Card& card) {
        for (const auto& player : players) {
            if (isCardInHand(player, card)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Game game;
    game.start();

    return 0;
}
