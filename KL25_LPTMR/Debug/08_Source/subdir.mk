################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../08_Source/isr.c \
../08_Source/main.c 

OBJS += \
./08_Source/isr.o \
./08_Source/main.o 

C_DEPS += \
./08_Source/isr.d \
./08_Source/main.d 


# Each subdirectory must supply rules for building sources it contributes
08_Source/%.o: ../08_Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/08_Source" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/07_Soft_Component" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/07_Soft_Component/common" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/07_Soft_Component/printf" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/04_Linker_File" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/05_Driver/uart" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/06_App_Component" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/06_App_Component/light" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/05_Driver" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/03_MCU" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/02_CPU" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/01_Doc" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/05_Driver/gpio" -I"C:/Users/ACER-BC/Desktop/KL25BOOKLS/KL25-program/ch07-Timer(bc-pnn)/KL25_LPTMR/05_Driver/lptmr" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


