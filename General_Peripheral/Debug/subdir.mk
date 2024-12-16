################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DIO_program.c \
../EEPROM_program.c \
../Keypad_program.c \
../LCD_program.c \
../TWI_program.c \
../Timer1_program.c \
../UART_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./DIO_program.o \
./EEPROM_program.o \
./Keypad_program.o \
./LCD_program.o \
./TWI_program.o \
./Timer1_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./DIO_program.d \
./EEPROM_program.d \
./Keypad_program.d \
./LCD_program.d \
./TWI_program.d \
./Timer1_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


