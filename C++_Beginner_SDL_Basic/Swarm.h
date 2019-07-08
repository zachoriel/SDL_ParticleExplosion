#pragma once

#include "Particle.h"

class Swarm
{
private:
	Particle *m_pParticles;
	int lastTime;

public:
	const static int NPARTICLES = 5000;

	Swarm();
	~Swarm();

	void UpdatePosition(int elapsed);

	const Particle *const GetParticles() { return m_pParticles; };
};

