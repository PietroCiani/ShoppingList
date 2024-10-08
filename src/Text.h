//
// Created by delta on 14/08/24.
//

#ifndef SHOPPINGLIST_TEXT_H
#define SHOPPINGLIST_TEXT_H


#include <SFML/Graphics.hpp>

class Text : public sf::Drawable, public sf::Transformable{
public:
    Text(std::string string, const sf::Vector2f &pos, const sf::Font& font, int size = 14, const sf::Color &col = sf::Color(251,241,199));

    void setString(const std::string &string);

    void setPos(const sf::Vector2f &pos);

    void setSize(int size);

    std::string getString();

    sf::Vector2f getPos() const;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Font font;
    std::string string;
    sf::Color color;
    sf::Vector2f pos;
    sf::Text text;
    int size;
};


#endif //SHOPPINGLIST_TEXT_H
