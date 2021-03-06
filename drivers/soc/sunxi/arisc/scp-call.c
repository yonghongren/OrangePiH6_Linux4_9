/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Copyright (C) 2018 Allwinner Tech Limited
 *
 * Author: fanqinghua <fanqinghua@allwinnertech.com>
 */

#include <linux/arm-smccc.h>

#ifdef CONFIG_ARM
int invoke_scp_fn_smc(u32 function_id, u32 arg0, u32 arg1, u32 arg2)
{
	struct arm_smccc_res res;

	arm_smccc_smc(function_id, arg0, arg1, arg2, 0, 0, 0, 0, &res);
	return res.a0;
}
#endif

#ifdef CONFIG_ARM64
int invoke_scp_fn_smc(u64 function_id, u64 arg0, u64 arg1, u64 arg2)
{
	struct arm_smccc_res res;

	arm_smccc_smc(function_id, arg0, arg1, arg2, 0, 0, 0, 0, &res);
	return res.a0;
}
#endif
