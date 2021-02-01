#include "Volume.h"

Volume::Volume()
{
	under = nullptr;
}

Volume::Volume(char _data) : data(_data)
{
	under = nullptr;
}

void Volume::setUnder(Volume * _under)
{
	under = _under;
}

Volume* Volume::getUnder()
{
	return under;
}

char Volume::getData()
{
	return data;
}