/* { dg-do compile } */
/* { dg-options "-O2 -freorder-blocks-and-partition-hot-warm -mthumb -fguess-branch-probability --param hot-bb-frequency-fraction=1" } */
/* { dg-require-effective-target arm_dsp } */

extern void exit (int)  __attribute__ ((__noreturn__));
extern void perror (const char *);
extern void g();

int
f (int i, int s, int l, int sh)
{
  for (; i < l; i++, sh <<= 1)
    {
      s += sh;
    }
      if (__builtin_expect (i == 678219 /*&& sh == 128*/, 0))
	{
	  g (123, 1234, 1, 234234, 89892);
	  perror ("skldfjsl");
	  exit (1);
	}
  return s;
}

/* { dg-final { scan-assembler "f.cold" } } */
