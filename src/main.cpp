#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

#include "LEDController.h"
#include "OFController.h"

int main()
{
    OFController OF;
    LEDController strip;
    vector<int> shape;

    OF.init();

    int OFnum = 7;
    int num_strip = 8;

    vector<int> status;
    status.resize(5 * OFnum);

    shape.clear();
    shape.resize(num_strip);

    for (int i = 0; i < num_strip; i++)	shape[i] = 100;
    strip.init(shape);

    vector<vector<int>> LEDstatus;
    LEDstatus.resize(num_strip);
    for (int i = 0; i < num_strip; i++)
	    LEDstatus[i].resize(shape[i]);

    for (int i = 0; i < 5*OFnum; i++)
    {
        status[i] = 0xaa000010;
    }
    for (int i = 0; i < num_strip; i++)
	    for (int j = 0; j < shape[i]; j++)	LEDstatus[i][j] = 0xaa000010;
    strip.sendAll(LEDstatus);
    OF.sendAll(status);
    usleep(1000000);

    for (int i = 0; i < 5*OFnum; i++)
    {
        status[i] = 0x00aa0010;
    }

    for (int i = 0; i < num_strip; i++)
	    for (int j = 0; j < shape[i]; j++)	LEDstatus[i][j] = 0x00aa0010;
    strip.sendAll(LEDstatus);
    OF.sendAll(status);
    usleep(1000000);

    for (int i = 0; i < 5*OFnum; i++)
    {
        status[i] = 0x0000aa10;
    }

    for (int i = 0; i < num_strip; i++)
	    for (int j = 0; j < shape[i]; j++)	LEDstatus[i][j] = 0x0000aa10;
    strip.sendAll(LEDstatus);
    OF.sendAll(status);
    usleep(1000000);

    for (int i = 0; i < 5*OFnum; i++)
    {
        status[i] = 0x00000010;
    }

    for (int i = 0; i < num_strip; i++)
	    for (int j = 0; j < shape[i]; j++)	LEDstatus[i][j] = 0x00000010;
    strip.sendAll(LEDstatus);
    OF.sendAll(status);
    strip.finish();

    
    return 0;
}  


