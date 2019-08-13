#include "types.h"
#include "user.h"
#include "uspinlock.h"

struct shm_cnt
{
  struct uspinlock lock;  
  volatile int cnt;
};

int main()
{
  int pid;                 // variable to hold fork results
  pid = fork();            // calls fork
  struct shm_cnt *pbase;   // pointer for shm_cnt for parent base
  struct shm_cnt *cbase;   // pointer for shm_cnt for child chase
  
    if (pid > 0 ) {
    int p;
    pbase = (struct shm_cnt *)shm_open(0xbeefbeef); // calls shm_open and assigns returned value to pbase
    initulock(&pbase->lock);                        // initiates parent base lock  

    for (p = 0; p < 100000; p++) {
      uacquire(&pbase->lock);   
      pbase->cnt = pbase->cnt + 1;
      urelease(&pbase->lock);
    }
    wait();
    printf(1, "%d\n", pbase->cnt);
  }
  if (pid == 0) {
    int c;
    cbase = (struct shm_cnt *)shm_open(0xbeefbeef); // calls shm_open and assigns returned value to cbase   

    for (c = 0; c < 100000; c++) {
      uacquire(&cbase->lock);
      cbase->cnt = cbase->cnt + 1;
      urelease(&cbase->lock);
    }
  }
  shm_close(0xbeefbeef);
  exit();
  return 0;
}


