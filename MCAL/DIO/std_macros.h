/*
 * std_macros.h
 *
 * Created: 12/2/2023 3:37:09 PM
 *  Author: sharasa
 */

#define  PORT_A 'A'
#define  PORT_B 'B'
#define  PORT_C 'C'
#define  PORT_D 'D'
/************************************************************************/
#define NOTPRESSED 0xff
#define HIGH 1
#define output 1
#define  LOW 0
#define  input 0
/************************************************************************/
#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define Read_bIT(reg,bit)    (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)        reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))
