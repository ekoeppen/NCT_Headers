/*	File:		New.h	Copyright:	� 1992, 1996 by Apple Computer, Inc., all rights reserved.	Derived from v2 internal.*/#ifndef __NEW_H#define __NEW_H#ifndef __STDDEF_H#include <stddef.h>#endif#ifdef __cplusplus#ifdef __arm	/* we're using ARMCpp: this stuff came from ARM's globalnew.h */	#pragma force_top_level	#pragma include_only_once	typedef void __HANDLER(void);	extern __HANDLER *_new_handler;	extern __HANDLER *set_new_handler(__HANDLER *);	void *operator new(size_t);	void operator delete(void *);	inline void *operator new(size_t, void *p) { return p; }#else /* not using ARMCpp */	/*	----------------------------------------------------------------	**	**	In-place operator new.	**	**		Use it to call a constructor for a hunk of bytes that you	**		have alllocated, like this:	**	**			void * hunk_of_memory = malloc(42);	**	**			TFoo * foo = new(hunk_of_memory) TFoo(...constructor args...);	**	*/	void * operator new ( size_t, void * );#endif /* else __arm */#endif /* __cplusplus */#endif /* __NEW_H */