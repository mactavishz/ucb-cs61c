#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    unsigned mask = 1 <<n;
    return (x & mask) >> n; /* UPDATE WITH THE CORRECT RETURN VALUE*/
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    unsigned mask_1 = ~(1 << n);
    // set the nth bit to 0
    *x &= mask_1;
    // set the nth bit to v
    unsigned mask_v = v << n;
    *x |= mask_v;
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
  // just reuse the get_bit and set_bit functions
  unsigned n_bit = get_bit(*x, n);
  set_bit(x, n, ~n_bit & 1);
}

