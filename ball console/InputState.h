#pragma once

class InputState
{
public:
	bool currentKeyStates[256], lastKeySates[256];

	InputState(void)
	{
		for(int i = 0; i < 256; i++)
			currentKeyStates[i] = lastKeySates[i] = false;
	}

	bool IsSelect()
	{
		int a = ' ';
		return lastKeySates[a] == false && currentKeyStates[a] == true;
	}
};
