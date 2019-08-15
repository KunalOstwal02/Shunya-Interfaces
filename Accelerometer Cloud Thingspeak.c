#include <stdlib.h>
#include <stdlib.h>
#include <shunyaInterfaces.h>
#include <thingSpeak.h>
#include <Wire.h>

int main()
{
	float x;
	float y;
	float z;
	shunyaInterfacesSetup();
	pcf8591Setup();
	thingSpeakSetWriteAPI(L8TJKD6PY1D4G3IZ);
	
	while(1)
		{
			x = pcf8591Read(A1);
			y = pcf8591Read(A2);
			z = pcf8591Read(A3);

			thingSpeakSetField(1, x);
			thingSpeakSetField(2, y);
			thingSpeakSetField(3, z);

			thingSpeakWriteFields();
			delay(30000);





		}

	return 0;
}