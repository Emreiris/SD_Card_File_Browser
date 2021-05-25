################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/lvgl/src/lv_widgets/subdir.mk
-include Core/lvgl/src/lv_themes/subdir.mk
-include Core/lvgl/src/lv_misc/subdir.mk
-include Core/lvgl/src/lv_hal/subdir.mk
-include Core/lvgl/src/lv_gpu/subdir.mk
-include Core/lvgl/src/lv_font/subdir.mk
-include Core/lvgl/src/lv_draw/subdir.mk
-include Core/lvgl/src/lv_core/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Modules_cpp/sdram_cpp/subdir.mk
-include Core/Modules_cpp/screen_cpp/touch_screen/subdir.mk
-include Core/Modules_cpp/screen_cpp/displayer/subdir.mk
-include Core/Modules_cpp/file_manager_cpp/subdir.mk
-include Core/Modules/audio_handler/subdir.mk
-include Core/Modules/Screen/Touch_Screen/subdir.mk
-include Core/Modules/Screen/Displayer/subdir.mk
-include Core/Modules/SDRAM/subdir.mk
-include Core/Modules/File_Manager/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SD_Card_File_System
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SD_Card_File_System.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SD_Card_File_System.list \

OBJCOPY_BIN += \
SD_Card_File_System.bin \


# All Target
all: main-build

# Main-build Target
main-build: SD_Card_File_System.elf secondary-outputs

# Tool invocations
SD_Card_File_System.elf: $(OBJS) $(USER_OBJS) D:\Warm\ up\ Projects\Embedded\ Software\ Projects\ST\ Projects\STM32F7\SD_Card_File_Browser\STM32F746NGHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "SD_Card_File_System.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\Warm up Projects\Embedded Software Projects\ST Projects\STM32F7\SD_Card_File_Browser\STM32F746NGHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SD_Card_File_System.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SD_Card_File_System.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SD_Card_File_System.list"
	@echo 'Finished building: $@'
	@echo ' '

SD_Card_File_System.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "SD_Card_File_System.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
