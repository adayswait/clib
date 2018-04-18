#ifndef ROCLIB_MACRO_H
#define ROCLIB_MACRO_H

#ifndef likely
#define likely(x) __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#endif

#ifndef container_of
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({                                    \
	const typeof(((type *)0)->member) * __mptr = (ptr);                         \
	(type *)((char *)__mptr - offsetof(type, member)); })
#endif

#endif /* ROCLIB_MACRO_H */
