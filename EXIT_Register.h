#ifndef _EXIT_REGISTER_H_

#define _EXIT_REGISTER_H_


#define MCUCR	*((u8*)0x55)
#define MCUCSR	*((u8*)0x54)
#define GICR	*((u8*)0x5B)
#define SREG	*((u8*)0x5F)
#define GIFR	*((u8*)0x5A)

void __vector_1(void)       __attribute__((signal));
void __vector_2(void)       __attribute__((signal));


#endif
