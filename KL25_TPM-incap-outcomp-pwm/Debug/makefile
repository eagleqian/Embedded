################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 08_Source/subdir.mk
-include 07_Soft_Component/printf/subdir.mk
-include 06_App_Component/light/subdir.mk
-include 05_Driver/uart/subdir.mk
-include 05_Driver/tpm/subdir.mk
-include 05_Driver/gpio/subdir.mk
-include 03_MCU/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
KL25_TPM-incap-outcomp-pwm.hex \

SECONDARY_LIST += \
KL25_TPM-incap-outcomp-pwm.lst \


# All Target
all: KL25_TPM-incap-outcomp-pwm.elf secondary-outputs

# Tool invocations
KL25_TPM-incap-outcomp-pwm.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -T "F:/kds/KL25_TPM-incap-outcomp-pwm/04_Linker_File/intflash.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"KL25_TPM-incap-outcomp-pwm.map" -n -o "KL25_TPM-incap-outcomp-pwm.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KL25_TPM-incap-outcomp-pwm.hex: KL25_TPM-incap-outcomp-pwm.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "KL25_TPM-incap-outcomp-pwm.elf"  "KL25_TPM-incap-outcomp-pwm.hex"
	@echo 'Finished building: $@'
	@echo ' '

KL25_TPM-incap-outcomp-pwm.lst: KL25_TPM-incap-outcomp-pwm.elf
	@echo 'Invoking: Cross ARM GNU Create Listing'
	arm-none-eabi-objdump --source --all-headers --demangle --line-numbers --wide "KL25_TPM-incap-outcomp-pwm.elf" > "KL25_TPM-incap-outcomp-pwm.lst"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(CC_DEPS)$(SECONDARY_FLASH)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS)$(SECONDARY_LIST)$(S_UPPER_DEPS) KL25_TPM-incap-outcomp-pwm.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
