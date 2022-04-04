#pragma once
#include <SDL.h>
#include <string>

class Save
{

public:

	bool SaveFile(const std::string* savetext);

	bool LoadFile(std::string* savetext);

private:

};