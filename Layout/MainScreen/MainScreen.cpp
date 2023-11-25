//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "MainScreen.h"
#include "../../Font/Font.h"

MainScreen::MainScreen(): gridView(sf::Vector2f (250,100)), leftButton( {840, 551},"L"),
    rightButton({890, 551},"R") {
    for (int i =0; i<32; i++) {
        gridView.pushItem(i);
    }
    homeScreenContainer.setFillColor(sf::Color::Black);
    homeScreenContainer.setPosition({247, 100});
    homeScreenContainer.setSize({699, 490});

    currPageIndex.setFont(Font::getFont());
    currPageIndex.setCharacterSize(24);
    currPageIndex.setString("1/10");
    currPageIndex.setPosition({760, 552});
}

void MainScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(homeScreenContainer);
    target.draw(gridView);
    target.draw(rightButton);
    target.draw(leftButton);
    target.draw(currPageIndex);
}

void MainScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    gridView.addEventHandler(window, event);
    rightButton.addEventHandler(window, event);
    leftButton.addEventHandler(window, event);
}

void MainScreen::update() {
    gridView.update();
    rightButton.update();
    leftButton.update();
    //update for the main page.
    //update the currPageIndex;


}

