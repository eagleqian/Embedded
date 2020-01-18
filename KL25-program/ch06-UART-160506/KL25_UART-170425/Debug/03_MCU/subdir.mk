################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../03_MCU/system_MKL25Z4.c 

S_UPPER_SRCS += \
../03_MCU/startup_MKL25Z4.S 

OBJS += \
./03_MCU/startup_MKL25Z4.o \
./03_MCU/system_MKL25Z4.o 

C_DEPS += \
./03_MCU/system_MKL25Z4.d 

S_UPPER_DEPS += \
./03_MCU/startup_MKL25Z4.d 


# Each subdirectory must supply rules for building sources it contributes
03_MCU/%.o: ../03_MCU/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

03_MCU/%.o: ../03_MCU/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/08_Source" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/07_Soft_Component" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/07_Soft_Component/common" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/07_Soft_Component/printf" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/04_Linker_File" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/05_Driver/uart" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/06_App_Component" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/06_App_Component/light" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/05_Driver" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/03_MCU" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/02_CPU" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/01_Doc" -I"E:/2013-2017 BOOK-170523/2012-2016 M0+-170523/06-User/SD-(M0+)-CD(V2.6)-170401/02-Software/KL25-program-160611/ch06-UART-160506/KL25_UART-170425/05_Driver/gpio" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

