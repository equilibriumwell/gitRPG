#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>


sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float m = sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));

    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;

}

int main()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

    std::vector<sf::RectangleShape> bullets;
    sf::RectangleShape bullet(sf::Vector2f(50, 20));
   
    float bulletSpeed = 1000.0f;

    sf::Clock clock;
    float lapseTime = 0;

    //sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");

    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    if (enemyTexture.loadFromFile("Assets/Player/Textures/Male.png"))

    {

        enemySprite.setTexture(enemyTexture);
        enemySprite.setPosition(sf::Vector2f(1200, 700));

        int indexX = 5;
        int indexY = 1;

        int tileWidth = enemyTexture.getSize().x / 9;
        int tileheight = enemyTexture.getSize().y / 4;

        sf::IntRect textureRect(indexX * tileWidth, indexY * tileheight, tileheight, tileWidth);

        enemySprite.setTextureRect(textureRect);
        std::cout << "Enemy image loaded!" << std::endl;
    }
    else
    {
        std::cout << "Enemy image failed to load!" << std::endl;
    }




    sf::Texture playerTexture;
    sf::Sprite playerSprite;



   

   

  

    if (playerTexture.loadFromFile("Assets/Player/Textures/Bones.png"))

    {
        std::cout << "Player loaded" << std::endl;
        playerSprite.setTexture(playerTexture);


        int indexX = 1;
        int indexY = 1;

        int tileWidth = playerTexture.getSize().x / 9;
        int tileheight = playerTexture.getSize().y / 4;

        sf::IntRect textureRect(indexX * tileWidth, indexY * tileheight, tileheight, tileWidth);
        playerSprite.setPosition(sf::Vector2f(0, 0));
        playerSprite.setTextureRect(textureRect);
    }
    else
    {
        std::cout << "Player failed to load!" << std::endl;
    }
        
    sf::Vector2f bulletDirection = enemySprite.getPosition() - bullet.getPosition();

    //bullet.setPosition(playerSprite.getPosition());

    bulletDirection = NormalizeVector(bulletDirection);
        /*  
  * 
 
    sf::CircleShape shit(50.0f);

    shit.setFillColor(sf::Color::Red);
    shit.setPosition(sf::Vector2f(100, 100));
    shit.setOutlineThickness(10);
    shit.setOutlineColor(sf::Color::Blue);

    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setPosition(sf::Vector2f(100, 100));

    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOrigin(rectangle.getSize() / 2.f);
   rectangle.setRotation(45);


  sf::CircleShape triangle(80.f, 3);
  triangle.setPosition(sf::Vector2f(30, 500));

   sf::CircleShape octagon(80.f, 8);
    octagon.setPosition(sf::Vector2f(30,300));

   sf::CircleShape square(80.f, 4);*/
    
   //main game loop (will keep game running)
    while (window.isOpen())
    {
        //event loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       /* sf::Vector2f bulletPosition = bullet.getPosition();*/
        //bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed* lapseTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            //sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(0, 0);
        }
        

        window.clear(sf::Color::Black);
  /*      window.draw(shit);
        window.draw(rectangle);
        window.draw(triangle);
       window.draw(octagon);*/
        window.draw(playerSprite);
        window.draw(enemySprite);
        window.draw(bullet);
        window.display();

        lapseTime = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}


