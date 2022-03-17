#pragma once
#include <string>
#include <SDL_image.h>
#include "Vector.h"
#include "Screen.h"

class Texture
{

public:

	Texture(int width = 0, int height = 0);

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void isAnimated(bool flag);
	void isAnimationLooping(bool flag);

	void SetTextureDimension(int width, int height);
	void SetSourceDimension(int columns, int rows, int width, int height);
	void SetAnimationSpeed(float animationSpeed);

	void Update();
	void Render(Screen& screen, int x = 0, int y = 0);

private:

	int m_cel;
	float m_animationSpeed;
	float m_animationRunningTime;

	bool m_isAnimated;
	bool m_isAnimationDead;
	bool m_isAnimationLooping;
	bool m_isAnimationLoopFinal;

	SDL_Texture* m_imgTexture;
	Vector<int> m_textureDimension;
	Vector<int> m_celDimension;
	Vector<int> m_sourceDimension;


};

