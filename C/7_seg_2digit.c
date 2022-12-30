#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define LED7SEG_A   GPIO_Pin_0
#define LED7SEG_B   GPIO_Pin_1
#define LED7SEG_C   GPIO_Pin_2
#define LED7SEG_D   GPIO_Pin_3
#define LED7SEG_E   GPIO_Pin_4
#define LED7SEG_F   GPIO_Pin_5
#define LED7SEG_G   GPIO_Pin_6

#define LED7SEG_DP  GPIO_Pin_7
#define LED1        GPIO_Pin_1
#define LED2        GPIO_Pin_2

#define PORT_LED7SEG_CODE GPIOC
#define PORT_LED          GPIOA

#define PORT_LED7SEG_CODE_CLOCK     RCC_APB2Periph_GPIOC
#define PORT_LED_CLOCK              RCC_APB2Periph_GPIOA

void Delay(uint32_t);
void Config(void);
// Arr Cathode or Anode
uint16_t Cathode[11] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};
uint16_t Anode[11] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xFF};
int main(void)
{
    Config();
    while(1)
    {
        GPIO_Config();
    
        GPIO_ResetBits(PORT_LED, LED1);  //LED1 = 0;
        GPIO_ResetBits(PORT_LED, LED2); //LED2 = 0;
        
        while(1){
            for(uint8_t i = 0; i < 100; i++){
                for(uint8_t j = 0; j < 24; j++){
                    GPIO_Write(PORT_LED7SEG_CODE, Anode[i/10]);
                    GPIO_SetBits(PORT_LED, LED1);  // LED1 = 1 
                    Delay(1);

                    GPIO_ResetBits(PORT_LED, LED1); //LED1 = 0
                    GPIO_Write(PORT_LED7SEG_CODE, Anode[i%10]);
                    GPIO_SetBits(PORT_LED, LED2); //LED2 = 1
                    Delay(1);

                    GPIO_ResetBits(PORT_LED, LED2); //L7S2 = 0
                }
            }
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
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(PORT_LED7SEG_CODE_CLOCK|PORT_LED_CLOCK, ENABLE);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin  = LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G|LED7SEG_A|LED7SEG_DP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PORT_LED7SEG_CODE, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin  = LED1|LED2;
    GPIO_Init(PORT_LED, &GPIO_InitStructure);   

}


