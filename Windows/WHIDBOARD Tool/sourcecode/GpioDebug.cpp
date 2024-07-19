/*****************************************************************************
**                      Copyright  (C)  WCH  2001-2022                      **
**                      Web:  http://wch.cn                                 **
******************************************************************************
Abstract:
  ����CH347 GPIO�ӿں�������Ӧ��ʾ��

Environment:
    user mode only,VC6.0 and later
Notes:
  Copyright (c) 2022 Nanjing Qinheng Microelectronics Co., Ltd.
Revision History:
  4/3/2022: TECH30
--*/


#include "Main.h"
#include "EepromDebug.h"

//ȫ�ֱ���
extern HWND SpiI2cGpioDebugHwnd;     //������
extern BOOL DevIsOpened;   //�豸�Ƿ��
extern BOOL SpiIsCfg;
extern ULONG SpiI2cGpioDevIndex;

//GPIOʹ�ܿؼ�ID
ULONG GpioEnCtrID[8] = {IDC_EnSet_Gpio0,IDC_EnSet_Gpio1,IDC_EnSet_Gpio2,IDC_EnSet_Gpio3,IDC_EnSet_Gpio4,IDC_EnSet_Gpio5,IDC_EnSet_Gpio6,IDC_EnSet_Gpio7};
//GPIO����ؼ�ID
ULONG GpioDirCtrID[8] = {IDC_Dir_Gpio0,IDC_Dir_Gpio1,IDC_Dir_Gpio2,IDC_Dir_Gpio3,IDC_Dir_Gpio4,IDC_Dir_Gpio5,IDC_Dir_Gpio6,IDC_Dir_Gpio7};
//GPIO��ƽ�ؼ�ID
ULONG GpioStaCtrID[8] = {IDC_Val_Gpio0,IDC_Val_Gpio1,IDC_Val_Gpio2,IDC_Val_Gpio3,IDC_Val_Gpio4,IDC_Val_Gpio5,IDC_Val_Gpio6,IDC_Val_Gpio7};

//GPIO����
BOOL Gpio_Set()
{
	ULONG i;
	UCHAR oEnable = 0;       //������Ч��־:��Ӧλ0-7,��ӦGPIO0-7.
	UCHAR oSetDirOut = 0;    //����I/O����,ĳλ��0���Ӧ����Ϊ����,ĳλ��1���Ӧ����Ϊ���.GPIO0-7��Ӧλ0-7.
	UCHAR oSetDataOut = 0;   //�������,���I/O����Ϊ���,��ôĳλ��0ʱ��Ӧ��������͵�ƽ,ĳλ��1ʱ��Ӧ��������ߵ�ƽ
	BOOL  RetVal;

	for(i=0;i<8;i++)
	{
		//ȡʹ��λ
		if( IsDlgButtonChecked(SpiI2cGpioDebugHwnd,GpioEnCtrID[i])==BST_CHECKED )
			oEnable |= (1<<i);
		//ȡ����
		if( IsDlgButtonChecked(SpiI2cGpioDebugHwnd,GpioDirCtrID[i])==BST_CHECKED )
			oSetDirOut |= (1<<i);
		//ȡ��ƽֵ
		if( IsDlgButtonChecked(SpiI2cGpioDebugHwnd,GpioStaCtrID[i])==BST_CHECKED )
			oSetDataOut |= (1<<i);
	}
	RetVal = CH347GPIO_Set(SpiI2cGpioDevIndex,oEnable,oSetDirOut,oSetDataOut);
	DbgPrint("CH347GPIO_SetOutput %s,oEnable:%02X,oSetDirOut:%02X,oSetDataOut:%02X",RetVal?"Succ":"Fail",oEnable,oSetDirOut,oSetDataOut);

	return RetVal;
}

//GPIO״̬��ȡ
BOOL Gpio_Get()
{
	BOOL RetVal;
	UCHAR iDir = 0,iData = 0,i,Sel;

	RetVal = CH347GPIO_Get(SpiI2cGpioDevIndex,&iDir,&iData);
	DbgPrint("CH347GPIO_Get %s,iDir:%02X,iData:%02X",RetVal?"Succ":"Fail",iDir,iData);
	if(RetVal)
	{
		for(i=0;i<8;i++)
		{		
			//��ʾ����
			Sel = (iDir&(1<<i))?BST_CHECKED:BST_UNCHECKED;
			CheckDlgButton(SpiI2cGpioDebugHwnd,GpioDirCtrID[i],Sel);				
			//��ƽֵ
			Sel = (iData&(1<<i))?BST_CHECKED:BST_UNCHECKED;
			CheckDlgButton(SpiI2cGpioDebugHwnd,GpioStaCtrID[i],Sel);
		}
	}
	return RetVal;
}

//ʹ��ȫ��GPIO
VOID GpioEnableAll()
{
	BOOL Sel;
	UCHAR i;

	Sel = IsDlgButtonChecked(SpiI2cGpioDebugHwnd,IDC_GpioEnableAll);
	for(i=0;i<8;i++)
		CheckDlgButton(SpiI2cGpioDebugHwnd,GpioEnCtrID[i],Sel);

	return;
}

//ѡ��ȫ��GPIO����
VOID GpioSetDirAll()
{
	BOOL Sel;
	UCHAR i;

	Sel = IsDlgButtonChecked(SpiI2cGpioDebugHwnd,IDC_GpioSetDirAll);
	for(i=0;i<8;i++)
		CheckDlgButton(SpiI2cGpioDebugHwnd,GpioDirCtrID[i],Sel);

	return;
}

//ѡ��ȫ��GPIO��ƽ
VOID GpioSetDataAll()
{
	BOOL Sel;
	UCHAR i;

	Sel = IsDlgButtonChecked(SpiI2cGpioDebugHwnd,IDC_GpioSetDataAll);
	for(i=0;i<8;i++)
		CheckDlgButton(SpiI2cGpioDebugHwnd,GpioStaCtrID[i],Sel);

	return;
}