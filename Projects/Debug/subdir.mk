################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../Counter_program.c \
../DIO_program.c \
../EXTI_program.c \
../GIE_program.c \
../HEXA_program.c \
../Keypad_program.c \
../LCD_program.c \
../LED_program.c \
../Timer0_program.c \
../Timer1_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./Counter_program.o \
./DIO_program.o \
./EXTI_program.o \
./GIE_program.o \
./HEXA_program.o \
./Keypad_program.o \
./LCD_program.o \
./LED_program.o \
./Timer0_program.o \
./Timer1_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./Counter_program.d \
./DIO_program.d \
./EXTI_program.d \
./GIE_program.d \
./HEXA_program.d \
./Keypad_program.d \
./LCD_program.d \
./LED_program.d \
./Timer0_program.d \
./Timer1_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


