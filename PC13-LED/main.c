#include "stm32f100xb.h"

/*时延函数定义*/
void busy_delay( uint32_t count )
{uint32_t i,j;
    for ( i = 0; i < count; i++)
    {
        for ( j = 0; j < count; j++);
           
    }
}

int main(void){
/*时钟-A2总线GPIOA对应位2*/

RCC->APB2ENR |=(1<<2);

/*A0输出*/
GPIOA->CRL &= ~(0xF <<0);
GPIOA->CRL |= ~(0x20 <<0);/*清零再输出*/

/*控制板载PC13-LED*/
while (1)
{
        GPIOA->ODR |= (1<<0);//A0高电平
        busy_delay (500000U);//时延
        GPIOA->ODR &= ~(1<<0);//A0低电平
        busy_delay(500000U);

}

}