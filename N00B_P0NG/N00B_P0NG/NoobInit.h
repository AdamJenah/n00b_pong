#pragma once
#include "NoobClass.h"

class N00BP0NG : public base<N00BP0NG>
{
public:
	N00BP0NG();
	~N00BP0NG();

	bool Initialize();

	void  Run();
	bool  HasFreeDiskSpace();
	bool ReadCPUSpeed();
	bool CheckMemory();

	const sf::Time FrameTime = sf::seconds(1.0f / 60.f);//Sets it to 60 frames per second after initialized in hpp.

private:
	friend base<N00BP0NG>;
	N00BP0NG(const N00BP0NG &_copy) = delete;

	bool  SystemRequirements();
	
};