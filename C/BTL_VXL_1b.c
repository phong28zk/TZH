#include "stm32f10x.h"                  // Device header

#define CLOCK      GPIO_Pin_0
#define DATA       GPIO_Pin_1
#define DATA_LOCK  GPIO_Pin_2


int mang[9] = {0X00, 0X01, 0X03, 0X07, 0X0F, 0X1F, 0X3F, 0X7F, 0XFF};
int mang_2[9] = {0X00, 0X80, 0XC0, 0XE0, 0XF0, 0XF8, 0XFC, 0XFE, 0XFF};

int snake_eff[9]={0X01, 0X03, 0X06, 0X0C, 0X18, 0X30, 0X60, 0XC0, 0X80};


int butterfly_eff1[9]={0X00, 0X01, 0X03, 0X07, 0X0F, 0X1F, 0X3F, 0X7F, 0XFF};
int butterfly_eff2[9]={0X00, 0X80, 0XC0, 0XE0, 0XF0, 0XF8, 0XFC, 0XFE, 0XFF};



int i;

void Config(void);
void Delay(uint16_t Time);

void Send_1_Byte(int dulieu);
void Send_4_Byte(int dulieu1, int dulieu2, int dulieu3, int dulieu4);
void Write_4byte(uint32_t CMD);

int main()
{
	Config();
	while(1)
	{
		// Sang dan tu den dau tien toi den cuoi cung								
		for(i=0; i<9; i++)
		{
			Send_4_Byte(mang[i],0X00, 0X00, 0X00);
			Delay(75);
		}
		for(i=1; i<9; i++)
		{
			Send_4_Byte(0XFF, mang[i], 0X00, 0X00);
			Delay(75);
		}
		for(i=1; i<9; i++)
		{
			Send_4_Byte(0XFF, 0XFF, mang[i], 0X00);
			Delay(75);
		}
		for(i=1; i<9; i++)
		{
			Send_4_Byte(0XFF, 0XFF, 0XFF, mang[i]);
			Delay(75);
		}
		// Tat dan tu led dau tien toi led cuoi cung				
		for(i=8; i>=0; i--)
		{
			Send_4_Byte(mang_2[i], 0XFF, 0XFF, 0XFF);
			Delay(75);
		}
		for(i=7; i>=0; i--)
		{
            Send_4_Byte(0X00, mang_2[i], 0XFF, 0XFF);
			Delay(75);
		}
		for(i=7; i>=0; i--)
		{
			Send_4_Byte(0X00, 0X00, mang_2[i], 0XFF);
			Delay(75);
		}
		for(i=7; i>=0; i--)
		{
			Send_4_Byte(0X00, 0X00, 0X00, mang_2[i]);
			Delay(75);
		}
		// Hieu ung Snake											
		for(i=0; i<8; i++)
		{
			Send_4_Byte(snake_eff[i],0X00, 0X00, 0X00);
			Delay(50);
		}
		Send_4_Byte(0X80, snake_eff[0], 0X00, 0X00);
		Delay(50);
		for(i=1; i<8; i++)
		{
			Send_4_Byte(0X00, snake_eff[i], 0X00, 0X00);
			Delay(50);
		}
		Send_4_Byte(0X00, 0X80, snake_eff[0], 0X00);
		Delay(50);
		for(i=1; i<8; i++)
		{
			Send_4_Byte(0X00, 0X00, snake_eff[i], 0X00);
			Delay(50);
		}
		Send_4_Byte(0X00, 0X00, 0X80, snake_eff[0]);
		Delay(50);
		for(i=1; i<9; i++)
		{
			Send_4_Byte(0X00, 0X00, 0X00, snake_eff[i]);
			Delay(50);
		} 
		// Hieu ung Butterfly
		// 1. Sang dan															
		for(i=0; i<9; i++)
		{
			Send_4_Byte(0X00, butterfly_eff2[i], butterfly_eff1[i], 0X00);
			Delay(50);
		}
		for(i=0; i<9; i++)
		{
			Send_4_Byte(butterfly_eff2[i],0xFF,0xFF,butterfly_eff1[i]);
			Delay(50);
		}
		// 2. Tat dan tu ngoai vao trong
		for(i=8; i>=0; i--)
		{
			Send_4_Byte(butterfly_eff2[i],0xFF, 0xFF, butterfly_eff1[i]);
			Delay(50);
		}
		for(i=8; i>=0; i--)
		{
			Send_4_Byte(0X00,butterfly_eff2[i], butterfly_eff1[i], 0X00);
			Delay(50);
		}
		// 3. Sang dan tro lai
		for(i=0; i<9; i++)
		{
			Send_4_Byte(butterfly_eff1[i],0X00, 0X00, butterfly_eff2[i]);
			Delay(50);
		}
		for(i=0; i<9; i++)
		{
			Send_4_Byte(0xFF,butterfly_eff1[i], butterfly_eff2[i], 0xFF);
			Delay(50);
		}
		// 4. Tat dan tu trong ra ngoai
		for(i=8; i>=0; i--)
		{
			Send_4_Byte(0XFF,butterfly_eff1[i], butterfly_eff2[i], 0XFF);
			Delay(50);
		}
		for(i=7; i>=0; i--)
		{
			Send_4_Byte(butterfly_eff1[i],0x00, 0x00,butterfly_eff2[i]);
			Delay(50);
		}
	}		
}

void Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;		
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
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


void Send_1_Byte(int dulieu)
{
	int k;
	for(k=1; k <= 8; k++ )// Ghi va dich du lieu
	{
		GPIO_WriteBit(GPIOA,DATA,(dulieu >> (8 - k)) & 1);	// Dịch dữ liệu sang phải 8-k bit và lấy bit cuối cùng
		GPIO_WriteBit(GPIOA,CLOCK,0);						
		GPIO_WriteBit(GPIOA,CLOCK,1);						
	}	
	GPIO_WriteBit(GPIOA,DATA_LOCK,0);						
	GPIO_WriteBit(GPIOA,DATA_LOCK,1);
}

void Send_4_Byte(int dulieu1, int dulieu2, int dulieu3, int dulieu4)
{
	Send_1_Byte(dulieu4);
	Send_1_Byte(dulieu3);
	Send_1_Byte(dulieu2);
	Send_1_Byte(dulieu1);
}
