#pragma once

class CGameTime
{
	int frameCount;

public:
	int elapsedTime, totalElapsedTime;
	float fps;

	CGameTime(void)
	{
		frameCount;
		elapsedTime = totalElapsedTime = 0;
	}

	void update(int time)
	{
		//elapsedTime = time - totalElapsedTime;
		//totalElapsedTime = time;
	}

	void calculateFPS(int time)
	{
		frameCount++;

		elapsedTime = time - totalElapsedTime;

		if(elapsedTime > 1000)
		{
			fps = frameCount / (elapsedTime / 1000.0f);

			totalElapsedTime = time;

			frameCount = 0;
		}
	}
};
