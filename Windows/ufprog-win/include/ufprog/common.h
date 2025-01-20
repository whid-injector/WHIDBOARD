/* SPDX-License-Identifier: LGPL-2.1-only */
/*
 * Author: Weijie Gao <hackpascal@gmail.com>
 *
 * Common definitions
 */
#pragma once

#ifndef _UFPROG_COMMON_H_
#define _UFPROG_COMMON_H_

#include <stddef.h>
#include <ufprog/status_code.h>

#ifdef __cplusplus
#define EXTERN_C_BEGIN		\
	extern "C" {

#define EXTERN_C_END		\
	}
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)				(sizeof(a) / sizeof(a[0]))
#endif

#if defined(WIN32)
#define UFPROG_API				__stdcall
#else
#define UFPROG_API
#endif

/* Version helper */
#define MAKE_VERSION(_major, _minor)		(((uint32_t)(_major) & 0xffff) << 16) | \
						 ((uint32_t)(_minor) & 0xffff)
#define GET_MAJOR_VERSION(_ver)			(((_ver) >> 16) & 0xffff)
#define GET_MINOR_VERSION(_ver)			((_ver) & 0xffff)

/* Generic directory names */
#define UFPROG_APPDATA_NAME			"ufprog"
#define UFPROG_DEVICE_DIR_NAME			"device"
#define UFPROG_PLUGIN_DIR_NAME			"plugin"
#define UFPROG_CONFIG_SUFFIX			".json"

/* Compiler-independent types */
typedef int ufprog_bool;

/* Cast a member of a structure out to the containing structure (simplified for compiling on MSVC) */
#define container_of(_ptr, _type, _member)	((_type *)((uintptr_t)(_ptr) - offsetof(_type, _member)))

#endif /* _UFPROG_COMMON_H_ */
