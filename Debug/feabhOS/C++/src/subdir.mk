################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../feabhOS/C++/src/Scheduler.cpp 

OBJS += \
./feabhOS/C++/src/Scheduler.o 

CPP_DEPS += \
./feabhOS/C++/src/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
feabhOS/C++/src/%.o: ../feabhOS/C++/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ubuntu/workspace/DP-303/feabhOS/C/common/inc" -I"/home/ubuntu/workspace/DP-303/feabhOS/C/POSIX/inc" -I"/home/ubuntu/workspace/DP-303/feabhOS/C++/inc" -I"/home/ubuntu/workspace/DP-303/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


