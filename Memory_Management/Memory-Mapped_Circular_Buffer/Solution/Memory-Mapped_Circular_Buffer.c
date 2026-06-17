#include <stdio.h>

#define MAXBUFSIZE 100

struct buff {
  int head;
  int tail;
  int *pbuff;
};

int deviceData[MAXBUFSIZE] = {0};        // creating the buffer
struct buff buffer = {0, 0, deviceData}; // initializing the buff

int isBuffEmpty(void) {
  if (buffer.tail == buffer.head) {
    return 0;
  }
  return 1;
}
int isBuffFull(void) {
  if ((buffer.tail + 1) == buffer.head) {
    return 1;
  }
  return 0;
}
void write(int data) {
  if (isBuffFull()) {
    buffer.head++;
    if (buffer.head == MAXBUFSIZE)
      buffer.head = 0;
    buffer.pbuff[++buffer.tail] = data;
    return;
  }
  buffer.pbuff[++buffer.tail] = data;
}

int read(void) {
  int res = -1;
  if (!isBuffEmpty()) {

    res = buffer.pbuff[buffer.tail++];
    if (buffer.tail == MAXBUFSIZE)
      buffer.tail = 0;
  }
  return res;
}

int main(void) {
    printf("--- Testing Circular Buffer ---\n\n");

    // 1. Test Writing data
    printf("Writing values 10, 20, 30 into buffer...\n");
    write(10);
    write(20);
    write(30);

    // 2. Test Reading data back
    printf("\nReading data back:\n");
    printf("Read 1: %d (Expected: 10)\n", read());
    printf("Read 2: %d (Expected: 20)\n", read());
    printf("Read 3: %d (Expected: 30)\n", read());

    // 3. Test Reading from an empty buffer
    printf("\nReading from empty buffer:\n");
    printf("Read 4: %d (Expected: -1)\n", read());

    // 4. Test Filling the buffer to its limit
    printf("\nFilling buffer to capacity...\n");
    for(int i = 1; i <= 105; i++) {
        write(i);
    }
    printf("Filled 105 items into a 100-size buffer.\n");

    // 5. Read after overflow
    printf("\nReading after overflow:\n");
    printf("Read: %d\n", read());

    return 0;
}