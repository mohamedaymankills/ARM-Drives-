//               بسم الله الرحمن الرحيم 




/*    Author    : 3mo MOHAMED AYMAN ABDELAZIZ                          */


/*                       /LIB                       */



#include "STD_TYPES.h"
#include "BIT_MATH.h"




/*                        INCLUDE                   */




#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"






void MGPIO_voidSetPinDirection(u8 copy_u8Port , u8 copy_u8Pin,u8 copy_u8Mode)
{   
    /* Configure based on Port number */
    switch(copy_u8Port)
    {
        /* Handle port A */
        case GPIO_PORTA : 
            /* In case of PIN0 -> PIN7*/
            if(copy_u8Pin<=7)
            {
                GPIOA_CRL &= ~((0b111)<<(copy_u8Pin*4));      
                GPIOA_CRL |= (copy_u8Mode) << (copy_u8Pin*4);  
            }
            /* In case of PIN8 -> PIN15*/
            else if(copy_u8Pin<=15)
            {
                copy_u8Pin -=8;     
                GPIOA_CRL &= ~((0b111)<<(copy_u8Pin*4));       
                GPIOA_CRL |= (copy_u8Mode) << (copy_u8Pin*4); 
            }   
            break;

        /* Handle port B */
        case GPIO_PORTB : 
            /* In case of PIN0 -> PIN7*/
            if(copy_u8Pin<=7)
            {
                GPIOB_CRL &= ~((0b111)<<(copy_u8Pin*4));       
                GPIOB_CRL |= (copy_u8Mode) << (copy_u8Pin*4);  
            }
            /* In case of PIN8 -> PIN15*/
            else if(copy_u8Pin<=15)
            {
                copy_u8Pin -=8;     
                GPIOB_CRL &= ~((0b111)<<(copy_u8Pin*4));          
                GPIOB_CRL |= (copy_u8Mode) << (copy_u8Pin*4);  
            }   
            break;

        /* Handle port C */
        case GPIO_PORTC : 
            /* In case of PIN0 -> PIN7*/
            if(copy_u8Pin<=7)
            {
                GPIOC_CRL &= ~((0b111)<<(copy_u8Pin*4));       
                GPIOC_CRL |= (copy_u8Mode) << (copy_u8Pin*4);           
            }
            /* In case of PIN8 -> PIN15*/
            else if(copy_u8Pin<=15)
            {
                copy_u8Pin -=8;     
                GPIOC_CRL &= ~((0b111)<<(copy_u8Pin*4));          
                GPIOC_CRL |= (copy_u8Mode) << (copy_u8Pin*4);  
            }   
            break;
                                                                
    }

}
void MGPIO_voidSetPinValue(u8 copy_u8Port , u8 copy_u8Pin,u8 copy_u8Value)
{
    switch(copy_u8Port)
    {
        case GPIO_PORTA : 
            if(copy_u8Value==GPIO_HIGH)
            {
                SET_BIT(GPIOA_ODR,copy_u8Pin);
            }
            else if(copy_u8Value==GPIO_LOW)
            {
                CLR_BIT(GPIOA_ODR,copy_u8Pin);
            }
            break;
        case GPIO_PORTB : 
            if(copy_u8Value==GPIO_HIGH)
            {
                SET_BIT(GPIOB_ODR,copy_u8Pin);
            }
            else if(copy_u8Value==GPIO_LOW)
            {
                CLR_BIT(GPIOB_ODR,copy_u8Pin);
            }
            break;
        case GPIO_PORTC : 
            if(copy_u8Value==GPIO_HIGH)
            {
                SET_BIT(GPIOC_ODR,copy_u8Pin);
            }
            else if(copy_u8Value==GPIO_LOW)
            {
                CLR_BIT(GPIOC_ODR,copy_u8Pin);
            }        
            break;
    }
}
u8 MGPIO_u8GetPinValue(u8 copy_u8Port , u8 copy_u8Pin)
{
    u8 local_u8Result=0;
    switch(copy_u8Port)
    {
        case GPIO_PORTA : 
            local_u8Result=GET_BIT(GPIOA_IDR,copy_u8Pin);
            break;
        case GPIO_PORTB : 
            local_u8Result=GET_BIT(GPIOB_IDR,copy_u8Pin);
            break;
        case GPIO_PORTC : 
            local_u8Result=GET_BIT(GPIOC_IDR,copy_u8Pin);
            break;
    }
    return local_u8Result;

}


//                      الحمد لله   