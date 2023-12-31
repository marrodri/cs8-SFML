//
// Created by Marthel Rodriguez on 12/7/23.
//

#ifndef SFMLTEMPLATE_MENUITEM_H
#define SFMLTEMPLATE_MENUITEM_H


#include "../Container/Container.h"
#include "../Text/Text.h"
#include "../Components/ContainerInterface.h"
#include "../AppHandler.h"

class MenuItem : public GUIComponent, public ContainerInterface {
private:
    Container menuItemContainer;
    Text MenuItemText;
    std::string title="";


    /**
     * function pointers.
     * */
    void (*pFunc)() = nullptr;

public:
    MenuItem();
    MenuItem(Container container, Text text);
    /**
     * methods
     * */
    void setOnClickFunction(void (*pOnClick)());

    void onClick();
    void setString(const std::string &str);


    /**
     * GUI component
     * */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;



    /**
     * Container interface
     * */
    sf::Vector2f getPosition() override;

    sf::Vector2f getSize() override;

    sf::FloatRect getLocalBounds() const override;

    sf::FloatRect getGlobalBounds() const override;

    void setOrigin(sf::Vector2f &origin) override;

    void setPosition(const sf::Vector2f &pos) override;

    void setFillColor(const sf::Color &color) override;

    void setTexture(const sf::Texture &texture) override;

    void setSize(sf::Vector2f size) override;

    void setOutlineThickness(float outlineThickness) override;

    void setOutlineColor(const sf::Color &color) override;

};


#endif //SFMLTEMPLATE_MENUITEM_H
