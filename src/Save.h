#pragma once
#include <SDL.h>
#include <string>

class Save
{

public:

	bool SaveFile(std::string savetext, int targetline);

	bool LoadFile(std::string savetext, int targetline);

private:

};

