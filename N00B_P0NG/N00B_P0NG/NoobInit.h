#pragma once
#include "NoobClass.h"

class N00BP0NG : public base<N00BP0NG>
{
public:
	N00BP0NG();
	~N00BP0NG();

	bool Initialize();

	void  Run(sf::RenderWindow Window);
	bool  HasFreeDiskSpace();
	bool ReadCPUSpeed();
	bool CheckMemory();

private:
	friend base<N00BP0NG>;
	N00BP0NG(const N00BP0NG &_copy) = delete;

	bool  SystemRequirements();
	
};