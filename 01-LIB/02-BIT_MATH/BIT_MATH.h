//               بسم الله الرحمن الرحيم 




/*    Author    : 3mo MOHAMED AYMAN ABDELAZIZ                          */




#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_POS)       (REG|=(1<<BIT_POS))    
#define CLR_BIT(REG,BIT_POS)       (REG&=~(1<<BIT_POS))    
#define TOG_BIT(REG,BIT_POS)       (REG^=(1<<BIT_POS))    
#define GET_BIT(REG,BIT_POS)       ((REG>>BIT_POS) &1) 

#endif