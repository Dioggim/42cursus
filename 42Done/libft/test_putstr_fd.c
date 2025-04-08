#include <fcntl.h>  // For open
#include <unistd.h> // For close
#include "libft.h"  // For your ft_putstr_fd function

int main(void)
{
    // Test 1: Write to standard output (fd 1)
    ft_putstr_fd("Hello, standard output!\n", 1);
    
    // Test 2: Write to standard error (fd 2)
    ft_putstr_fd("Hello, standard error!\n", 2);
    
    // Test 3: Test with NULL parameter
    ft_putstr_fd(NULL, 1);
    
    // Test 4: Write to a file
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd != -1)
    {
        ft_putstr_fd("This text should be in the file!\n", fd);
        close(fd);
        ft_putstr_fd("Successfully wrote to file 'test_output.txt'\n", 1);
    }
    else
    {
        ft_putstr_fd("Failed to open file for writing\n", 2);
    }
    
    // Test 5: Empty string
    ft_putstr_fd("", 1);
    ft_putstr_fd("Test completed.\n", 1);

    return (0);
}