#include "pch.h"
#include "Particle.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;


Particle::Particle(): m_xPos(0), m_yPos(0)
{
	Init();
}

void Particle::Init()
{
	m_xPos = 0;
	m_yPos = 0;

	m_Direction = (2 * M_PI * rand()) / RAND_MAX;
	m_Speed = (0.03 * rand()) / RAND_MAX;

	m_Speed *= m_Speed;
}


Particle::~Particle()
{

}

void Particle::UpdatePosition(int interval)
{
	m_Direction += interval * 0.001;

	double xSpeed = m_Speed * cos(m_Direction);
	double ySpeed = m_Speed * sin(m_Direction);

	m_xPos += xSpeed * interval;
	m_yPos += ySpeed * interval;

	if (m_xPos < -1 || m_xPos > 1 || m_yPos < -1 || m_yPos > 1)
	{
		Init();
	}

	if (rand() < randMaxDivisor)
	{
		Init();
	}
}
