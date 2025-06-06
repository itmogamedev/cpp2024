#pragma once

#include "SFML/Graphics/Text.hpp"

class Footer final : public sf::Drawable {
	sf::Text energyText;
	sf::Text healthText;

	static constexpr float FONT_SIZE = 24.0f;

public:
	Footer(const sf::Font& font) : energyText(font), healthText(font) {

		energyText.setCharacterSize(FONT_SIZE);
		energyText.setFillColor(sf::Color::Red);
		energyText.setStyle(sf::Text::Bold);

		healthText.setCharacterSize(FONT_SIZE);
		healthText.setFillColor(sf::Color::Green);
		healthText.setStyle(sf::Text::Bold);
	}

	void update(const sf::RenderWindow& window) {
		const sf::Vector2f window_size(window.getSize().x, window.getSize().y);
		const float footer_pos_y = window.getSize().y - FOOTER_HEIGHT / 2.0f;

		const GameState& gameState = GameState::get();

		energyText.setString("ENERGY: " + std::to_string(gameState.energy));
		healthText.setString("HEALTH: " + std::to_string(gameState.health));

		const auto energyTextSize = energyText.getGlobalBounds();
		const auto healthTextSize = healthText.getGlobalBounds();

		energyText.setPosition({window_size.x / 4 - energyTextSize.size.x / 2, footer_pos_y - energyTextSize.size.y / 2});
		healthText.setPosition({window_size.x * 3 / 4 - energyTextSize.size.x / 2, footer_pos_y - healthTextSize.size.y / 2});
	}

	void draw(sf::RenderTarget& target, const sf::RenderStates states) const override {
		target.draw(energyText, states);
		target.draw(healthText, states);
	}
};
