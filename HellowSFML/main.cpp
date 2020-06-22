#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    // VideoMode : length, width
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Ann 的第一個 SFML window"); // L : wide char // system font
    
    // Create a graphical text to display
    // content font : search font, copy and paste to the current location
    // chinese font : https://www.freechinesefont.com/category/traditional-chinese/
    sf::Font font;
    if (!font.loadFromFile("STHeiti Light.ttc"))   
        return EXIT_FAILURE;
    sf::Text text(L"Hello 你好", font, 50);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

// compile : g++ main.cpp -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
