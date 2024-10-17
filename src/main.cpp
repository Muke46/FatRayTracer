#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <cmath>

#include "Core/Vector.h"
#include "Core/Ray.h"
#include "Core/Triangle.h"
#include "Core/Sphere.h"
#include "Render/PixelBuffer.h"
#include "Utils/Color.h"
#include "Render/Camera.h"
#include <iostream>

int main()
{
    const unsigned int width = 800;
    const unsigned int height = 600;

    auto window = sf::RenderWindow{{width, height}, "CMake SFML Project"};
    window.setFramerateLimit(144);

    // Pick a font
    sf::Font font;
    font.loadFromFile("/home/dennis/Projects/FatRayTracer/assets/fonts/Open_Sans/OpenSans-VariableFont_wdth,wght.ttf");

    // FPS Counter text element
    sf::Text fpsCounter;
    fpsCounter.setFont(font);
    fpsCounter.setCharacterSize(24);
    fpsCounter.setFillColor(sf::Color::Red);

    // FPS Counter variables
    sf::Clock clock;
    int framecount = 0;           // Used to count the frames between two intervals
    float updateInterval = 0.01f; // Time between FPS updates
    float elapsedTime = 0.0f;     // Used to count the elapsed time from the last FPS print

    // Create a pixel buffer
    PixelBuffer pixelBuffer(width, height);

    // Create an SFML texture to display the pixel buffer
    sf::Texture texture;
    texture.create(width, height);

    // Variables to convert the pixelBuffer in a format accepted from SFML

    // SFML Color vector
    std::vector<sf::Color> pixels_sfml;
    pixels_sfml.resize(width * height);

    // Temp color vector
    std::vector<Color> pixels;
    pixels.resize(width * height);

    // Create a vector to store pointers to SceneObject
    std::vector<std::shared_ptr<SceneObject>> objects;

    Vector3 v0 = Vector3(10.0f, 10.0f, 0.0f);
    Vector3 v1 = Vector3(20.0f, 10.0f, 0.0f);
    Vector3 v2 = Vector3(10.0f, 20.0f, 0.0f);
    Triangle3 triangle0 = Triangle3(v1, v0, v2);
    Triangle3 triangle1 = Triangle3(v0, v1, v2);

    // Vector3 v3 = Vector3(250.0f, 100.0f, 10.0f);
    // Vector3 v4 = Vector3(250.0f, 250.0f, 10.0f);
    // Vector3 v5 = Vector3(100.0f, 250.0f, 10.0f);
    // Triangle3 triangle2 = Triangle3(v3, v4, v5);

    // scene.push_back(triangle2);

    Sphere sphere0 = Sphere(Vector3(0.0f, 0.0f, 30.0f) ,10.f);
    Sphere sphere1 = Sphere(Vector3(-30.0f, 0.0f, 10.0f), 10.0f);

    objects.push_back(std::make_shared<Sphere>(sphere0));
    objects.push_back(std::make_shared<Sphere>(sphere1));
    objects.push_back(std::make_shared<Triangle3>(triangle0));
    objects.push_back(std::make_shared<Triangle3>(triangle1));
    

    // Create a camera
    Vector3 cameraOrigin = Vector3(0.0f, 0.0f, -150.0f);
    Vector3 cameraDirection = Vector3(0.0f, 0.0f, 1.0f);
    Camera3 camera(cameraOrigin, cameraDirection, 15.0f, 10.0f, 10.0f);

    // Camera settings
    sf::Text CameraText;
    CameraText.setFont(font);
    CameraText.setCharacterSize(24);
    CameraText.setFillColor(sf::Color::Red);
    CameraText.setPosition(sf::Vector2f(10, height - 24 * 4));


int iterations = 0;
int iterationsLimit = 100;
    // Main loop
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) // Check if a key is pressed
            {

                // Check if 'Control' is held down and 'C' is pressed
                if (event.key.code == sf::Keyboard::C && event.key.control)
                {
                    // Action for when 'Ctrl+C' is pressed
                    window.close();
                }

                pixelBuffer.clearBuffer();
                iterations = 0;

                if (event.key.code == sf::Keyboard::A) 
                {
                    camera.origin.x -= 5.0f;
                }
                if (event.key.code == sf::Keyboard::D) 
                {
                    camera.origin.x += 5.0f;
                }
                if (event.key.code == sf::Keyboard::E) 
                {
                    camera.origin.y += 5.0f;
                }
                if (event.key.code == sf::Keyboard::Q) 
                {
                    camera.origin.y -= 5.0f;
                }
                if (event.key.code == sf::Keyboard::W) 
                {
                    camera.origin.z += 1.0f;
                }
                if (event.key.code == sf::Keyboard::S) 
                {
                    camera.origin.z -= 1.0f;
                }

                if (event.key.code == sf::Keyboard::F) 
                {
                    camera.focalLength -= 0.1f;
                    if (camera.focalLength < 0.1f) {
                        camera.focalLength = 0.1f;
                    }
                }
                if (event.key.code == sf::Keyboard::G) 
                {
                    camera.focalLength += 0.1f;
                }


                // You can add other keys in a similar way
                if (event.key.code == sf::Keyboard::Escape) // Example: check for 'Escape' key
                {
                    window.close(); // Close the window when 'Escape' is pressed
                }
            }
        }

        // pixelBuffer.clearBuffer();
        if (iterations < iterationsLimit) {
        camera.render(pixelBuffer, objects);
        iterations++;
        }
        if (iterations == iterationsLimit - 1){
            std::cout << "Done" << std::endl;
        }

        // Convert the pixel buffer to SFML
        pixels = pixelBuffer.getPixels(); // Get the colors

        for (unsigned int y = 0; y < height; ++y)
        {
            for (unsigned int x = 0; x < width; ++x)
            {
                // Create a sf::Color object with the render output, and assign it to pixels_sfml
                Color tmp = pixels[y * width + x];
                pixels_sfml[y * width + x] = sf::Color(tmp.r, tmp.g, tmp.b);
            }
        }

        // Update the texture with the pixel buffer data
        texture.update(reinterpret_cast<const sf::Uint8 *>(pixels_sfml.data()));

        // FPS Counter
        framecount++;
        elapsedTime += clock.restart().asSeconds();

        if (elapsedTime >= updateInterval)
        {
            char buffer[10];
            snprintf(buffer, sizeof(buffer), "%.2f", framecount / updateInterval); // Format FPS with 2 decimal places                framecount = 0;
            fpsCounter.setString(buffer);
            framecount = 0;
            elapsedTime = 0.0f;
        }

        // Camera settings
        char buffer[100];
        sprintf(buffer, "Camera position: x:%.2f, y:%.2f, z:%.2f\nCamera rotation: x:%.2f, y:%.2f, z:%.2f\nFocal length%.2f",
                camera.origin.x,
                camera.origin.y,
                camera.origin.z,
                camera.direction.x,
                camera.direction.y,
                camera.direction.z,
                camera.focalLength);
        CameraText.setString(buffer);

        window.clear();

        // Create a sprite to draw the texture
        sf::Sprite sprite(texture);
        window.draw(sprite); // Draw the sprite containing the texture
        window.draw(fpsCounter);
        window.draw(CameraText);

        window.display();
    }

    return 0; // Return 0 to indicate successful execution
}
