# Comment Encrypt-Decrypt Tool in C

This project consists of two C programs for encrypting and decrypting C source code comments using a simple character shifting method.  
It is designed for educational purposes (homework) and demonstrates file parsing, character mapping, and basic encryption/decryption logic.

## Features

- **Part 1 (220104004043_part1.c):**  
  Reads C code from stdin, encrypts all characters (except spaces/newlines) by shifting them in a custom alphabet, and when a comment (`/* ... */`) is encountered, it counts the number of non-space characters inside the comment, encrypts this count, and marks it with an `@` symbol in the output.
- **Part 2 (220104004043_part2.c):**  
  Reads the encrypted output, decrypts characters back to the original, and replaces each `@ <encrypted_number>` marker with a readable message indicating the number of characters as a comment.

## How It Works

- Uses a 61-character custom alphabet for character mapping.
- The encryption shifts the index of each character by `my_key=2`, the decryption reverses this shift.
- Comments are specially handled: The number of non-space characters in each comment is counted, encrypted, and output with an `@` marker.

## Usage

### **Compile Both Parts**

```bash
gcc 220104004043_part1.c -o encryptor
gcc 220104004043_part2.c -o decryptor
