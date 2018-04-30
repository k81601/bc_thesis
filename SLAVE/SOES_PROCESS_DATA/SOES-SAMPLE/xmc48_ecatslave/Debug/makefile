################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Libraries/XMCLib/src/subdir.mk
-include Libraries/Newlib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
xmc48_ecatslave.hex \

SECONDARY_LIST += \
xmc48_ecatslave.lst \

SECONDARY_SIZE += \
xmc48_ecatslave.siz \


LIST_FILES = $(addsuffix .o.lst, $(basename $(OBJS))) 
MAP_FILE = "xmc48_ecatslave.map"

TOOLCHAIN_ROOT=C:/DAVEv4-64Bit/DAVE-4.3.2/eclipse/ARM-GCC-49
PROJECT_LOC=C:/Workspaces/SOES-SAMPLE/xmc48_ecatslave

# All Target
all: pre-build main-build

# Main-build Target
main-build: xmc48_ecatslave.elf secondary-outputs

# Tool invocations
xmc48_ecatslave.elf: $(OBJS) ../linker_script.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	$(file >objects.rsp,$(OBJS))
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -T"../linker_script.ld" -nostartfiles -Xlinker --gc-sections -specs=nosys.specs -L"C:\Workspaces\SOES-SAMPLE\soes\Debug" -Wl,-Map,$(MAP_FILE) -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "xmc48_ecatslave.elf" "@objects.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo.
xmc48_ecatslave.hex: xmc48_ecatslave.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objcopy" -O ihex "xmc48_ecatslave.elf" "xmc48_ecatslave.hex"
	@echo 'Finished building: $@'
	@echo.
xmc48_ecatslave.lst: xmc48_ecatslave.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objdump" -h -S "xmc48_ecatslave.elf" > "xmc48_ecatslave.lst"
	@echo 'Finished building: $@'
	@echo.
xmc48_ecatslave.siz: xmc48_ecatslave.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-size" --format=berkeley "xmc48_ecatslave.elf"
	@echo 'Finished building: $@'
	@echo.
# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) xmc48_ecatslave.elf $(LIST_FILES) $(MAP_FILE) objects.rsp
	-@echo.
pre-build:
	-copy "..\xmc4800_slave.bin" sii_eeprom.bin & "C:\DAVEv4-64Bit\DAVE-4.3.2\eclipse\ARM-GCC-49/bin/arm-none-eabi-objcopy.exe" -I binary -O elf32-littlearm -B arm sii_eeprom.bin sii_eeprom.o
	-@echo.
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets
