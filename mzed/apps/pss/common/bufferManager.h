#ifndef BUF_MAN_H
#define BUF_MAN_H

#if defined(__linux__)
	#define uint8  unsigned char
	#define uint16 unsigned short
	#define uint32 unsigned int
#endif

/* packet  Descriptor fields */
#define BIT32 0x80000000
#define BIT31 0x40000000
#define BIT29 0x20000000
#define BIT28 0x10000000
#define BIT27 0x08000000
#define BIT26 0x04000000
#define BIT25 0x02000000
#define BIT24 0x01000000
#define BIT23 0x00800000
#define BIT22 0x00400000
#define BIT21 0x00200000
#define BIT19 0x00100000
#define BIT18 0x00080000
#define BIT17 0x00040000
#define BIT16 0x00020000
#define BIT15 0x00010000
#define BIT16 0x00020000

#define SET_FIELD(field,mask,value) 
#define GET_FIELD(field,mask,value) 

struct packetDescriptorNode
{
	uint32 id; 
	struct packetDescriptorNode* previous;
	struct packetDescriptorNode* next;
	uint32* packetDescriptor;
};

struct packetDescriptorNode* CreateDescriptorList(uint32 size);

#endif
