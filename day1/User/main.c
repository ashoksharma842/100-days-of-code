/******************************************************************************
 * @file     main.c
 * Board : NuTiny-EVB-NUC240 V1.2
*****************************************************************************/
//#include <stdio.h>
//#include "NUC230_240.h"

char const my_data[] = "test data";
int main()
{
	char data[10];
	for(int i = 0; i < sizeof(my_data); i++){
		data[i] = my_data[i];
	}
	return 0;
}

