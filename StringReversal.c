#include<stdio.h>

// Recursive function to reverse a string
// The function modifies the string in place by swapping characters
void reverse_string(char *str, int start, int end)
{
    char temp;
    
    // Base case: if start meets or passes end, we're done
    if(start >= end){
        return;
    }
    
    // Swap characters
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursively reverse the rest
    reverse_string(str, start+1, end-1);
}

// Helper function to get string length
int string_length(char *str)
{
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

// Alternative recursive approach using pointer arithmetic
char* reverse_recursive(char *str)
{
    // Base case: empty string
    if(str[0] == '\0'){
        return str;
    }
    
    // Recursive call on the rest of the string
    reverse_recursive(&str[1]);
    
    // Print character after recursion (post-order traversal)
    printf("%c", str[0]);
    
    return str;
}

int main()
{
    char string1[100] = "zebra";
    char string2[100] = "Hello World";
    char string3[100] = "Programming";
    
    printf("=== STRING REVERSAL PROGRAM (RECURSIVE) ===\n\n");
    
    // Method 1: In-place reversal
    printf("Method 1: In-place Reversal\n");
    printf("==========================\n");
    printf("Original: %s\n", string1);
    reverse_string(string1, 0, string_length(string1)-1);
    printf("Reversed: %s\n\n", string1);
    
    // Reverse back to original for next test
    reverse_string(string1, 0, string_length(string1)-1);
    
    printf("Original: %s\n", string2);
    reverse_string(string2, 0, string_length(string2)-1);
    printf("Reversed: %s\n\n", string2);
    
    // Method 2: Using pointer arithmetic and printing
    printf("Method 2: Print Recursively\n");
    printf("===========================\n");
    printf("Original: %s\n", string3);
    printf("Reversed: ");
    reverse_recursive(string3);
    printf("\n\n");
    
    // Another example
    char string4[100] = "recursion";
    printf("Original: %s\n", string4);
    printf("Reversed: ");
    reverse_recursive(string4);
    printf("\n");
    
    return 0;
}
