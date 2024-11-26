int main(void)
{
	ft_printf("Teste de caracteres: %c\n", 'A');
	ft_printf("Teste de string: %s\n", "Hello, World!");
	ft_printf("Teste de ponteiro: %p\n", main);
	ft_printf("Teste de decimal: %d\n", 42);
	ft_printf("Teste de inteiro negativo: %i\n", -42);
	ft_printf("Teste de unsigned: %u\n", 123456789);
	ft_printf("Teste de hexadecimal (minúsculo): %x\n", 255);
	ft_printf("Teste de hexadecimal (maiúsculo): %X\n", 255);
	ft_printf("Teste de porcentagem: %%\n");
	return (0);
}