#pragma once

class Volume
{
	char data;
	Volume* under;
public:
	Volume();
	Volume(char _data);
	void setUnder(Volume* under);
	Volume* getUnder();
	char getData();
};