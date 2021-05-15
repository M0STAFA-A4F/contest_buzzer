#ifndef _STD_TYPES_h_
#include "STD_TYPES.h"
#endif

#ifndef _BIT_MATH_h_
#include "BIT_MATH.h"
#endif

#include "EXIT_Register.h"


#define NULL	0


void static (* EXIT0CallBackPtr)(void) = NULL;
void static (* EXIT1CallBackPtr)(void) = NULL;


void EXIT_VidInit(void)
{
	
	// The rising edge of INT0
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	// The rising edge of INT1
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	
	// INT0 Enable
	SET_BIT(GICR,6);
	// INT1 Enable
	SET_BIT(GICR,7);
	
	// GIE=1
	SET_BIT(SREG,7);
	
}

void EXIT_VidSetCallBackFun(void (* PFun0)(void) , void (* PFun1)(void))
{
	EXIT0CallBackPtr = PFun0;
	EXIT1CallBackPtr = PFun1;
}

void __vector_1(void)
{
	EXIT0CallBackPtr();
}

void __vector_2(void)
{
	EXIT1CallBackPtr();
}





