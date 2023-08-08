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
		static const sf::Color dark_grey {40, 40, 40};
		static const sf::Color dark_green {0, 100, 0};
	}

	namespace player {
		/// <summary>
		/// ������� �������� ������
		/// </summary>
		static const int BASE_MOVING_SPEED = 50;
		/// <summary>
		/// ���������������� �������� ������
		/// </summary>
		static float rotate_sense = 0.001f;
		static const float BASE_ROTATING_SPEED = std::numbers::pi * 1.5;

	}

	namespace render {
		static const float FOV = std::numbers::pi * 0.6F;
		static const float VIEW_DISTANCE = 100;
		static const float RAYS_NUM = 200;
		/// <summary>
		/// ����� ���������� ����������������
		/// </summary>
		static const float MAGIC_CONSTANT = 5000;
	}

	namespace mini_map {
		static const float RESIZE_SPEED = 0.3f;
		static const sf::Vector2i POSITION{0, 0};
		static const sf::Vector2i SIZE{300, 300};
		static int size{ 300 };
	}

	namespace game {
		const sf::Color WALL_COLOR{229, 230, 25};
		const sf::Color FLOOR_COLOR{100, 100, 100};
		const sf::Color SKY_COLOR{172, 221, 237};
	}
	
	namespace control_buttons_codes {
		/// <summary>
		/// �������� ������ ������
		/// </summary>
		static auto player_foward = sf::Keyboard::W;

		/// <summary>
		/// �������� ������ �����
		/// </summary>
		static auto player_backward = sf::Keyboard::S;

		/// <summary>
		/// �������� ������ �����
		/// </summary>
		static auto player_left = sf::Keyboard::A;

		/// <summary>
		/// �������� ������ ������
		/// </summary>
		static auto player_right = sf::Keyboard::D;

		/// <summary>
		/// ������ ������
		/// </summary>
		static auto exit_button = sf::Keyboard::Escape;

		/// <summary>
		/// ������ ������������ ���������� �����
		/// </summary>
		static auto fix_mouse = sf::Keyboard::LControl;

		/// <summary>
		/// ���������� �������� ���������
		/// </summary>
		static auto minimap_size_increase = sf::Keyboard::Equal;

		/// <summary>
		/// ���������� �������� ���������
		/// </summary>
		static auto minimap_size_decrease = sf::Keyboard::Hyphen;

		///// <summary>
		///// ������� ������ �� ������� �������
		///// </summary>
		//static auto player_rotate_left = sf::Keyboard::Left;

		///// <summary>
		///// ������� ������ ������ ������� �������
		///// </summary>
		//static auto player_rotate_right = sf::Keyboard::Right;
	}
}