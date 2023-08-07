#pragma once
#include<string>
#include "SFML/Graphics.hpp"
#include <numbers>


namespace config {
	namespace window {
		/// <summary>
		/// ширина окна
		/// </summary>
		static int width = 1600;
		/// <summary>
		/// высота окна
		/// </summary>
		static int height = 800;
		/// <summary>
		/// Описание окна
		/// </summary>
		static std::string title = "RayCasting";

		/// <summary>
		/// ФПС игры
		/// </summary>
		static const int FPS = 240;
	}

	namespace color {
		static const sf::Color black {0, 0, 0};
		static const sf::Color white {255, 255, 255};
		static const sf::Color grey {100, 100, 100};
		static const sf::Color green {0, 255, 0};
		static const sf::Color dark_grey {40, 40, 40};
		static const sf::Color dark_green {0, 100, 0};
	}

	namespace player {
		/// <summary>
		/// Базовая скорость игрока
		/// </summary>
		static const int BASE_MOVING_SPEED = 100;
		static const float BASE_ROTATING_SPEED = std::numbers::pi * 1.5;

	}

	namespace render {
		static const float FOV = std::numbers::pi * 0.6F;
		static const float VIEW_DISTANCE = 200;
		static const float RAYS_NUM = 800;
		/// <summary>
		/// штука полученная эксперементально
		/// </summary>
		static const float MAGIC_CONSTANT = 10000;
	}

	namespace control_buttons_codes {
		/// <summary>
		/// Движение игрока вперед
		/// </summary>
		static auto player_foward = sf::Keyboard::Up;

		/// <summary>
		/// Движение игрока назад
		/// </summary>
		static auto player_backward = sf::Keyboard::Down;

		/// <summary>
		/// Поворот игрока по часовой стрелке
		/// </summary>
		static auto player_rotate_left = sf::Keyboard::Left;

		/// <summary>
		/// Воворот игрока против часовой стрелки
		/// </summary>
		static auto player_rotate_right = sf::Keyboard::Right;
	}
}