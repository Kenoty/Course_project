#pragma once

#include <iostream>

class Lecture
{
	std::string material;
	std::string link_to_video;
public:
	void set_material(std::string_view);
	std::string get_material();
	void set_link(std::string_view);
	std::string get_link();
};