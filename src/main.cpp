#include <SFML/Graphics.hpp>
#include <vector>

// Define a structure to represent a pixel buffer
class PixelBuffer {
public:
    PixelBuffer(unsigned int width, unsigned int height) 
        : width(width), height(height), pixels(width * height) {}

    // Set the color of a specific pixel
    void setPixel(unsigned int x, unsigned int y, sf::Color color) {
        if (x < width && y < height) {
            pixels[y * width + x] = color; // Set pixel color at (x, y)
        }
    }

    // Get a pointer to the pixel data
    const std::vector<sf::Color>& getPixels() const {
        return pixels;
    }

    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; }

private:
    unsigned int width, height; // Dimensions of the pixel buffer
    std::vector<sf::Color> pixels; // Vector to hold pixel colors
};

int main()
{
    const unsigned int width = 800;
    const unsigned int height = 600;

    auto window = sf::RenderWindow{ { width, height }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    // Create a pixel buffer
    PixelBuffer pixelBuffer(width, height);

    // Initialize the pixel buffer with a gradient
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            // Set pixel color based on position (gradient effect)
            sf::Color color(
                static_cast<sf::Uint8>(x % 256), // Red component based on x
                static_cast<sf::Uint8>(y % 256), // Green component based on y
                128 // Constant Blue component
            );
            pixelBuffer.setPixel(x, y, color);
        }
    }

    // Create an SFML texture to display the pixel buffer
    sf::Texture texture;
    texture.create(width, height);

    // Main loop
    // while (window.isOpen())
    // {
    //     for (auto event = sf::Event{}; window.pollEvent(event);)
    //     {
    //         if (event.type == sf::Event::Closed)
    //         {
    //             window.close();
    //         }
    //     }

    //     // Update the texture with the pixel buffer data
    //     texture.update(reinterpret_cast<const sf::Uint8*>(pixelBuffer.getPixels().data()));

    //     window.clear();

    //     // Create a sprite to draw the texture
    //     sf::Sprite sprite(texture);
    //     window.draw(sprite); // Draw the sprite containing the texture

    //     window.display();
    // }

    return 0; // Return 0 to indicate successful execution
}
