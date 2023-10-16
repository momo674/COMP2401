#include <stdio.h>
#include <string.h>

#define MAX_BUF  256
#define IV 0b11001011

unsigned char initKey(); //done
unsigned char processKey(unsigned char);

void encode(unsigned char*, unsigned char*, unsigned char, int);
void decode(unsigned char*, unsigned char*, unsigned char, int);

unsigned char encryptByte(unsigned char, unsigned char, unsigned char);
unsigned char decryptByte(unsigned char, unsigned char, unsigned char);
unsigned char cShiftRight(unsigned char); //done
unsigned char cShiftLeft(unsigned char); //done

int readBytes(unsigned char*, int); //done
unsigned char getBit(unsigned char, int); //done
unsigned char setBit(unsigned char, int); //done
unsigned char clearBit(unsigned char, int); //done


int main()
{
  char str[8];
  int  choice;
  unsigned char i;
  // printf("Enter number: ");
  // scanf(" %d", &i);
  // printf("%d\n",i);


  printf("\nYou may:\n");
  printf("  (1) Encrypt a message \n");
  printf("  (2) Decrypt a message \n");
  printf("  (0) Exit\n");
  printf("\n  what is your selection: ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &choice);


  switch (choice) {

    case 1:
      
      unsigned char plaintext[MAX_BUF];

      unsigned char partial_key = initKey();

      printf("\n  Enter your message in plain text: ");
      fgets(plaintext, 256, stdin);

      printf("This is your key -> %d: This is your message -> %s\n", partial_key, plaintext);

      
      

      
      
      break;

    case 2:

      break;

    default:

      break;
  }

  return(0);
}

/*
  Function:  readBytes
  Purpose:   reads characters from the standard output
      out:   the buffer containing the bytes read
       in:   the capacity of the buffer (maximum size)
   return:   the number of bytes actually read from the user
*/
int readBytes(unsigned char* buffer, int max)
{
  int num = 0;

  fgets((char*)buffer, max, stdin);
  num = strlen((char*)buffer) - 1;
  buffer[num] = '\0';

  return num;
}

/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)
{
  return ((c & (1 << n)) >> n);
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)
{
  unsigned char result;
  result = c | (1 << n);
  return result;
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n)
{
  unsigned char result;
  result = c & (~(1 << n));
  return result;
}

//working
unsigned char initKey()
{
  unsigned int input;
  printf("Enter the partial key (between 1 and 15): ");
  scanf(" %d", &input);
  fgetc(stdin);
  unsigned char partial_key = (unsigned char) input;

  for (int i = 0; i < 4; i++) {
    partial_key = cShiftLeft(partial_key);
  }
  

  for (int i = 7; i > 3; i--) {
    unsigned char bit = getBit(partial_key, i);
    int second_index = (i-1) % 4;
    
    if (bit == 1) {
      partial_key = clearBit(partial_key, second_index);
    }
    else if (bit == 0) {
      partial_key = setBit(partial_key, second_index);
    }
    
  }
  return partial_key;
}

unsigned char cShiftLeft(unsigned char byte)
{
  unsigned char updated;
  updated = (byte << 1) | (byte >> (8 - 1));
  return updated;
}

unsigned char cShiftRight(unsigned char byte)
{
  unsigned char updated;
  updated = (byte >> 1) | (byte << (8 - 1));
  return updated;
}

unsigned char processKey(unsigned char key) 
{
  if (key % 3 == 0) {
    for (int i = 0; i < 3; i ++) 
    {
      key = cShiftLeft(key);
    }
  }

  else 
  {
    for (int i = 0; i < 2; i ++) 
    {
      key = cShiftLeft(key);
    }
  }

  return key;
}
