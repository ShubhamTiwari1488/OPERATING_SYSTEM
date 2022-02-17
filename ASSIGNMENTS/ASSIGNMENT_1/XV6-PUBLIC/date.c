
#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[]){
  struct rtcdate r;
  if(date(&r))
    exit();
    
  printf(1,"%d %d %d\n",r.day,r.month,r.year);
  exit();
}
