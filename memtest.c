#include <stdlib.h> 
#include <limits.h> 
#include <float.h> 
#include <string.h>
 
/* simple memory allocation test, written to check for memory allocation problem on AIX -> AIX has a limited size of memory allocation for one chunk (256? MB per CPU), however for version higher than 3.? you can tell the ld to increase that */ 

/* gcc -lm -o memtest memtest.c */
/* copyright Kai Kadau 2002 */
main(){ 
  char *m, *mm; 
  size_t s, s_old; 
  unsigned int l; 
  int i=INT_MAX/100; 
  int ii=101;
  long int i1, i2; 
  double d1, d2, d3;
  long double ld1, ld2, ld3;

 
  printf("int:%d long int: %d\n", sizeof(int), sizeof(long int)); 
  printf("float:%d: %d\n", sizeof(float));
  printf("double:%d long double: %d\n", sizeof(double), sizeof(long double));
   
  i1=CHAR_MIN;
  i2=CHAR_MAX;
  printf("CHAR_MIN:%ld CHAR_MAX:%ld\n", i1, i2); 

  i1=INT_MIN;
  i2=INT_MAX;
  printf("INT_MIN:%ld INT_MAX:%ld\n", i1, i2); 

  i1=LONG_MIN;
  i2=LONG_MAX;
  printf("LONG_MIN:%ld LONG_MAX:%ld\n", i1, i2); 

  d1=FLT_MIN;
  d2=FLT_MAX;
  d3=FLT_EPSILON;
  printf("FLT_MIN:%e FLT_MAX:%e FLT_EPSILON:%e\n", d1, d2, d3); 

  d1=DBL_MIN;
  d2=DBL_MAX;
  d3=DBL_EPSILON;
  printf("DBL_MIN:%e DBL_MAX:%e DBL_EPSILON:%e\n", d1, d2, d3); 

  ld1=LDBL_MIN;
  ld2=LDBL_MAX;
  ld3=LDBL_EPSILON;
  printf("LDBL_MIN:%Le LDBL_MAX:%Le LDBL_EPSILON:%Le\n", ld1, ld2, ld3); 

  printf("ulimt -a\n"); 
  system("ulimit -a"); 
  s=LONG_MAX; 
  l=LONG_MAX; 
  printf("LONG_MAX (size_t):%lu (unsigned long int):%lu\n", s, l); 
  s++; 
  l++; 
  printf("LONG_MAX+1 (size_t):%lu (unsigned long int):%lu\n", s, l); 
  s=ULONG_MAX; 
  l=ULONG_MAX; 
  printf("ULONG_MAX (size_t):%lu (unsigned long int):%lu\n", s, l); 
  s++; 
  l++; 
  printf("ULONG_MAX+1 (size_t):%lu (unsigned long int):%lu\n", s, l); 
 
  m= (char *) malloc(i*ii); 
  if(!m) printf("FAILED TO ALLO NON CASTED \n"); 
  free(m); 
 
  m= (char *) malloc((size_t)i*ii);  
  if(m) printf("SUCCESFUL ALLO CASTED \n");  
  free(m);  

  for(s=2024*2024; ;s*=2){ 
    m= (char *) malloc(s); 
    if(!m) { 
      printf("Failed to allocate %lf MByte\n",s/1024./1024.); 
      m=(char *) malloc(s_old); 
      mm=(char *) malloc(s_old); 
      if(!mm) printf("Failed to allocated two chunks of %lf MByte\n",s_old/1024./1014.); else printf("Succesfully allocated two chunks of %lf MByte\n", s_old/1024./1024.); 
      exit(1); 
    } else printf("Allocate %lf MByte\n",s/1024./1024.); 
 
    free(m); 
    s_old=s; 
 
  } 
} 
