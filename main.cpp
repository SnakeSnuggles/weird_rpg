#include <iostream>
#include <random>
#include <vector>

int bills = 0;
int burgers = 0;
int going_poop_in = -1;
char whatdo;
int platerhp = 100;

int random(int min, int max) {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

// Makes a input and stores it in a var, thanks chatgpt
char send_message(const std::string& message, char& inputVar) {
    std::cout << message;
    std::cin >> inputVar;
    return inputVar;
}

int enemy_count = random(1, 4);
std::vector<int> enemyhp(enemy_count);


int totalEnemyHP = 0;
void totalenemyHPcount()
{
    totalEnemyHP = 0;
    for (int i = 0; i <= enemy_count; i++)
    {
        totalEnemyHP += enemyhp[i];
    }
}


void battle()
{
    system("cls");
    enemy_count = random(1, 4);
    for (int i = 0; i <= enemy_count; i++)
    {
        std::cout << "Goblin " << i << "     ";
    }
    std::cout << '\n';

    for (int i = 0; i <= enemy_count; i++)
    {
        enemyhp[i] = random(5, 20);
        std::cout << " Hp: " << enemyhp[i] << "     ";
        totalenemyHPcount();
    }
    std::cout << '\n';
    std::cout << "You have: " << platerhp << '\n';
    
    bool showstat = false;

    while (totalEnemyHP != 0 && platerhp >= 0)
    {
        
        if(showstat)
        { 
            for (int i = 0; i <= enemy_count; i++)
            {
                if (enemyhp[i] > 0)
                {
                    std::cout << "Goblin " << i << "     ";
                }
                else
                {
                    continue;
                }

            }
            std::cout << '\n';
            for (int i = 0; i <= enemy_count; i++)
            {
                if (enemyhp[i] > 0)
                {
                    std::cout << " Hp: " << enemyhp[i] << "     ";

                }
                else
                {
                    continue;
                }
                
            }
            std::cout << '\n';
            std::cout << "You have: " << platerhp << '\n';
        }

        showstat = true;
        int choosenenemy;
        char atktype;
        int damage;
        int chance = random(1, 100);

        std::cout << "Which enemy would you like to attack?: "; 
        std::cin >> choosenenemy;

        if (choosenenemy > enemy_count || choosenenemy <= -1)
        {
            std::cout << "That enemy does not exist, please try agian \n";
            continue;
        }
        else
        {
            std::cout << "What type of attack small(s), medium(m), large(l)?: ";
            std::cin >> atktype;

            system("cls");
            switch (atktype)
            {
            case 's':
                damage = random(1, 5);
                if (chance > 4)
                {
                   enemyhp[choosenenemy] = enemyhp[choosenenemy] - damage;
                   std::cout << "You attacked Goblin " << choosenenemy << " doing " << damage << " damage" << '\n';
                   (enemyhp[choosenenemy] < damage) ? enemyhp[choosenenemy] = 0 : enemyhp[choosenenemy] -= damage;
                   totalenemyHPcount();
                   break;
                }
                else
                {
                    std::cout << "You failed your attack" << '\n';
                }
                break;
            case 'm':
                damage = random(20, 40);
                if (chance > 19)
                {
                    enemyhp[choosenenemy] =- damage;
                    std::cout << "You attacked Goblin " << choosenenemy << " doing " << damage << " damage" << '\n';
                    (enemyhp[choosenenemy] < damage) ? enemyhp[choosenenemy] = 0 : enemyhp[choosenenemy] -= damage;
                    totalenemyHPcount();
                    break;
                }
                else
                {
                    std::cout << "You failed your attack" << '\n';
                }
                break;
            case 'l':
                damage = random(60, 100);
                if (chance > 64)
                {
                    enemyhp[choosenenemy] = enemyhp[choosenenemy] - damage;
                    std::cout << "You attacked Goblin " << choosenenemy << " doing " << damage << " damage" << '\n';
                    (enemyhp[choosenenemy] < damage) ? enemyhp[choosenenemy] = 0 : enemyhp[choosenenemy] -= damage;
                    totalenemyHPcount();
                    break;
                }
                else
                {
                    std::cout << "You failed your attack" << '\n';
                }
                break;
            default:
                break;
            }

        }
        int total = 0;
        std::cout << "The goblins attack doing: ";
        for (int i = 0; i < enemy_count; i++)
        {
            
            int gobdmg = random(0, 5);
            platerhp = platerhp - gobdmg;

            total = total + gobdmg;
        }
        std::cout << total << '\n';

        
        std::cout << "Press enter";
        std::cin.get();
        std::cin.get();
        system("cls");
    }
    
    return;
}

void adventure()
{
    battle();

    for (int i = 0; i < enemy_count+1; i++)
    {
        bills++;
    }
    std::cout << "You have gained " << enemy_count+1 << " bills" << '\n';

}

void store()
{
    char ansforstore;
    send_message("Welcome to the store. Do you want to buy a burger (y) or (n)?: ", ansforstore);

    if (ansforstore == 'y' && bills >= 1) {
        std::cout << "You now have a burger\n";
        burgers++;
        bills--;
        std::cin.get();
        system("cls");
    }
    else {
        std::cout << "You do not have a 5 dollar bill!\n";
        std::cin.get();
    }
    system("cls");
}

void eat()
{
    if (burgers >= 1) {
        std::cout << "You have eaten the burger and now you feel the power of the random. You see: ";
        burgers--;
        going_poop_in = random(5, 15);
        platerhp += 20;

        if (random(0, 1) == 0) {
            std::cout << "heads\n";
        }
        else {
            std::cout << "tails\n";
        }
        std::cout << "You have gained 20hp" << '\n';
        std::cin.get();
        std::cin.get();
        system("cls");
    }
    else {
        std::cout << "You do not have a burger\n";
        std::cin.get();
        std::cin.get();
    }
}

void actions()
{
    std::cout << "Bills: " << bills << "\n";
    std::cout << "Burgers: " << burgers << "\n";
    std::cout << "Health: " << platerhp << "\n";
    send_message("Do you want to go on an adventure (a), go to store (s), or eat burger (b): ", whatdo);
    going_poop_in--;
}

void poo_poo()
{
    std::cout << "You have pooped \n";
    going_poop_in = -1;
}


int main() {

    while (platerhp > 0) {
        

        if (going_poop_in == 0)
        {
            poo_poo();
            continue;
        }
        else
        {
            actions();
        }

        switch (whatdo) {
            
            case 'a':
                adventure();
                break;

            case 's':
                store();
                break;


            case 'b':
                eat();
                break;

            default:
                std::cout << "Not valid please try agian" << '\n';
            }
    }
    return 0;
}
