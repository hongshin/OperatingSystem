void
_write(int fid, char * c, long len)
{
	asm(
	"movq $1, %rax\n\t" 
	"movq %rdi, %rdi\n\t"
	"movq %rsi, %rsi\n\t"
	"movq %rdx, %rdx\n\t"
	"syscall"
	) ;
}

int 
main()
{
	_write(1, "hello\n", 6) ;
}

