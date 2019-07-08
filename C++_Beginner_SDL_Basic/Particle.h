#pragma once

#include <stdlib.h>

struct Particle
{
	double m_xPos;
	double m_yPos;

private:
	double m_Speed;
	double m_Direction;

	int randMaxDivisor = RAND_MAX / 100;

private:
	void Init();

public:
	Particle();
	virtual ~Particle();

	void UpdatePosition(int interval);
};

