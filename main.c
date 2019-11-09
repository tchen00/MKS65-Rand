# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int * gen_rand(){
  int rand_file = open("/dev/random", O_RDONLY);
  int i;
  int random_int = read(rand_file, &i, sizeof(int));
  close(rand_file);
  return i;
}

int main(){
  int arr[10];

  printf("Generating random numbers:\n");
  int i;
  for(i = 0; i < 10; i++) {
    arr[i] = gen_rand();
    printf("\trandom %d: %d\n", i, arr[i]);
  }

  printf("Writing numbers to file...\n");
  int file = open("text.txt", O_WRONLY);
  write(file, arr, 10 * sizeof(int));
  close(file);

  printf("Reading numbers from file...\n");
  file = open("text.txt", O_RDONLY);
  int arr2[10];
  read(file, arr2, 10 * sizeof(int));
  close(file);

  printf("Verification that written values were the same:\n");
  for(i = 0; i < 10; i++) {
    printf("\trandom %d: %d\n", i, arr2[i]);
  }

  return 0;
}
