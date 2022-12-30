#include"stm32f10x.h"
int Sang[2]={0x5555,0xAAAA};
void Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;		
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void Delay(uint16_t Time)
{
	int i = 0;
	while(Time--)
	{
		for(i = 0 ; i < 0x2aff; i++);
	}
}
int main()
{
    Config();
    // Phan a
    for(int i=0; i<10; i++)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_All);
        Delay(1000);
        GPIO_ResetBits(GPIOA, GPIO_Pin_All);
        Delay(1000);
    }
    // Phan b
    for(int i=0; i<5; i++)
    {
        GPIO_Write(GPIOA, Sang[0]);
        Delay(500);
        GPIO_Write(GPIOA, Sang[1]);
        Delay(500);
    }
}