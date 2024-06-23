#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class WindowText
{
private:
    sf::Text mText;
    sf::Font mTextFont;
    sf::Vector2f mTextPos;
    std::string nameFont = "fibberish.ttf";

public:
    void setString(const std::string& str)
    {
        mText.setString(str);
    }

    void setup(int chSize, const sf::Color& color)
    {
        mText.setCharacterSize(chSize);
        mText.setFillColor(color);

        if (!mTextFont.loadFromFile("files/text/" + nameFont))
            throw std::exception("The font could not be loaded!");
        mText.setFont(mTextFont);
    }

    void setPosition(const sf::Vector2f& pos)
    {
        mTextPos = pos;
        mText.setPosition(pos);
    }

    void centerByWidth(int width)
    {
        float x = (width - mText.getLocalBounds().width) / 2;
        this->setPosition({mTextPos.x + x, mTextPos.y});
    }

    sf::Text getText()
    {
        return mText;
    }
};