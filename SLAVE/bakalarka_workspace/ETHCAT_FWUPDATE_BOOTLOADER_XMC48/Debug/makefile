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
-include Dave/Generated/subdir.mk
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
ETHCAT_FWUPDATE_BOOTLOADER_XMC48.hex \

SECONDARY_LIST += \
ETHCAT_FWUPDATE_BOOTLOADER_XMC48.lst \

SECONDARY_SIZE += \
ETHCAT_FWUPDATE_BOOTLOADER_XMC48.siz \


LIST_FILES = $(addsuffix .o.lst, $(basename $(OBJS))) 
MAP_FILE = "ETHCAT_FWUPDATE_BOOTLOADER_XMC48.map"

TOOLCHAIN_ROOT=C:/Program Files/DAVE-IDE-4.4.2-64Bit/eclipse/ARM-GCC-49
PROJECT_LOC=C:/src/bakalarka_workspace/ETHCAT_FWUPDATE_BOOTLOADER_XMC48

# All Target
all: ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf secondary-outputs

# Tool invocations
ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf: $(OBJS) ../linker_script.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	$(file >objects.rsp,$(OBJS))
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -T"../linker_script.ld" -nostartfiles -Xlinker --gc-sections -specs=nano.specs -specs=nosys.specs -Wl,-Map,$(MAP_FILE) -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf" "@objects.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo.
ETHCAT_FWUPDATE_BOOTLOADER_XMC48.hex: ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objcopy" -O ihex "ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf" "ETHCAT_FWUPDATE_BOOTLOADER_XMC48.hex"
	@echo 'Finished building: $@'
	@echo.
ETHCAT_FWUPDATE_BOOTLOADER_XMC48.lst: ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objdump" -h -S "ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf" > "ETHCAT_FWUPDATE_BOOTLOADER_XMC48.lst"
	@echo 'Finished building: $@'
	@echo.
ETHCAT_FWUPDATE_BOOTLOADER_XMC48.siz: ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-size" --format=berkeley "ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf"
	@echo 'Finished building: $@'
	@echo.
# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) ETHCAT_FWUPDATE_BOOTLOADER_XMC48.elf $(LIST_FILES) $(MAP_FILE) objects.rsp
	-@echo.
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
