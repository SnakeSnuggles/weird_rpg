#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <sstream>
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
std::vector<int> enemyhp(5);


int totalEnemyHP = 0;
void totalenemyHPcount()
{
    totalEnemyHP = 0;
    for (int i = 0; i <= enemy_count; i++)
    {
        totalEnemyHP += enemyhp[i];
    }
}


void battlegen()
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

        if (showstat)
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
                    enemyhp[choosenenemy] = -damage;
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
            if (enemyhp[i] == 0)
            {
                continue;
            }
            else
            {
                platerhp -= gobdmg;
                total += gobdmg;
            }



        }
        std::cout << total << '\n';


        std::cout << "Press enter";
        std::cin.get();
        std::cin.get();
        system("cls");
    }
    for (int i = 0; i < enemy_count + 1; i++)
    {
        bills++;
    }
    std::cout << "You have gained " << enemy_count + 1 << " bills" << '\n';
    return;
}

void Adventure()
{
    battlegen();
}

void Store()
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

void Eat()
{
    system("cls");
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

    }
    else {
        std::cout << "You do not have a burger\n";

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


sf::Text createText(const std::string& content, sf::Font& font, unsigned int fontSize,
    const sf::Color& color, const sf::Vector2f& position) {
    sf::Text text, var;
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(fontSize);
    text.setFillColor(color);
    text.setPosition(position);

    return text;
}

class Button {
public:
    Button(sf::Vector2f position, sf::Vector2f size, const std::string& text, sf::Font& font,
        const sf::Color& backgroundColor = sf::Color(128, 128, 128), const sf::Color& textColor = sf::Color::White)
        : position(position), size(size), textString(text), font(font),
        backgroundColor(backgroundColor), textColor(textColor) {

        background.setSize(size);
        background.setPosition(position);
        background.setFillColor(backgroundColor);

        buttonText.setString(text);
        buttonText.setFont(font);
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(textColor);

        sf::FloatRect textRect = buttonText.getLocalBounds();
        buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        buttonText.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(buttonText);
    }

    bool isMouseOver(const sf::RenderWindow& window) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::FloatRect bounds(position.x, position.y, size.x, size.y);
        return bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    }

    void setOnClick(std::function<void()> onClick) {
        onClickFunction = onClick;
    }

    void handleEvent(const sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            if (isMouseOver(window) && onClickFunction) {
                onClickFunction();
            }
        }
    }

    void setText(const std::string& text) {
        textString = text;
        buttonText.setString(text);
        sf::FloatRect textRect = buttonText.getLocalBounds();
        buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        buttonText.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
    }

private:
    sf::Vector2f position;
    sf::Vector2f size;
    std::string textString;
    sf::Font& font;
    sf::Color backgroundColor;
    sf::Color textColor;
    sf::RectangleShape background;
    sf::Text buttonText;
    std::function<void()> onClickFunction;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Weird RPG");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\User\\OneDrive\\Desktop\\visualsrpg\\gui\\gamegui\\x64\\Release\\arial.ttf")) {
        // Handle font loading error
        return 1;
    }

    Button adventure(sf::Vector2f(150, 250), sf::Vector2f(150, 150), "Adventure", font);
    Button store(sf::Vector2f(350, 250), sf::Vector2f(150, 150), "Store", font);
    Button eat(sf::Vector2f(550, 250), sf::Vector2f(150, 150), "Eat", font);

    adventure.setOnClick([&]() {
        Adventure();
        });
    store.setOnClick([&]() {
        Store();
        });
    eat.setOnClick([&]() {
        Eat();
        });


    sf::RectangleShape statseparator;
    statseparator.setSize(sf::Vector2f(5000, 10));
    statseparator.setPosition(0, 500);
    statseparator.setFillColor(sf::Color::Black);

    sf::RectangleShape hpboundingbox;
    sf::RectangleShape bugerboundingbox;
    sf::RectangleShape billboundingbox;



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            adventure.handleEvent(event, window);
            store.handleEvent(event, window);
            eat.handleEvent(event, window);
        }

        std::stringstream hpstring;
        hpstring << "HP: " << platerhp;

        sf::Text hpText = createText(hpstring.str(), font, 24, sf::Color::Black, sf::Vector2f(50, 540));
        hpboundingbox.setPosition(5, 515);
        hpboundingbox.setSize(sf::Vector2f(200, 80));
        hpboundingbox.setOutlineColor(sf::Color::Black);
        hpboundingbox.setOutlineThickness(2);

        std::stringstream burgerstring;
        burgerstring << "Burgers: " << burgers;

        sf::Text burgerText = createText(burgerstring.str(), font, 24, sf::Color::Black, sf::Vector2f(250, 540));
        bugerboundingbox.setPosition(210, 515);
        bugerboundingbox.setSize(sf::Vector2f(200, 80));
        bugerboundingbox.setOutlineColor(sf::Color::Black);
        bugerboundingbox.setOutlineThickness(2);

        std::stringstream billstring;
        billstring << "Bills: " << bills;

        sf::Text billText = createText(billstring.str(), font, 24, sf::Color::Black, sf::Vector2f(450, 540));
        billboundingbox.setPosition(415, 515);
        billboundingbox.setSize(sf::Vector2f(200, 80));
        billboundingbox.setOutlineColor(sf::Color::Black);
        billboundingbox.setOutlineThickness(2);

        window.clear(sf::Color::White);
        adventure.draw(window);
        store.draw(window);
        eat.draw(window);
        window.draw(statseparator);
        window.draw(hpboundingbox);
        window.draw(bugerboundingbox);
        window.draw(billboundingbox);
        window.draw(hpText);
        window.draw(burgerText);
        window.draw(billText);
        window.display();
    }

    return 0;
}
