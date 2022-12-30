#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define BUTTON              GPIO_Pin_2
#define PORT_BUTTON         GPIOC
#define PORT_BUTTON_CLOCK   RCC_APB2Periph_GPIOC

#define LED              GPIO_Pin_5
#define PORT_LED         GPIOB
#define PORT_LED_CLOCK   RCC_APB2Periph_GPIOB

#define LED_ON           GPIO_ResetBits(PORT_LED, LED);
#define LED_OFF          GPIO_SetBits(PORT_LED, LED);

void Delay(uint32_t);
void GPIO_Config(void);
void Clock_Config(void);

int main(void)
{
    Clock_Config(); // configuraion clock
    SystemCoreClockUpdate(); // update SystemCoreClock varibale
    GPIO_Config();

    while(1){
        
        if(GPIO_ReadInputDataBit(PORT_BUTTON, BUTTON)==0){
            LED_ON
        }
        else{
            LED_OFF
        }
    }
}
/*Delay tuong doi*/
void Delay(uint32_t t){
    unsigned int i,j;
    
    for(i=0;i<t;i++){
        for(j=0;j< 0x2AFF; j++);
    }

}
void GPIO_Config(){
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /*enble clock for GPIOC*/
    RCC_APB2PeriphClockCmd(PORT_BUTTON_CLOCK|PORT_LED_CLOCK, ENABLE);
    
    /*Configuration GPIO pin*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin  = BUTTON;
    GPIO_Init(PORT_BUTTON,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin  = LED;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(PORT_LED, &GPIO_InitStructure);
}