################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Condition.cpp \
../src/Filters.cpp \
../src/Mutex.cpp \
../src/Signal.cpp \
../src/Thread.cpp \
../src/main.cpp 

OBJS += \
./src/Condition.o \
./src/Filters.o \
./src/Mutex.o \
./src/Signal.o \
./src/Thread.o \
./src/main.o 

CPP_DEPS += \
./src/Condition.d \
./src/Filters.d \
./src/Mutex.d \
./src/Signal.d \
./src/Thread.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ubuntu/workspace/DP-303/feabhOS/C/common/inc" -I"/home/ubuntu/workspace/DP-303/feabhOS/C/POSIX/inc" -I"/home/ubuntu/workspace/DP-303/feabhOS/C++/inc" -I"/home/ubuntu/workspace/DP-303/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ubuntu/workspace/DP-303/feabhOS/C/common/inc" -I"/home/ubuntu/workspace/DP-303/feabhOS/C/POSIX/inc" -I"/home/ubuntu/workspace/DP-303/feabhOS/C++/inc" -I"/home/ubuntu/workspace/DP-303/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


