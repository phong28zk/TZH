#include"stm32f10x.h"
#define GPIO_Struct GPIO_InitTypeDef
void Config()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_Struct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Struct.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_Struct);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_Struct.GPIO_Mode = GPIO_Mode_Out_IPU;
    GPIO_Struct.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_Struct);
}
// Delay function
void Delay(uint_32 t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
    {
        for(j=0;j<0x2AFF;j++);
    }
}
int main()
{
    uint16_t status = 0;
    Config();
    while(1)
    {
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)==0) GPIO_SetBits(GPIOA, GPIO_Pin_0);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)==0) GPIO_SetBits(GPIOA, GPIO_Pin_1);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)==0) GPIO_SetBits(GPIOA, GPIO_Pin_2);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)==0) GPIO_SetBits(GPIOA, GPIO_Pin_3);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12)==0) GPIO_SetBits(GPIOA, GPIO_Pin_4);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_13)==0) GPIO_SetBits(GPIOA, GPIO_Pin_5);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_14)==0) GPIO_SetBits(GPIOA, GPIO_Pin_6);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)==0) GPIO_SetBits(GPIOA, GPIO_Pin_7);

        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_0);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_1);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_2);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_3);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_4);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_13)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_14)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_6);
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)==1) GPIO_ResetBits(GPIOA, GPIO_Pin_7);

    }
}