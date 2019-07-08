#include "pch.h"
#include "Swarm.h"


Swarm::Swarm(): lastTime(0)
{
	m_pParticles = new Particle[NPARTICLES];
}


Swarm::~Swarm()
{
	delete[] m_pParticles;
}

void Swarm::UpdatePosition(int elapsed)
{
	int interval = elapsed - lastTime;

	for (int i = 0; i < Swarm::NPARTICLES; i++)
	{
		m_pParticles[i].UpdatePosition(interval);
	}

	lastTime = elapsed;
}
