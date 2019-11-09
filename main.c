#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int rand_gen(){
  int file = open("/dev/random", O_RDONLY);
  int i;
  read(file, &i, sizeof(int));

  if (errno) { // hopefully not
    printf("Errno number: %d\n", errno);
    printf("Message: %s\n", strerror(errno));
  }

  close(file);
  return i;
}


int main(){
  int rand[10];

  printf("Generating random numbers:\n");
  int i;
  for (i = 0; i < 10; i++){
    rand[i] = rand_gen();
    printf("\trandom %d: %d\n", i, rand[i]);
  }

  printf("\nWriting numbers to file...\n");

  int file2 = open("random.txt", O_RDWR|O_CREAT, 0666);
  write(file2, rand, sizeof(rand));
  close(file2);

  if (errno) { //DEBUGGING -- hopefully not
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
  }

  printf("\nReading numbers from file...\n");
  int new[10];
  int file3 = open("random.txt", O_RDONLY);
  read(file3, &new, sizeof(new));
  close(file3);

  if (errno) {
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
  }

  printf("\nVerification that written values were the same:\n");
  for ( i = 0; i < 10; i++){
    printf("\trandom %d: %d\n", i, new[i]);
  }

  return 0;

}
