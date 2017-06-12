#include "I2C.h"

uint8_t tick_us(uint32_t* t) {
	if((*t) >= I2C_TIMEOUT) return 1;
	
	(*t)++;
	Delay_us(1);
	
	return 0;
}

void I2C01_Init() {
	I2C1_Init();
}
void I2C01_Reset() {
	STOP_I2C1_CR1_bit = 1;
	PE_I2C1_CR1_bit = 0;
	Delay_ms(10);
	PE_I2C1_CR1_bit = 1;
	I2C1_Init();
}
uint8_t I2C01_Start() {
	uint32_t t = 0;
	
	while(BUSY_I2C1_SR2_bit) if(tick_us(&t)) return I2C_STATUS_BUS_BUSY;
	
	START_I2C1_CR1_bit = 1;
	
	t = 0;
	while(!SB_I2C1_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
	
	return I2C_STATUS_OK;
}
uint8_t I2C01_Send_Address(uint8_t address, uint8_t rnw) {
	uint16_t x;
	uint32_t t = 0;

	while(!SB_I2C1_SR1_bit) if(tick_us(&t)) return I2C_STATUS_NO_START;
	
	I2C1_DR = (address << 1) | (rnw ? 1 : 0);
	
	while(!ADDR_I2C1_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
	
	if(AF_I2C1_SR1_bit) return I2C_STATUS_ACK_ERROR;
	
	x = I2C1_SR1;
	if(x) x = 0; // NEED THIS CUZ COMPILER IS SH*T
	x = I2C1_SR2;
	if(x) x = 0; // NEED THIS CUZ COMPILER IS SH*T
	
	return I2C_STATUS_OK;
}
uint8_t I2C01_Read(uint8_t address, uint8_t* dst, uint32_t count, uint8_t restart) {
	uint8_t bus_status;
	uint32_t i = 0, t = 0;
	
	bus_status = I2C01_Send_Address(address, 1);
	
	if(bus_status == I2C_STATUS_OK) {
		while(i < count) {
			ACK_I2C1_CR1_bit = !!(i < count - 1);
			
			while(!RxNE_I2C1_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
			
			*(dst + i) = I2C1_DR;
			
			i++;
		}
		
		STOP_I2C1_CR1_bit = (!restart ? 1 : 0);
		START_I2C1_CR1_bit = (restart ? 1 : 0);
		
		return I2C_STATUS_OK;
	}
	
	return bus_status;
}
uint8_t I2C01_Write(uint8_t address, uint8_t* src, uint32_t count, uint8_t restart) {
	uint8_t bus_status;
	uint32_t i = 0, t = 0;
	
	bus_status = I2C01_Send_Address(address, 0);
	
	if(bus_status == I2C_STATUS_OK) {
		while(i < count) {
			t = 0;
			
			while(!TxE_I2C1_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
			
			I2C1_DR = *(src + i);
			
			i++;
		}
		
		while(!BTF_I2C1_SR1_bit) {
			if(tick_us(&t)) {
				if(AF_I2C1_SR1_bit) return I2C_STATUS_ACK_ERROR;
				return I2C_STATUS_TIMED_OUT;
			}
		}
		
		STOP_I2C1_CR1_bit = (!restart ? 1 : 0);
		START_I2C1_CR1_bit = (restart ? 1 : 0);
		
		return I2C_STATUS_OK;
	}
	
	return bus_status;
}


void I2C02_Init() {
	I2C2_Init();
}
void I2C02_Reset() {
	STOP_I2C2_CR1_bit = 1;
	PE_I2C2_CR1_bit = 0;
	Delay_ms(10);
	PE_I2C2_CR1_bit = 1;
	I2C2_Init();
}
uint8_t I2C02_Start() {
	uint32_t t = 0;
	
	while(BUSY_I2C2_SR2_bit) if(tick_us(&t)) return I2C_STATUS_BUS_BUSY;
	
	START_I2C2_CR1_bit = 1;
	
	t = 0;
	while(!SB_I2C2_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
	
	return I2C_STATUS_OK;
}
uint8_t I2C02_Send_Address(uint8_t address, uint8_t rnw) {
	uint16_t x;
	uint32_t t = 0;

	while(!SB_I2C2_SR1_bit) if(tick_us(&t)) return I2C_STATUS_NO_START;
	
	I2C2_DR = (address << 1) | (rnw ? 1 : 0);
	
	while(!ADDR_I2C2_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
	
	if(AF_I2C2_SR1_bit) return I2C_STATUS_ACK_ERROR;
	
	x = I2C2_SR1;
	if(x) x = 0; // NEED THIS CUZ COMPILER IS SH*T
	x = I2C2_SR2;
	if(x) x = 0; // NEED THIS CUZ COMPILER IS SH*T
	
	return I2C_STATUS_OK;
}
uint8_t I2C02_Read(uint8_t address, uint8_t* dst, uint32_t count, uint8_t restart) {
	uint8_t bus_status;
	uint32_t i = 0, t = 0;
	
	bus_status = I2C02_Send_Address(address, 1);
	
	if(bus_status == I2C_STATUS_OK) {
		while(i < count) {
			ACK_I2C2_CR1_bit = !!(i < count - 1);
			
			while(!RxNE_I2C2_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
			
			*(dst + i) = I2C2_DR;
			
			i++;
		}
		
		STOP_I2C2_CR1_bit = (!restart ? 1 : 0);
		START_I2C2_CR1_bit = (restart ? 1 : 0);
		
		return I2C_STATUS_OK;
	}
	
	return bus_status;
}
uint8_t I2C02_Write(uint8_t address, uint8_t* src, uint32_t count, uint8_t restart) {
	uint8_t bus_status;
	uint32_t i = 0, t = 0;
	
	bus_status = I2C02_Send_Address(address, 0);
	
	if(bus_status == I2C_STATUS_OK) {
		while(i < count) {
			t = 0;
			
			while(!TxE_I2C2_SR1_bit) if(tick_us(&t)) return I2C_STATUS_TIMED_OUT;
			
			I2C2_DR = *(src + i);
			
			i++;
		}
		
		while(!BTF_I2C2_SR1_bit) {
			if(tick_us(&t)) {
				if(AF_I2C2_SR1_bit) return I2C_STATUS_ACK_ERROR;
				return I2C_STATUS_TIMED_OUT;
			}
		}
		
		STOP_I2C2_CR1_bit = (!restart ? 1 : 0);
		START_I2C2_CR1_bit = (restart ? 1 : 0);
		
		return I2C_STATUS_OK;
	}
	
	return bus_status;
}