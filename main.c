#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "EXIT_Interface.h"


#define LedLeft		PIN0
#define LedRight	PIN1
#define ResetGIE	PIN2


u8 flag;


void BTN_Left()
{
	if(1 == flag)
	{
		DIO_VidSetPinValue(PORTB, LedLeft, HIGH);
		flag = 0;
	}
}

void BTN_Right()
{
	if(1 == flag)
	{
		DIO_VidSetPinValue(PORTB, LedRight, HIGH);
		flag = 0;
	}
}

int main()
{
	flag = 1;

	DIO_VidSetPinDirection(PORTB, LedLeft, OUTPUT);
	DIO_VidSetPinDirection(PORTB, LedRight, OUTPUT);

	DIO_VidSetPinDirection(PORTB, ResetGIE, INPUT);
	DIO_VidSetPinDirection(PORTD, PIN2, INPUT);
	DIO_VidSetPinDirection(PORTD, PIN3, INPUT);

	EXIT_VidSetCallBackFun(&BTN_Left, &BTN_Right);

	EXIT_VidInit();

	while(1)
	{
		if(DIO_U8GetPinValue(PORTB, ResetGIE) == HIGH)
		{
			DIO_VidSetPinValue(PORTB, LedLeft, LOW);
			DIO_VidSetPinValue(PORTB, LedRight, LOW);

			flag = 1;

			while(ResetGIE == HIGH);
		}
	}

	return 0;
}
