#include "include_all.h"


void ec_init(void)
{
    if(!InitializeWinIo())
    {
        ShutdownWinIo();
        qDebug() << "Fail";
    }
    else
    {
        qDebug() << "init io success";
    }

}
unsigned char EC_Read_Data(unsigned short Addr)
{
    DWORD data = 0x00;

    SetPortVal(EC_ADDR_PORT,0x2E,1);
    SetPortVal(EC_DATA_PORT,0x11,1);
    SetPortVal(EC_ADDR_PORT,0x2F,1);
    SetPortVal(EC_DATA_PORT,Addr >> 8,1);

    SetPortVal(EC_ADDR_PORT,0x2E,1);
    SetPortVal(EC_DATA_PORT,0x10,1);
    SetPortVal(EC_ADDR_PORT,0x2F,1);
    SetPortVal(EC_DATA_PORT,Addr &0xFF,1);

    SetPortVal(EC_ADDR_PORT,0x2E,1);
    SetPortVal(EC_DATA_PORT,0x12,1);
    SetPortVal(EC_ADDR_PORT,0x2F,1);
    GetPortVal(EC_DATA_PORT,&data,1);

    return(data);
}
