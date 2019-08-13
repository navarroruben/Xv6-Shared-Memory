#include "param.h"
#include "types.h"
#include "defs.h"
#include "x86.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

struct {
  struct spinlock lock;
  struct shm_page{
    uint id;
    char* frame;
    int refcnt;
    uint temp;
  } shm_pages[64];
} shm_tab;

int shm_open (unsigned int id) {
  cprintf(1, "IN HERE\n");
/*
 int i;                                                                                                                                                             
  acquire(&(shm_tab.lock)); // acquires lock                                                                                                                                                  
  for (i = 0; i < 64; ++i) {
    if (shm_tab.shm_pages[i].id == id) {
      uint var = PGROUNDUP(proc->sz);
      shm_tab.shm_pages[i].temp = V2P(shm_tab.shm_pages[i].frame);
      mappages(proc->pgdir,(void*)PGROUNDUP(proc->sz), PGSIZE, V2P(shm_tab.shm_pages[i].frame), PTE_W | PTE_U);
      shm_tab.shm_pages[i].refcnt++;
      proc->sz += PGSIZE;
      release(&(shm_tab.lock));
      return var;
    }
  }
  for (i = 0; i < 64; ++i) { // searches through shm_pages                                                                                                                                    
    if(shm_tab.shm_pages[i].id == 0) { // if shm_page[i] is not found                                                                                                                         
      shm_tab.shm_pages[i].id = id;          // assin                                                                                                                                         
      shm_tab.shm_pages[i].frame = kalloc(); // allocates physical frame                                                                                                                      
      shm_tab.shm_pages[i].refcnt = 0;       // refcnt is initiated to 0                                                                                                                      
      uint var = PGROUNDUP(proc->sz);
      shm_tab.shm_pages[i].temp = V2P(shm_tab.shm_pages[i].frame);
      memset(shm_tab.shm_pages[i].frame, 0, PGSIZE); // clears frame                                                                                                                          
      mappages(proc->pgdir, (void*) PGROUNDUP(proc->sz), PGSIZE, V2P(shm_tab.shm_pages[i].frame), PTE_W|PTE_U); // maps
                                                                                                                // virtual
                                                                                                                // address
                                                                                                                // to
                                                                                                                // physical
                                                                                                                // frame
                                                                                                                // address                             
//      shm_pages[i].refcnt++; // increments refcnt                                                                                                                                           
      proc->sz += PGSIZE;
      release(&(shm_tab.lock));        // releases lock                                                                                                                                       
      return var;
    }
  }
  release(&(shm_tab.lock));          // releases lock if previous if statement
                                     // does not trigger                                                                                               
                                     */
  return -1;

}












int shm_close(unsigned int id) { /*
//  if (id < 0) {                                                                                                                                                          
//    return -1;                                                                                                                                                           
//  }                                                                                                                                                                      
  int i; // variable for for loops                                                                                                                                         
//  initlock(&lock, "SHM lock");                                                                                                                                           
  acquire(&(shm_tab.lock)); // acquires lock                                                                                                                               
  for (i = 0; i < 64; ++i) { // searches through shm_pages                                                                                                                 
    if(shm_tab.shm_pages[i].id == id) { // if id matches id passed in                                                                                                      
      shm_tab.shm_pages[i].refcnt--;    // decreases refcnt                                                                                                                
      if(shm_tab.shm_pages[i].refcnt == 0) { // if refcnt gets to 0                                                                                                        
        shm_tab.shm_pages[i].id = 0;           // assigns 0 to id                                                                                                          
        shm_tab.shm_pages[i].frame = 0;          // assigns 0 to frame                                                                                                     
      }
      uint k;
      pte_t *pte;
//      size = proc->sz;                                                                                                                                                   
      for (k = 0; k < proc->sz; k += PGSIZE) {
        pte = walkpgdir(proc->pgdir,(void *)k, 0);
        if (shm_tab.shm_pages[i].temp == PTE_ADDR(*pte)) {
          *pte = 0;
        }
//        proc->sz -= PGSIZE;                                                                                                                                              
//        break;                                                                                                                                                           
      }
      proc->sz -= PGSIZE;
      break;
    }
//    proc->sz -= PGSIZE;                                                                                                                                                  
//    break;                                                                                                                                                               
  }
  release(&(shm_tab.lock));
                                 */
  return 0;
}
