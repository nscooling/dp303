################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../feabhOS/C/POSIX/src/feabhOS_condition.c \
../feabhOS/C/POSIX/src/feabhOS_interrupts.c \
../feabhOS/C/POSIX/src/feabhOS_memory.c \
../feabhOS/C/POSIX/src/feabhOS_mutex.c \
../feabhOS/C/POSIX/src/feabhOS_queue.c \
../feabhOS/C/POSIX/src/feabhOS_scheduler.c \
../feabhOS/C/POSIX/src/feabhOS_semaphore.c \
../feabhOS/C/POSIX/src/feabhOS_signal.c \
../feabhOS/C/POSIX/src/feabhOS_task.c 

OBJS += \
./feabhOS/C/POSIX/src/feabhOS_condition.o \
./feabhOS/C/POSIX/src/feabhOS_interrupts.o \
./feabhOS/C/POSIX/src/feabhOS_memory.o \
./feabhOS/C/POSIX/src/feabhOS_mutex.o \
./feabhOS/C/POSIX/src/feabhOS_queue.o \
./feabhOS/C/POSIX/src/feabhOS_scheduler.o \
./feabhOS/C/POSIX/src/feabhOS_semaphore.o \
./feabhOS/C/POSIX/src/feabhOS_signal.o \
./feabhOS/C/POSIX/src/feabhOS_task.o 

C_DEPS += \
./feabhOS/C/POSIX/src/feabhOS_condition.d \
./feabhOS/C/POSIX/src/feabhOS_interrupts.d \
./feabhOS/C/POSIX/src/feabhOS_memory.d \
./feabhOS/C/POSIX/src/feabhOS_mutex.d \
./feabhOS/C/POSIX/src/feabhOS_queue.d \
./feabhOS/C/POSIX/src/feabhOS_scheduler.d \
./feabhOS/C/POSIX/src/feabhOS_semaphore.d \
./feabhOS/C/POSIX/src/feabhOS_signal.d \
./feabhOS/C/POSIX/src/feabhOS_task.d 


# Each subdirectory must supply rules for building sources it contributes
feabhOS/C/POSIX/src/%.o: ../feabhOS/C/POSIX/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/ubuntu/workspace/DP-303/feabhOS/C/common/inc" -I"/home/ubuntu/workspace/DP-303/feabhOS/C/POSIX/inc" -I"/home/ubuntu/workspace/DP-303/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


