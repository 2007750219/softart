#ifndef SASL_VM_OP_CODE_H
#define SASL_VM_OP_CODE_H

#include "op_code/instruction_list.h"

//enum op_code{
//	/*********************************
//	*	辅助
//	*********************************/
//	op_nop = 0,
//	// 描述：		空指令
//	// 指令格式：	op_nop
//	// 参数：		无
//	op_halt,
//	// 描述：		在任意状态下，终止虚拟机的执行并停机
//	// 指令格式：	op_halt
//	// 参数：		无
//
//	/*********************************
//	*	整数代数运算
//	*********************************/
//	op_add_si,
//	// 描述：		将两个寄存器中的数以有符号整数的形式相加。
//	// 指令格式：	op_add_si REG0, REG1
//	// 参数：		REG0: 目标寄存器号，REG1: 源寄存器号
//
//	/*********************************
//	*	栈
//	*********************************/
//	op_push,
//	// 描述：		将寄存器压入栈中。
//	// 指令格式：	op_push REG0
//	// 参数：		REG0：要压入栈的寄存器号。
//	op_pop,
//	// 描述：		将栈中数据返回寄存器，并从栈中弹出相应数据。
//	// 指令格式：	op_pop REG0
//	// 参数：		REG0：接受返回值的寄存器号。
//
//	/*********************************
//	*	拷贝
//	*********************************/
//	op_load_i32r_fr,
//	// 描述：		将浮点寄存器中的数值截断后取32位整数保存到整数寄存器中。
//	// 指令格式：	op_load_i32r_fr REG, FREG
//	// 参数：		REG：整数寄存器号，FREG：浮点寄存器号
//	op_load_fr_i32r,
//	// 描述：		将32位整数转换成浮点数保存到浮点数寄存器中。
//	// 指令格式：	op_load_fr_i32r FREG, REG
//	// 参数：		FREG：浮点寄存器号，REG：整数寄存器号
//	op_load_r,
//	// 描述：		将一个常量读入到寄存器中
//	// 指令格式：	op_load_r REG0, CONST
//	// 参数：		REG0：目标寄存器号，CONST：有符号整数
//	op_load_r_s,
//	// 描述：		从栈中读取到寄存器中
//	// 指令格式：	op_load_r_ssi REG0, OFFSET
//	// 参数：		REG0：目标寄存器，CONST：栈基偏移地址
//	op_load_s_r,
//	// 描述：		将寄存器中值写入到栈的某个地址中
//	// 指令格式：	op_load_r_ssi REG0, OFFSET
//	// 参数：		REG0：目标寄存器，CONST：栈基偏移地址
//
//	/*********************************
//	*	子过程调用
//	*********************************/	
//	op_call,
//	// 描述：		调用指令。依次将ebp和eip压栈，并跳转至目标地址。
//	// 指令格式：	op_call ADDR
//	// 参数：		ADDR：指令地址
//	op_ret
//	// 描述：		调用返回指令。清理子过程栈的使用，恢复父过程的栈基指针，并跳转会父指令的位置。
//	// 指令格式：	op_ret
//	// 参数：		无
//};

#endif //SASL_VM_OP_CODE_H