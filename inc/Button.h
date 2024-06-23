#pragma once

#include <SFML/Graphics.hpp>
#include <WindowText.h>

class Button
{
private:
    sf::RectangleShape mButton;
    sf::Vector2f mButtonPos;
    WindowText mButtonText;

public:
    void setup(const sf::Vector2f& size, const sf::Color& color)
    {
        mButton.setSize(size);
        mButton.setFillColor(color);
    }

    void setText(const std::string& str, int chSize, const sf::Color& color)
    {
        mButtonText.setString(str);
        mButtonText.setup(chSize, color);
    }

    void setPosition(const sf::Vector2f& pos)
    {
        mButtonPos = pos;
        mButton.setPosition(pos);

        float textX = (pos.x + mButton.getLocalBounds().width / 2) - (mButtonText.getText().getLocalBounds().width / 2);
        float textY = (pos.y + mButton.getLocalBounds().height / 4) - (mButtonText.getText().getLocalBounds().height / 4);
        mButtonText.setPosition({textX, textY});
    }

    void centerByWidth(int width)
    {
        float x = (width - mButton.getLocalBounds().width) / 2;
        this->setPosition({mButton.getPosition().x + x, mButton.getPosition().y});
    }

    bool isMouseOver(sf::RenderWindow& window)
    {
        auto mousePos = sf::Mouse::getPosition(window);
        float buttonW = mButtonPos.x + mButton.getLocalBounds().width;
        float buttonH = mButtonPos.y + mButton.getLocalBounds().height;

        if ((mousePos.x > mButtonPos.x && mousePos.x < buttonW) &&
            (mousePos.y > mButtonPos.y && mousePos.y < buttonH))
        {
            mButton.setFillColor(sf::Color(189,236,182));
            return true;
        }
        else
        {
            mButton.setFillColor(sf::Color::White);
            return false;
        }
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(mButton);
        window.draw(mButtonText.getText());
    }
};