#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

// 7 8  9  10
// 6       11
// 5       12
// 4 15 14 13
// 3
// 2
// 1
// 0

void Delay(uint32_t);
void Config(void);
uint16_t sangdan[17]={0x0000,0x0001,0x0003,0x0007,0x000F,0x001F,0x003F,0x007F,0x00FF,0x01FF,0x03FF,0x07FF,0x0FFF,0x1FFF,0x3FFF,0x7FFF,0xFFFF};
uint16_t toidan[17]={0xFFFF,0x7FFF,0x3FFF,0x1FFF,0x0FFF,0x07FF,0x03FF,0x01FF,0x00FF,0x007F,0x003F,0x001F,0x000F,0x0007,0x0003,0x0001,0x0000};
unsigned int i,j;
int main(void)
{
    Config();
    while(1)
    {
        // Sang tat ca led
        GPIO_SetBits(GPIOA, GPIO_Pin_All);
        Delay(500);
        // Tat tat ca led
        GPIO_ResetBits(GPIOA, GPIO_Pin_All);
        Delay(500);
        // Sang dan tung led
        for(i=0; i<16; i++)
        {
            GPIO_Write(GPIOA, sangdan[i]);
            Delay(500);
        }
        // Toi dan tung led
        for(i=0; i<!6; i++)
        {
            GPIO_Write(GPIOA, toidan[i]);
            Delay(500);
        }
    }
}
// Delay func
void Delay(uint32_t t)
{    
    for(i=0;i<t;i++)
    {
        for(j=0;j< 0x2AFF; j++);
    }
}
// Config func
void Config()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}


