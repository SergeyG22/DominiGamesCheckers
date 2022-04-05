#include "../../include/Graphics/rendering_element.h"

RenderingElement::RenderingElement(std::string file_name) {
	if (!m_texture.loadFromFile("../resources/images/" + file_name)) {
		std::cerr << "error loading the " << file_name << " file";
	}
	m_file_name = file_name;
	sprite.setTexture(m_texture);
	sprite.setPosition(sf::Vector2f(0, 0));
}

std::string RenderingElement::getFileName() const {
	return m_file_name;
}
