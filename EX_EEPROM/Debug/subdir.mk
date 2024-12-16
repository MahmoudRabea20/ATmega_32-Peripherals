################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../EEPROM.c \
../EEPROM_program.c \
../EX_EEPROM_program.c \
../HEXA_program.c \
../IIC_prog.c \
../Keypad_program.c \
../LCD_program.c \
../TWI_program.c \
../UART_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./EEPROM.o \
./EEPROM_program.o \
./EX_EEPROM_program.o \
./HEXA_program.o \
./IIC_prog.o \
./Keypad_program.o \
./LCD_program.o \
./TWI_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./EEPROM.d \
./EEPROM_program.d \
./EX_EEPROM_program.d \
./HEXA_program.d \
./IIC_prog.d \
./Keypad_program.d \
./LCD_program.d \
./TWI_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


