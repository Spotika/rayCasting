#pragma once
#include<string>
#include "SFML/Graphics.hpp"
#include <numbers>


namespace config {
	namespace window {
		/// <summary>
		/// ������ ����
		/// </summary>
		static int width = 1600;
		/// <summary>
		/// ������ ����
		/// </summary>
		static int height = 800;
		/// <summary>
		/// �������� ����
		/// </summary>
		static std::string title = "RayCasting";

		/// <summary>
		/// ��� ����
		/// </summary>
		static const int FPS = 240;
	}

	namespace color {
		static const sf::Color black {0, 0, 0};
		static const sf::Color white {255, 255, 255};
		static const sf::Color grey {100, 100, 100};
		static const sf::Color green {0, 255, 0};
	}

	namespace player {
		/// <summary>
		/// ������� �������� ������
		/// </summary>
		static const int BASE_MOVING_SPEED = 400;
		static const double BASE_ROTATING_SPEED = std::numbers::pi;
	}

	namespace control_buttons_codes {
		/// <summary>
		/// �������� ������ ������
		/// </summary>
		static auto player_foward = sf::Keyboard::Up;

		/// <summary>
		/// �������� ������ �����
		/// </summary>
		static auto player_backward = sf::Keyboard::Down;

		/// <summary>
		/// ������� ������ �� ������� �������
		/// </summary>
		static auto player_rotate_left = sf::Keyboard::Left;

		/// <summary>
		/// ������� ������ ������ ������� �������
		/// </summary>
		static auto player_rotate_right = sf::Keyboard::Right;
	}
}