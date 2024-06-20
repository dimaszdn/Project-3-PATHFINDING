#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Info
{
private:
    std::string mStr;
    std::string nameFont = "fibberish.ttf";

    sf::Text mText;
    sf::Font mFont;
    sf::Vector2f mPos;

public:
    Info() = default;

    void setup(int size, sf::Color color)
    {
        if (!mFont.loadFromFile("files/text/" + nameFont))
            throw std::exception("The font could not be loaded!");

        mText.setFont(mFont);
        mText.setCharacterSize(size);
        mText.setFillColor(color);
    }

    void setPos(sf::Vector2f pos)
    {
        mPos = pos;
        mText.setPosition(mPos);
    }

    void setString(const std::string& str)
    {
        mStr = str;
        mText.setString(mStr);
    }

    sf::Text getText()
    {
        return mText;
    }
};