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


//GPIO����
BOOL Gpio_Set();
//GPIO״̬��ȡ
BOOL Gpio_Get();
//ѡ��ȫ��GPIO��ƽ
VOID GpioSetDataAll();
//ʹ��ȫ��GPIO
VOID GpioEnableAll();
//ѡ��ȫ��GPIO����
VOID GpioSetDirAll();