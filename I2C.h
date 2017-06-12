#include <stdint.h>

#ifndef I2C_h
#define I2C_h

#define SWRST_I2C1_CR1_bit I2C1_CR1.B15
#define ALERT_I2C1_CR1_bit I2C1_CR1.B13
#define PEC_I2C1_CR1_bit I2C1_CR1.B12
#define POS_I2C1_CR1_bit I2C1_CR1.B11
#define ACK_I2C1_CR1_bit I2C1_CR1.B10
#define STOP_I2C1_CR1_bit I2C1_CR1.B9
#define START_I2C1_CR1_bit I2C1_CR1.B8
#define NOSTRETCH_I2C1_CR1_bit I2C1_CR1.B7
#define ENGC_I2C1_CR1_bit I2C1_CR1.B6
#define ENPEC_I2C1_CR1_bit I2C1_CR1.B5
#define ENARP_I2C1_CR1_bit I2C1_CR1.B4
#define SMBTYPE_I2C1_CR1_bit I2C1_CR1.B3
#define SMBUS_I2C1_CR1_bit I2C1_CR1.B1
#define PE_I2C1_CR1_bit I2C1_CR1.B0

#define SMBALERT_I2C1_SR1_bit I2C1_SR1.B15
#define TIMEOUT_I2C1_SR1_bit I2C1_SR1.B14
#define PECERR_I2C1_SR1_bit I2C1_SR1.B12
#define OVR_I2C1_SR1_bit I2C1_SR1.B11
#define AF_I2C1_SR1_bit I2C1_SR1.B10
#define ARLO_I2C1_SR1_bit I2C1_SR1.B9
#define BERR_I2C1_SR1_bit I2C1_SR1.B8
#define TxE_I2C1_SR1_bit I2C1_SR1.B7
#define RxNE_I2C1_SR1_bit I2C1_SR1.B6
#define STOPF_I2C1_SR1_bit I2C1_SR1.B4
#define ADD10_I2C1_SR1_bit I2C1_SR1.B3
#define BTF_I2C1_SR1_bit I2C1_SR1.B2
#define ADDR_I2C1_SR1_bit I2C1_SR1.B1
#define SB_I2C1_SR1_bit I2C1_SR1.B0

#define DUALF_I2C1_SR2_bit I2C1_SR2.B7
#define SMBHOST_I2C1_SR2_bit I2C1_SR2.B6
#define SMBDEFAULT_I2C1_SR2_bit I2C1_SR2.B5
#define GENCALL_I2C1_SR2_bit I2C1_SR2.B4
#define TRA_I2C1_SR2_bit I2C1_SR2.B2
#define BUSY_I2C1_SR2_bit I2C1_SR2.B1
#define MSL_I2C1_SR2_bit I2C1_SR2.B0


#define SWRST_I2C2_CR1_bit I2C2_CR1.B15
#define ALERT_I2C2_CR1_bit I2C2_CR1.B13
#define PEC_I2C2_CR1_bit I2C2_CR1.B12
#define POS_I2C2_CR1_bit I2C2_CR1.B11
#define ACK_I2C2_CR1_bit I2C2_CR1.B10
#define STOP_I2C2_CR1_bit I2C2_CR1.B9
#define START_I2C2_CR1_bit I2C2_CR1.B8
#define NOSTRETCH_I2C2_CR1_bit I2C2_CR1.B7
#define ENGC_I2C2_CR1_bit I2C2_CR1.B6
#define ENPEC_I2C2_CR1_bit I2C2_CR1.B5
#define ENARP_I2C2_CR1_bit I2C2_CR1.B4
#define SMBTYPE_I2C2_CR1_bit I2C2_CR1.B3
#define SMBUS_I2C2_CR1_bit I2C2_CR1.B1
#define PE_I2C2_CR1_bit I2C2_CR1.B0

#define SMBALERT_I2C2_SR1_bit I2C2_SR1.B15
#define TIMEOUT_I2C2_SR1_bit I2C2_SR1.B14
#define PECERR_I2C2_SR1_bit I2C2_SR1.B12
#define OVR_I2C2_SR1_bit I2C2_SR1.B11
#define AF_I2C2_SR1_bit I2C2_SR1.B10
#define ARLO_I2C2_SR1_bit I2C2_SR1.B9
#define BERR_I2C2_SR1_bit I2C2_SR1.B8
#define TxE_I2C2_SR1_bit I2C2_SR1.B7
#define RxNE_I2C2_SR1_bit I2C2_SR1.B6
#define STOPF_I2C2_SR1_bit I2C2_SR1.B4
#define ADD10_I2C2_SR1_bit I2C2_SR1.B3
#define BTF_I2C2_SR1_bit I2C2_SR1.B2
#define ADDR_I2C2_SR1_bit I2C2_SR1.B1
#define SB_I2C2_SR1_bit I2C2_SR1.B0

#define DUALF_I2C2_SR2_bit I2C2_SR2.B7
#define SMBHOST_I2C2_SR2_bit I2C2_SR2.B6
#define SMBDEFAULT_I2C2_SR2_bit I2C2_SR2.B5
#define GENCALL_I2C2_SR2_bit I2C2_SR2.B4
#define TRA_I2C2_SR2_bit I2C2_SR2.B2
#define BUSY_I2C2_SR2_bit I2C2_SR2.B1
#define MSL_I2C2_SR2_bit I2C2_SR2.B0


#define I2C_STATUS_OK 0x00
#define I2C_STATUS_NO_START 0xFC
#define I2C_STATUS_ACK_ERROR 0xFD
#define I2C_STATUS_BUS_BUSY 0xFE
#define I2C_STATUS_TIMED_OUT 0xFF

#define I2C_TIMEOUT 20000

uint8_t tick_us(uint32_t* t);

extern void I2C01_Init();
extern void I2C01_Reset();
extern uint8_t I2C01_Start();
void I2C01_Send_Address(uint8_t address, uint8_t rnw);
extern uint8_t I2C01_Read(uint8_t address, uint8_t* dst, uint32_t count, uint8_t restart);
extern uint8_t I2C01_Write(uint8_t address, uint8_t* src, uint32_t count, uint8_t restart);


extern void I2C02_Init();
extern void I2C02_Reset();
extern uint8_t I2C02_Start();
void I2C02_Send_Address(uint8_t address, uint8_t rnw);
extern uint8_t I2C02_Read(uint8_t address, uint8_t* dst, uint32_t count, uint8_t restart);
extern uint8_t I2C02_Write(uint8_t address, uint8_t* src, uint32_t count, uint8_t restart);

#endif /* #ifndef I2C_h */
