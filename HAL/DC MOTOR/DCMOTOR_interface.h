#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H


uint8 DCMotor_u8RotatCW(uint8 copy_u8PortNumber,uint8 copy_u8CWPin,uint8 copy_u8CCWPin );
uint8 DCMOTOR_u8RotatCCW(uint8 copy_u8PortNumber,uint8 copy_u8CWPin,uint8 copy_u8CCWPin );
uint8 DCMOTOR_u8Stop(uint8 copy_u8PortNumber,uint8 copy_u8CWPin,uint8 copy_u8CCWPin);
#endif
