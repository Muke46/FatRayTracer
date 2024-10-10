#include <SFML/Graphics.hpp>
#include <vector>

#include <cmath>

#include "Core/Vector.h"
#include "Core/Ray.h"
#include "Core/Triangle.h"
#include "Render/PixelBuffer.h"
#include "Utils/Color.h"
#include "Render/Camera.h"

void triangleRender(PixelBuffer &pixelBuffer, int height, int width, Triangle3 triangle)
{

    // Initialize the pixel buffer with a gradient
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {

            // Create a ray
            Vector3 origin = Vector3((float)x, (float)y, 0.0f);
            Vector3 direction = Vector3(0.0f, 0.0f, 1.0f);
            Ray3 ray = Ray3(origin, direction);

            Vector3 intersection;

            // Check if the ray intersects with the triangle
            if (triangle.checkIntersect(ray, intersection) == true)
            {
                Color color(
                    255,
                    255,
                    255,
                    0);
                pixelBuffer.setPixel(x, y, color);
            }
            else
            {
                Color color(
                    0,
                    0,
                    0,
                    0);
                pixelBuffer.setPixel(x, y, color);
            }
        }
    }
}

int main()
{
    const unsigned int width = 800;
    const unsigned int height = 600;

    auto window = sf::RenderWindow{{width, height}, "CMake SFML Project"};
    window.setFramerateLimit(144);

    // Pick a font
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");

    // FPS Counter text element
    sf::Text fpsCounter;
    fpsCounter.setFont(font);
    fpsCounter.setCharacterSize(24);
    fpsCounter.setFillColor(sf::Color::Red);

    // FPS Counter variables
    sf::Clock clock;
    int framecount = 0; // Used to count the frames between two intervals
    float updateInterval = 0.01f; // Time between FPS updates
    float elapsedTime = 0.0f; // Used to count the elapsed time from the last FPS print

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
    
    // Create a scene with some triangles
    std::vector<Triangle3> scene;

    Vector3 v0 = Vector3(100.0f, 100.0f, 10.0f);
    Vector3 v1 = Vector3(200.0f, 100.0f, 10.0f);
    Vector3 v2 = Vector3(100.0f, 200.0f, 10.0f);
    Triangle3 triangle = Triangle3(v0, v1, v2);

    scene.push_back(triangle);

    Vector3 v3 = Vector3(250.0f, 100.0f, 10.0f);
    Vector3 v4 = Vector3(250.0f, 250.0f, 10.0f);
    Vector3 v5 = Vector3(100.0f, 250.0f, 10.0f);
    Triangle3 triangle2 = Triangle3(v3, v4, v5);

    scene.push_back(triangle2);
    
    // Create a camera
    Vector3 cameraOrigin = Vector3(5.0f, 5.0f, -10.0f);
    Vector3 cameraDirection = Vector3(0.0f, 0.0f, 1.0f);
    Camera3 camera(cameraOrigin, cameraDirection, 15.0f, 20.0f, 20.0f);

    float i = 1.0f;

    // Main loop
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        camera.setFocalLength(i);
        pixelBuffer.clearBuffer();
        camera.render(pixelBuffer, scene);

        if (i<100.0f) {
            i = i + 0.1f;
        }
        else{
            i = 1.0f;
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

        window.clear();

        // Create a sprite to draw the texture
        sf::Sprite sprite(texture);
        window.draw(sprite); // Draw the sprite containing the texture
        window.draw(fpsCounter);

        window.display();
    }

    return 0; // Return 0 to indicate successful execution
}
