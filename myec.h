#ifndef MYEC_H
#define MYEC_H

#include <QWidget>

//class ec: public QWidget
#define EC_ADDR_PORT    0x4E
#define EC_DATA_PORT    0x4F

void ec_init(void);
unsigned char EC_Read_Data(unsigned short Addr);


#endif // MYEC_H
