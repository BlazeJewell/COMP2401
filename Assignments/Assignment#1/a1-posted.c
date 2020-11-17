#include <stdio.h>
#include <string.h>

#define MAX_BUF  256

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);

unsigned char stepOne(unsigned char counter, unsigned char key);  // You must have a minimum of three (3) additional functions,
unsigned char stepFour(unsigned char counter,unsigned char message );
unsigned char stepXOR(unsigned char counter, unsigned char message, int i);

int main(){
  char str[8];
  int  choice;

  unsigned char key = 0b10110010;                             // a key and a counter that are initialized at the beginning of the program. 
  unsigned char counter = 0b00101000;

  printf("\nYou may:\n");
  printf("  (1) Encrypt a message \n");
  printf("  (2) Decrypt a message \n");
  printf("\n  what is your selection: ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &choice);

  switch (choice) {
    case 1:{                                                
      unsigned char message[MAX_BUF];                         // Encrypt a message
      printf("\nEnter your message:\n");                      // Read a plaintext string from the command line;                             
      fgets((char *)message, sizeof(message), stdin);         // Gives me a warning if I dont cast it
      int index = 0;
      while(message[index] != '\n'){
        counter = stepOne(counter, key);
        ++counter;                                            // (2) increment the updated counter value by 1
        ++key;                                                // (3) increment the key value by 1
        message[index] = stepFour(counter, message[index]);
        printf("%d ", message[index]);
        ++index;
      }
      break;
    }
    case 2:{    
      unsigned char message[MAX_BUF];                         // (2) Decrypt a message                   
      printf("\nEnter your code:\n");
      int num;
      int index = 0;
      while(num != -1){                                       // Read a sequence of numbers from the command line, up to a sentinel value of -1
        scanf("%d", &num);
        message[index] = num;
        ++index;
      }
      int total = index-1;
      index = 0;
      while(index != total){
        counter = stepOne(counter, key);
        ++counter;                                            // (2) increment the updated counter value by 1
        ++key;                                                // (3) increment the key value by 1
        message[index] = stepFour(counter, message[index]);
        printf("%c", message[index]);
        ++index;
      }
      break;
    }
    
    default:
      printf("\n  Enter a valid option! \n");
      main();
      break;
  }
  printf("\n");
  return 0;
}

/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n){ 
    return ((c & (1 << n)) >> n);
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)   { 
  return c | (1 << n);
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n) { 
  return c & (~(1 << n));
}

/*
  Function:  stepXOR
  Purpose:   compute the xor of the source bit and the counter bit 
       in:   counter
       in:   message
       in:   i
   return:   Returns the temp value bit to the result of the xor operation
*/
unsigned char stepXOR(unsigned char counter, unsigned char message, int i){
  if (getBit(message, i) ^ getBit(counter, i))
    return setBit(message, i);                                // Set the temp counter bit at the current bit position to the result of the xor operation
  else
    return clearBit(message, i);                              // Set the temp counter bit at the current bit position to the result of the xor operation
}

/*
  Function:  stepOne
  Purpose:   Process the counter value, using the key value, 
       in:   counter
       in:   key
   return:   Returns the temp counter value as the updated counter value
*/
unsigned char stepOne(unsigned char counter, unsigned char key){
  int positionOne = 0;                                        // compute two bit positions (position 1 and position 2) 
  int positionTwo = 0;
  for (int i = 7; i>-1; --i){                                 // for every bit position, starting at bit position 7:
    positionOne = i;                                          // Current bit position 
                                                              // 2 is computed as follows:
    if(getBit(key, i)){                                       // if the key bit at the current bit position is 1
      if(i !=7 )
        positionTwo = i+1;
    }
    else{
      if(6 < i)
        positionTwo = 1;                                      // Circle back
      else if(6 == i)
        positionTwo = 0;                                      // Circle back
      else
        positionTwo = i + 2;                                  // Then position 2 is set to two bit positions to the left of the current bit position
    }                                                         // can't use the XOR function, because its slightly different and wouldnt be efficent make my function handle it
    if(getBit(counter, positionOne)^getBit(counter, positionTwo)) // XOR the two temp counter bits found at positions 1 and 2
      counter = setBit(counter, i);                           // Set the counter bit at the current bit position to the result of the xor operation
    else
      counter = clearBit(counter, i);                         // Set the counter bit at the current bit position to the result of the xor operation
  }
  return counter;
}

unsigned char stepFour(unsigned char counter, unsigned char message ){
  unsigned char temp = counter;                               // (a) make a copy of the source byte into a temp value
  int tempInt = temp % 9;                                     // (b) compute the counter value modulo 9
  if(tempInt < 3)
    for (int i = 0; i<8; i+=2)
      message = stepXOR(counter, message, i);
  else if(tempInt <= 5)
    for (int i = 1; i<8; i+=2)
            message = stepXOR(counter, message, i);
  else
    for (int i = 0; i<8; ++i)
      message = stepXOR(counter, message, i);
  return message;
}