#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
void Delay(uint32_t);
void Config(void);
// Use led anode
uint16_t Led7Seg[10]= {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int main(void)
{
    Config();
    while(1)
    {
        // Hien thi so tu 0 den 9
        for(int i=0; i<10; i++)
        {
            GPIO_Write(GPIOA, Led7Seg[i]);
            Delay(1000);
        }
        // Hien thi chi so chan
        for(int i=0; i<10; i+=2)
        {
            GPIO_Write(GPIOA, Led7Seg[i]);
            Delay(1000);
        }
        // Hien thi chi so le
        for(int i=1; i<10; i+=2)
        {
            GPIO_Write(GPIOA, Led7Seg[i]);
            Delay(1000);
        }
        // Reversed order
        for(int i=9; i>=0; i--)
        {
            GPIO_Write(GPIOA, Led7Seg[i]);
            Delay(1000);
        }
    }
}
// Delay func
void Delay(uint32_t t)
{
    unsigned int i,j;
    
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


