#include <iostream>
using namespace std;

class boss 
{
    int health;
public:
    boss()
    {
        health = 50;
    };
    void decreaseHealth(int attackDamage)
    {
        this->health = health - attackDamage;
    }
    int getHealth()
    {
        return this->health;
    }
};

class player 
{
    int health;
public:
    player()
    {
        health = 50;
    };
    void decreaseHealth(int attackDamage)
    {
        this->health = health - attackDamage;
    }
    int getHealth()
    {
        return this->health;
    }
};

int main() {
        boss boss1 = boss();
        player player1 = player(); 
        int attackChoice;
        int attacks[3] = {20, 30, 50};

        cout << "Boss has appeared" << endl;
        cout << "enter attack, 1, 2 or 3" << endl;
        while(!(cin>> attackChoice) || attackChoice > 3 || attackChoice < 1)
        {
            cout << "Invalid attack/n";
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please Re-Enter attack: ";
        }
        boss1.decreaseHealth(attacks[attackChoice - 1]);
        cout << "Boss Health: " << boss1.getHealth() << endl;
        if(boss1.getHealth() == 0)
        {
            cout << "You Win!\n";
        }
        else 
        {
            cout << "You lose:(\n";
            player1.decreaseHealth(50);
            cout << "Player health: " << player1.getHealth() << endl;
        }
}

