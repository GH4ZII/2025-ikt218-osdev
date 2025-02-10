#ifndef GDT_H
#define GDT_H

#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"

#define GDT_ENTRIES 5


// Define the GDT entry structure
struct gdt_entry_t {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_middle;
  uint8_t access;
  uint8_t granularity;
  uint8_t base_high;
} __attribute__((packed));


// Define the GDT and IDT pointers
struct gdt_ptr_t {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));



// Initialize the GDT and IDT
void init_gdt();


// Load the GDT and IDT
void gdt_load();


void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);


static struct gdt_entry_t gdt[GDT_ENTRIES];
static struct gdt_ptr_t gdt_ptr;

#endif 