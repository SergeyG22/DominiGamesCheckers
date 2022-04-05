#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class RenderingElement{
	std::string m_file_name;
	sf::Texture m_texture;
public:
	RenderingElement(std::string);
	sf::Sprite sprite;
	std::string getFileName() const;
};